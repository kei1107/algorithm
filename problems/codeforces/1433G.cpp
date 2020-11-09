#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T>& V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> >& Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T>& mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }
template<typename T>vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}
/*
 <url:>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */

class Dijkstra{
public:
    ll V;
    ll root;
    
    struct edge{
        ll u;
        ll v;
        ll cost;
        edge(){}
        edge(ll u,ll v,ll c):u(u),v(v),cost(c){}
    };
    
    vector<vector<edge>> G;
    vector<ll> dist;
    
    Dijkstra(ll V):V(V){
        G.resize(V);
        dist.assign(V, INF);
    }
    void add_edge(ll u,ll v,ll cost, bool undirected = false){
        G[u].emplace_back(edge(u,v,cost));
        if(undirected){
            G[v].push_back(edge(v,u,cost));
        }
    }
    
    void calc_dist(ll root){
        fill(dist.begin(),dist.end(),INF);

        this->root = root;
        dist[root] = 0;
        queue<pll> q; q.push({root,0});
        while(!q.empty()){
            auto p = q.front(); q.pop();
            ll n = p.first;
            ll now_d = p.second;
            if(now_d > dist[n]) continue;
            for(auto e:G[n]){
                if(dist[e.v] > dist[e.u] + e.cost){
                    dist[e.v] = dist[e.u] + e.cost;
                    q.push({e.v,now_d + e.cost});
                }
            }
        }
    }
    
    inline ll get_dist(ll n) const{ return dist[n];}
};

template<class Type>
Type solve(Type res = Type()){
    int n,m,k; cin >> n >> m >> k;

    Dijkstra dijkstra(n);
    vector<pii> edges,target_edges;
    for(int i = 0; i < m;i++){
        int x,y; ll w; cin >> x >> y >> w;
        x--; y--;

        if(x > y) swap(x,y);
        dijkstra.add_edge(x,y,w,true);
        edges.emplace_back(x,y);
    }
    for(int i = 0; i < k;i++){
        int x,y; cin >> x >> y;
        x--; y--;

        if(x > y) swap(x,y);
        target_edges.emplace_back(x,y);
    }

    vector<vector<ll>> dist(n,vector<ll>(n));
    for(int i = 0; i < n;i++){
        dijkstra.calc_dist(i);
        dist[i] = dijkstra.dist;
    }

    res = LINF;

    for(auto e:edges){
        int u,v; tie(u,v) = e;

        ll sum_dist = 0;
        for(auto te:target_edges){
            int tu,tv; tie(tu,tv) = te;
            sum_dist += min({
                dist[tu][tv],
                dist[tv][tu],
                dist[tu][u]+dist[tv][v],
                dist[tu][v]+dist[tv][u],
            });
        }
        res = min(res,sum_dist);
    }

    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    //solve<ll>(0);
    cout << fixed << setprecision(12) << solve<ll>() << endl;
    return 0;
}