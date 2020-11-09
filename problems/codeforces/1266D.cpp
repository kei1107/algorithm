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
 <url:https://codeforces.com/problemset/problem/1266/D>
 問題文============================================================
 D. Decreasing Debts
 =================================================================
 解説=============================================================
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int n,m; cin >> n >> m;
    vector<ll> ds(n);

    for(int i = 0; i < m;i++){
        ll u,v,d; cin >> u >> v >> d;
        u--; v--;
        ds[u] += d;
        ds[v] -= d;
    }

    vector<ll> x,y;
    for(int i = 0; i < n;i++){
        if(ds[i] > 0){
            x.emplace_back(i);
        }else if(ds[i] < 0){
            y.emplace_back(i);
            ds[i] = -ds[i];
        }
    }

    using Item = tuple<ll,ll,ll>;
    vector<Item> ans;

    while(x.size() && y.size()){
        ll a = x.back(), b = y.back();

        ll d = min(ds[a],ds[b]);

        ans.emplace_back(a+1,b+1,d);

        ds[a] -= d; ds[b] -= d;

        if(ds[a] == 0) x.pop_back();
        if(ds[b] == 0) y.pop_back();        
    }

    cout << ans.size() << endl;
    for(int i = 0; i < (int)ans.size();i++){
        ll u,v,d; tie(u,v,d) = ans[i];
        cout << u << " " << v << " " << d << endl;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    solve<ll>(0);
    // cout << fixed << setprecision(12) << solve<ll>() << endl;
    return 0;
}