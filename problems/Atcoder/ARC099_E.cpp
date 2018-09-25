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
 <url:https://beta.atcoder.jp/contests/arc099/tasks/arc099_c>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 グラフを二つの完全グラフに分けるとは
 補グラフに置いて、二部グラフとできることと同意
 
 よって、補グラフでにぶグラフになるかどうかで不可能の判定ができる
 
 二部グラフにできるのであれば、孤立したにぶグラフ群をどう合わせるかになるが、
 これはdpで全通り試すことができる
 
 ================================================================
 */

class BipartiteGraph{
public:
    vector<vector<ll>> G; // グラフ
    ll N; // 頂点数
    vector<int> color;
    
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
        int c = 1;
        for(int i = 0; i < N;i++){
            if(color[i] == 0){
                // まだ頂点iが塗られていなければ1で塗る
                if(!dfs(i,c++)) return false;
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
ll solve(){
    ll res = LINF;
    int N,M; cin >> N >> M;
    vector<int> A(M),B(M); for(int i = 0; i < M;i++) cin >> A[i] >> B[i];
    
    vector<vector<int>> G(N,vector<int>(N,0));
    for(int i = 0; i < M;i++){
        A[i]--; B[i]--;
        G[A[i]][B[i]] = G[B[i]][A[i]] = 1;
    }
    
    BipartiteGraph BG(N);
    for(int i = 0; i < N;i++){
        for(int j = i+1;j < N;j++){
            if(G[i][j])continue;
            BG.add_edge(i, j);
        }
    }
    if(!BG.build()) return -1;
    auto color = BG.color;
    ll group_num = *max_element(color.begin(), color.end());
    vector<ll> S(group_num),T(group_num);
    for(auto c:color){
        if(c > 0){
            S[c-1]++;
        }else{
            T[abs(c)-1]++;
        }
    }
    vector<vector<int>> dp(group_num+1,vector<int>(N+1,0));
    dp[0][0] = true;
    for(int i = 0; i < group_num;i++){
        for(int j = 0; j <= N;j++){
            if(!dp[i][j]) continue;
            dp[i+1][j+S[i]] = true;
            dp[i+1][j+T[i]] = true;
        }
    }
    
    for(int i = 0; i <= N;i++){
        if(dp[group_num][i]){
            ll n1 = i,n2 = N - i;
            res = min(res,n1*(n1-1)/2 + n2*(n2-1)/2);
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
