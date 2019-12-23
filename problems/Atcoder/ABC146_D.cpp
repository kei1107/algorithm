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
 <url:https://atcoder.jp/contests/abc146/tasks/abc146_d>
 問題文============================================================
 D - Coloring Edges on Tree
 =================================================================
 解説=============================================================
 任意の頂点（ex. 1)を根とした木を考える。
 ある頂点nについて着目する。
 頂点nからその親への辺に色xを塗られている時
 子への辺には色xを除いて、色1から順番に色を付けていけばいい
 そして、次に子を着目する頂点にして同様の処理を行なっていけば最適となる。

 これは、根から再帰的に処理を行えるのでO(N)で解ける。
 （辺の管理をmapで行うならば計算量がもう少し増えるが十分間に合う）

 https://atcoder.jp/contests/abc146/submissions/9099848
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int N; cin >> N;
    vector<vector<int>> G(N);
    vector<pii> edges;
    for(int i = 0; i < N-1;i++){
        int a,b; cin >> a >> b;
        a--; b--;

        G[a].push_back(b);
        G[b].push_back(a);
        edges.push_back(pii(a,b));

    }

    int M = -1;
    map<pii,int> mp;
    function<void(int,int)> rec = [&](int n,int pre){
        set<int> st;
        for(int next:G[n]){
            if(next == pre) continue;
            if(mp[pii(min(n,next),max(n,next))]) st.insert(mp[pii(min(n,next),max(n,next))]);
        }

        int ng = mp[pii(min(n,pre),max(n,pre))];
        int num = 1;
        for(int next:G[n]){
            if(next == pre) continue;
            if(ng == num) num++;

            M = max(M,num);
            mp[pii(min(n,next),max(n,next))] = num;
            num++;
            rec(next,n);
        }
        return;
    };
    rec(0,-1);

    cout << M << endl;
    for(auto e:edges){
        cout << mp[pii(e.first,e.second)] << endl;
    }

    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve(0);
    // cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
