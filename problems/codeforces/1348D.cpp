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
 <url:https://codeforces.com/problemset/problem/1348/D>
 問題文============================================================
 D. Phoenix and Science
 =================================================================
 解説=============================================================
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    ll n; cin >> n;
    
    ll l = 0, r = sqrt(n)+1;
    
    auto check = [&](ll m){
        ll now = m+1;
        ll bac_num = 1;
        for(int i = 0; i < m;i++){
            ll left = n - now;
            if(left < 0) continue;
            ll get = m-i;
            ll cnt = min(bac_num,left/get);
            
            now += cnt*get;
            bac_num += cnt;
        }
        return now == n;
    };
    while(r-l>1){
        ll m = (l+r)/2;
        if(check(m)) r = m;
        else l = m;
    }
    ll m = r;
    vector<ll> ret(m);
    ll now = m+1;
    ll bac_num = 1;
    for(int i = 0; i < m;i++){
        ll left = n - now;
        if(left < 0) continue;
        ll get = m-i;
        ll cnt = min(bac_num,left/get);
        
        now += cnt*get;
        bac_num += cnt;
        ret[i] = cnt;
    }
    cout << ret.size() << endl;
    cout << ret << endl;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve(0);

    return 0;
}
