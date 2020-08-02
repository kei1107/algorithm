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
 <url:>
 問題文============================================================
 =================================================================
 解説=============================================================
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
    int n; cin >>n;
    vector<int> xs(n),vs(n);
    for(auto& in:xs) cin >> in;
    for(auto& in:vs) cin >> in;
    
    auto T = xs;
    sort(T.begin(),T.end()); T.erase(unique(T.begin(),T.end()),T.end());
    
    vector<pii> vx(n);
    for(int i = 0; i < n;i++){
        int idx = (int)(lower_bound(T.begin(),T.end(),xs[i]) - T.begin()) + 5;
        vx[i] = make_pair(vs[i],idx);
    }

    sort(vx.begin(),vx.end());
    BIT bit_cord(n+10);
    BIT bit_cnt(n+10);
    
    for(int i = 0; i < n;i++){
        int x_idx; ll v; tie(v,x_idx) = vx[i];
        ll x = T[x_idx-5];
        
        ll cord_sum = bit_cord.RangeSum(1, x_idx);
        ll cnt = bit_cnt.RangeSum(1,x_idx);
        res += x*cnt - cord_sum;
        
        bit_cord.RangeAdd(x_idx,x_idx,x);
        bit_cnt.RangeAdd(x_idx,x_idx,1);
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
