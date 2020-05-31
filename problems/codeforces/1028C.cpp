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
 <url:https://codeforces.com/problemset/problem/1028/C>
 問題文============================================================
 C. Rectangles
 =================================================================
 解説=============================================================
 ================================================================
 */

struct rectangle{
    ll xl,yl,xr,yr;
    
    rectangle():xl(0),yl(0),xr(0),yr(0){}
    rectangle(ll xl,ll yl,ll xr,ll yr):xl(xl),yl(yl),xr(xr),yr(yr){}
    
    rectangle intersect(rectangle t){
        ll xl = max(this->xl,t.xl);
        ll yl = max(this->yl,t.yl);
        ll xr = min(this->xr,t.xr);
        ll yr = min(this->yr,t.yr);
        
        if(xl > xr || yl > yr) return rectangle(LINF,LINF,LINF,LINF);
        return rectangle(xl,yl,xr,yr);
    }
};
template<class Type>
Type solve(Type res = Type()){
    int n; cin >> n;
    vector<ll> xs,ys;
    vector<ll> xl(n),xr(n),yl(n),yr(n);
    vector<rectangle> rect;
    for(int i = 0; i < n;i++){
        cin >> xl[i] >> yl[i] >> xr[i] >> yr[i];
        rect.emplace_back(xl[i],yl[i],xr[i],yr[i]);
    }
    
    vector<rectangle> prefix,suffix;
    prefix.emplace_back(-LINF,-LINF,LINF,LINF);
    suffix.emplace_back(-LINF,-LINF,LINF,LINF);
    
    for(int i = 0; i < n;i++){
        prefix.emplace_back(rect[i].intersect(prefix.back()));
        suffix.emplace_back(rect[n-1-i].intersect(suffix.back()));
    }
    
    for(int i = 0; i <= n;i++){
        if(prefix[i].xl == LINF) continue;
        rectangle trect = prefix[i].intersect(suffix[n-i-1]);
        if(trect.xl == LINF) continue;
        
        cout << trect.xl << " " << trect.yl << endl;
        break;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve(0);
    // cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
