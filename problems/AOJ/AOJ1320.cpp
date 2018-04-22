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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1320>
 問題文============================================================
 n個の単語が与えられる。
 この単語全てを部分文字列とするような最小の文字列を求めよ
 =================================================================
 解説=============================================================
 蟻本の練習問題に同様の考え方をする上位問題があった気がする。
 
 まず、ある単語が他の単語を内包するような物があれば、
 内包される単語は考慮する必要が無い為取り除いておく。
 
 その後残った単語に関して
 
 dp[i][j] := 使用した単語の状態がiであり、末尾に単語jが連結されている時の最小長さ
 
 としてbitDPをすればよい
 
 ================================================================
 */

#define MAX_N 14
ll dp[1<<MAX_N][MAX_N];
void init(){
    fill(*dp,*dp + (1<<MAX_N)*MAX_N,LINF);
}

void comp(vector<string>& S){
    ll N = S.size();
    vector<int> f(N,0);
    for(int i = 0; i < N;i++){
        for(int j = 0; j < N;j++){
            if(i == j) continue;
            if(S[j].find(S[i]) != string::npos){
                f[i] = true;
            }
        }
    }
    
    for(ll i = N-1; i >= 0;i--){
        if(f[i]){
            S.erase(S.begin()+i);
        }
    }
}
ll solve(ll N){
    ll res = LINF;
    vector<string> S(N);
    for(auto& in:S) cin >> in;
    comp(S);
    N = S.size();
    vector<vector<ll>> minCost(N,vector<ll>(N,LINF));
    for(int i = 0; i < N;i++){
        for(int j = 0; j < N;j++){
            if(i==j) continue;
            string& s1 = S[i];
            string& s2 = S[j];
            minCost[i][j] = s2.length();
            for(int k = 0; k <s1.length();k++){
                if(s1.substr(k) == s2.substr(0,s1.length()-k)){
                    minCost[i][j] = min(minCost[i][j],(ll)(s2.length() - (s1.length()-k)));
                }
            }
        }
    }
    
    for(int i = 0; i < N;i++) dp[1<<i][i] = S[i].length();
    
    for(int i = 0; i < (1<<N);i++){
        for(int j = 0; j < N;j++){
            if(dp[i][j] == LINF) continue;
            for(int k = 0; k < N;k++){
                if((i>>k)&1) continue;
                dp[i|(1<<k)][k] = min(dp[i|(1<<k)][k],dp[i][j]+minCost[j][k]);
           }
        }
    }
    for(int i = 0; i < N;i++) res = min(res,dp[(1<<N)-1][i]);
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    ll N;
    while(cin>>N,N){
        init();
        cout << solve(N) << endl;
    }
    return 0;
}
