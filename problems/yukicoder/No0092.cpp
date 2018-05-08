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
 <url:https://yukicoder.me/problems/no/92>
 問題文============================================================
 Yuki City は N 個の町と M 本の道路からなる。
 町は 1 から N まで番号が振られている。
 道路は双方向に通行でき、それぞれ通行料金が設定されている。
 
 さて、Yuki City 警察のあなたはある指名手配犯を追っている。
 長らく犯人の居場所を掴めなかったあなただが、つい先日有力な情報を手に入れた。
 その情報とは、犯人が支払った通行料金のうち、直近 K 回分を時系列順に並べたものである。
 あなたはこの情報を使い、犯人が今いる可能性のある町を絞り込みたい。
 
 警察官であると同時に天才プログラマーでもあるあなたは、プログラムによってこの問題を解こうと考えた。
 =================================================================
 解説=============================================================
 
 dp[i][j] := i番目の頂点から1~(K-j)番目までのコストを満たす道順が存在するかどうか
 
 として、メモ化再帰
 ================================================================
 */

ll N,M,K;
bool rec(ll n,ll dep,vector<ll>& d,vector<vector<pll>>& G,vector<vector<int>>& dp){
    if(~dp[n][dep]) return dp[n][dep];
    int& ret = dp[n][dep];
    ret = false;
    if(dep == K) return ret = true;
    for(const pll& p:G[n]){
        if(p.second == d[dep]){
            ret |= rec(p.first,dep+1,d,G,dp);
        }
    }
    return ret;
}
void solve(){
    cin >> N >> M >> K;
    vector<ll> a(M),b(M),c(M);
    for(int i = 0; i < M;i++) cin >> a[i] >> b[i] >> c[i];
    vector<ll> d(K);
    for(int i = 0; i < K;i++) cin >> d[i];
    
    vector<vector<pll>> G(N);
    for(int i = 0; i < M;i++){
        a[i]--; b[i]--;
        G[a[i]].push_back({b[i],c[i]});
        G[b[i]].push_back({a[i],c[i]});
    }
    reverse(d.begin(),d.end());
    vector<vector<int>> dp(N,vector<int>(K+1,-1));

    vector<ll> ans;
    for(int i = 0; i < N;i++){
        if(rec(i,0,d,G,dp)) ans.push_back(i+1);
    }
    cout << ans.size() << endl;
    cout << ans << endl;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
