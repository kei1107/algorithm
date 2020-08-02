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
template<class T> ostream& operator << (ostream& out,const vector<T>& V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> >& Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T>& mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }
template<typename T>vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}
/*
 <url:https://atcoder.jp/contests/abc173/tasks/abc173_e>
 問題文============================================================
 E - Multiplication 4
 =================================================================
 解説=============================================================
 ================================================================
 */

const ll MOD = 1e9+7;
// a^b % MOD;
ll powmod(ll a,ll b) {ll res=1;a%=MOD; for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
// 逆元 1/a % MOD
ll inversemod(ll a) { return powmod(a,MOD - 2);}

template<class Type>
Type solve(Type res = Type()){
    ll N,K; cin >> N >> K;
    vector<ll> A(N); for(auto& in:A) cin >>in;
    sort(A.begin(), A.end(),[](const ll a,const ll b) {
        return abs(a) > abs(b);
    });

    ll mul = 1, plus = 0, minus = 0;
    for(int i=0; i<K; i++) {
        if(A[i] < 0) minus++;
        if(A[i] > 0) plus++;
        if(A[i] == 0) {
            return 0;
        }
        mul *= A[i];
        mul = (mul%MOD + MOD)%MOD;
    }

    if(minus % 2 == 0 or N == K) {
        return mul;
    }

    int neg = 0;
    for(auto e : A) if(e < 0) neg++;
    if(neg == N) {
        sort(A.rbegin(), A.rend());
        mul = 1;
        for(int i=0; i<K; i++) {
            mul *= A[i];
            mul = (mul%MOD + MOD)%MOD;
        }
        return mul;
    }

    // plus の中で最も小さいものを、K 個範囲外の minus と交換
    // minus の中で最も小さいものを、K 個範囲外の plus と交換
    ll ans = mul;
    ll a1 = -1, b1 = -1;
    if(plus > 0) {
        ll min_v = LINF;
        for(int i=0; i<K; i++) {
            if(A[i] <= 0) continue;
            min_v = min(min_v,abs(A[i]));
        }
        a1 = min_v;

        ll max_v = -LINF;
        for(ll i=K; i<N; i++) {
            if(A[i] > 0) continue;
            max_v = max(max_v,abs(A[i]));
        }
        b1 = max_v;
    }
    ll a2 = -1, b2 = -1;
    if(minus > 0) {
        ll min_v = LINF;
        for(int i=0; i<K; i++) {
            if(A[i] >= 0) continue;
            min_v = min(min_v,abs(A[i]));
        }
        a2 = min_v;

        ll max_v = -LINF;
        for(ll i=K; i<N; i++) {
            if(A[i] < 0) continue;
            max_v = max(max_v,abs(A[i]));
        }
        b2 = max_v;
    }

    if(a1 >= 0 and a2 >= 0 and b1 >= 0 and b2 >= 0) {
        ans = MOD - ans;
        ans %= MOD;

        // a1, b1
        if(b1*a2 > b2*a1) {
            ans *= inversemod(a1);
            ans %= MOD;
            ans *= b1;
            ans %= MOD;
        }
        // a2, b2
        else {
            ans *= inversemod(a2);
            ans %= MOD;
            ans *= b2;
            ans %= MOD;
        }
    }
    else if(a1 >= 0 and b1 >= 0) {
        ans = MOD - ans;
        ans %= MOD;

        ans *= inversemod(a1);
        ans %= MOD;
        ans *= b1;
        ans %= MOD;
    }
    else if(a2 >= 0 and b2 >= 0) {
        ans = MOD - ans;
        ans %= MOD;

        ans *= inversemod(a2);
        ans %= MOD;
        ans *= b2;
        ans %= MOD;
    }
    res = ans;

    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
