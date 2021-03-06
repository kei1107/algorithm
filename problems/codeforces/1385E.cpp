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
 <url:https://codeforces.com/problemset/problem/1385/E>
 問題文============================================================
 E. Directing Edges
 =================================================================
 解説=============================================================
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int n,m; cin >> n >> m;
    vector<vector<int>> G(n);
    vector<pii> edges;
    for(int i = 0; i < m;i++){
        int t,x,y; cin >> t >> x >> y;
        x--; y--;
        if(t == 1){
            G[x].emplace_back(y);
        }
        edges.emplace_back(x,y);
    }
    
    vector<int> tsort,visit(n);
    function<void(int)> dfs = [&](int u){
        visit[u] = true;
        for(auto& v:G[u]){
            if(!visit[v]) dfs(v);
        }
        tsort.emplace_back(u);
    };
    for(int u = 0; u < n;u++){
        if(!visit[u]) dfs(u);
    }
    reverse(tsort.begin(),tsort.end());
    
    vector<int> pos(n);
    for(int i = 0; i < n;i++){
        pos[tsort[i]] = i;
    }
    bool ng = false;
    for(int u = 0; u < n;u++){
        for(auto& v:G[u]){
            if(pos[u] > pos[v]){
                ng = true;
            }
        }
    }
    if(ng){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
        
        for(auto p:edges){
            int x,y; tie(x,y) = p;
            
            if(pos[x] < pos[y]){
                cout << x+1 << " " << y+1 << endl;
            }else{
                cout << y+1 << " " << x+1 << endl;
            }
        }
    }
    
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve(0);
    
    // cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
