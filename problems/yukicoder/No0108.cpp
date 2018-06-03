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
 <url:https://yukicoder.me/problems?page=3&sort=no_asc>
 問題文============================================================
 日本語のため省略
 =================================================================
 解説=============================================================
 こういう期待値の問題は苦手なイメージがある。
 
 dp[n3][n2][n1] := あと3枚,2枚,1枚必要とするカードがそれぞれn3,n2,n1枚であるときの確率
 
 としてdpする。
 この時、すでに3枚以上引いているカードを引く期待値は その枚数をkとすれば N/(N-k)となる
 
 またn3,n2,n1であるようなカードを引く確率は 単純に x/(n3+n2+n1) となる (xはn1,n2,n3のいずれか)
 
 ================================================================
 */

typedef long double ld;

ll N;
ld dp[101][101][101];
ld rec(ll n3,ll n2,ll n1,vector<ld>& A){
    if(dp[n3][n2][n1] >= -0.1) return dp[n3][n2][n1];
    ld& res = dp[n3][n2][n1];
    res = 0;
    if(n1+n2+n3 == 0) return res;
    
    res += (double)N/(N-(N-(n1+n2+n3)));
    if(n3) res += (rec(n3-1,n2+1,n1,A)) * n3 / (n3+n2+n1);
    if(n2) res += (rec(n3,n2-1,n1+1,A)) * n2 / (n3+n2+n1);
    if(n1) res += (rec(n3,n2,n1-1,A)) * n1 / (n3+n2+n1);
    return res;
}
ld solve(){
    ld res = 0;
    cin >> N;
    vector<ld> A(N); for(auto& in:A) cin >> in;
    fill(**dp,**dp+101*101*101,-1);
    
    ll n1 = 0, n2 = 0, n3 = 0;
    for(int i = 0; i < N;i++){
        if(A[i] == 0) n3++;
        if(A[i] == 1) n2++;
        if(A[i] == 2) n1++;
    }
    res = rec(n3,n2,n1,A);
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(12) << solve() << endl;
    return 0;
}
