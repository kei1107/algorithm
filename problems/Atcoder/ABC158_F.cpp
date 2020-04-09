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
 <url:https://atcoder.jp/contests/abc158/tasks/abc158_f>
 問題文============================================================
 F - Removing Robots
 =================================================================
 解説=============================================================
 
 前もって、各ロボットを座標について昇順にソートしておく。
 
 このとき、座標の大きい方から順にロボットを見て行くと考える。
 i番目のロボットについて、ロボットを起動しない場合とする場合の２通りを選択できる。
 このときのそれぞれの場合の組み合わせ数は
 1) ロボットを起動しない場合
    (i+1)〜N番目のロボットについてみたときの組み合わせ数
 2) ロボットを起動する場合
    i番目のロボットを起動したとき、起動されることがないiより大きい最小のロボットの番号jに対し、
    j〜N番目のロボットについてみたときの組み合わせ数
 
 として考えることができる。
 
 よって、dp[i] := i〜N番目のロボットについてみたときの組み合わせ数 とおいたとき、
 上記jを用いて、dp[i] = dp[i+1] + dp[j] として更新することができる。
 
 このとき、ネックとなるのはiより大きい最小のロボットの番号jの計算だが、
 これはセグメント木を用いて座標の大きいロボットから順に更新を行なっていくことで求めることが可能となる。
 よって、O(NlogN)で解ける。
 
 https://atcoder.jp/contests/abc158/submissions/11649733
 ================================================================
 */

template <typename Monoid>
struct SegmentTree {
public:
    using Type = typename Monoid::Type;
    int sz; // Array size
    vector<Type>node;
    SegmentTree(int n){
        sz = 1;
        while(sz < n) sz <<= 1;
        node.assign(2*sz,Monoid::id());
    }
    void set(int k,const Type& val){
        node[k+sz] = val;
    }
    void build(){
        for(int k = sz - 1; k > 0; k--){
            node[k] = Monoid::op(node[2*k],node[2*k+1]);
        }
    }
    inline void update(int k, const Type& val) {
        k += sz;
        node[k] = val;
        while (k >>= 1) {
            node[k] = Monoid::op(node[2*k], node[2*k+1]);
        }
    }
    inline Type query(int l, int r) {
        if (l >= r)return Monoid::id();
        Type vl = Monoid::id(), vr = Monoid::id();
        for (l += sz, r += sz; l != r; l >>= 1, r >>= 1) {
            if (l & 1)  vl = Monoid::op(vl, node[l++]);
            if (r & 1)  vr = Monoid::op(node[--r], vr);
        }
        return Monoid::op(vl, vr);
    }
    Type operator[](int i) { return node[i + sz]; }
};

struct Monoid {
    using Type = int;/* Monoidに乗せる型 */
    static Type id() { return 0; /* モノイドの初期値 */};
    
    // ================================================ //
    //                              マージ処理            //
    // ================================================ //
    static Type op(const Type&l, const Type &r) {
        Type ret;
        ret = max(l,r);
        return ret;
    }
};

const ll MOD = 998244353;
template<class Type>
Type solve(Type res = Type()){
    int N; cin >> N;
    vector<pii> XD(N);
    for(auto& in:XD) cin >> in.first >> in.second;
    sort(XD.begin(),XD.end());
    XD.emplace_back(numeric_limits<int>::max(),0);
    SegmentTree<Monoid> ST(N+1);
    ST.update(N,N);
    
    vector<ll> dp(N+1);
    dp[N] = 1;
    for(int i = N-1; i >= 0; i--){
        // don't move
        (dp[i] += dp[i+1])%=MOD;
        // move
        {
            int r= (int)(lower_bound(XD.begin(),XD.end(),pii(XD[i].first+XD[i].second,-1))-XD.begin());
            
            if(i+1 == r){
                (dp[i] += dp[i+1])%=MOD;
                ST.update(i,i+1);
            }else{
                int j = ST.query(i+1,r);
                (dp[i] += dp[j])%=MOD;
                ST.update(i,j);
            }
        }
    }
    res = dp[0];
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
