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
 <url:https://atcoder.jp/contests/abc132/tasks/abc132_e>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 dist[i][j] := 頂点iにいる時状態jである場合の最小距離（j = 0,1,2)として
 ダイクストラ
 ================================================================
 */

ll dist[100005][5];
vector<ll> G[100005];
using Item = tuple<ll,ll,ll>;

template<class Type>
Type solve(Type res = Type()){
    fill(*dist,*dist+100005*5,INF);
    ll N,M; cin >> N >> M;
    for(int i = 0; i < M;i++){
        ll u,v; cin >> u >> v; u--; v--;
        G[u].push_back(v);
    }
    int S,T; cin >> S >> T; S--; T--;

    priority_queue<Item> pq;
    pq.push(Item(0,S,0));
    while(pq.size()){
        ll cost,n,dep; tie(cost,n,dep) = pq.top(); pq.pop();
        if(dist[n][dep] < cost) continue;
        cost *= -1;
        dist[n][dep] = cost;
        for(auto next:G[n]){
            if(dist[next][(dep+1)%3] > dist[n][dep] + (dep==2)){
                dist[next][(dep+1)%3] = dist[n][dep] + (dep==2);
                pq.push(Item(-dist[next][(dep+1)%3],next,(dep+1)%3));
            }
        }
    }

    res = dist[T][0];
    if(res == INF) res = -1;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
