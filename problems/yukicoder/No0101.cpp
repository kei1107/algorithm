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
 <url:https://yukicoder.me/problems/no/101>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 あみだくじは置換で表すことができる。
 
 置換のあるループに注目すると、そのループの長さがxであれば、
 x個のあみだくじを繋げれば、そのループは最初のループと一致する。
 
 よって、すべてのループについて、その長さの最小公倍数と取れば、それが求める答えである
 
 ================================================================
 */

inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }
ll solve(){
    ll res = 1;
    ll N; cin >> N;
    ll K; cin >> K;
    vector<ll> X(K),Y(K);
    for(int i = 0; i < K;i++) cin >> X[i] >> Y[i];
    vector<ll> amida(N+1); iota(amida.begin(),amida.end(),0);
    for(int i = 0; i < K;i++) swap(amida[X[i]],amida[Y[i]]);
    vector<ll> f(N+1,1);
    for(int i = 1; i <= N;i++){
        if(f[i] == 0) continue;
        ll cnt = 0;
        ll n = i;
        while(f[n]){
            f[n] = 0;
            cnt++;
            n = amida[n];
        }
        res = lcm(res,cnt);
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
