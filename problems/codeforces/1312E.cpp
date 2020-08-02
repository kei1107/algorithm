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
 <url:https://codeforces.com/problemset/problem/1312/E>
 問題文============================================================
 E. Array Shrinking
 =================================================================
 解説=============================================================
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int n; cin >> n;
    vector<int> a(n); for(auto& in:a) cin >>in;
    
    auto sec = make_v<int>(2001,n+1);
    fill_v(sec,-1);
    for(int i = 0; i < n;i++){
        sec[a[i]][i] = i;
    }
    for(int x = 0; x < 2000; x++){
        for(int l = 0; l < n;l++){
            int m = sec[x][l];
            if(m == -1) continue;
            int r = sec[x][sec[x][l]+1];
            if(r == -1) continue;
            sec[x+1][l] = r;
        }
    }
    auto memo = make_v<int>(n);
    fill_v(memo,-1);
    function<int(int)> dfs = [&](int i){
        if(i >= n) return 0;
        if(~memo[i]) return memo[i];
        memo[i] = INF;
        for(int x = 0; x < 2000; x++){
            if(sec[x][i] == -1) continue;
            memo[i] = min(memo[i],dfs(sec[x][i]+1)+1);
        }
        return memo[i];
    };
    res = dfs(0);
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
