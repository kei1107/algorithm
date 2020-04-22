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
 <url:https://atcoder.jp/contests/abc163/tasks/abc163_f>
 問題文============================================================
 F - path pass i
 =================================================================
 解説=============================================================
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    ll N; cin >> N;
    vector<ll> c(N); for(auto& in:c){ cin >> in; in--;}
    
    vector<vector<ll>> G(N);
    for(int i = 0; i < N-1; i++){
        ll a,b; cin >> a >> b;
        a--; b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    
    vector<ll> num(N),S(N);
    vector<ll> ans(N,N*(N-1)/2);
    ll sum = 0;
    function<ll(ll,ll)> dfs = [&](ll v,ll p){
        S[v]=1;
        
        ll t = num[c[v]];
        for(auto next:G[v]){
            if(next == p) continue;
            ll prev = sum - num[c[v]];
            S[v] += dfs(next,v);
            ll nextv = sum - num[c[v]];
            ans[c[v]] -= (nextv - prev)*(nextv - prev - 1)/2;
        }
        num[c[v]] = t + S[v];
        sum++;
        return S[v];
    };
    dfs(0,-1);
    
    for(int i = 0; i < N;i++){
        ll prev = 0, nextv = N-num[i];
        ans[i] -= (nextv - prev)*(nextv - prev - 1)/2;
    }
    for(auto t:c) ans[t]++;
    
    for(auto a:ans) cout << a << endl;
    
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve(0);
    // cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
