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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2222>
 問題文============================================================
 N本の指とM個の屈曲規則がある。
 
 指Aを曲げる時、指Bが同時に曲がる
 
 とした時、指が表現できる形の総数を答えよ
 =================================================================
 解説=============================================================
 
 同時に曲がる指が強連結になっている場合、それらの指は一本の指としてまとめたほうがいい。
 
 強連結成分分解後は、指の曲がる規則は必ずいくつかの指に収束する。
 よって、その収束する指から逆に規則を辿っていき、パターンの総数を数えればよい
 
 ================================================================
 */

const ll MOD = 1e9+7;

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

ll dfs(ll n,vector<vector<int>>& G){
    ll ret = 1;
    for(int i = 0; i < G[n].size();i++){
        (ret *= dfs(G[n][i],G))%=MOD;
    }
    return (ret+1)%MOD;
}
ll solve(){
    ll res = 1;
    int N,M; cin >> N >> M;
    SCC scc(N);
    vector<int> S(M),D(M);
    for(int i = 0; i < M;i++){
        cin >> S[i] >> D[i];
        S[i]--; D[i]--;
        scc.add_edge(S[i], D[i]);
    }
    scc.make_group();
    scc.make_group_graph();
    auto G = scc.get_group_G();
    auto rG = scc.get_group_rG();
    int num = scc.group_num;
    
    for(int i = 0; i < num; i++){
        if(G[i].size() == 0) (res *= dfs(i,rG))%=MOD;
    }

    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
