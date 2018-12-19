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
 <url:https://atcoder.jp/contests/code-festival-2014-relay/tasks/code_festival_relay_h>
 問題文============================================================
 =================================================================
 解説=============================================================
 座圧と尺取りの容量
 [l,r)の区間を横にスライドさせていくイメージで実装すれば解ける
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    ll n,m; cin >> n >> m;
    vector<ll> a(m); for(auto& in:a) cin >> in;
    vector<ll> xa = a;
    sort(xa.begin(),xa.end());
    xa.erase(unique(xa.begin(),xa.end()),xa.end());
    xa.push_back(LINF);
    map<ll,ll> mp; for(auto v:a) mp[v]++;
    
    ll l = 0, r = 0;
    ll cnt = 0;
    for(; l < xa.size()-1; l++){
        while(xa[r] - xa[l] <= n) { cnt += mp[xa[r]]; r++; }
        res = max(res,cnt);
        cnt -= mp[xa[l]];
    }
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    //solve<ll>();
    cout << fixed << setprecision(12) << solve<ll>() << endl;
    return 0;
}
