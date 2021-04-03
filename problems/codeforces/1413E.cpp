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
template<class T> ostream& operator << (ostream& out,const vector<T>& V){ for(size_t i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> >& Mat){ for(size_t i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T>& mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }
template<typename T>vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}
/*
 <url:https://codeforces.com/problemset/problem/1413/E>
 問題文============================================================
 E. Solo mid Oracle
 =================================================================
 解説=============================================================
 ================================================================
 */

void simulate(ll a,ll b,ll c,ll d){
    cout << " ====================== " << endl;
    vector<pll> hs[2];
    int cur = 0,next = 1;
    ll total_damage = 0;
    for(int step = 0; step <= 1000; step++){
        for(auto& p:hs[cur]){
            total_damage -= p.first;
            if(--p.second){
                hs[next].emplace_back(p.first,p.second);
            }
        }
        hs[cur].clear();
        if(step%d == 0){
            total_damage += a;
            hs[next].emplace_back(b,c);
        }
        swap(cur,next);
        if(step%d == 0){
            cout << "step " << step << " : " << total_damage << endl;
        }
    }
}
template<class Type>
Type solve(Type res = Type()){
    ll a,b,c,d; cin >> a >> b >> c >> d;
    // simulate(a,b,c,d); return res;    
    if(a > b*c) return -1;

    auto calc = [&](ll k){
        return a*(k+1) - k*(k+1)/2*b*d;
    };
    ll l = 0, r = c/d;
    while(r-l>2){
        ll ml = (2*l+r)/3;
        ll mr = (l+2*r)/3;

        if(calc(ml) < calc(mr)){
            l = ml;
        }else{
            r = mr;
        }
    }
    for(ll k = l; k <= r; k++) res = max(res,calc(k));
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);

    //solve<ll>(0);
    int t; cin >> t; 
    while(t--) cout << fixed << setprecision(12) << solve<ll>() << endl;
    return 0;
}