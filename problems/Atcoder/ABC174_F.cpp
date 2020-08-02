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


/**
 * 与えられた数列の区間中の種類数を求める
 * a : 数列
 * query : クエリ (l,r)  0-index
 */
template<class T>
struct BIT {
    T N;
    vector<T> bit;
    BIT(int N):N(N) { bit.resize(N + 1, 0);}
    void add(int x, T val){ while (x <= N) { bit[x] += val; x += x & -x;}}
    T sum(int x){ T ret = 0; if(x == 0) return ret; while (x) { ret += bit[x]; x &= (x - 1); } return ret;}
    T sum(int l,int r){ return sum(r) - sum(l-1);}
};
vector<int> CountCoveringValue(vector<int>& a, vector<pii>& query){
    int n = (int)a.size();
    int q = (int)query.size();
    
    vector<int> ans(q);
    
    using Item = tuple<int,int,int>;
    vector<Item> qinfo(q);
    for(int i = 0; i < q;i++){
        qinfo[i] = Item(query[i].second,query[i].first,i);
    }
    sort(qinfo.begin(),qinfo.end());
    
    BIT<int> bit(n);
    map<int,int> lastAppeared; // これを配列に変えることで高速化可能
    for(int i = 0; i < n;i++){
        lastAppeared[a[i]] = i;
    }
    for(auto p:lastAppeared){
        bit.add(p.second+1,1);
    }
    int nowr = -1;
    for(auto q:qinfo){
        int l,r,id; tie(r,l,id) = q;
        while(nowr < r){ // 更新を後でまとめることで高速化可能
            nowr++;
            int prev = lastAppeared[a[nowr]];
            lastAppeared[a[nowr]] = nowr;
            int v = lastAppeared[a[nowr]];
            bit.add(prev+1,-1);
            bit.add(v+1,1);
        }
        ans[id] = bit.sum(l+1,r+1);
    }
    return ans;
};


// verified : https://atcoder.jp/contests/abc174/tasks/abc174_f

template<class Type>
Type solve(Type res = Type()){
    int N,Q; cin >> N >> Q;
    
    vector<int> a(N); for(auto& in:a) cin >> in;
    vector<pii> query(Q);
    for(int i = 0; i < Q;i++){
        int l,r; cin >> l >> r;
        l--; r--;
        query[i] = make_pair(l, r);
    }
    
    auto ans = CountCoveringValue(a, query);
    for(int i = 0; i < Q;i++){
        cout << ans[i] << endl;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve(0);
    //cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
