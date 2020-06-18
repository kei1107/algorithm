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
 <url:https://codeforces.com/problemset/problem/1361/B>
 問題文============================================================
 B. Johnny and Grandmaster
 =================================================================
 解説=============================================================
 ================================================================
 */

const ll MOD = 1e9+7;
// a^b % MOD;
ll powmod(ll a,ll b) {ll res=1;a%=MOD;
    for(;b>0;b>>=1){
        if(b&1)res=res*a%MOD;
        a=a*a%MOD;
    }return res;
    
}

template<class Type>
Type solve(Type res = Type()){
    ll n,p; cin >> n >> p;
    
    vector<ll> k(n); for(auto& in:k) cin >> in;
    sort(k.begin(),k.end());
    vector<ll> T = k;
    
    ll sum = 0;
    ll preV = 1e6+10;
    bool ok = false;
    while(T.size()){
        ll t = T.back(); T.pop_back();
        ll diff = preV - t;
        preV = t;
        
        res*=powmod(p,diff);
        res %= MOD;
        
        for(int i = 0; i < min(diff,20LL); i++){
            sum *= p;
            if(sum > 1e6+10){
                ok = true;
                break;
            }
        }
        
        while(k.size() && k.back() == t){
            k.pop_back();
            
            if(ok || sum > 0){
                sum--;
                res += MOD-1;
            }else{
                sum++;
                res++;
            }
            res %=MOD;
        }
    }
    res *= powmod(p,preV);
    res %= MOD;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    int t; cin >> t;
    while(t--) cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
