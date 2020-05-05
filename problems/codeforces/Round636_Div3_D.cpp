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
 <url:https://codeforces.com/contest/1343/problem/D>
 問題文============================================================
 D. Constant Palindrome Sum

 配列が与えられ、要素を1〜kの値に自由に置換できるとする

 変更後の配列について1-indexで常に
 a[i] + a[n-i+1] = x
 が満たされるとする。（xは任意）

 条件を満たすような配列を作るために必要な要素の置換回数の最小値はいくつか

 =================================================================
 解説=============================================================

 bitで殴る

 対象となるある二つの要素 a[m]とa[m-i+1]を見た時
 a[m] + a[m-i+1]となるようなxを選択すれば置換回数は0となる。
 また、
 min(a[m]+1,a[m-i+1]) <= x <= max(a[m]+k,a[m-i+1]+k)
 となるようなxを選択すれば置換回数は1となる(ここでx!=a[m] + a[m-i+1]とする)。
 それ以外の区間では2回の置換が必要となる。

 よって、対象とする要素ペアに対して、各x毎に必要な置換回数の個数がわかる。
 bitでxについてこの置換回数を保持・更新していくことで、この問題は解ける。
 O(t(n+k)logk)
 ================================================================
 */

/*
 1-index
 RangeAdd : [s,t] に xを加算
 RangeSum : [s,t] の総和を出力
 */
struct BIT {
    int N;
    vector<ll> bit1;
    vector<ll> bit2;
    BIT(ll N):N(N) {
        /* BITは[1..N]で扱う */
        bit1.resize(N + 1, 0);
        bit2.resize(N + 1, 0);
    }

    void add1(int x, ll val){
        while (x <= N) {
            bit1[x] += val;
            x += x & -x;
        }
    }
    void add2(int x, ll val){
        while (x <= N) {
            bit2[x] += val;
            x += x & -x;
        }
    }

    // [l,r]
    void RangeAdd(int l,int r,ll val){
        // Update BIT1
        add1(l,val);
        add1(r+1,-val);

        // Update BIT2
        add2(l,val*(l-1));
        add2(r+1,-val*r);
    }

    ll sum1(int x){
        ll ret = 0;
        while (x) {
            ret += bit1[x];
            x &= (x - 1);
        }
        return (ret);
    }

    ll sum2(int x){
        ll ret = 0;
        while (x) {
            ret += bit2[x];
            x &= (x - 1);
        }
        return (ret);
    }

    ll sum(int x){
        return sum1(x)*x - sum2(x);
    }
    // [l,r]
    ll RangeSum(int l,int r){
        return sum(r) - sum(l-1);
    }
};

template<class Type>
Type solve(Type res = Type()){
    int n,k; cin >> n >> k;
    vector<int> a(n); for(auto& in:a) cin >> in;

    BIT bit(2*k);
    for(int i = 0; i < n/2; i++){
        bit.RangeAdd(2, 2*k, 2); // とりあえず全区間で二つの要素変更が必要としておく

        // どちらか一方を固定してできる値
        // a[i]を固定
        // a[i] + 1 <= x <= a[i] + k
        // a[n-1-i]を固定
        // a[n-1-i] + 1 <= x <= a[n-1-i] + k
        int L = min(a[i]+1,a[n-1-i]+1);
        int R = max(a[i]+k,a[n-1-i]+k);
        bit.RangeAdd(L, R, -1); // 片方固定でいけるので1減らす

        // 両方を固定してできる値
        bit.RangeAdd(a[i]+a[n-1-i],a[i]+a[n-1-i],-1); // 両方固定でいけるのでさらに1減らす
    }

    res = LINF;
    for(int i = 2; i <= 2*k; i++){
        res = min(res,bit.RangeSum(i, i));
    }

    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    int t; cin >> t;
    while(t--){
        cout << fixed << setprecision(15) << solve<ll>() << endl;
    }
    return 0;
}
