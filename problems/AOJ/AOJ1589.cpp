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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1589>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 コマを月曜日から金曜日まで
 0 - 5N の連続したコマとしてみる
 dp[i][j] := i番目のコマを見た時、これまで受けた授業がj個のときの最大幸福度
 
 でdp
 ================================================================
 */

ll solve(){
    ll res = 0;
    int N,M,L; cin >> N >> M >> L;
    vector<int> d(M),a(M),k(M),t(M);
    for(int i = 0; i < M;i++) cin >> d[i] >> a[i] >> k[i] >> t[i];
    vector<vector<pll>> event(5*N+1);
    for(int i = 0; i < M;i++){
        event[d[i]*N+a[i]].push_back(make_pair(k[i],t[i]));
    }
    vector<vector<ll>> dp(5*N+2,vector<ll>(L+1,0));
    for(int i = 0; i <= 5*N;i++){
        for(int j = 0; j <= L;j++){
            dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
            if(j == L) continue;
            for(auto e:event[i]){
                dp[i+e.first][j+1] = max(dp[i+e.first][j+1],dp[i][j]+e.second);
            }
        }
    }
    res = *max_element(dp[5*N+1].begin(), dp[5*N+1].end());
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
