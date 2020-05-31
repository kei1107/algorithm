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
 <url:https://codeforces.com/problemset/problem/1349/C>
 問題文============================================================
 C. Orac and Game of Life
 =================================================================
 解説=============================================================
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int n,m,t; cin >> n >> m >> t;
    
    vector<vector<ll>> loop_s(n,vector<ll>(m,numeric_limits<ll>::max()));
    vector<vector<char>> masu(n,vector<char>(m));
    for(auto& vec:masu) for(auto& in:vec) cin >> in;
    
    queue<pii> q;
    int dir[4] = {1,0,-1,0};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m;j++){
            bool update = false;
            for(int k = 0; k < 4;k++){
                int ni = i + dir[k];
                int nj = j + dir[k^1];
                if(ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                if(masu[i][j] == masu[ni][nj]) update = true;
            }
            if(update){
                q.emplace(i,j);
                loop_s[i][j] = 0;
            }
        }
    }
    
    while(q.size()){
        int i,j; tie(i,j) = q.front(); q.pop();
        for(int k = 0; k < 4;k++){
            int ni = i + dir[k];
            int nj = j + dir[k^1];
            if(ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
            if(loop_s[ni][nj] > loop_s[i][j] + 1){
                loop_s[ni][nj] = loop_s[i][j] + 1;
                q.emplace(ni,nj);
            }
        }
    }
    
    while(t--){
        int i,j; ll p; cin >> i >> j >> p;
        i--; j--;
        
        if(loop_s[i][j] >= p) cout << masu[i][j] << endl;
        else{
            ll x = (p - loop_s[i][j])%2;
            
            if(x==0) cout << masu[i][j] << endl;
            else{
                if(masu[i][j] == '0') cout << 1 << endl;
                else cout << 0 << endl;
            }
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
