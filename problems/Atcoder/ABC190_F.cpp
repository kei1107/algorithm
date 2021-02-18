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
 <url:https://atcoder.jp/contests/abc190/tasks/abc190_f>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */

/*
 BIT 0-index
 */
template<typename type>
struct BIT0 { // 0-index
    int N;
    int nn;
    vector<type> data;
    //動的はmap<int?,type>data
    BIT0(int n) {
        N = n + 1;
        data = vector<type>(n + 1, 0);
        nn = 1;
        while (nn * 2 <= N)nn *= 2;
    }
    void add(int i, type w) { // a[i] += w
        i++;
        for (int x = i; x < N; x += x & -x) {
            data[x] += w;
        }
    }
    type sum(int i) { // iまでの和 [0,i)
        type ret = 0;
        for (int x = i; x > 0; x -= x & -x) {
            ret += data[x];
        }
        return ret;
    }
    // [l, r)
    type sum(int l, int r) {
        return sum(r) - sum(l);
    }
    
    /*    BIT 上で二分探索
     二分木の分かれ方に従って二分探索する
     左の子に進むか右の子に進むかを知るためには，左の子の範囲の和がわかればよい
     ちょうど BIT がもっている情報，O(1) 時間で得られる
     a[1] + a[2] + a[3] + ... a[x] >= w となる最小のxを返す、ただしa[i] >= 0    */
    
    int lower_bound(type w) {//  w≦[0,x]以上となる最小のindex,x
        if (w <= 0) return 0;
        int x = 0;
        for (int k = nn; k > 0; k /= 2) {
            if (x + k < N && data[x + k] < w) {
                w -= data[x + k];
                x += k;
            }
        }
        return x;
    }
};

template<class Type>
Type solve(Type res = Type()){
    int N; cin >> N;
    vector<int> a(N); for(auto& in:a) cin >> in;

    BIT0<int> bit(N);

    ll inv_num = 0;
    for(int i = 0; i < N;i++){
        inv_num += bit.sum(a[i],N);
        bit.add(a[i],1);
    }

    for(int i = 0; i < N;i++){
        cout << inv_num << endl;

        inv_num += N - 2*a[i] - 1;
    }

    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    solve<ll>(0);
    // cout << fixed << setprecision(12) << solve<ll>() << endl;
    return 0;
}