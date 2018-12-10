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
 <url:https://yukicoder.me/problems/no/403>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 (A^B)^C は普通に計算
 
 A^(B^C) はフェルマーの小定理から指数部分をMOD-1で割ったあまりにしてやればいい
 ただし、この時AがMODで割り切れる場合 答えは 0だが 0^0となり 1と出てしまうときがあるので
 例外処理が必要
 ================================================================
 */

const ll MOD = 1e9+7;
ll powmod(ll a,ll b,ll MOD) {ll res=1;a%=MOD;for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
vector<ll> solve(){
    vector<ll> res;
    ll A,B,C; char c;
    cin >> A >> c >> B >> c >> C;
    if(A%MOD==0) return vector<ll>{0,0};
    res.push_back(powmod(powmod(A,B,MOD),C,MOD));
    res.push_back(powmod(A,powmod(B,C,MOD-1),MOD));
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
