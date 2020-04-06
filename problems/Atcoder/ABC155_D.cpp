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
 <url:https://atcoder.jp/contests/abc155/tasks/abc155_d>
 問題文============================================================
 D - Pairs
 =================================================================
 解説=============================================================
 
 実装が面倒

 正・0・負の要素の数を数えておけば、答えが正・0・負のいずれかになるかは一意に決まる。

 答えが正の時は 正*正 or 負*負　の組み合わせで
 答えが負の時は 正*負 の組み合わせで

 ある値 m 以下になるものの個数がいくつあるかを二分探索すればいい
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    ll N,K; cin >> N >> K;
    vector<ll> A(N); for(auto& in:A) cin >> in;
    vector<ll> plus,zero,minus;
    for(auto a:A){
        if(a > 0) plus.emplace_back(a);
        else if(a == 0) zero.emplace_back(a);
        else minus.emplace_back(-a);
    }
    ll psz = plus.size();
    ll zsz = zero.size();
    ll msz = minus.size();

    sort(plus.begin(),plus.end());
    sort(minus.begin(),minus.end());
    if(K <= psz*msz){
        auto ok = [&](ll m){
            ll C = 0;
            for(int i = 0; i < psz; i++){
                C += msz - (upper_bound(minus.begin(),minus.end(),m/plus[i]) - minus.begin());
            }
            return C;
        };
        ll l = 0, r = 2*LINF;
        while(r-l>1){
            ll m = (l+r)/2;
            if(K <= ok(m)){
                l = m;
            }else{
                r = m;
            }
        }
        res = -r;
    }else if(K <= psz*msz + zsz*(psz+msz) + zsz*(zsz-1)/2){
        return 0;
    }else{
        ll add = psz*msz + zsz*(psz+msz) + zsz*(zsz-1)/2;
        K -= add;
        auto ok = [&](ll m){
            ll C = 0;

            for(int i = 0; i < psz;i++){
                C += upper_bound(plus.begin(),plus.end(),m/plus[i]) - plus.begin();
                if(plus[i] < m/plus[i]) C--;
            }
            for(int i = 0; i < msz;i++){
                C += upper_bound(minus.begin(),minus.end(),m/minus[i]) - minus.begin();
                if(minus[i] < m/minus[i]) C--;
            }
            return C/2;
        };
        ll l = 0, r = 2*LINF;
        while(r-l>1){
            ll m = (l+r)/2;
            if(K <= ok(m)){
                r = m;
            }else{
                l = m;
            }
        }
        res = r;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
