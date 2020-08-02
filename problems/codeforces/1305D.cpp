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
 <url:https://codeforces.com/problemset/problem/1305/D>
 問題文============================================================
 D. Kuroni and the Celebration
 =================================================================
 解説=============================================================
 ================================================================
 */


int query(int u,int v){
    int ret;
    cout << "? " << u << " " << v << endl;
    cin >> ret;
    if(ret == -1) exit(0);
    return ret;
}
void ans(int x){
    cout << "! " << x << endl;
    return;
}
template<class Type>
Type solve(Type res = Type()){
    int n; cin >> n;
    vector<set<int>> G(n+1);
    for(int i = 0; i < n-1;i++){
        int x,y; cin >> x >> y;
        G[x].insert(y);
        G[y].insert(x);
    }
    
    auto find_diameter = [&G,&n](int root){
        queue<int> q;

        vector<int> dist1(n+1,INF);
        dist1[root] = 0;
        q.emplace(root);
        while(q.size()){
            int u = q.front(); q.pop();
            for(auto& v:G[u]){
                if(dist1[v] > dist1[u] + 1){
                    dist1[v] = dist1[u] + 1;
                    q.emplace(v);
                }
            }
        }
        replace(dist1.begin(),dist1.end(),INF,-1);
        
        int s = (int)(max_element(dist1.begin(), dist1.end()) - dist1.begin());
        
        vector<int> dist2(n+1,INF);
        dist2[s] = 0;
        q.emplace(s);
        while(q.size()){
            int u = q.front(); q.pop();
            for(auto& v:G[u]){
                if(dist2[v] > dist2[u] + 1){
                    dist2[v] = dist2[u] + 1;
                    q.emplace(v);
                }
            }
        }
        replace(dist2.begin(),dist2.end(),INF,-1);
        
        int t = (int)(max_element(dist2.begin(), dist2.end()) - dist2.begin());
        
        return make_pair(s, t);
    };
    
    auto delete_edge = [&G](int lca,int s,int t){
        function<bool(int,int)> dfs = [&](int n,int pre){
            if(n == s || n == t) return true;
            for(auto& next:G[n]){
                if(next == pre) continue;
                if(dfs(next,n)) return true;
            }
            return false;
        };
        
        vector<int> del_u;
        for(auto& u:G[lca]){
            if(dfs(u,lca)){
                del_u.emplace_back(u);
            }
        }
        for(auto& u:del_u) G[lca].erase(u);
    };
    
    int lca = 1;
    while(true){
        // 木の直径の端点を探す
        int s,t; tie(s,t) = find_diameter(lca);
        if(s == t) {ans(s); break; }
        
        lca = query(s,t);
        
        delete_edge(lca,s,t);
    }
    
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve(0);
    // cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
