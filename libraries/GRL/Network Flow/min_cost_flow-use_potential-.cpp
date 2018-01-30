typedef ll PD_Type;
const PD_Type PD_INF = 1 << 30;

struct Primal_Dual
{
    typedef pair< PD_Type, int > pii;
    
    struct edge
    {
        int to, rev;
        PD_Type    cap, cost;
        edge() {}
        edge(int to, PD_Type cap, PD_Type cost, int rev) :to(to), cap(cap), cost(cost), rev(rev) {}
        
    };
    vector< vector< edge > > graph;
    vector< int > prevv, preve;
    vector< PD_Type > potential, min_cost;
    Primal_Dual(int V) : graph(V) {}
    
    void add_edge(int from, int to, PD_Type cap, PD_Type cost)
    {
        graph[from].push_back(edge(to, cap, cost, (int)graph[to].size()));
        graph[to].push_back(edge(from, 0, -cost, (int)graph[from].size() - 1));
    }
    
    PD_Type min_cost_flow(int s, int t, int f)
    {
        int V = (int)graph.size();
        PD_Type ret = 0;
        priority_queue< pii, vector< pii >, greater< pii > > que;
        potential.assign(V, 0);
        preve.assign(V, -1);
        prevv.assign(V, -1);
        
        //一回だけbellmanfordで最初のポテンシャルを求める
        for(int k = 0; k < V; k++) {
            for(int i = 0;i < V;i++) {
                for(int j = 0; j < (int)graph[i].size(); j++) {
                    edge &e = graph[i][j];
                    if (e.cap == 0)continue; // 誤差注意
                    potential[e.to] = min(potential[e.to], potential[i] + e.cost);
                }
            }
        }
        
        while (f > 0) {
            min_cost.assign(V, PD_INF);
            que.push(pii(0, s));
            min_cost[s] = 0;
            
            while (!que.empty()) {
                pii p = que.top();
                que.pop();
                if (min_cost[p.second] < p.first) continue;
                for (int i = 0; i < (int)graph[p.second].size(); i++) {
                    edge &e = graph[p.second][i];
                    PD_Type nextCost = min_cost[p.second] + e.cost + potential[p.second] - potential[e.to];
                    if (e.cap > 0 && min_cost[e.to] > nextCost) {
                        min_cost[e.to] = nextCost;
                        prevv[e.to] = p.second; preve[e.to] = i;
                        que.push(pii(min_cost[e.to], e.to));
                    }
                }
            }
            if (min_cost[t] == PD_INF) return -1;
            for (int v = 0; v < V; v++) potential[v] += min_cost[v];
            PD_Type addflow = f;
            for (int v = t; v != s; v = prevv[v]) {
                addflow = min(addflow, graph[prevv[v]][preve[v]].cap);
            }
            f -= addflow;
            ret += addflow * potential[t];
            for (int v = t; v != s; v = prevv[v]) {
                edge &e = graph[prevv[v]][preve[v]];
                e.cap -= addflow;
                graph[v][e.rev].cap += addflow;
            }
        }
        return ret;
    }
};

/*
 Primal_Dual F(V);
 F.add_edge(u,v,cap,cost);
 F.min_cost_flow(S, T, F);
 */

// ==============================

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

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
int main(){
    int E,F,a,b,c,d;
    cin>>V>>E>>F;
    while(E--){
        cin>>a>>b>>c>>d;
        add_edge(a,b,c,d);
    }
    cout<<min_cost_flow(0,V-1,F)<<endl;
    return 0;
}
