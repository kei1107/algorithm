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
 <url:https://codeforces.com/problemset/problem/1335/E2>
 問題文============================================================
 E2. Three Blocks Palindrome (hard version)
 =================================================================
 解説=============================================================
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int n; cin >> n;
    vector<int> A(n); for(auto& in:A) cin >> in;
    
    auto cusum = make_v<int>(201,n+1);
    for(int i = 0; i < n;i++){
        for(int j = 1; j <= 200; j++){
            cusum[j][i+1] += cusum[j][i];
        }
        cusum[A[i]][i+1]++;
    }
    
    vector<vector<int>> G(201);
    
    for(int i = 0; i < n;i++){
        G[A[i]].emplace_back(i+1);
    }
    for(int a = 1; a <= 200; a++){
        res = max(res,(ll)G[a].size());
        
        int Lid = 0,Rid = (int)G[a].size()-1;
        for(;Lid < Rid; Lid++,Rid--){
            
            int Lind = G[a][Lid];
            int Rind = G[a][Rid];
            
            int Lcnt = Lid+1;
            int a_sum = Lcnt*2;
            
            for(int b = 1; b <= 200; b++){
                if(a==b) continue;
                
                int b_sum = cusum[b][Rind-1] - cusum[b][Lind];
                
                res = max(res,(ll)a_sum+b_sum);
            }
        }
    }
    
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    int t; cin >> t;
    while(t--) cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
