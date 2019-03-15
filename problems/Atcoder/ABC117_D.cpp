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
 <url:https://atcoder.jp/contests/abc117/tasks/abc117_d>
 問題文============================================================
 =================================================================
 解説=============================================================
 dp[桁数][K以下か] := 最大値
 
 として、桁dpする
 ================================================================
 */


// dp[桁数][K以下か]
ll dp[55][2];
template<class Type>
Type solve(Type res = Type()){
    ll N,K; cin >> N >> K;
    vector<ll> A(N); for(auto& in:A) cin >> in;
    
    string bitK;
    while(K){
        bitK += to_string(K%2);
        K/=2;
    }
    while(bitK.length() < 55) bitK += "0";
    reverse(bitK.begin(),bitK.end());
    int len = (int)bitK.length();
    fill(*dp,*dp+55*2,-1);
    
    ll Sum = 0;
    bool ok = false;
    for(int i = 0; i < len;i++){
        ll Add = 1LL<<(len-1-i);
        for(int j = 0; j < 2;j++){
            if(dp[i][j]==-1) continue;
            int lim = j==1?1:(bitK[i]-'0');
            for(int k = 0; k <= lim;k++){
                ll T = 0;
                for(int l = 0; l < N;l++){
                    ll b = (A[l]>>(len-1-i))&1;
                    if(b^k){
                        T += Add;
                    }
                }
                dp[i+1][j|(k<lim)] = max(dp[i+1][j|(k<lim)],dp[i][j]+T);
            }
        }
        
        // 最上位 1
        ll T = Sum;
        for(int l = 0; l < N;l++){
            ll b = (A[l]>>(len-1-i))&1;
            if(b^1){
                T += Add;
            }else{
                Sum += Add;
            }
        }
        if(ok){
            dp[i+1][1] = max(dp[i+1][1],T);
            continue;
        }
        if(bitK[i]=='1') ok = true;
        if(ok){
            dp[i+1][0] = max(dp[i+1][0],T);
        }
    }
    res = max({Sum,dp[len][0],dp[len][1]});
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
