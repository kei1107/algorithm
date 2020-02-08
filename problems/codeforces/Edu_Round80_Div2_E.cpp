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
 <url:https://codeforces.com/contest/1288/problem/E>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */

struct BIT {
    ll N;
    vector<ll> bit;
    BIT(ll N):N(N) {
        /* BITは[1..N]で扱う */
        bit.resize(N + 1, 0);
    }
    
    void add(int x, ll val){
        while (x <= N) {
            bit[x] += val;
            x += x & -x;
        }
    }
    
    ll sum(int x){
        ll ret = 0;
        if(x == 0) return ret;
        while (x) {
            ret += bit[x];
            x &= (x - 1);
        }
        return (ret);
    }
    // [l,r]
    ll sum(int l,int r){
        return sum(r) - sum(l-1);
    }
};

template<class Type>
Type solve(Type res = Type()){
    int n,m; cin >> n >> m;
    vector<int> a(m); for(auto& in: a) cin >> in;
    vector<int> minpos(n),maxpos(n);
    iota(minpos.begin(),minpos.end(),0);
    iota(maxpos.begin(),maxpos.end(),0);
    
    for(int i = 0; i < m;i++){
        a[i]--;
        minpos[a[i]] = 0;
    }
    
    int base = max(n,m) + 10;
    BIT bit(base*2);
    vector<int> pos(n);
    for(int i = 0; i < n;i++){
        pos[i] = base + i;
        bit.add(base+i,1);
    }
    
    for(int i = 0; i < m;i++){
        maxpos[a[i]] = max(maxpos[a[i]],(int)bit.sum(pos[a[i]]-1));
        bit.add(pos[a[i]],-1);
        pos[a[i]] = base-1-i;
        bit.add(pos[a[i]],1);
    }
    for(int i = 0; i < n;i++){
        maxpos[i] = max(maxpos[i],(int)bit.sum(pos[i]-1));
    }
    for(int i = 0; i < n;i++){
        cout << minpos[i] + 1 << " " << maxpos[i] + 1 << endl;
    }
    
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve(0);
    // cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
