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
 <url:https://codeforces.com/problemset/problem/1366/E>
 問題文============================================================
 E. Two Arrays
 =================================================================
 解説=============================================================
 ================================================================
 */

const ll MOD = 998244353;
template<class Type>
Type solve(Type res = Type()){
    int n,m; cin >> n >> m;
    vector<int> a(n),b(m);
    for(auto& in:a) cin >> in;
    for(auto& in:b) cin >> in;
    b.emplace_back(numeric_limits<int>::max());

    vector<pii> bsec_id(m,make_pair(INF,-INF));
    vector<vector<int>> b_id(m);

    for(int i = 0; i < n;i++){
        int id = (int)(lower_bound(b.begin(),b.end(),a[i]) - b.begin());

        if(b[id] == a[i]){
            b_id[id].emplace_back(i);
            bsec_id[id] = make_pair(min(bsec_id[id].first,i),max(bsec_id[id].second,i));
        }else{
            id--;
            if(id < 0){ // none
                return 0;
            }
            bsec_id[id] = make_pair(min(bsec_id[id].first,i),max(bsec_id[id].second,i));
        }
    }
    //cout << b_id << endl;
    //cout << bsec_id << endl;
    
    for(int i = 0; i < m;i++){
        if(b_id[i].empty()) return 0;
    }

    res = 1;
    ll L = bsec_id[0].second;
    for(int i = 1; i < m;i++){
        if(L >= b_id[i].back()) return 0;
        ll M = b_id[i].back();
        res *= (M-L);
        res %= MOD;
        L = bsec_id[i].second;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    //solve<ll>(0);
    cout << fixed << setprecision(12) << solve<ll>() << endl;
    return 0;
}