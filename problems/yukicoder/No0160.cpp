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
 <url:https://yukicoder.me/problems/no/160>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 経路復元をする。
 
 Gからの最短距離を求めて、Sから順番に決めていけば良い
 ================================================================
 */

struct edge{
    ll u,v,cost;
    edge(ll u = 0,ll v = 0,ll cost = 0):u(u),v(v),cost(cost){}
};

vector<ll> solve(){
    vector<ll> res;
    ll N,M,S,G; cin >> N >> M >> S >> G;
    vector<vector<edge>> g(N);
    for(int i = 0; i < M;i++){
        ll u,v,cost; cin >> u >> v >> cost;
        g[u].push_back(edge(u,v,cost));
        g[v].push_back(edge(v,u,cost));
    }
    for(int i = 0; i < N;i++){
        sort(g[i].begin(),g[i].end(),[](const edge& e1,const edge& e2){return e1.v < e2.v;});
    }
    vector<ll> dists(N,INF);
    dists[S] = 0;
    {
        queue<ll> q; q.push(S);
        while(q.size()){
            ll n = q.front(); q.pop();
            for(auto e:g[n]){
                if(dists[e.v] > dists[e.u] + e.cost){
                    dists[e.v] = dists[e.u] + e.cost;
                    q.push(e.v);
                }
            }
        }
    }
    vector<ll> distg(N,INF);
    distg[G] = 0;
    {
        queue<ll> q; q.push(G);
        while(q.size()){
            ll n = q.front(); q.pop();
            for(auto e:g[n]){
                if(distg[e.v] > distg[e.u] + e.cost){
                    distg[e.v] = distg[e.u] + e.cost;
                    q.push(e.v);
                }
            }
        }
    }

    res.push_back(S);
    ll now = S;
    while(now != G){
        for(auto e:g[now]){
            if(distg[e.u] == distg[e.v] + e.cost){
                res.push_back(e.v);
                now = e.v;
                break;
            }
        }
    }
    
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
