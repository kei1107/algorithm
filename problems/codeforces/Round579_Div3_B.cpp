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
 <url:https://codeforces.com/contest/1203/problem/B>
 問題文============================================================
 =================================================================
 解説=============================================================
 長さ順に棒を並べたのち
 両端から2個ずつ取っていくのが最適
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    map<int,int> mp;
    int n; cin >> n;
    for(int i = 0; i < 4*n;i++){
        int a; cin >> a;
        mp[a]++;
    }
    
    bool ok = true;
    for_each(mp.begin(),mp.end(),[&](const pii& v){
        if(v.second%2) ok = false;
    });
    if(!ok) return "NO";
    
    vector<pii> as(mp.begin(),mp.end());
    int l = 0, r = (int)as.size()-1;
    
    int area = as[l].first * as[r].first;
    as[l].second -= 2;
    as[r].second -= 2;
    while(true){
        if(as[l].second == 0) l++;
        if(as[r].second == 0) r--;
        if(l > r){
            break;
        }
        if(area != as[l].first * as[r].first) return "NO";
        as[l].second -= 2;
        as[r].second -= 2;
        
    }
    return "YES";
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    int q; cin >> q;
    while(q--){
        cout << fixed << setprecision(15) << solve<string>() << endl;
    }
    return 0;
}
