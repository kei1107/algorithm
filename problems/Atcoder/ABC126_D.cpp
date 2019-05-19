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
 <url:https://atcoder.jp/contests/abc126/tasks/abc126_d>
 問題文============================================================
 =================================================================
 解説=============================================================
 根を0として根から偶数距離の点を全て0、他を1にすればok
 ================================================================
 */

struct edge{
    ll u,v,w;
    edge(){};
    edge(ll u,ll v ,ll w):u(u),v(v),w(w){}
};

vector<vector<edge>> G;
vector<int> color;

void rec(ll n,ll len,ll pre){
    if(len%2 == 0) color[n] = 0;
    for(auto e:G[n]){
        if(e.v == pre) continue;
        rec(e.v,len+e.w,n);
    }
}
template<class Type>
Type solve(Type res = Type()){
    ll N; cin >> N;
    G.resize(N);
    color.resize(N);
    fill(color.begin(),color.end(),1);

    for(int i = 0; i < N-1;i++){
        ll u,v,w; cin >> u >> v >> w;
        u--; v--;
        G[u].emplace_back(u,v,w);
        G[v].emplace_back(v,u,w);
    }
    rec(0,0,-1);

    for(int i = 0; i < N;i++){
        cout << color[i] << endl;
    }


    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve(0);
    //cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
