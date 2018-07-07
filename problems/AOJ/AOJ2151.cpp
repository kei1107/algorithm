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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2151>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 頂点と消費予算を持った拡張ダイクストラをとく
 ================================================================
 */

int N,M,L;
struct edge{
    ll to,cost,num;
    edge(){};
    edge(ll a,ll b,ll c):to(a),cost(b),num(c){};
};
ll solve(){
    ll res = 0;
    vector<vector<edge>> G(N);
    for(int i = 0; i < M;i++){
        ll u,v,cost,num; cin >> u >> v >> cost >> num;
        u--; v--;
        G[u].emplace_back(v,cost,num);
        G[v].emplace_back(u,cost,num);
    }
    vector<vector<ll>> dist(N,vector<ll>(L+1,LINF));
    dist[0][0] = 0;
    queue<pll> q; q.push({0,0});
    while(q.size()){
        ll n,len; tie(n,len) = q.front(); q.pop();
        for(auto& e:G[n]){
            if(dist[e.to][len] > dist[n][len] + e.num){
                dist[e.to][len] = dist[n][len] + e.num;
                q.push({e.to,len});
            }
            if(len + e.cost > L) continue;
            if(dist[e.to][len+e.cost] > dist[n][len]){
                dist[e.to][len+e.cost] = dist[n][len];
                q.push({e.to,len+e.cost});
            }
        }
    }
    res = *min_element(dist[N-1].begin(), dist[N-1].end());
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    while(cin >> N >> M >> L,N|M|L){
        cout << solve() << endl;
    }
    return 0;
}
