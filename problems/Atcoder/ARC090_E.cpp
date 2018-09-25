#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

/*
 <url:https://beta.atcoder.jp/contests/arc090/tasks/arc090_c>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 移動経路が交差しうる場所は、最短経路の中心なので、
 交差しうる頂点または辺がわかる。
 
 あとは、その頂点または辺への到達経路数をdpなどで求めて置いて、計算すれば良い
 
 総数 - (交差数)
 
 がわかりやすい。
 
 
 また、最短経路生成とdp生成を分けて行うとTLEする可能性があるので、
 最短経路生成とdp生成は一緒にやってやると良い
 
 ================================================================
 */

const ll MOD = 1e9+7;

ll solve(){
    ll res = 0;
    ll N,M; cin >> N >> M;
    ll S,T; cin >> S >> T;
    S--; T--;
    vector<vector<pll>> G(N);
    for(int i = 0; i < M;i++){
        ll U,V,D; cin >> U >> V >> D;
        U--; V--;
        G[U].push_back({V,D});
        G[V].push_back({U,D});
    }

    priority_queue<pll> pq;
    vector<ll> d1(N,LINF),d2(N,LINF);
    vector<ll> dp1(N),dp2(N);
    d1[S] = d2[T] = 0;
    dp1[S] = dp2[T] = 1;
    
    pq.push((pll(0,S)));
    while(pq.size()){
        ll d,u; tie(d,u) = pq.top(); pq.pop();
        ll c = -d;
        if(d1[u] != c) continue;
        for(auto e:G[u]){
            ll v = e.first,cost = e.second;
            if(d1[v] > c+cost){
                dp1[v] = 0;
                d1[v] = c+cost;
                pq.push(pll(-d1[v],v));
            }
            if(d1[v] == c+cost){
                (dp1[v] += dp1[u])%=MOD;
            }
        }
    }
    pq.push(pll(0,T));
    while(pq.size()){
        ll d,u; tie(d,u) = pq.top(); pq.pop();
        ll c = -d;
        if(d2[u] != c) continue;
        for(auto e:G[u]){
            ll v = e.first,cost = e.second;
            if(d2[v] > c+cost){
                dp2[v] = 0;
                d2[v] = c + cost;
                pq.push(pll(-d2[v],v));
            }
            if(d2[v] == c+cost){
                (dp2[v] += dp2[u])%=MOD;
            }
        }
    }

    res = dp1[T]*dp1[T]%MOD;
    for(int i = 0; i < N;i++){
        if(d1[i] + d2[i] != d1[T]) continue;
        if(d1[i] == d2[i]){
            res = (res - dp1[i]*dp1[i]%MOD*dp2[i]%MOD*dp2[i]%MOD + MOD)%MOD;
        }
        if(d1[i]<d2[i]){
            for(auto e:G[i]){
                if(d1[e.first]+d2[e.first] != d1[T]) continue;
                if(d1[e.first] <= d2[e.first]) continue;
                if(d1[e.first] != d1[i]+e.second) continue;
                res = (res - dp1[i]*dp1[i]%MOD*dp2[e.first]%MOD*dp2[e.first]%MOD + MOD)%MOD;
            }
        }
        res %= MOD;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
