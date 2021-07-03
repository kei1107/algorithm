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
template<class T> ostream& operator << (ostream& out,const vector<T>& V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> >& Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T>& mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }
template<typename T>vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}
/*
 <url:https://atcoder.jp/contests/typical90/tasks/typical90_cd>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */

const ll MOD = 1e9+7;
// a^b % MOD;
ll powmod(ll a,ll b) {ll res=1;a%=MOD; for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
// 逆元 1/a % MOD
ll inversemod(ll a) { return powmod(a,MOD - 2);}

ll calc(ll T){
    ll ret = 0;

    ll l = 1, r = 10, len = 1;

    while(true){

        if(r <= T){
            ll n = (r - l)%MOD;
            ll S = n * (2*l%MOD + (n-1))%MOD * inversemod(2)%MOD;
            ret += len * S;
            ret %= MOD;

            // cout << l << " " << r << " " << T << " / " << len << " " << S << endl;
        }else{
            ll n = (T - l + 1)%MOD;
            ll S = n * (2*l%MOD + (n-1))%MOD * inversemod(2)%MOD;
            ret += len * S;
            ret %= MOD;
            // cout << l << " " << r << " " << T << " / " << len << " " << S << endl;
            break;
        }

        if(r == (ll)1e18){
            ret += 19 * (((ll)1e18)%MOD);
            ret %= MOD;
            break;
        }

        l *= 10;
        r *= 10;
        len++;
    }

    return ret;
}
template<class Type>
Type solve(Type res = Type()){
    ll L,R; cin >> L >> R;
    // cout << calc(R) << endl;
    //cout << calc(L-1) << endl;
    return res = (calc(R) - calc(L-1) + MOD)%MOD;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    //solve<ll>(0);
    cout << fixed << setprecision(12) << solve<ll>() << endl;
    return 0;
}