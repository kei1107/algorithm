#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <bitset>
#include <iostream>
#include <iomanip>
#include <memory>
#include <string>
#include <cstring>
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
#define INF (1<<30)
#define LINF (1LL<<60)

/*
<url:>
問題文============================================================

=================================================================

解説=============================================================
反転
================================================================
*/
const int N = 21;
int f[N]; // 区間[i, i+ K -1] を反転させたかどうか
int bowls[N]; // 向き
int tmp[N];

int calc(int K){
    memset(f,0,sizeof(f));
    int res = 0;
    for(int i = 0; i <= 18;i++){
        if(bowls[i] == 1){
            res++;
            for(int j = 0; j < 3;j++){
                bowls[i+j] = !bowls[i+j];
            }
        }
    }
    return res;
}

void solve(){
    int K = 3;
    int res = calc(K);
    bowls[0] = !tmp[0];
    bowls[1] = !tmp[1];
    for(int i = 2; i < N;i++){
        bowls[i] = tmp[i];
    }
    res = min(res,calc(K)+1);
    cout << res << endl;
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    for(int i = 0; i < 20;i++){
        cin >> bowls[i];
        tmp[i] = bowls[i];
    }
    solve();
	return 0;
}
