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
 <url:https://onlinejudge.u-aizu.ac.jp/challenges/sources/JOI/Prelim/0590?year=2006>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 OEISゲー
 https://oeis.org/A047845
 
 ================================================================
 */

// return (a * b) % m
ll mul_mod(ll a,ll b,ll m){
    ll res = 0;
    ll exp = a % m;
    while(b){
        if(b&1){
            res += exp;
            if(res > m) res -= m;
        }
        exp <<= 1;
        if(exp > m) exp -= m;
        b >>= 1;
    }
    return res;
}

// return (x ^ k) % m
ll pow_mod(ll a, ll b, ll m){
    ll res = 1;
    ll exp = a % m;
    while(b){
        if(b& 1) res = mul_mod(res, exp, m);
        exp = mul_mod(exp, exp, m);
        b >>= 1;
    }
    return res;
}

// ミラーラビン素数判定法
// return 判定値 n が 最大times回、乱択的にチェックした時に素数判定されるかどうか
bool miller_rabin(ll n, ll times) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (!(n & 1)) return false;
    
    ll q = n-1;
    int k = 0;
    while (q % 2 == 0) {
        k++;
        q >>= 1;
    }
    // n - 1 = 2^k * q (qは奇素数)
    // nが素数であれば、下記のいずれかを満たす
    // (i) a^q ≡ 1 (mod n)
    // (ii) a^q, a^2q,..., a^(k-1)q のどれかがnを法として-1
    //
    // なので、逆に(i)(ii)いずれも満たしていない時は合成数と判定できる
    //
    for (int i = 0; i < times; i++) {
        ll a = rand() % (n-1) + 1; // 1,..,n-1からランダムに値を選ぶ
        ll x = pow_mod(a, q, n);
        // (i)をチェック
        if (x == 1) continue;
        // (ii)をチェック
        bool found = false;
        for (int j = 0; j < k; j++) {
            if (x == n-1) {
                found = true;
                break;
            }
            x = mul_mod(x, x, n);
        }
        if (found) continue;
        
        return false;
    }
    return true;
}

template<class Type>
Type solve(Type res = Type()){
    int N; cin >> N;
    for(int i = 0; i < N;i++){
        ll A; cin >> A;
        A = 2*A + 1;
        if(miller_rabin(A, 30)) res++;
    }
    return res;
}

void test(){
    map<ll,bool> mp;
    for(ll x = 1; x <= 10; x++){
        for(ll y = 1; y <= 10; y++){
            mp[2*x*y+x+y] = true;
        }
    }
    cout << mp << endl;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // test();
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
