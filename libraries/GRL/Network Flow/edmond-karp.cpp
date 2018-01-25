#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

const int MAX_N = 232;
// capacity : edge(s -> t : capacity[s][t] = cap) / non edge : capacity[s][t] = 0
int edmonds_karp(const int capacity[MAX_N][MAX_N], int N, int source, int sink){
    static int flow[MAX_N][MAX_N];
    for (int i = 0; i < N; i++) fill_n(flow[i], N, 0);
    
    int max_flow = 0;
    while (true) {
        static int parent[MAX_N];
        fill_n(parent, N, -1);
        queue<int> q;
        q.push(source);
        
        while (!q.empty() && parent[sink] < 0) {
            const int v = q.front(); q.pop();
            for (int u = 0; u < N; u++) {
                if (parent[u] < 0 && capacity[v][u] - flow[v][u] > 0) {
                    parent[u] = v;
                    if (u == sink) break;
                    q.push(u);
                }
            }
        }
        
        if (parent[sink] < 0) break;
        
        int aug = numeric_limits<int>::max();
        for (int v = sink; v != source; v = parent[v]) {
            const int u = parent[v];
            aug = min(aug, capacity[u][v] - flow[u][v]);
        }
        max_flow += aug;
        for (int v = sink; v != source; v = parent[v]) {
            const int u = parent[v];
            flow[u][v] += aug;
            flow[v][u] -= aug;
        }
    }
    
    return max_flow;
}
