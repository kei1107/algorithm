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
 <url:https://codeforces.com/problemset/problem/1364/D>
 問題文============================================================
 D. Ehab's Last Corollary
 =================================================================
 解説=============================================================
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int n,m,k; cin >> n >> m >> k;
    vector<vector<int>> G(n);
    for(int i = 0; i < m;i++){
        int u,v; cin >> u >> v;
        u--; v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    
    if(m == n-1){ // グラフが木である場合
        
        int tk = (k+1)/2;
        vector<int> parity(n,-1);
        function<void(int,int,int)> dfs = [&](int n,int pre,int state){
            parity[n] = state;
            for(auto next:G[n]){
                if(next == pre) continue;
                dfs(next,n,!state);
            }
        };
        dfs(0,-1,0);
        
        size_t zero_cnt = count(parity.begin(),parity.end(),0);
        size_t one_cnt = n-zero_cnt;
        
        int t_parity = one_cnt >= zero_cnt;
        cout << 1 << endl;
        for(int i = 0; i < n;i++){
            if(tk && parity[i]==t_parity){
                cout << i+1 << " ";
                tk--;
            }
        }cout << endl;
    }else{ // グラフが閉路を持つ場合
        // 単純閉路となる部分グラフを1つ見つける
        vector<int> depth(n,INF);
        int ldep = -1,rdep = -1;
        function<bool(int,int,int)> dfs = [&](int n,int pre,int dep){
            depth[n] = dep;
            int max_dep = -1;
            for(auto next:G[n]){
                if(next == pre) continue;
                if(depth[next] < depth[n]){ // detect
                    max_dep = max(max_dep,depth[next]);
                }
            }
            for(auto next:G[n]){
                if(next == pre) continue;
                if(depth[next] < depth[n] && max_dep == depth[next]){ // detect
                    ldep = depth[next];
                    rdep = depth[n];
                    return true;
                }
                
            }
            
            for(auto next:G[n]){
                if(next == pre) continue;
                if(dfs(next,n,dep+1)) return true;
            }
            
            depth[n] = INF;
            return false;
        };
        dfs(0,-1,0);
        vector<pii> vs;
        for(int i = 0; i < n;i++){
            if(ldep <= depth[i] && depth[i] <= rdep){
                vs.emplace_back(depth[i],i);
            }
        }
        sort(vs.begin(),vs.end());
        // cout << vs << endl;
        
        if(k >= vs.size()){ // 閉路出力
            cout << 2 << endl;
            cout << vs.size() << endl;
            for(auto v:vs) cout << v.second+1 << " ";
            cout << endl;
        }else{ // 安定集合が作れるので作る
            int tk = (k+1)/2;
            cout << 1 << endl;
            for(int i = 0; i < vs.size();i+=2){
                if(tk){
                    cout << vs[i].second+1 << " ";
                    tk--;
                }
            }cout << endl;
        }
    }
    
    
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve(0);
    // cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
