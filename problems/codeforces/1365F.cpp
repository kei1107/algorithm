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
 <url:https://codeforces.com/problemset/problem/1365/F>
 問題文============================================================
 F. Swaps Again
 =================================================================
 解説=============================================================
 交換を行っても要素の位置関係は保たれる
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int n; cin >> n;
    vector<int> a(n),b(n);
    for(auto& in:a) cin >> in;
    for(auto& in:b) cin >> in;

    if(n%2 == 1){
        if(a[n/2] != b[n/2]) return "No";
    }
    map<pii,int> mpa,mpb;
    for(int i = 0; i < n;i++){
        int j = n-1-i;
        if(i >= j) break;
        if(a[i] > a[j]) swap(a[i],a[j]);
        mpa[pii(a[i],a[j])]++;
        if(b[i] > b[j]) swap(b[i],b[j]);
        mpb[pii(b[i],b[j])]++;
    }
    // cout << mpa << " " << mpb << endl;
    return mpa == mpb ? "Yes":"No";
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    //solve<ll>(0);
    int t; cin >> t; while(t--)
    cout << fixed << setprecision(12) << solve<string>() << endl;
    return 0;
}
