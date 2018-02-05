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
<url:http://poj.org/problem?id=1065>
問題文============================================================
 長さ l と重さ w で特徴付けられる棒が n 本あります。
 これらの棒を 1 本ずつ順番に機械で処理することを考えます。
 
 直前に処理した棒を (l1,w1)，次に処理する棒を (l2,w2) とすると、l1 <= l2 and w1 <= w2 であれば、
 (l2,w2) の処理にかかる時間は 0 分になります。
 そうでなければ、処理にかかる時間は 1 分になります。
 
 最適な順番で処理を行うとき、合計処理時間の最小値を求めてください。
=================================================================

解説=============================================================
要するにDAGの最小パス被膜を求めよ。しかし、制約的にフローで解くことができないので別の解法を探す
 
 すると、解説を進めて行くと、この問題は
 pair(l1,w1)でソートして、小さいペアから順番に選択可能であれば、選んでいけば良いことがわかる
================================================================
*/
#define MAX_N 5000

pii lw[MAX_N];
bool f[MAX_N];

int main(void) {
    int kassa;
    scanf("%d",&kassa);
    for(int kinogassa = 0; kinogassa < kassa; kinogassa++){
        fill(f,f+MAX_N,false);
        int N; scanf("%d",&N);
        for(int i = 0; i < N;i++){
            scanf("%d%d",&lw[i].first,&lw[i].second);
        }
        sort(lw,lw+N);
        
        int ans = 0;
        for(int i = 0; i < N;i++){
            if(f[i]) continue;
            f[i] = true;
            ans++;
            int idx = i;
            for(int j = i+1;j < N;j++){
                if(f[j]) continue;
                if(lw[idx].second <= lw[j].second){
                    f[j] = true;
                    idx = j;
                }
            }
        }
        cout << ans << endl;
    }
	return 0;
}
