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
 <url:https://beta.atcoder.jp/contests/maximum-cup-2018/tasks/maximum_cup_2018_e>
 問題文============================================================
 数列S={1} が渡されます。以下の2種類のクエリを合計q回実行してください。
 
 A,i,j ：　S[k] = iを満たすいずれか一つのkに対して、
 「S[k]を取り除き、その位置に数列　V=i,j,i を挿入する」という操作を行う。
 
 B,i,j ： 今までのクエリでできる可能性のある数列すべてに対して、
 「S[a] = i,S[b] = j を満たし、 |a − b| が最小になるときのa,bに対し、
 {S[k]|(min(a,b) < k < max(a,b))} に含まれる数の種類」を求めてから、
 その中で最も小さい数を出力する。

 =================================================================
 解説=============================================================
 
 最適な状態を考えると、
 次のような問題の言い換えができる
 
 A,i,j := 頂点iからjへ辺を引く
 B,i,j := 頂点iからjへの間のパスの数-1を出力する。
 
 これは、制約より、問題の最終結果が必ず木になる、ということから
 先にクエリAを処理したのちにクエリBについてLCAを用いて求めることができる
 ================================================================
 */

class LCA{
public:
    ll V; // 頂点数
    vector<vector<ll>> T; // Tree
    vector<pll> ET; // Euler Tour ET(dep, n)
    vector<int> visited;
    vector<ll> Ind; // 各頂点に対応するETのindexを保持
    
    ll N; // SegTreeの要素数
    vector<pll> node; // SegTree
    
    LCA(ll V):V(V){
        T.resize(V); Ind.resize(V);
    }
    
    void add_edge(ll u,ll v){
        T[u].emplace_back(v);
        T[v].emplace_back(u);
    }
    
    void fit(ll root){
        visited.clear(); visited.assign(V,0);
        dfs(root,0);
        ll N_ = ET.size();
        N = 1;
        while(N < N_) N*=2;
        node.clear(); node.assign(2*N - 1,make_pair(INF,INF));
        for(int i = 0; i < N_;i++) node[N-1+i] = ET[i];
        for(ll k = N - 2; k>=0;k--) node[k] = min(node[2*k+1],node[2*k+2]);
    }
    
    void dfs(ll n,ll dep){
        visited[n] = 1;
        ET.emplace_back(make_pair(dep, n));
        Ind[n] = (int)ET.size() - 1;
        for(auto next:T[n]){
            if(visited[next] == 1)continue;
            dfs(next,dep +1);
            ET.emplace_back(make_pair(dep,n));
        }
    }
    
    
    pll RMQ(ll a,ll b){ return RMQ(a,b,0,0,N); }
    pll RMQ(ll a,ll b,ll k,ll l, ll r){
        if(r <= a || b <= l)return make_pair(INF,INF);
        if(a <= l && r <= b)return node[k];
        auto vl = RMQ(a,b,2*k+1,l,(l+r)/2);
        auto vr = RMQ(a,b,2*k+2,(l+r)/2,r);
        return min(vl,vr);
    }
    
    ll query(ll s,ll t){
        ll idx1 = Ind[s],idx2 = Ind[t];
        if(idx1 > idx2) swap(idx1,idx2);
        
        return RMQ(idx1,idx2+1).second;
    }
};
#define MAX_Q 200001
void solve(){
    
    LCA lca(MAX_Q);
    vector<ll> dep(MAX_Q,LINF); dep[1] = 1;
    ll q; cin >> q;
    
    vector<pll> query;
    while(q--){
        char c; ll i,j; cin >> c >> i >> j;
        if(c == 'A'){
            lca.add_edge(i, j);
            dep[j] = dep[i]+1;
        }
        if(c == 'B'){
            query.push_back({i,j});
        }
    }
    lca.fit(1);
    for(auto p:query){
        ll i,j; tie(i,j) = p;
        ll _lca = lca.query(i,j);
        cout << (dep[i] + dep[j] - 2*dep[_lca] - 1) << endl;
    }
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
