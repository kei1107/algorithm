#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }


/*
 <ref: http://algoogle.hadrori.jp/algorithm/wavelet.html>
 
 Algoogleでの実装
 
 自分なりに使えるように使い方についてまとめておく
*/
// WaveletMatrix ============================================ //
/*
 
 FID
 
 rank: 区間[0,r)にあるvalの個数
 select: i番目のvalの位置
 []: i番目の要素
 
 
 Wavelet行列
 rank: 区間[0,r)にあるvalの個数
 select: i番目のvalの位置
 get, []: i番目の要素
 kth_number: 区間[l,r)でk番目に大きい数
 maximum: 区間[l,r)で大きい順にk個
 freq: 区間[l,r)で値が[lb,ub)になる要素の数
 freq_list: 区間[l,r)で値が[lb,ub)になる値とその出現回数の組のリスト
 get_rect: 区間[l,r)で値が[lb,ub)になる要素の位置とその値の組(つまり矩形内にある点の座標)のリスト

 */

template<int N> class FID {
    static const int bucket = 512, block = 16;
    static char popcount[];
    int n, B[N/bucket+10];
    unsigned short bs[N/block+10], b[N/block+10];
    
public:
    FID(){}
    FID(int n, bool s[]) : n(n) {
        if(!popcount[1]) for (int i = 0; i < (1<<block); i++) popcount[i] = __builtin_popcount(i);
        
        bs[0] = B[0] = b[0] = 0;
        for (int i = 0; i < n; i++) {
            if(i%block == 0) {
                bs[i/block+1] = 0;
                if(i%bucket == 0) {
                    B[i/bucket+1] = B[i/bucket];
                    b[i/block+1] = b[i/block] = 0;
                }
                else b[i/block+1] = b[i/block];
            }
            bs[i/block]   |= short(s[i])<<(i%block);
            b[i/block+1]  += s[i];
            B[i/bucket+1] += s[i];
        }
        if(n%bucket == 0) b[n/block] = 0;
    }
    
    // number of val in [0,r), O(1)
    int count(bool val, int r) { return val? B[r/bucket]+b[r/block]+popcount[bs[r/block]&((1<<(r%block))-1)]: r-count(1,r); }
    // number of val in [l,r), O(1)
    int count(bool val, int l, int r) { return count(val,r)-count(val,l); }
    // position of ith in val, 0-indexed, O(log n)
    int select(bool val, int i) {
        if(i < 0 or count(val,n) <= i) return -1;
        i++;
        int lb = 0, ub = n, md;
        while(ub-lb>1) {
            md = (lb+ub)>>1;
            if(count(val,md) >= i) ub = md;
            else lb = md;
        }
        return ub-1;
    }
    int select(bool val, int i, int l) { return select(val,i+count(val,l)); }
    bool operator[](int i) { return bs[i/block]>>(i%block)&1; }
};
template<int N> char FID<N>::popcount[1<<FID<N>::block];

