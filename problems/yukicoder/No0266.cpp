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
 <url:https://yukicoder.me/problems/no/266>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 dp[i][j] := i番目の進化状態で、潜在能力jのカードを作るのに必要な最低カード数
 
 でdp
 
 典型的だね
 ================================================================
 */

vector<ll> solve(){
    vector<ll> ret;
    ll N; cin >> N;
    vector<ll> S(N+1); for(auto& in:S) cin >> in;
    vector<vector<ll>> ness(N+1,vector<ll>(S[N]+1,LINF));
    ness[0][0] = 1; for(int j = 1; j <= S[0];j++) ness[0][j] = min(ness[0][j],ness[0][j-1] + 1);
    for(int i = 1; i <= N;i++){
        for(int j = 0; j <= S[N];j++) ness[i][j] = min(ness[i][j],ness[i-1][j] + 1);
        for(int j = 0; j <= S[i]; j++){
            for(int k = j; k <= S[i];k++){
                ness[i][min(ll(j)+k+1,S[i])] = min(ness[i][min(ll(j)+k+1,S[i])],ness[i][j]+ness[i][k]);
            }
        }
    }
    ret = ness[N];
    return ret;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
