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
<url:https://onlinejudge.u-aizu.ac.jp/services/room.html#RitsCamp18Day1/problems/E>
問題文============================================================
 あなたはグラフのアルゴリズムとして典型であるフローの問題を解いていた。
 その問題で与えられるグラフは、頂点 N 個、辺 M 本であり、
 頂点 xi から 頂点 yi に容量 zi 、コスト di の辺が張られている。
 ところが、AORイカちゃんが入力ケースにいたずらした。
 その結果、 xi,yi,zi の順序がシャッフルされ、頂点の情報と容量の情報が区別できなくなってしまった。
 
 そこで、あなたは s−t 間のフローを求めることを諦め、 s−t 間の最短距離を求めることにした。
 あなたは、 xi,yi,zi の順序がシャッフルされた入力ケース ai,bi,ci のうちから二つを頂点情報にし、
 コスト di の辺を張ることにした。
 つまり、ai から bi, ai から ci, bi から ci の三つの候補のうち一つにコスト di の辺を張る。
 
 考えられるグラフのうち、 「s から t への最短距離」の最小値を求めよ。
=================================================================

解説=============================================================

 ai から bi, ai から ci, bi から ciの３パターン分、無方向辺を貼ってdijkstraすれば良い
 
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N,M,s,t; cin >> N >> M >> s >> t;
    s--; t--;
    vector<ll> a(M),b(M),c(M),d(M);
    for(int i = 0; i < M;i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i]--; b[i]--; c[i]--;
    }
    vector<vector<pll>> G(N);
    for(int i = 0; i < M;i++){
        G[a[i]].push_back({b[i],d[i]});
        G[b[i]].push_back({a[i],d[i]});
        
        G[a[i]].push_back({c[i],d[i]});
        G[c[i]].push_back({a[i],d[i]});
        
        G[b[i]].push_back({c[i],d[i]});
        G[c[i]].push_back({b[i],d[i]});
    }
    
    vector<ll> dist(N,LINF);
    dist[s] = 0;
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    pq.push({0,s});
    while(pq.size()){
        ll d,n; tie(d,n) = pq.top(); pq.pop();
        if(dist[n] < d) continue;
        for(auto e:G[n]){
            ll next = e.first,cost = e.second;
            if(dist[next] > dist[n] + cost){
                dist[next] = dist[n] + cost;
                pq.push({dist[next],next});
            }
        }
    }
    cout << dist[t] << endl;
	return 0;
}
