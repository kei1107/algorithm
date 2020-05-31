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
 <url:https://codeforces.com/problemset/problem/1354/E>
 問題文============================================================
 E. Graph Coloring
 =================================================================
 解説=============================================================
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int n,m; cin >> n >> m;
    int n1,n2,n3; cin >> n1 >> n2 >> n3;
    vector<vector<int>> G(n);
    for(int i = 0; i < m;i++){
        int u,v; cin >> u >> v;
        u--; v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    vector<int> parity(n,-1);
    vector<pii> parity_num;
    vector<set<int>> parity_g;
    vector<int> roots;
    
    bool ng = false;
    function<void(int,int)> dfs = [&](int now,int now_parity){
        if(ng) return;
        
        if(now_parity == 0) parity_num.rbegin()->first++;
        else parity_num.rbegin()->second++;
        
        parity_g.rbegin()->insert(now);
        parity[now] = now_parity;
        int next_parity = !now_parity;
        for(int next:G[now]){
            if(parity[next] == -1){
                dfs(next,next_parity);
            }else{
                if(parity[next] != next_parity){
                    ng = true;
                }
            }
            if(ng) return;
        }
    };
    for(int root = 0; root < n;root++){
        if(parity[root] != -1) continue;
        parity_num.emplace_back(0,0);
        roots.emplace_back(root);
        parity_g.emplace_back();
        dfs(root,0);
    }
    
    if(ng) {
        cout << "NO" << endl;
        return res;
    }
    
    int sz = (int)roots.size();
    
    auto dp = make_v<int>(sz+1,n+1);
    
    dp[0][0] = true;
    for(int i = 0; i < sz;i++){
        for(int j = 0; j <= n;j++){
            if(!dp[i][j]) continue;
            // assert(j+parity_num[i].first <= n);
            dp[i+1][j+parity_num[i].first]  |= dp[i][j];
            // assert(j+parity_num[i].second <= n);
            dp[i+1][j+parity_num[i].second] |= dp[i][j];
        }
    }
    if(!dp[sz][n2]){
        cout << "NO" << endl;
        return res;
    }
    
    string ans(n,'#');
    
    
    auto assign = [&](int t,bool reverse_flag){
        for(auto v:parity_g[t]){
            if(reverse_flag){
                if(parity[v] == 1){
                    ans[v] = '2';
                    n2--;
                }else{
                    if(n1){
                        ans[v] = '1';
                        n1--;
                    }else{
                        ans[v] = '3';
                        n3--;
                    }
                }
            }else{
                if(parity[v] == 0){
                    ans[v] = '2';
                    n2--;
                }else{
                    if(n1){
                        ans[v] = '1';
                        n1--;
                    }else{
                        ans[v] = '3';
                        n3--;
                    }
                }
            }
        }
    };
    
    int now_parity_num = n2;
    for(int i = sz-1; i >= 0; i--){

        if(now_parity_num-parity_num[i].first >= 0 && dp[i][now_parity_num-parity_num[i].first]){
            assign(i,false);
            now_parity_num -= parity_num[i].first;
        }else if(now_parity_num-parity_num[i].second >= 0 && dp[i][now_parity_num-parity_num[i].second]){
            assign(i,true);
            now_parity_num -= parity_num[i].second;
        }
    }
    
    cout << "YES" << endl;
    cout << ans << endl;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve(0);
    // cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
