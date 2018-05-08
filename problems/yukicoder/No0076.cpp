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
 <url:https://yukicoder.me/problems/no/76>
 問題文============================================================
 サイコロXは 6 つの面を持っていてそれぞれの面には 1 から 6 までの整数が書かれています。
 出目の和が N 以上となるまでサイコロXを振り続けます。
 何回振ることになるか、期待値を求めるプログラムを書いてください。
 何回か振った時のサイコロの出目は独立であると仮定してください。
 （サイコロの各面が出る確率は等しいとは限りません）
 =================================================================
 解説=============================================================
 
 解説を見た。
 
 いや、無理
 
 http://kmjp.hatenablog.jp/entry/2015/07/20/1000
 ================================================================
 */

void solve(){
    int T; cin >> T;
    vector<int> N(T); for(auto& in:N) cin >> in;
    vector<double> dp(int(1e6+10));
    double S[7];
    S[1]=1.0/12; S[2]=2.0/12; S[3]=3.0/12; S[4]=1.0/12; S[5]=3.0/12; S[6]=2.0/12;
    for(int i=1;i<=int(1e6+10);i++) {
        dp[i+10]=1+(dp[i+10-1]*S[1]+dp[i+10-2]*S[2]+dp[i+10-3]*S[3]+dp[i+10-4]*S[4]+dp[i+10-5]*S[5]+dp[i+10-6]*S[6]);
    }
    for(int i = 0; i < T;i++){
        cout << fixed << setprecision(12) << dp[N[i]+10] << endl;
    }
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
