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
 <url:https://atcoder.jp/contests/typical90/tasks/typical90_c>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */

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

template<class Type>
Type solve(Type res = Type()){
    ll n; cin >> n;
    vector<vector<edge>> T(n);
    for(int i = 0; i < n - 1;i++){
        ll s,t; cin >> s >> t;
        s--; t--;
        T[s].emplace_back(edge(s,t,1));
        T[t].emplace_back(edge(t,s,1));
    }
    
    ll root = 0;
    ll v1,v2;
    vector<ll> dist(n,INF);
    dijkstra(root, n, T, dist);
    v1 = max_element(dist.begin(), dist.end()) - dist.begin();
    
    dist.assign(n,INF);
    dijkstra(v1, n, T, dist);
    v2 = max_element(dist.begin(), dist.end()) - dist.begin();
    
    res = dist[v2]+1;
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    //solve<ll>(0);
    cout << fixed << setprecision(12) << solve<ll>() << endl;
    return 0;
}