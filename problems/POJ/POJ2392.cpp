#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <bitset>
#include <iostream>
#include <iomanip>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <numeric>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <deque>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e16;

/*
<url:>
問題文============================================================

=================================================================

解説=============================================================
ブロックはあらかじめ限界高さ順にソート済み
 dp[i][j] := i番目のブロックのブロックを観ている時、高さjに到達した際に残っているブロックの個数
 
================================================================
*/

struct Block{
    int h,a,c;
    Block(){}
    Block(int h,int a,int c):h(h),a(a),c(c){}
    bool operator < (const Block& o)const{
        return a < o.a;
    }
};

#define MAX_A 100*400
#define MAX_K 400
int K;
int dp[MAX_A+1];
Block block[MAX_K];

int main(void) {
//	cin.tie(0); ios::sync_with_stdio(false);
    scanf("%d",&K);
    for(int i = 0; i < K;i++){
        int h,a,c; scanf("%d%d%d",&h,&a,&c);
        block[i] = Block(h,a,c);
    }
    sort(block,block + K);
    
    fill(dp,dp + MAX_A+1,-1);
    dp[0] = 0;
    
    for(int i = 0; i < K;i++){
        for(int j = 0; j <= block[i].a; j++){
            if(dp[j] >= 0){
                dp[j] = block[i].c;
            }
            if(j >= block[i].h){
                dp[j] = max(dp[j],dp[j-block[i].h] - 1);
            }
        }
    }
    for(int i = MAX_A;i>= 0;i--){
        if(dp[i] >= 0){
            cout << i << endl;
            return 0;
        }
    }
	return 0;
}
