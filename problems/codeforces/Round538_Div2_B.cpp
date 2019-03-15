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
 <url:https://codeforces.com/contest/1087/problem/B>
 問題文============================================================
 (x/k)*(x mod k) = n となる最小のxを求めよ
 =================================================================
 解説=============================================================
 x=a*k+bとすると a*b=nとなるから
 　 a*b=nとなるa,bを全探索して最小のxを探す
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    ll n,k; cin >> n >> k;
    res = LINF;
    for(ll a = 1; a <= n; a++){
        if(n%a!=0) continue;
        ll b = n/a;
        ll x = a*k+b;
        if(x/k*(x%k)==n){
            res = min(res,x);
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    //solve<ll>(0);
    cout << fixed << setprecision(12) << solve<ll>() << endl;
    return 0;
}
