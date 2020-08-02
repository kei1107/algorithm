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
 <url:https://codeforces.com/problemset/problem/1280/C>
 問題文============================================================
 C. Jeremy Bearimy
 =================================================================
 解説=============================================================
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int k; cin >> k;
    int n = 2*k;
    vector<vector<pll>> T(n);
    for(int i = 0; i < n-1;i++){
        int a,b,t; cin >> a >> b >> t;
        a--; b--;
        T[a].emplace_back(b,t);
        T[b].emplace_back(a,t);
    }
    
    vector<int> num(n);
    function<int(int,int)> dfs1 = [&](int now,int par){
        num[now] = 1;
        for(auto& e:T[now]){
            ll next;
            tie(next,ignore) = e;
            if(next == par) continue;
            num[now] += dfs1(next,now);
        }
        return num[now];
    };
    dfs1(0,-1);
    // cout << num << endl;
    
    ll G = 0,B = 0;
    function<void(int,int)> dfs2 = [&](int now,int par){
        for(auto& e:T[now]){
            ll next,cost;
            tie(next,cost) = e;
            if(next == par) continue;
            
            ll min_v = min(num[next],n-num[next]);
            // cout << now << " : " << min_v << endl;
            if(min_v%2 == 1) G += cost;
            B += min_v*cost;
            
            dfs2(next,now);
        }
    };
    dfs2(0,-1);
    cout << G << " " << B << endl;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve(0);
    // cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
