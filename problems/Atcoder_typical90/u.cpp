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
 <url:https://atcoder.jp/contests/typical90/tasks/typical90_u>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */

/*
 SCC:強連結成分分解
 有向グラフにおいて「お互いに行き来できる ⟺ 同じグループ」を満たすように頂点をグループ分け
 */
class SCC {
public:
    typedef int TYPE;
    TYPE V;
private:    
    vector<vector<TYPE>> G;             // 入力グラフ
    vector<vector<TYPE>> rG;            // 入力の逆辺グラフ
    vector<vector<TYPE>> group_G;       // 強連結成分同士の有向辺グラフ
    vector<vector<TYPE>> group_rG;      // 強連結成分同士の無向辺グラフ
    vector<vector<TYPE>> each_group_G;  // 各強連結成分内のグラフ（トポロジカル順）
    vector<TYPE> group;                 // 各頂点の強連結成分グループ番号
    vector<TYPE> List;
public:    
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
        each_group_G.back().emplace_back(u);
        for (TYPE& next : rG[u]){ if (visited[next] != 1) dfs2(next, group_num); }
    }
    
    void scc() {
        group.clear(); group.assign(V, -1);
        visited.clear(); visited.assign(V, 0);
        for (int i = 0; i < V;i++){ if (visited[i] != 1) dfs1(i); }
        
        reverse(List.begin(), List.end());
        
        visited.clear(); visited.assign(V, 0);
        group_num = 0;
        for (TYPE& v : List) { 
            if (visited[v] != 1){
                each_group_G.emplace_back(vector<TYPE>());
                dfs2(v, group_num++); 
            }
        }

        make_group_graph();
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
    vector<vector<TYPE>>& get_each_group_G() { return each_group_G; }
};

template<class Type>
Type solve(Type res = Type()){
    int N,M; cin >> N >> M;
    SCC scc(N);
    for(int i = 0; i < M;i++){
        int a,b; cin >> a >> b;
        a--; b--;
        scc.add_edge(a,b);
    }
    scc.scc();
    auto G = scc.get_each_group_G();

    for(auto g:G) res += (ll)g.size() * (g.size() - 1)/2;
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    //solve<ll>(0);
    cout << fixed << setprecision(12) << solve<ll>() << endl;
    return 0;
}