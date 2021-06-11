#include "bits/stdc++.h"
#include "atcoder/all"
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
 <url:https://atcoder.jp/contests/typical90/tasks/typical90_bg>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */


template<class Type>
Type solve(Type res = Type()){
    int N,M,Q; cin >> N >> M >> Q;
    vector<vector<int>> G(N);
    vector<vector<int>> rG(N);
    for(int i = 0; i < M;i++){
        int X,Y; cin >> X >> Y;
        X--; Y--;
        G[X].emplace_back(Y);
        rG[Y].emplace_back(X);
    }
    for(int i = 0; i < N;i++){
        sort(G[i].begin(),G[i].end());
        G[i].erase(unique(G[i].begin(),G[i].end()),G[i].end());
        sort(rG[i].begin(),rG[i].end());
        rG[i].erase(unique(rG[i].begin(),rG[i].end()),rG[i].end());
    }    
    vector<int> A(Q),B(Q);
    for(int i = 0; i < Q;i++){
        cin >> A[i] >> B[i];
        A[i]--; B[i]--;
    }

    for(int i = 0; i * 64 < Q; i++){
        vector<unsigned long long> dp(N,0);
        for(int j = i * 64; j < (i+1)*64 && j < Q; j++){
            dp[A[j]] |= 1ULL << (j-i*64);
        }
        for(int v = 0; v < N; v++){
            for(auto u : rG[v]){
                dp[v] |= dp[u];
            }
        }
        for(int j = i * 64; j < (i+1)*64 && j < Q; j++){
            cout << (((dp[B[j]] >> (j-i*64))&1)&1? "Yes" : "No") << endl;
        }

    }
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    solve<ll>(0);
    // cout << fixed << setprecision(12) << solve<ll>() << endl;
    return 0;
}