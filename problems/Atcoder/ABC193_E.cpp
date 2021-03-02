#include "bits/stdc++.h"
#include "atcoder/all"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T>& V){ for(size_t i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> >& Mat){ for(size_t i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T>& mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }
template<typename T>vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}
/*
 <url:https://atcoder.jp/contests/abc193/tasks/abc193_e>
 問題文============================================================
 E - Oversleeping 
 =================================================================
 解説=============================================================
 ================================================================
 */

/*
 中国剰余定理 (Chinese Remainder Theorem)
 x ≡ b1 (mod. m1)
 x ≡ b2 (mod. m2)
 ...
 x ≡ bk (mod. mk)
 を満たす x ≡ r (mod. lcm(m1,m2,...,mk)) を求める
 
 答えを x ≡ r (mod. M) として、{r, M} をリターン, 存在しない場合は {0, -1} をリターン
 */
inline ll mod(ll a,ll m){ return (a%m + m)%m;}
/* 拡張ユークリッドの互除法 extgcd */
ll extgcd(ll a, ll b, ll& x, ll& y){
    ll g = a; x = 1; y = 0;
    if(b!=0) { g = extgcd(b, a%b, y, x); y -= (a/b)*x;}
    return g;
}
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
template<class Type>
Type solve(Type res = Type()){
    ll X,Y,P,Q; cin >> X >> Y >> P >> Q;

    ll a = 2*X + 2*Y;
    ll c = P + Q;

    ll T = numeric_limits<ll>::max();
    for(ll b = X; b < X+Y; b++){
        for(ll d = P; d < P+Q; d++){

            // a*x + b = c*y + d
            // t = b (mod a)
            // t = c (mod c)

            auto ret = CRT(vector<ll>{b,d},vector<ll>{a,c});
            if(ret.second == -1) continue;
            T = min(T,ret.first);
        }
    }

    if(T == numeric_limits<ll>::max()){
        return "infinity";
    }else{
        return to_string(T);
    }

    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    //solve<ll>(0);
    ll T; cin >> T;
    while(T--) cout << fixed << setprecision(12) << solve<string>() << endl;
    return 0;
}