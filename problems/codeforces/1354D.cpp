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
 <url:https://codeforces.com/problemset/problem/1354/D>
 問題文============================================================
 D. Multiset
 =================================================================
 解説=============================================================
 ================================================================
 */

struct BIT {
    int N;
    vector<int> bit;
    BIT(int N):N(N) {
        /* BITは[1..N]で扱う */
        bit.resize(N + 1, 0);
    }
    
    void add(int x,int val){
        while (x <= N) {
            bit[x] += val;
            x += x & -x;
        }
    }
    int sum(int x){
        int ret = 0;
        if(x == 0) return ret;
        while (x) {
            ret += bit[x];
            x &= (x - 1);
        }
        return (ret);
    }
    // [l,r]
    int sum(int l,int r){
        return sum(r) - sum(l-1);
    }
};
const int MAX_N = 1000000;
template<class Type>
Type solve(Type res = Type()){
    
    BIT bit(MAX_N);
    
    int n,q; cin >> n >> q;
    for(int i = 0; i < n;i++){
        int a; cin >> a;
        bit.add(a,1);
    }
    while(q--){
        int k; cin >> k;
        if(k > 0){
            bit.add(k,1);
        }else{
            k = -k;
            
            int l = 0, r = MAX_N;
            while(r-l>1){
                int m = (l+r)/2;
                
                int sum = bit.sum(m);
                if(sum >= k) r = m;
                else l = m;
            }
            bit.add(r,-1);
        }
    }
    res = 0;
    for(int i = 1; i <= MAX_N; i++){
        if(bit.sum(i,i)) res = i;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
