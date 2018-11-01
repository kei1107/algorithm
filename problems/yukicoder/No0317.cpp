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
 <url:https://yukicoder.me/problems/no/317>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 初期状態の連結成分の各個数がわかれば
 あとはそれらの間に辺を1つ追加して頂点数の和の連結成分を作る事ができる
 
 
 これは個数制限付きナップサック問題に帰着できる。
 高速な解法も存在するが間に合いそうだったので簡単な１段階落としたdpを行う
 
 蟻本p301-302
 
 ================================================================
 */

class SCC {
public:
    typedef int TYPE;
    TYPE V;
    vector<vector<TYPE>> G;
    vector<vector<TYPE>> rG;
    vector<vector<TYPE>> group_G;
    vector<vector<TYPE>> group_rG;
    vector<TYPE> group;
    vector<TYPE> List;
    
    vector<int> visited;
    int group_num;
    
    SCC(TYPE V) :V(V),group_num(0) {
        G.resize(V); rG.resize(V);
    }
    
    void init(TYPE V){
        G.clear(); G.resize(V);
        rG.clear(); rG.resize(V);
    }
    
    void add_edge(TYPE u, TYPE v) {
        G[u].emplace_back(v); rG[v].emplace_back(u);
    }
    
    void dfs1(TYPE u) {
        visited[u] = 1;
        for (TYPE& next : G[u]){ if (visited[next] != 1) dfs1(next); }
        List.emplace_back(u);
    }
    
    void dfs2(TYPE u,TYPE group_num) {
        visited[u] = 1; group[u] = group_num;
        for (TYPE& next : rG[u]){ if (visited[next] != 1) dfs2(next, group_num); }
    }
    
    void make_group() {
        group.clear(); group.assign(V, -1);
        visited.clear(); visited.assign(V, 0);
        for (int i = 0; i < V;i++){ if (visited[i] != 1) dfs1(i); }
        
        reverse(List.begin(), List.end());
        
        visited.clear(); visited.assign(V, 0);
        group_num = 0;
        for (TYPE& v : List) { if (visited[v] != 1) dfs2(v, group_num++); }
    }
    
    void make_group_graph(){
        group_G.clear(); group_G.resize(group_num);
        group_rG.clear(); group_rG.resize(group_num);
        for(int u = 0; u < V;u++){
            for(TYPE& v: G[u]){
                if(!same(u,v)){
                    group_G[group[u]].emplace_back(group[v]);
                    group_rG[group[v]].emplace_back(group[u]);
                }
            }
        }
    }
    
    TYPE get_group(TYPE n){ return group[n]; }
    bool same(TYPE u,TYPE v) {
        return group[u] == group[v];
    }
    
    vector<vector<TYPE>>& get_G() { return G; }
    vector<vector<TYPE>>& get_rG() { return rG; }
    vector<vector<TYPE>>& get_group_G() { return group_G; }
    vector<vector<TYPE>>& get_group_rG() { return group_rG; }
};
void solve(){
    int N,M; cin >> N >> M;
    SCC scc(N);
    for(int i = 0; i < M;i++){
        int u,v; cin >> u >> v;
        u--; v--;
        scc.add_edge(u, v);
        scc.add_edge(v, u);
    }
    scc.make_group();
    
    vector<int> cc(scc.group_num);
    for(auto g:scc.group) cc[g]++;
    map<ll,ll> mp;
    for(auto c:cc){
        mp[c]++;
    }
    vector<pll> m;
    for(auto p:mp) m.push_back(p);
    vector<ll> dp(N+1,LINF);
    dp[0] = 0;
    for(const pll& p:m){
        for(int i = N; i >= 0;i--){
            if(dp[i]==LINF) continue;
            for(int j = 1; j <= p.second;j++){
                dp[i+p.first*j] = min(dp[i+p.first*j],dp[i]+j);
            }
        }
    }
    for(int i = 1; i <= N;i++){
        if(dp[i]==LINF) cout << -1 << endl;
        else cout << dp[i]-1 << endl;
    }
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
