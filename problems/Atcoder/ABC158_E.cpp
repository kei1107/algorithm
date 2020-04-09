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
 <url:https://atcoder.jp/contests/abc158/tasks/abc158_e>
 問題文============================================================
 E - Divisible Substring
 =================================================================
 解説=============================================================

 位置iから末尾Nまでを文字列として評価した値を T(i)とする。
 このとき、位置i,j (i <= j)での部分文字列の値は (T(i) - T(j)) / 10^(j-i) となる。
 すなわち、(T(i) - T(j)) / 10^(j-i) mod P が0となる位置の個数を数えることとなる。
 このとき、分母の10に注目したとき、P = 2,5の場合は右端の値により一意に決める事ができる。
 P ≠2,5の場合、分母10とPは互いに素であるので T(i) - T(j) mod P = 0の場合と同等に数える事ができる。
 よって、 T(i) mod P == T(j) mod P と式変形することができ、全ての位置iについてT(i) mod Pの値がいくつ存在するかを保存した配列やmapを用いて計算を行う事が可能となる。

 https://atcoder.jp/contests/abc158/submissions/11647796
 ================================================================
 */

ll MOD = -1;
ll powmod(ll a,ll b) {ll res=1;a%=MOD; for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}

template<class Type>
Type solve(Type res = Type()){
    int N,P; cin >> N >> P;
    MOD = P;
    string S; cin >> S;
    for(auto& c:S) c -= '0';

    if(P==2 || P == 5){
        for(int i = 0; i < N;i++){
            if(S[i]%P==0){
                res += i+1;
            }
        }
    }else{
        for(auto& c:S) c%=P;
        map<ll,ll> mp;

        ll num = 0;
        for(int i = N-1; i >= 0; i--){
            num += powmod(10,N-1-i)*S[i]%P;
            num %= P;
            mp[num]++;
        }
        mp[0]++;
        for(int i = 0; i < P;i++){
            res += mp[i]*(mp[i]-1)/2;
        }
    }

    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
