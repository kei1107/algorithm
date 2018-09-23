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
 <url:https://beta.atcoder.jp/contests/code-festival-2018-quala/tasks/code_festival_2018_quala_c>
 問題文============================================================
 =================================================================
 解説=============================================================
 各数字は64bit以下の数字なので、
 高々64*N回の操作で数列に0が存在するか操作回数がKと一致していれば数列が確定する
 よって
 dp[i][j]][k]
    :=i番目の数字を見た時j回操作を行っておりこれまでで0になった要素があるかどうか(k)の場合の数の総数
 みたいなdpすればO(N*min(K,N*64)*2*64)で解ける
 ================================================================
 */

const ll MOD = 1e9+7;
ll solve(){
    ll res = 0;
    ll N,K; cin >> N >> K;
    vector<ll> A(N); for(auto& in:A) cin >> in;
    sort(A.begin(),A.end());
    vector<ll> cnt(N);
    for(int i = 0; i < N;i++){
        ll a =  A[i];
        while(a!=0){
            cnt[i]++;
            a/=2;
        }
    }
 //   cout << cnt << endl;
    ll sum = accumulate(cnt.begin(),cnt.end(),0LL);
    // dp[i][j][k] := i番目の数字を見たときj個の操作を行い、これまで0になったものの個数
    ll dp[55][64*55][2] = { 0 };
    dp[0][0][A[0]==0] = 1;

    for(int i = 0; i < N;i++){
        for(int j = 0; j <= min(K,sum);j++){
            for(int k = 0; k < 2;k++){
                if(dp[i][j][k] == 0) continue;
                for(int l = 0; l <= cnt[i]; l++){ // 操作回数
                    (dp[i+1][j+l][k|(l==cnt[i])] += dp[i][j][k])%=MOD;
                }
            }
        }
    }

    for(int j = 0; j <= min(K,sum);j++){
        (res += dp[N][j][1])%=MOD;
    }
    if(K <= sum){
        (res += dp[N][K][0])%=MOD;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
