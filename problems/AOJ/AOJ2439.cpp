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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2439&lang=jp>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 dp[i][j][k] := i番目を見た時、今までで割り当てられず余っているチーム数j,今までで割り当てることができる順位数kでの場合の数
 
 としてdp
 
 詳細な遷移は < http://mayokoex.hatenablog.com/entry/2016/09/01/184646 >
 に詳しく書いてある
 ================================================================
 */
const ll MOD = 1e9+7;
ll solve(){
    ll res = 0;
    ll n; cin >> n;
    vector<char> c;
    for(int i = 0; i < n;i++){
        char tmp; cin >> tmp;
        if(tmp != '-') c.push_back(tmp);
    }
    ll sz = c.size();
    using VLL = vector<ll>;
    using VVLL = vector<VLL>;
    using VVVLL = vector<VVLL>;
    VVVLL dp(sz+1,VVLL(sz+1,VLL(sz+1,0)));
    dp[0][0][0] = 1;
    for(int i = 0; i < sz;i++){
        for(int j = 0; j <= i;j++){
            for(int k = 0; k <= i;k++){
                if(dp[i][j][k] == 0) continue;
                if(c[i] == 'U'){
                    (dp[i+1][j+1][k+1] += dp[i][j][k])%=MOD; // 割り当てを決めない
                    (dp[i+1][j][k] += dp[i][j][k]*k)%=MOD; // 今まで割り当てられていない人に割り当てる
                }else{
                    (dp[i+1][j][k] += dp[i][j][k]*j)%=MOD; // 今まで未割り当ての人を割り当てる
                    if(j > 0 && k > 0){ // i番目と今まで割り当てられていない人を同時に決める
                        (dp[i+1][j-1][k-1] += dp[i][j][k]*j*k)%=MOD;
                    }
                }
            }
        }
    }
    res = dp[sz][0][0];
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
