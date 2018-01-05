#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

#define MAX_N 10000
int N, M;
vector<int> G[MAX_N];
bool used[MAX_N];
int low[MAX_N], ord[MAX_N];


void lowlink(int at, int p, int &k) {
    //int &k can be altered as int k
    //used this as lowlink(0, -1, k). declare int k = 0
    //if(ord[at] < low[n]) (n, at) is a bridge
    //if(at == 0) if(nG[at].size() > 1) at  is an articulation point
    //else if(ord[at] <= low[n]) at  is an articulation point
    used[at] = true;
    low[at] = ord[at] = k;
    k++;
    for(int i = 0; i < G[at].size(); i++) {
        int n = G[at][i];
        if(!used[n]) {
            lowlink(n, at, k);
            low[at] = min(low[at], low[n]);
        }
        else if(n != p) low[at] = min(low[at], ord[n]);
    }
}


int dfs(int at, int root, int ng) {
    used[at] = true;
    bool tmp = false;
    int cnt = 0, res = 0;
    for(int i = 0; i < G[at].size(); i++) {
        int n = G[at][i];
        if(used[n] || n == ng) continue;
        if(at != root && ord[at] <= low[n] && !tmp) {
            res++;
            tmp = true;
        }
        res += dfs(n, root, ng);
        cnt++;
    }
    if(at == root && cnt > 1) {
        res++;
    }
    return res;
}
