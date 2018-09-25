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
 <url:https://yukicoder.me/problems/no/186>
 問題文============================================================
 =================================================================
 解説=============================================================
 ref: https://qiita.com/drken/items/ae02240cd1f8edfc86fd
 ================================================================
 */

inline ll mod(ll a,ll m){ return (a%m + m)%m;}
/* 拡張ユークリッドの互除法 extgcd */
ll extgcd(ll a, ll b, ll& x, ll& y){
    ll g = a; x = 1; y = 0;
    if(b!=0) { g = extgcd(b, a%b, y, x); y -= (a/b)*x;}
    return g;
}

/*
 中国剰余定理 (Chinese Remainder Theorem)
 x ≡ b1 (mod. m1)
 x ≡ b2 (mod. m2)
 ...
 x ≡ bk (mod. mk)
 を満たす x ≡ r (mod. lcm(m1,m2,...,mk)) を求める
 
 答えを x ≡ r (mod. M) として、{r, M} をリターン, 存在しない場合は {0, -1} をリターン
*/
pll CRT(const vector<ll>& b,const vector<ll>& m){
    ll r = 0, M = 1;
    for(int i = 0; i < (int)b.size();i++){
        ll p,q;
        ll d = extgcd(M,m[i],p,q);
        if((b[i]-r)%d != 0) return make_pair(0,-1);
        ll tmp = (b[i]-r)/d*p%(m[i]/d);
        r += M*tmp;
        M *= m[i]/d;
    }
    return make_pair(mod(r,M), M);
}

ll solve(){
    vector<ll> b(3),m(3);
    for(int i = 0; i < 3;i++) cin >> b[i] >> m[i];
    pll res = CRT(b,m);
    if(res.second == -1) return -1;
    if(count(b.begin(),b.end(),0)==3) return res.second; // lcm(m1,m2,m3)
    return res.first;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
