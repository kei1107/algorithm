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
 <url:https://codeforces.com/problemset/problem/1307/D>
 問題文============================================================
 D. Cow and Fields
 =================================================================
 解説=============================================================
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int n,m,k; cin >> n >> m >> k;
    vector<int> a(k);
    for(auto& in:a) {cin >> in; in--;}
    vector<vector<int>> G(n);
    
    for(int i = 0; i < m;i++){
        int x,y; cin >> x >> y;
        x--; y--;
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }
    
    vector<ll> dist(n,INF);
    dist[0] = 0;
    queue<int> q;
    q.emplace(0);
    while(q.size()){
        int n; tie(n) = q.front(); q.pop();
        
        for(auto next:G[n]){
            if(dist[next] > dist[n] + 1){
                dist[next] = dist[n] + 1;
                q.emplace(next);
            }
        }
    }
    vector<ll> rdist(n,INF);
    rdist[n-1] = 0;
    q.emplace(n-1);
    while(q.size()){
        int n; tie(n) = q.front(); q.pop();
        for(auto next:G[n]){
            if(rdist[next] > rdist[n] + 1){
                rdist[next] = rdist[n] + 1;
                q.emplace(next);
            }
        }
    }
    
    
    vector<pii> D;
    for(int i = 0; i < k; i++){
        D.emplace_back(dist[a[i]],a[i]);
    }
    sort(D.begin(),D.end());
    
    res = dist[n-1];
    
    ll maxd = 0;
    for(int i = 1; i < k; i++){
        int u = D[i-1].second;
        int v = D[i].second;
        
        // cout << min(dist[u]+1+rdist[v],dist[v]+1+rdist[u]) << endl;
        maxd = max(maxd,min(dist[u]+1+rdist[v],dist[v]+1+rdist[u]));
    }
    res = min(res,maxd);
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
