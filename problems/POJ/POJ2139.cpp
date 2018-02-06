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
#define INF 1<<30
#define LINF 1LL<<60

/*
 <url:http://poj.org/problem?id=2139>
 問題文============================================================
 N 頭の牛に関して，M 本の各映画について，それぞれどの牛が出演したかの情報が与えられる．
 
 同じ映画にある2頭の牛が出演したとき，互いに「1 degree away」であるという．
 同じ映画に出演したことはないが，どちらもある別の牛となら同じ映画に出演したことがあるなら，
 互いに「2 degree away」といい，以降同様に degree を定める．
 
 degree の平均が最も小さい牛に興味がある．その牛の degree の平均値の100倍の値を整数値(切り捨て)で答える．
 =================================================================
 
 解説=============================================================
 ワーシャルフロイド
 ================================================================
 */
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll N,M; cin >> N >> M;
    vector<vector<ll> > G(N,vector<ll>(N,LINF));
    for(int i = 0; i < N;i++) G[i][i] = 0;
    for(int i = 0; i < M;i++){
        ll n; cin >> n;
        vector<int> v(n);
        for(int j = 0;j < n;j++){
            cin >>v[j]; v[j]--;
        }
        for(int j = 0; j < n;j++){
            for(int k = j+1;k<n;k++){
                G[v[j]][v[k]] = G[v[k]][v[j]] = 1;
            }
        }
    }
    
    for(int i = 0; i < N;i++){
        for(int j = 0; j < N;j++){
            for(int k = 0; k < N;k++){
                G[j][k] = min(G[j][k],G[j][i]+G[i][k]);
            }
        }
    }
    ll ans = LINF;
    for(int i = 0; i < N;i++){
        ll tmp = 0;
        for(int j = 0; j < N;j++){
            if(i == j) continue;
            tmp += G[i][j];
        }
        ans = min(ans,tmp);
    }
    cout << 100*ans/(N-1) << endl;
    return 0;
}
