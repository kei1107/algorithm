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
 <url:https://yukicoder.me/problems/no/19>
 問題文============================================================
 Naomiは、とあるアクションゲームをしている。
 
 そのゲームでは、N個(1から番号がふられている）のステージがありそれぞれ難易度が設定されている。
 さらに、それぞれのステージは、先に指定されたステージをクリアしていると難易度が半分になるという仕組みになっている。
 
 選んだステージは必ずクリアできるとし、すべてのステージをクリアすると考える。
 この時、任意の順番でステージを選べるとして、各ステージの難易度の合計が最小になるように、
 ステージを選ぶとしたとき、その難易度の合計を求めてください。
 
 答えは小数になることもあるが、小数第一位まで求めるとして、丸め誤差などの誤差はないように求めてください。
 =================================================================
 解説=============================================================
 
 条件より、強連結部分については、その中で一番小さい値のステージを最初に選択することによって、
 その中でのコストを最小にできる
 
 また、選択の順番については、強連結のグループで区分けされたグラフを作り、親が存在しないグループが
 一回はそのままの難易度で挑まなければならない
 
 よって、まず、強連結成分を求め、強連結成分のグループごとの遷移のグラフを新たに作成
 
 その根（親が存在しないグループとする）のグループにおいてコスト最小となる選択を行い、
 残りのグループについて全て難易度半分としたものが答え

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

double solve(){
    double res = 0;
    int N; cin >> N;
    vector<int> L(N),S(N);
    for(int i = 0; i < N;i++){ cin >> L[i] >> S[i]; S[i]--; }
    
    SCC scc(N);
    for(int i = 0; i < N;i++){ scc.add_edge(S[i], i); }
    scc.make_group();
    scc.make_group_graph();
    auto rG = scc.get_group_rG();
    vector<int> roots;
    for(int i = 0; i < scc.group_num;i++){
        if(rG[i].size()) continue;
        roots.push_back(i);
    }

    vector<int> used(N,0);
    int tmp = 0;
    for(auto root:roots){
        int MinL = INF;
        for(int i = 0; i < N;i++){ if(root == scc.get_group(i)){ MinL = min(MinL,L[i]); } }
        tmp += MinL;
    }
    res = accumulate(L.begin(),L.end(),0)/2.0 + tmp/2.0;
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    cout << fixed << setprecision(1) << solve() << endl;
    return 0;
}
