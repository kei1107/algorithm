#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:>
問題文============================================================

=================================================================

解説=============================================================

================================================================
*/
#define MAX_V 10000
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
int min_cost_flow(int s,int t,int f){
    int res = 0;
    fill(h,h+V,0);
    
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
    
    while(f>0){
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


int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    int M,N,K; cin >> M >> N >> K;
    
    V = K;
    
    int res = 0;
    vector<int> A(N);
    vector<vector<int>> B(N);
    for(int i = 0; i < N;i++) cin >> A[i];
    for(int i = 0; i < K;i++){
        int a; cin >> a; a--;
        B[a].push_back(i);
        res += A[a];
    }
    
    for(int i = 0; i < N;i++){
        if((int)B[i].size() <= 1) continue;
        for(int j = 0; j < (int)B[i].size()-1;j++){
            int s = B[i][j], t = B[i][j+1];
            if(s+1 != t){
                add_edge(s+1, t, 1, -A[i]);
            }else{
                res -= A[i];
            }
        }
    }
    for(int i = 0; i < K-1;i++){
        add_edge(i, i+1, M, 0);
    }
    cout << res + min_cost_flow(0, K-1, M-1) << endl;
    return 0;
}