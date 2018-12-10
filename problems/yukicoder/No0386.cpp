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
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

/*
 <url:https://yukicoder.me/problems/no/386>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 コストはLCAを用いて簡単にもとまるので
 クエリごとに落ち着いて処理すればいい
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
ll solve(){
    ll res = 0;
    int N; cin >> N;
    LCA lca(N);
    for(int i = 0; i < N-1;i++){
        int A,B; cin >> A >> B;
        lca.add_edge(A, B);
    }
    vector<ll> U(N); for(auto &in:U) cin >> in;
    
    vector<ll> dist(N,INF);
    lca.fit(0);
    dist[0] = U[0];
    queue<int> q; q.push(0);
    while(q.size()){
        int n = q.front(); q.pop();
        for(auto next:lca.T[n]){
            if(dist[next] > dist[n] + U[next]){
                dist[next] = dist[n] + U[next];
                q.push(next);
            }
        }
    }
    
    int M; cin >> M;
    while(M--){
        int A,B,C; cin >> A >> B >> C;
        ll cost = (dist[A] + dist[B] - 2*dist[lca.query(A, B)] + U[lca.query(A, B)]);
        res += cost*C;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
