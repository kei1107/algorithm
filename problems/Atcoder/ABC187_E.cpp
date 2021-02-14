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
 <url:https://atcoder.jp/contests/abc187/tasks/abc187_e>
 問題文============================================================
 =================================================================
 解説=============================================================
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
        G[a].emplace_back(b); G[b].emplace_back(a);
        edges.emplace_back(a,b);
    }

    vector<pii> ET(N);

    auto dfs = [&](auto self,int n,int pre,int& id) -> void{
        ET[n].first = id++;

        for(auto next:G[n]){
            if(next == pre) continue;
            self(self,next,n,id);
        }

        ET[n].second = id++;
    };
    int id = 0;
    dfs(dfs,0,-1,id);

    // cout << ET << endl;

    vector<ll> imos(id+1);

    int Q; cin >> Q;
    while(Q--){
        int t,e,x; cin >> t >> e >> x;
        e--;

        auto [a,b] = edges[e];
        if(t == 2) swap(a,b);

        if(ET[a].first < ET[b].first){
            imos[0]  += x;
            imos[id] -= x;

            imos[ET[b].first] -= x;
            imos[ET[b].second+1] += x;
        }else{
            imos[ET[a].first] += x;
            imos[ET[a].second+1] -= x;
        }
    }
    for(int i = 0; i < id;i++){
        imos[i+1] += imos[i];
    }

    for(int i = 0; i < N;i++){
        cout << imos[ET[i].first] << endl;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    solve<ll>(0);
    // cout << fixed << setprecision(12) << solve<ll>() << endl;
    return 0;
}