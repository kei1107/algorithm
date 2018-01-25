#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

struct edge{
    ll u;
    ll v;
    ll cost;
    edge(){}
    edge(ll u,ll v, ll cost):u(u),v(v),cost(cost){}
};

void dijkstra(ll root,ll n,vector<vector<edge>>&T ,vector<ll>& dist){
    queue<ll> q;
    q.push(root);
    dist[root] = 0;
    while(!q.empty()){
        ll next = q.front(); q.pop();
        for(auto e:T[next]){
            if(dist[e.v] > dist[e.u] + e.cost){
                dist[e.v] = dist[e.u] + e.cost;
                q.push(e.v);
            }
        }
    }
}

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n; cin >> n;
    vector<vector<edge>> T(n);
    for(int i = 0; i < n - 1;i++){
        ll s,t, w; cin >> s >> t >> w;
        T[s].emplace_back(edge(s,t,w));
        T[t].emplace_back(edge(t,s,w));
    }
    
    
    /*
     木の直径：任意の一点から各点への最短距離を求める。次に、求めた最短距離の中で最も最長な点から再度各点への最短距離を求める
             求めた最短距離のうち最長な長さが直径
     */
    ll root = 0;
    ll v1,v2;
    ll max_dist;
    vector<ll> dist(n,INF);
    dijkstra(root, n, T, dist);
    v1 = max_element(dist.begin(), dist.end()) - dist.begin();
    
    dist.assign(n,INF);
    dijkstra(v1, n, T, dist);
    v2 = max_element(dist.begin(), dist.end()) - dist.begin();
    
    cout << dist[v2] << endl;
    
    return 0;
}
