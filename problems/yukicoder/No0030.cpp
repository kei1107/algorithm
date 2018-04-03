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
 <url:https://yukicoder.me/problems/no/30>
 問題文============================================================
 太郎君はとある工場を建てようとしています。
 効率よく生産するためには、材料を計画的に購入しなければなりません。
 この工場では、最終的に製造したい製品を 製品番号N とし、
 製品番号1 ～ N−1 の中間素材となる製品を取り扱います。
 
 製品番号1 ～ N−1 の製品は、外部から購入するか、
 またはこの工場で製造するかのどちらかにより手に入るものとします。
 また、最終製品Nも含め製造することが出来る製品は、外部から購入せずに必ず製造するものとします。
 
 入力に、各製品番号(1～N)の製造方法（材料の製品番号・個数と、その材料から1個製造できる製品番号）
 が与えられるので、最終製品Nを1個作るために、外部から購入する必要のある最小の個数を
 1～N−1番の 製品番号ごとにそれぞれ1行で出力してください。
 
 製品iの製造方法が複数書かれている場合は、それらすべての材料が必要です。
 製品Nを製造するための製造方法は必ず与えられます。
 
 1 行目に、製品の種類数を表す整数 N (2≤N≤100) が与えられる。
 2行目に、製造方法の数を表す整数 M (1≤M≤1500) が与えられる。
 続くM行に、製造方法を表す3つの整数、材料の製品番号Pi、材料の個数Qi、製造する製品番号Riがスペース区切りで与えられる。
 1≤Pi<N、1≤Qi≤100、1≤Ri≤N
 
 1≤i≤M、i≠j ならば (Pi,Ri)≠(Pj,Rj)
 すべてのRiについて、
 Riの材料(および材料の材料、…)としてRi自身を必要とすることはありません。

 =================================================================
 解説=============================================================
 
 dp[i] := i番目の製品を必要とする個数としてメモ化再帰
 
 ================================================================
 */

struct edge{
    ll u,v,cost;
    edge(){}
    edge(ll u,ll v,ll c):u(u),v(v),cost(c){}
};

ll dfs(ll n,vector<ll>& dp,vector<vector<edge>>&G){
    ll& res = dp[n];
    if(~res) return res;
    res = 0;
    for(edge& e:G[n]){
        res += e.cost * dfs(e.v,dp,G);
    }
    return res;
}

void solve(){
    ll N,M; cin >> N >> M;
    vector<ll> P(M),Q(M),R(M);
    for(int i = 0; i < M;i++) cin >> P[i] >> Q[i] >> R[i];
    
    vector<vector<edge>> G(N);
    vector<int> roots(N,true);
    for(int i = 0; i < M;i++){
        P[i]--; R[i]--;
        G[P[i]].push_back(edge(P[i],R[i],Q[i]));
        roots[R[i]] = false;
    }
    
    vector<ll> dp(N,-1);
    dp[N-1] = 1;
    for(int i = 0; i < N-1;i++){
        if(roots[i]) dfs(i,dp,G);
    }
    
    for(int i = 0; i < N-1;i++){
        if(roots[i]) cout << dp[i] << endl;
        else cout << 0 << endl;
    }
    
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
