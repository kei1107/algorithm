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
 <url:https://codeforces.com/problemset/problem/1303/D>
 問題文============================================================
 D. Fill The Bag
 =================================================================
 解説=============================================================
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    ll n,m; cin >> n >> m;
    vector<ll> a(m); for(auto& in:a) cin >> in;
    sort(a.rbegin(),a.rend());
    
    ll suma = accumulate(a.begin(),a.end(),0LL);
    if(suma < n) return -1;
    
    vector<int> pow2(61);
    for(int i = 0; i < m;i++){
        pow2[__builtin_ctzll(a[i])]++;
    }
    // cout << pow2 << endl;
    
    int i = 0;
    while(i < 60){
        if((n>>i)&1){
            if(pow2[i]){
                pow2[i]--;
            }else{
                while(i<60 && pow2[i]==0){
                    i++;
                    res++;
                }
                pow2[i]--;
                continue;
            }
        }
        pow2[i+1] += pow2[i]/2;
        i++;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    int t; cin >> t; while(t--)
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
