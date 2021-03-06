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
 <url:https://atcoder.jp/contests/arc077/tasks/arc077_c>
 問題文============================================================
 E - guruguru
 =================================================================
 解説=============================================================
 ================================================================
 */

template<class T>
struct cum_sum_linear{
    int n;
    vector<T> x,a,b;
    cum_sum_linear(int n_ = 0) : n(n_), x(n), a(n+1), b(n+1){}

    // 区間[l,r)に対して、
    // x_l += c , x_l+1 += c + d , x_l+2 = c + 2*d, x_l+r = c + (r-l)*d
    // を加算する
    void add(int l,int r, T c, T d){
        a[l] += c; a[r] -= c;
        a[l] -= d*l; a[r] += d*l;
        b[l] += d; b[r] -= d;
    }
    void fix(){
        for(int i = 0; i < n;i++){
            x[i] = a[i] + b[i]*i;
            a[i+1] += a[i];
            b[i+1] += b[i];
        }
    }
    T operator[](int i) const { return x[i]; }
};



// verified : ARC077 https://atcoder.jp/contests/arc077/tasks/arc077_c
template<class Type>
Type solve(Type res = Type()){
    int n,m; cin >> n >> m;
    vector<ll> a(n); for(auto& in:a) cin >> in;

    ll sum = 0;
    cum_sum_linear<ll> x(2*m+1);
    for(int i = 1; i < n;i++){
        ll l = a[i-1], r = a[i];
        if(r < l) r += m;

        sum += r-l;

        x.add(l+1,r+1,0,1);
    }
    x.fix();

    res = LINF;
    for(int i = 1; i <= m;i++){
        res = min(res,sum - x[i] - x[i+m]);
    }

    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    //solve<ll>(0);
    cout << fixed << setprecision(12) << solve<ll>() << endl;
    return 0;
}