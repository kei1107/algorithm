#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <bitset>
#include <iostream>
#include <iomanip>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <numeric>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <deque>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e16;

/*
<url:http://poj.org/problem?id=3068>
問題文============================================================

=================================================================

解説=============================================================

================================================================
*/

struct Edge {
    //to : Edge(from -> to)   cap:capacity cost:cost   rev:reverse
    int to, cap, cost, rev;
    Edge(int to, int cap, int cost, int rev) :to(to), cap(cap), cost(cost), rev(rev) {}
};

#define P vector<vector<Edge> >
vector<int> dist;
bool bellman_ford(P& Graph, int s, int t, vector<int>& parent_v, vector<int>& parent_at) {
    dist = vector<int>(t + 1, INF);
    dist[s] = 0;
    for (int i = 0; i <= t;i++) {
        for (int v = 0; v <= t;v++) {
            if (dist[v] == INF)continue;
            for (int at = 0; at < Graph[v].size();at++) {
                Edge &e = Graph[v][at];
                if (e.cap > 0 && dist[e.to] > dist[v] + e.cost) {
                    //cout << i << " " << v << endl;
                    dist[e.to] = dist[v] + e.cost;
                    parent_v[e.to] = v;
                    parent_at[e.to] = at;
                    if (i == t) return false;
                }
            }
        }
    }
    return true;
}

int primal_dual(P& Graph, int s, int t, int F) {
    vector<int> parent_v(t + 1);
    vector<int> parent_at(t + 1);
    int min_cost_flow = 0;
    while (bellman_ford(Graph, s, t, parent_v, parent_at)) {
        if (dist[t] == INF) { return -1; }
        int path_flow = F;
        for (int v = t; v != s; v = parent_v[v]) {
            path_flow = min(path_flow, Graph[parent_v[v]][parent_at[v]].cap);
        }
        
        F -= path_flow;
        min_cost_flow += path_flow*dist[t];
        if (F == 0) { return min_cost_flow; }
        if (F < 0) { return -1; }
        
        for (int v = t; v != s; v = parent_v[v]) {
            Edge & e = Graph[parent_v[v]][parent_at[v]];
            e.cap -= path_flow;
            Graph[v][e.rev].cap += path_flow;
        }
    }
    return min_cost_flow;
}

#define MAX_N 64
P G(MAX_N);

int N,M;

void init(){
    for(int i = 0; i < MAX_N;i++) G[i].clear();
}

int main(void) {
//	cin.tie(0); ios::sync_with_stdio(false);
    for(int q = 1;;q++){
        scanf("%d%d",&N,&M);
        if(N == 0 && M == 0) break;
        init();
        for(int i = 0; i < M;i++){
            int u,v,cost; scanf("%d%d%d",&u,&v,&cost);
            G[u].push_back(Edge(v,1,cost,(int)G[v].size()));
            G[v].push_back(Edge(u,0,-cost,(int)G[u].size()-1));
        }
        int res = primal_dual(G, 0,N-1, 2);
        if(res == -1){
            cout << "Instance #" << q << ": Not possible" << endl;
        }else{
            cout << "Instance #" << q << ": " << res << endl;
        }
    }
    
	return 0;
}
