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
 <url:https://codeforces.com/problemset/problem/1329/A>
 問題文============================================================
 A. Dreamoon Likes Coloring
 =================================================================
 解説=============================================================
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int n,m; cin >> n >> m;
    vector<int> p(m); for(auto& in:p) cin >> in;
    
    Type ans(m);
    int maxp = -1;
    for(int i = 0; i < m;i++){
        ans[i] = i+1;
        maxp = max(maxp,i+p[i]);
        if(i+p[i] > n){
            return Type{-1};
        }
    }
    vector<int> maxps(m+1,-1);
    for(int i = m-1; i >= 0; i--){
        maxps[i] = max(i+p[i],maxps[i+1]);
    }
    int add = 0;
    for(int i = 0; i < m;i++){
        ans[i] += add;
        if(i != m-1) add += min(n-(maxps[i+1]+add),p[i]-1);
    }
    
    bool ok = false;
    for(int i = 0; i < m;i++){
        if(ans[i]-1+p[i] == n) ok = true;
    }
    if(!ok) return Type{-1};
    res = ans;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<vector<int>>() << endl;
    return 0;
}
