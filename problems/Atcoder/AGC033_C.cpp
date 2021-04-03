#include "bits/stdc++.h"
#include "atcoder/all"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T>& V){ for(size_t i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> >& Mat){ for(size_t i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T>& mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }
template<typename T>vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}
/*
 <url:https://atcoder.jp/contests/agc033/tasks/agc033_c>
 問題文============================================================
 C - Removing Coins 
 =================================================================
 解説=============================================================
 ================================================================
 */

template<typename CType>
class Dijkstra{
public:
    struct edge{
        size_t u,v;
        CType cost;
        edge() {}
        edge(size_t u,size_t v,CType c):u(u),v(v),cost(c) {}
    };

    size_t V;
    size_t now_root;

    vector<vector<edge>> G;
    vector<CType> dist;

    Dijkstra(size_t V):V(V){
        G.resize(V);
        dist.resize(V);
        init();
    }
    void init(CType init_val = numeric_limits<CType>::max()){
        fill(dist.begin(),dist.end(),init_val);
    }

    void add_edge(size_t u,size_t v,CType cost){
        G[u].emplace_back(edge(u,v,cost));
    }
    void add_biedge(size_t u,size_t v,CType cost){
        add_edge(u,v,cost);
        add_edge(v,u,cost);
    }

    void fit(size_t root){
        now_root = root;
        dist[now_root] = 0;

        using Item = tuple<CType,size_t>;
        priority_queue<Item,vector<Item>,greater<Item>> pq;
        pq.emplace(0,now_root);

        while(pq.size()){
            auto [cost,n] = pq.top(); pq.pop();
            if(cost > dist[n]) continue;
            for(auto e:G[n]){
                if(dist[e.v] > dist[e.u] + e.cost){
                    dist[e.v] = dist[e.u] + e.cost;
                    pq.emplace(dist[e.v],e.v);
                }
            }
        }
    }
    CType operator[](int i) { return dist[i]; }
};


template<class Type>
Type solve(Type res = Type()){
    int N; cin >> N;

    Dijkstra<int> dijkstra(N);
    for(int i = 0; i < N-1; i++){
        int a,b; cin >> a >> b;
        a--; b--;
        dijkstra.add_biedge(a,b,1);
    }

    dijkstra.init(); dijkstra.fit(0);
    int s = (int)distance(dijkstra.dist.begin(),max_element(dijkstra.dist.begin(),dijkstra.dist.end()));
    dijkstra.init(); dijkstra.fit(s);
    int t = (int)distance(dijkstra.dist.begin(),max_element(dijkstra.dist.begin(),dijkstra.dist.end()));
    
    if(dijkstra[t]%3 == 1) return "Second";
    else return "First";
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    //solve<ll>(0);
    cout << fixed << setprecision(12) << solve<string>() << endl;
    return 0;
}