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
#define INF (1<<30)
#define LINF (1LL<<60)

/*
<url:>
問題文============================================================

=================================================================

解説=============================================================

 dp[S1][i] := 購入済S1,今いる場所i
 
================================================================
*/

struct Route{
    int a;
    int b;
    int c;
    int P;
    int R;
    Route(){}
    Route(int a,int b,int c,int P,int R):a(a),b(b),c(c),P(P),R(R){}
};

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    int N,m; cin >> N >> m;
    vector<vector<Route> > G(m);
    for(int i = 0; i < m;i++){
        int a,b,c,P,R; cin >> a >> b >> c >> P >> R;
        a--; b--; c--;
        G[a].push_back(Route(a,b,c,P,R));
    }

    vector<vector<int> > dist(1<<N,vector<int>(N,INF));
    queue<pii> q;
    q.push(make_pair(1<<0,0));
    dist[1<<0][0] = 0;
    
    while(!q.empty()){
        pii p = q.front(); q.pop();
        int S = p.first, n = p.second;
        for(int i = 0; i < (int)G[n].size();i++){
            int cost;
            if((S>>G[n][i].c)&1){
                cost = G[n][i].P;
            }else{
                cost = G[n][i].R;
            }
            if(dist[S|1<<G[n][i].b][G[n][i].b] > dist[S][n] + cost){
                dist[S|1<<G[n][i].b][G[n][i].b] = dist[S][n] + cost;
                q.push(make_pair(S|1<<G[n][i].b,G[n][i].b));
            }
        }
    }
    int ans = INF;
    for(int i = 0; i < (1<<(N-1));i++){
        ans = min(ans,dist[i|(1<<(N-1))][N-1]);
    }
    if(ans == INF){
        cout << "impossible" << endl;
    }else{
        cout << ans << endl;
    }
	return 0;
}