template<class T, int N, int D> class wavelet {
    int n, zs[D];
    FID<N> dat[D];
    
    void max_dfs(int d, int l, int r, int &k, T val, vector<T> &vs) {
        if(l >= r or !k) return;
        if(d == D) {
            while(l++ < r and k > 0) vs.push_back(val), k--;
            return;
        }
        int lc = dat[d].count(1,l), rc = dat[d].count(1,r);
        // if min, change this order
        max_dfs(d+1, lc+zs[d], rc+zs[d], k, 1ULL<<(D-d-1)|val,vs);
        max_dfs(d+1, l-lc, r-rc, k, val, vs);
    }
    
    T max_dfs(int d, int l, int r, T val, T a, T b) {
        if(r-l <= 0 or val >= b) return -1;
        if(d == D) return val>=a? val: -1;
        int lc = dat[d].count(1,l), rc = dat[d].count(1,r);
        T ret = max_dfs(d+1, lc+zs[d], rc+zs[d], 1ULL<<(D-d-1)|val, a, b);
        if(~ret) return ret;
        return max_dfs(d+1, l-lc, r-rc, val, a, b);
    }
    
    int freq_dfs(int d, int l, int r, T val, T a, T b) {
        if(l == r) return 0;
        if(d == D) return (a <= val and val < b)? r-l: 0;
        T nv = 1ULL<<(D-d-1)|val, nnv = ((1ULL<<(D-d-1))-1)|nv;
        if(nnv < a or b <= val) return 0;
        if(a <= val and nnv < b) return r-l;
        int lc = dat[d].count(1,l), rc = dat[d].count(1,r);
        return freq_dfs(d+1,l-lc,r-rc,val,a,b)+
        freq_dfs(d+1,lc+zs[d],rc+zs[d],nv,a,b);
    }
    
    void list_dfs(int d, int l, int r, T val, T a, T b, vector<pair<T,int>> &vs) {
        if(val >= b or r-l <= 0) return;
        if(d == D) {
            if(a <= val) vs.push_back(make_pair(val,r-l));
            return;
        }
        T nv = val|(1LL<<(D-d-1)), nnv = nv|(((1LL<<(D-d-1))-1));
        if(nnv < a) return;
        int lc = dat[d].count(1,l), rc = dat[d].count(1,r);
        list_dfs(d+1,l-lc,r-rc,val,a,b,vs);
        list_dfs(d+1,lc+zs[d],rc+zs[d],nv,a,b,vs);
    }
public:
    wavelet(){}
    wavelet(int n, T seq[]) : n(n) {
        T f[N], l[N], r[N];
        bool b[N];
        memcpy(f, seq, sizeof(T)*n);
        for (int d = 0; d < D; d++) {
            int lh = 0, rh = 0;
            for (int i = 0; i < n; i++) {
                bool k = (f[i]>>(D-d-1))&1;
                if(k) r[rh++] = f[i];
                else l[lh++] = f[i];
                b[i] = k;
            }
            dat[d] = FID<N>(n,b);
            zs[d] = lh;
            swap(l,f);
            memcpy(f+lh, r, rh*sizeof(T));
        }
    }
    T get(int i) {
        T ret = 0;
        bool b;
        for (int d = 0; d < D; d++) {
            ret <<= 1;
            b = dat[d][i];
            ret |= b;
            i = dat[d].count(b,i)+b*zs[d];
        }
        return ret;
    }
    T operator[](int i) { return get(i); }
    
    int count(T val, int l, int r) {
        for (int d = 0; d < D; d++) {
            bool b = (val>>(D-d-1))&1;
            l = dat[d].count(b,l)+b*zs[d];
            r = dat[d].count(b,r)+b*zs[d];
        }
        return r-l;
    }
    int count(T val, int r) { return count(val,0,r); }
    
    int select(T val, int k) {
        int ls[D], rs[D], l = 0, r = n;
        for (int d = 0; d < D; d++) {
            ls[d] = l; rs[d] = r;
            bool b = val>>(D-d-1)&1;
            l = dat[d].count(b,l)+b*zs[d];
            r = dat[d].count(b,r)+b*zs[d];
        }
        for (int d = D-1; d >= 0; d--) {
            bool b = val>>(D-d-1)&1;
            k = dat[d].select(b,k,ls[d]);
            if(k >= rs[d] or k < 0) return -1;
            k -= ls[d];
        }
        return k;
    }
    int select(T val, int k, int l) { return select(val,k+count(val,l)); }
    
    vector<T> maximum(int l, int r, int k) {
        if (r-l < k) k = r-l;
        if(k < 0) return {};
        vector<T> ret;
        max_dfs(0,l,r,k,0,ret);
        return ret;
    }
    
    T maximum(int l, int r, T a, T b) { return max_dfs(0,l,r,0,a,b); }
    
    // k is 0-indexed
    T kth_number(int l, int r, int k) {
        if(r-l <= k or k < 0) return -1;
        T ret = 0;
        for (int d = 0; d < D; d++) {
            int lc = dat[d].count(1,l), rc = dat[d].count(1,r);
            if(rc-lc > k) {
                l = lc+zs[d];
                r = rc+zs[d];
                ret |= 1ULL<<(D-d-1);
            }
            else {
                k -= rc-lc;
                l -= lc;
                r -= rc;
            }
        }
        return ret;
    }
    
    vector<pair<T,int>> freq_list(int l, int r, T a, T b) {
        vector<pair<T,int>> ret;
        list_dfs(0,l,r,0,a,b,ret);
        return ret;
    }
    
    vector<pair<int,T>> get_rect(int l, int r, T a, T b) {
        vector<pair<T,int>> res = freq_list(l,r,a,b);
        vector<pair<int,T>> ret;
        for(auto &e: res)
            for (int i = 0; i < e.second; i++)
                ret.push_back(make_pair(select(e.first,i,l), e.first));
        return ret;
    }
    // number of elements in [l,r) in [a,b), O(D)
    int freq(int l, int r, T a, T b) { return freq_dfs(0,l,r,0,a,b); }
};

// END WaveletMatrix ====================================================//
/*
 
 FID
 
 rank: 区間[0,r)にあるvalの個数
 select: i番目のvalの位置
 []: i番目の要素
 
 Wavelet行列
 
 rank: 区間[0,r)にあるvalの個数
 select: i番目のvalの位置
 get, []: i番目の要素
 kth_number: 区間[l,r)でk番目に大きい数
 maximum: 区間[l,r)で大きい順にk個
 freq: 区間[l,r)で値が[lb,ub)になる要素の数
 freq_list: 区間[l,r)で値が[lb,ub)になる値とその出現回数の組のリスト
 get_rect: 区間[l,r)で値が[lb,ub)になる要素の位置とその値の組(つまり矩形内にある点の座標)のリスト
 
 注意: rは n+1を超えないようにする
 */

// initialize
/*
const int N = 100010, D = 30;
wavelet<int,N,D> wv;
 */


void test(){ // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2674
    const int base = 5e8;
    int x[100010];
    int n; cin >> n;
    for(int i = 0; i < n;i++){
        cin >> x[i]; x[i] += base;
    }
    int q; cin >> q;
    wavelet<int,100010,30> wv(n,x);
    while(q--){
        int l,r,e; cin >> l >> r >> e;
        l--; r--;
        int maxx = max(x[l],x[r]),minx = min(x[l],x[r]);
        //  freq: 区間[l,r)で値が[lb,ub)になる要素の数
        cout << wv.freq(l,r+1,0,minx-e) + wv.freq(l,r+1,maxx+e+1,INF) << endl;
    }
}

void test2(){ // http://codeforces.com/contest/961/problem/E
    int x[200010];
    int n; cin >> n;
    x[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> x[i];
    }
    wavelet<int,200010,30> wv(n+1,x);
    ll ans = 0;
    for(int i = 1; i <= n;i++){
        if(x[i] <= i) continue;
        int l = i+1, r = min(x[i]+1,n+1); // 注意: rは n+1を超えないようにする
        //  freq: 区間[l,r)で値が[lb,ub)になる要素の数
        ll ret = wv.freq(l,r,i,INF+1);
        ans += ret;
    }
    cout << ans << endl;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    //test();
    test2();
    return 0;
}
