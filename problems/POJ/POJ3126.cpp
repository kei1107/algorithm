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
<url:>
問題文============================================================

=================================================================

解説=============================================================

================================================================
*/
vector<int> prime(10000,0);
void Prime() {
    prime[2] = 1;
    for (int i = 3; i < 10000; i += 2) {
        bool f = false;
        for (int j = 3; j <= sqrt(i); j += 2) {
            if (i%j == 0) {
                f = true;
                break;
            }
        }
        if (!f){
            prime[i] = 1;
        }
    }
}

struct edge{
    int u;
    int v;
    int cost;
    edge(){};
    edge(int u,int v,int cost):u(u),v(v),cost(cost){}
};

template < typename T > std::string to_string( const T& n )
{
    std::ostringstream stm ;
    stm << n ;
    return stm.str() ;
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    Prime();
    vector<vector<edge> > G(10000);
    for(int u = 1000; u < 10000;u++){
        if(prime[u] == 0) continue;
        string t  = to_string(u);
        for(int i = 0; i < 4;i++){
            for(int j = 0; j <= 9;j++){
                if(i == 0 && j == 0)continue;
                if(t[i] - '0' == j) continue;
                string tmp = t;
                tmp[i] = '0' + j;
                
                int v = atoi(tmp.c_str());
                if(prime[v] == 0) continue;
                
                G[u].push_back(edge(u,v,1));
            }
        }
    }
    
    int Case; cin >> Case;
    for(int XXXXXXXX = 0; XXXXXXXX < Case; XXXXXXXX++){
        vector<int> dist(10000,INF);
        int s,t; cin >> s >> t;
        dist[s] = 0;
        queue<int> q; q.push(s);
        while(!q.empty()){
            int n = q.front(); q.pop();
            for(int i = 0; i < G[n].size();i++){
                edge& e = G[n][i];
                if(dist[e.v] > dist[e.u] + e.cost){
                    dist[e.v] = dist[e.u] + e.cost;
                    q.push(e.v);
                }
            }
        }
        
        if(dist[t] == INF){
            cout << "Impossible" << endl;
        }else{
            cout << dist[t] << endl;
        }
    }
}
