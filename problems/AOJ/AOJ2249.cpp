#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

/*
 <url:>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */
struct edge{
    ll u,v,d,c;
    edge(){}
    edge(ll u,ll v,ll d,ll c):u(u),v(v),d(d),c(c){}
    bool operator < (const edge& o) const{
        return c < o.c;
    }
    bool operator > (const edge& o) const{
        return c > o.c;
    }
};
ll solve(ll N,ll M){
    ll res = 0;
    vector<vector<edge>> G(N);
    for(int i = 0;i <M;i++){
        ll u,v,d,c; cin >> u >> v >> d >> c;
        u--; v--;
        G[u].push_back(edge(u,v,d,c));
        G[v].push_back(edge(v,u,d,c));
    }
    
    vector<ll> dist(N,LINF);
    dist[0] = 0;
    queue<ll> q;
    q.push(0);
    while(q.size()){
        ll n = q.front(); q.pop();
        for(auto e:G[n]){
            if(dist[e.v] > dist[e.u] + e.d){
                dist[e.v] = dist[e.u] + e.d;
                q.push(e.v);
            }
        }
    }
    
    for(int i = 1; i < N;i++){
        ll Min = LINF;
        for(edge e:G[i]){
            if(dist[e.u] == dist[e.v] + e.d) Min = min(Min,e.c);
        }
        res += Min;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    ll N,M;
    while(cin >> N >> M,N|M){
        cout << solve(N,M) << endl;
    }
    return 0;
}
