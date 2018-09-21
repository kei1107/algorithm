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
 <url:https://onlinejudge.u-aizu.ac.jp/services/room.html#ACPC2018Day2/problems/F>
 問題文============================================================
 =================================================================
 解説=============================================================
 色々ときつかった。。。。
 
 priority_queueでダイクストラ。
 
 次コストを三分探索で決定していく
 ================================================================
 */

struct edge{
    ll u,v,a,b;
    edge(ll u = 0,ll v = 0,ll a = 0,ll b = 0):u(u),v(v),a(a),b(b){}
};

ll N,M,S,G;
vector<vector<edge>> g;
vector<ll> dist;


ll check(ll t,ll a,ll b){
    if(a+t >= b) return t+1;
    ll ret = LINF;
    ll l = t, r = b;
    while(r-l>2){
        ll m1 = (r-l)/3 + l;
        ll m2 = (r-l)*2/3 + l;
        
        double c1 = m1 + (double)(b+m1+a-1)/(m1+a);
        double c2 = m2 + (double)(b+m2+a-1)/(m2+a);
        if(c1 < c2){
            r = m2;
        }else{
            l = m1;
        }
    }
    for(ll t = l; t <= r; t++){
        ret = min(ret,t+(b+t+a-1)/(t+a));
    }
    return ret;
}
ll solve(){
    ll res = 0;
    scanf("%lld %lld %lld %lld",&N,&M,&S,&G);
    S--; G--;

    g.resize(N); dist.resize(N);
    for(int i = 0; i < M;i++){
        ll U,V,A,B;
        scanf("%lld %lld %lld %lld",&U,&V,&A,&B);
        U--; V--;
        g[U].push_back(edge(U,V,A,B));
        g[V].push_back(edge(V,U,A,B));
    }
    
    
    fill(dist.begin(),dist.end(),LINF);
    dist[S] = 0;
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    pq.push({0,S});
    while(pq.size()){
        ll t,n; tie(t,n) = pq.top(); pq.pop();
        if(t > dist[n]) continue;
        if(n == G) break;
        
        for(const edge& e:g[n]){
            ll a = e.a, b = e.b;
            ll cost = check(t,a,b);
            if(dist[e.v] > cost){
                dist[e.v] = cost;
                pq.push({dist[e.v],e.v});
            }
        }
    }
    if(dist[G] == LINF) return -1;
    res = dist[G];
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
