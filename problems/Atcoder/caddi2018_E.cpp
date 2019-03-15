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
 <url:https://atcoder.jp/contests/caddi2018/tasks/caddi2018_c>
 問題文============================================================
 =================================================================
 解説=============================================================
 解説AC -> https://img.atcoder.jp/caddi2018/editorial.pdf
 ================================================================
 */


vector<vector<ll>> calc(vector<ll>& A){
    vector<vector<ll>> dp(A.size()+1,vector<ll>(16));
    ll N = A.size();
    for(ll i = N-2; i >= 0;i--){
        for(ll j = 0; j <= 15;j++){
            ll add = LLONG_MAX;
            
            ll nowA = A[i] * (1LL << (2*j)); // 4^jを乗じた値
            if(nowA <= A[i+1]){
                add = dp[i+1][0]; // 操作の必要がない
            }else{
                // 何回操作したら超えるか
                ll cnt = 0;
                ll mul = (A[i+1] + nowA-1)/A[i+1];
                while(!(mul <= 1LL<<(cnt*2))) cnt++;
                if(cnt > 15){
                    ll diff = cnt - 15;
                    add = (N-1-i)*2*diff + 15*2 + dp[i+1][15];
                }else{
                    add = cnt*2 + dp[i+1][cnt];
                }
            }
            
            dp[i][j] = add;
        }
    }
    return dp;
}
template<class Type>
Type solve(Type res = Type()){
    int N; cin >> N;
    vector<ll> A(N);for(auto& in:A) cin >> in;
    auto dp1 = calc(A); // pos
    reverse(A.begin(),A.end());
    auto dp2 = calc(A); // neg
    
    res = min(dp1[0][0],dp2[0][0]+N);
    for(ll i = 1; i < N;i++){
        res = min(res,dp1[i][0] + dp2[N-i-1][0] + i);
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
