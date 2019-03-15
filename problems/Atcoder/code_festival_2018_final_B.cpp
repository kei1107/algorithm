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
 <url:https://atcoder.jp/contests/code-festival-2018-final-open/tasks/code_festival_2018_final_b>
 問題文============================================================
 =================================================================
 解説=============================================================
 これ300点じゃ無いでしょ。
 
 まず、確率は nCr1*(n-r1Cn-r1-r2)*..../M^N
 だけど、そのまま計算はできないので、対数計算でがんばる
 ================================================================
 */

const ll MAXNM = 1e5+5;
template<class Type>
Type solve(Type res = Type()){
    ll N,M; cin >> N >> M;
    vector<ll> r(M); for(auto& in:r) cin >> in;
    vector<double> factlog(MAXNM);
    factlog[0] = 0;
    for(int i = 1; i < MAXNM;i++){
        factlog[i] = factlog[i-1] + log10(i);
    }
    
    double val = -N*log10(M);
    for(auto& v:r){
        val += factlog[N] - factlog[N-v] - factlog[v];
        N -= v;
    }
    res = abs(floor(val));
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
