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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1280>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 UFを用いた枝借り全探索で間に合う
 ================================================================
 */

struct edge{
    int u,v,c;
    edge(){}
    edge(int u,int v,int c):u(u),v(v),c(c){}
    bool operator < (const edge& e) const{
        return c < e.c;
    }
};

struct UnionFind {
    vector<int> data;
    UnionFind(int size) : data(size, -1) { }
    bool unionSet(int x, int y) {
        x = root(x); y = root(y);
        if (x != y) {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y]; data[y] = x;
        }
        return x != y;
    }
    bool findSet(int x, int y) {
        return root(x) == root(y);
    }
    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    int size(int x) {
        return -data[root(x)];
    }
};

template<class Type>
Type solve(Type res = Type()){
    int n,m;
    while(cin >> n >> m,n){
        vector<edge> E(m);
        vector<int> C(m);
        for(int i = 0; i < m;i++){
            int u,v,w; cin >> u >> v >> w;
            u--; v--;
            E[i] = edge(u,v,w);
            C[i] = w;
        }
        sort(E.begin(),E.end());
        sort(C.begin(),C.end());
        C.erase(unique(C.begin(),C.end()),C.end());
        
        int ans = INF;
        for(int c:C){
            int l = (int)(lower_bound(E.begin(),E.end(),edge(-1,-1,c))-E.begin());
            UnionFind UF(n);
            for(int r = l; r < m; r++){
                UF.unionSet(E[r].u, E[r].v);
                if(UF.size(0) == n){
                    ans = min(ans,E[r].c - E[l].c);
                    break;
                }
                if(E[r].c - E[l].c >= ans) break;
            }
        }
        cout << (ans==INF?-1:ans) << endl;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve(0);
    // cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
