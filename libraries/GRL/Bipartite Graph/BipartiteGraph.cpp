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

