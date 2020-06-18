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
 <url:https://codeforces.com/problemset/problem/1360/H>
 問題文============================================================
 H. Binary Median
 =================================================================
 解説=============================================================
 ================================================================
 */

#include <bitset>

template<class T> void printb(T v) {
  std::cout << std::bitset<sizeof(v) * CHAR_BIT>(v);
}

template<class T> void putb(T v) {
  std::cout << "0b"; printb(v); std::cout << std::endl;
}
template<class Type>
Type solve(Type res = Type()){
    int n,m; cin >> n >> m;
    vector<ll> bs(n);
    for(int i = 0; i < n;i++){
        string b; cin >> b;
        bs[i] = stoll(b.c_str(),0LL,2);
    }
    sort(bs.begin(),bs.end());
    set<ll> st(bs.begin(),bs.end());
    
    ll k = (1LL<<m) - n;
    for(ll x = max(0LL,(1LL<<m)/2 - 300); x <= min((1LL<<m)-1,(1LL<<m)/2 + 300); x++){
        if(st.find(x) != st.end()) continue;
        
        ll id = x - (lower_bound(bs.begin(),bs.end(),x) - bs.begin());
        if((k-1)/2 == id){
            for(int i = m-1; i >= 0; i--){
                res += (char)(((x>>i)&1) + '0');
            }
            break;
        }
    }
    assert(res.length() != 0);
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    int t; cin >> t;
    while(t--) cout << fixed << setprecision(15) << solve<string>() << endl;
    return 0;
}
