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
 <url:https://codeforces.com/problemset/problem/1363/E>
 問題文============================================================
 E. Tree Shuffling
 =================================================================
 解説=============================================================
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int N; cin >> N;
    vector<int> a(N),b(N),c(N);
    for(int i = 0; i < N;i++) cin >> a[i] >> b[i] >> c[i];
    vector<vector<int>> G(N);
    for(int i = 0; i < N-1;i++){
        int u,v; cin >> u >> v;
        u--; v--;
        
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    vector<int> b_one(N),c_one(N);
    vector<int> par(N);
    function<void(int,int)> pre_dfs = [&](int n,int pre){
        par[n] = pre;
        for(auto next:G[n]){
            if(next == par[n]) continue;
            pre_dfs(next,n);
            
            b_one[n] += b_one[next];
            c_one[n] += c_one[next];
        }
        
        if(b[n] == c[n]) return;
        if(b[n]) b_one[n]+=b[n];
        if(c[n]) c_one[n]+=c[n];
    };
    pre_dfs(0,-1);
    if(b_one[0] != c_one[0]) return -1;
    
    vector<pll> target_a(N);
    for(int i = 0; i < N;i++){
        target_a[i] = pll(a[i],i);
    }
    sort(target_a.begin(),target_a.end());
    
    vector<bool> visited(N);
    for(auto p:target_a){
        ll A,id; tie(A,id) = p;
        if(visited[id]) continue;
        int  L = 0,R = 0;
        function<void(ll)> dfs = [&](ll n){
            visited[n] = true;
            for(auto next:G[n]){
                if(next == par[n]) continue;
                
                if(visited[next]){
                    L += b_one[next] - min(b_one[next],c_one[next]);
                    R += c_one[next] - min(b_one[next],c_one[next]);
                }else{
                    dfs(next);
                }
            }
            if(b[n] == c[n]) return;
            if(b[n]) L++;
            if(c[n]) R++;
        };
        dfs(id);
        res += A*min(L,R)*2;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
