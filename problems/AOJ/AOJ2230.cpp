#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 2e8;
const int inf = 1e6;
const ll LINF = 1e18;

/*
<url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2230>
問題文============================================================

 正の重み付きDAGで,さらに,任意のiに対し0->i->N-1となるpathがあるものが与えられる.
 0からN-1への最長距離を変えないように辺の重みを0以上の整数増やす.
 どれだけ増やせるか.N<=100,M<=1000,重み<=1000
 
=================================================================

解説=============================================================
解説を見た 
 参考: < http://sigma425.hatenablog.com/entry/2015/07/12/235941 >
      < http://lepton.hatenablog.jp/entry/2015/08/07/185540 >
 
================================================================
*/

#define MAX_V 101
struct edge{
    int to;
    int cap;
    int cost;
    int rev;
    edge(){}
    edge(int to,int cap,int cost,int rev):to(to),cap(cap),cost(cost),rev(rev){}
};

int V;
vector<edge> G[MAX_V];
int h[MAX_V];
int dist[MAX_V];
int prevv[MAX_V],preve[MAX_V];
void init_edge(){
    for(int i=0;i<V;i++)G[i].clear();
}
void add_edge(int from,int to,int cap,int cost){
    G[from].push_back(edge(to,cap,cost,(int)G[to].size()));
    G[to].push_back(edge(from,0,-cost,(int)G[from].size()-1));
}
void add_edge_lbub(int from,int to,int lb,int ub,int cost){
    add_edge(from,to,ub-lb,cost);
    add_edge(from,to,lb,cost-inf);
}
int min_cost_flow(int s,int t,int f){
    int res = 0;
    fill(h,h+V,INF);
    h[s] = 0;
    //一回だけbellmanfordで最初のポテンシャルを求める
    for(int k = 0; k < V; k++) {
        for(int i = 0;i < V;i++) {
            for(int j = 0; j < (int)G[i].size(); j++) {
                edge &e = G[i][j];
                if (e.cap == 0)continue; // 誤差注意
                h[e.to] = min(h[e.to], h[i] + e.cost);
            }
        }
    }
    f = INF;
    while(h[t] < 0){
        priority_queue< pii, vector<pii>, greater<pii> >  que;
        fill( dist, dist+V , INF );
        dist[s]=0;
        que.push(pii(0,s));
        while(!que.empty()){
            pii p = que.top(); que.pop();
            int v = p.second;
            if(dist[v]<p.first)continue;
            for(int i=0;i<(int)G[v].size();i++){
                edge &e = G[v][i];
                if(e.cap>0&&dist[e.to] > dist[v]+e.cost+h[v]-h[e.to]){
                    dist[e.to]=dist[v]+e.cost+h[v]-h[e.to];
                    prevv[e.to]=v;
                    preve[e.to]=i;
                    que.push(pii(dist[e.to],e.to));
                }
            }
        }
        
        if(dist[t]==INF){
            return -1;
        }
        for(int v=0;v<V;v++)h[v]+=dist[v];
        
        int d=f;
        for(int v=t;v!=s;v=prevv[v]){
            d=min(d,G[prevv[v]][preve[v]].cap);
        }
        f-=d;
        res+=d*h[t];
        for(int v=t;v!=s;v=prevv[v]){
            edge &e = G[prevv[v]][preve[v]];
            e.cap -= d;
            G[v][e.rev].cap += d;
        }
    }
    return res;
}

vector<pii> GG[MAX_V];
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    int N,M; cin >> N >> M;
    for(int i = 0; i < M;i++){
        int x,y,s; cin >> x >> y >> s;
        add_edge_lbub(x, y, 1, INF, -s);
        GG[x].push_back(pll(y,s));
    }
    int S = 0, T = N;
    V = N + 1;
    int D = 0;
    {
        int d[MAX_V] = {};
        for(int i = 0; i < N;i++){
            for(auto e:GG[i]){
                d[e.first] = max(d[e.first],d[i]+e.second);
            }
        }
        D=d[N-1];
    }
    add_edge(N-1,N,INF,D);
    cout << min_cost_flow(S, T,INF) + M*inf << endl;
	return 0;
}
