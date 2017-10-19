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
     各点での木の高さ：木の直径を求める、その直径に対応する点をu,vとすると、任意の点iからの高さはmax(uからの距離, vからの距離)
     */
    ll root = 0;
    ll v1,v2;
    vector<ll> dist1(n,INF);
    dijkstra(root, n, T, dist1);
    v1 = max_element(dist1.begin(), dist1.end()) - dist1.begin();

    vector<ll> dist2(n,INF);
    dijkstra(v1, n, T, dist2);
    v2 = max_element(dist2.begin(), dist2.end()) - dist2.begin();
    
    vector<ll> dist3(n,INF);
    dijkstra(v2, n, T, dist3);
    
    for(int i = 0; i < n;i++){
        cout << max(dist2[i],dist3[i]) << endl;
    }
    return 0;
}
