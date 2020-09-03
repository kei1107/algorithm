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
 <url:https://codeforces.com/problemset/problem/1267/K>
 問題文============================================================
 K. Key Storage
 =================================================================
 解説=============================================================
 ================================================================
 */

ll calc(vector<ll>& fingerprint){
    int sz = (int)fingerprint.size();
    ll T = 1;
    for(int i = 2; i <= sz+1; i++){
        int cnt = 0;
        for(int j = 0; j < sz;j++){
            if(fingerprint[j] < i) cnt++;
        }
        T*=(cnt-i+2);
    }
    ll U = 0;
    for(int i = 0; i < sz;i++){
        if(i == 0 || fingerprint[i]!=fingerprint[i-1]) U=1;
        else U++;
        T/=U;
    }
    return T;
}
template<class Type>
Type solve(Type res = Type()){
    ll k; cin >> k;

    vector<ll> fingerprint;
    ll x = 2;
    while(k){
        fingerprint.emplace_back(k%x);
        k/=x++;
    }
    sort(fingerprint.begin(),fingerprint.end());
    res = calc(fingerprint);
    if(*fingerprint.begin() == 0){ 
        fingerprint.erase(fingerprint.begin());
        res -= calc(fingerprint);
    }
    res -= 1;
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    //solve<ll>(0);
    int t; cin >> t; while(t--)
    cout << fixed << setprecision(12) << solve<ll>() << endl;
    return 0;
}