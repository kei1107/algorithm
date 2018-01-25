#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> G[1000000];
vector<pair<int, int> > bridge;
vector<int> articulation;
int ord[1000000], low[1000000];
bool vis[1000000];

// lowlink and determin bridge ,articulationpoint

//if(ord[at] < low[n]) (n, at) is a bridge
//if(at == 0) if(nG[at].size() > 1) at  is an articulation point
//else if(ord[at] <= low[n]) at  is an articulation point
void dfs(int v, int p, int &k)
{
    vis[v] = true;
    
    ord[v] = k++;
    low[v] = ord[v];
    
    bool isArticulation = false;
    int ct = 0;
    
    for (int i = 0; i < G[v].size(); i++){
        if (!vis[G[v][i]]){
            ct++;
            dfs(G[v][i], v, k);
            low[v] = min(low[v], low[G[v][i]]);
            if (~p && ord[v] <= low[G[v][i]]) isArticulation = true;
            if (ord[v] < low[G[v][i]]) bridge.push_back(make_pair(min(v, G[v][i]), max(v, G[v][i])));
        }
        else if (G[v][i] != p){
            low[v] = min(low[v], ord[G[v][i]]);
        }
    }
    
    if (p == -1 && ct > 1) isArticulation = true;
    if (isArticulation) articulation.push_back(v);
}

int main()
{
    int n, m;
    
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < m; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        G[--x].push_back(--y);
        G[y].push_back(x);
    }
    
    int k = 0;
    for (int i = 0; i < n; i++){
        if (!vis[i]) dfs(i, -1, k);
    }
    
    sort(bridge.begin(), bridge.end());
    sort(articulation.begin(), articulation.end());
    
    printf("%d\n", articulation.size());
    
    for (int i = 0; i < articulation.size(); i++)
        printf("%d\n", articulation[i] + 1);
    
    printf("%d\n", bridge.size());
    
    for (int i = 0; i < bridge.size(); i++)
        printf("%d %d\n", bridge[i].first + 1, bridge[i].second + 1);
    
    
    return (0);
}
