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
