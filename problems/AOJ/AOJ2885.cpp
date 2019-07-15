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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2885&lang=jp>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 図を色々書いてみると、分割が２部グラフでしか成り立たないことがわかる。
 よって、２部グラフ判定する。
 
 答えは、２部グラフになるようであれば、各グループに属する頂点数/2が候補
 ================================================================
 */

/*
 
 二部グラフ判定
 
 build : falseならば二部グラフではない
 make : 色1となる頂点をlvへ、色-1となる頂点をrvへ格納
 
 */
class BipartiteGraph{
public:
    vector<vector<ll>> G; // グラフ
    ll N; // 頂点数
    vector<int> color; // 頂点iの色(1 or -1);
    
    vector<ll> lv,rv;
    BipartiteGraph(int _N):N(_N){ G.resize(N); color.resize(N,0); }
    BipartiteGraph(ll _N):N(_N){ G.resize(N); color.resize(N,0); }
    
    void init(ll _N){
        N = _N;
        G.clear(); color.clear();
        G.resize(N); color.resize(N,0);
    }
    
    void add_edge(ll u,ll v){
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    bool dfs(ll v,int c){
        color[v] = c; // 頂点vをcで塗る
        for(int i = 0; i < G[v].size(); i++){
            // 隣接している頂点が同じ色ならfalse
            if(color[G[v][i]] == c) return false;
            // 隣接している頂点がまだ塗られていないなら-cで塗る
            if(color[G[v][i]] == 0 && !dfs(G[v][i],-c)) return false;
        }
        // すべての頂点を濡れたらtrue
        return true;
    }
    
    bool build(){
        for(int i = 0; i < N;i++){
            if(color[i] == 0){
                // まだ頂点iが塗られていなければ1で塗る
                if(!dfs(i,1)) return false;
            }
        }
        return true;
    }
    
    void make(){
        for(int i = 0; i < N;i++){
            if(color[i] == 1) lv.push_back(i);
            if(color[i] == -1) rv.push_back(i);
        }
    }
};

ll N,M;
template<class Type>
Type solve(Type res = Type()){
    while(cin >> N >> M,N){
        BipartiteGraph BG(N);
        for(int i = 0; i < M;i++){
            ll u,v; cin >> u >> v;
            u--; v--;
            BG.add_edge(u, v);
        }
        
        bool ok = BG.build();
        if(!ok){
            cout << 0 << endl;
        }else{
            vector<ll> ans;
            BG.make();
            if(BG.lv.size()%2 == 0) ans.push_back(BG.lv.size()/2);
            if(BG.rv.size()%2 == 0) ans.push_back(BG.rv.size()/2);
            sort(ans.begin(),ans.end());
            ans.erase(unique(ans.begin(),ans.end()),ans.end());
            cout << ans.size() << endl;
            for(auto v:ans){
                cout << v << endl;
            }
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve(0);
    // cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
