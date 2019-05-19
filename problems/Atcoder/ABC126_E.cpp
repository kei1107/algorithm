#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T>& V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> >& Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T>& mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }
template<typename T>vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}
/*
 <url:https://atcoder.jp/contests/abc126/tasks/abc126_e>
 問題文============================================================
 =================================================================
 解説=============================================================
 問題を整理すると互いに行き来できる頂点集合の個数はいくつか？になるので書く
 ================================================================
 */

void rec(ll n,vector<int>& visited,vector<vector<ll>>& G){
    if(visited[n]) return;
    visited[n] = true;
    for(auto next:G[n]){
        rec(next,visited,G);
    }
}
template<class Type>
Type solve(Type res = Type()){
    ll N,M; cin >> N >> M;
    vector<vector<ll>> G(N);
    vector<ll> X(M),Y(M),Z(M);
    vector<int> visited(N);
    for(int i = 0; i < M;i++){
        cin >> X[i] >> Y[i] >> Z[i];
        X[i]--;Y[i]--;
        Z[i]%=2;
        G[X[i]].push_back(Y[i]);
        G[Y[i]].push_back(X[i]);
    }
    for(ll i = 0; i < N;i++){
        if(visited[i]) continue;
        res++;
        rec(i,visited,G);
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
