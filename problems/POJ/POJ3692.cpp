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
<url:>
問題文============================================================

=================================================================

解説=============================================================

================================================================
*/

#define MAX_V 400
int Girls_kassa,Boys_kassa,M;
bool siriai[MAX_V][MAX_V];

ll V;
vector<vector<ll> > G(MAX_V);
vector<ll> match(MAX_V);
vector<int> used(MAX_V);

void add_edge(ll u, ll v) {
    G[u].push_back(v);
    G[v].push_back(u);
}

bool dfs(ll v) {
    used[v] = 1;
    for (int i = 0; i < G[v].size(); i++) {
        ll u = G[v][i], w = match[u];
        if (w < 0 || ((used[w] == 0) && dfs(w))) {
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    return false;
}

ll bipartite_matching() {
    ll res = 0;
    for (int i = 0; i < (int)match.size();i++)match[i] = -1;
    for (int v = 0;v < V;v++) {
        if (match[v] < 0) {
            for (int i = 0; i < (int)used.size();i++)used[i] = 0;
            if (dfs(v))res++;
        }
    }
    return res;
}

void init(){
    memset(siriai,0,sizeof(siriai));
    for(int i = 0; i < MAX_V;i++) G[i].clear();
    fill(used.begin(),used.end(),0);
    fill(match.begin(),match.end(),0);
}

int main(void) {
	//cin.tie(0); ios::sync_with_stdio(false);
    for(int kassa = 1;;kassa++){
        scanf("%d%d%d",&Girls_kassa,&Boys_kassa,&M);
        if((Girls_kassa|Boys_kassa|M) == 0) break;
        init();
        for(int i = 0;i < M;i++){
            int a,b; scanf("%d%d",&a,&b); a--; b--;
            siriai[a][b+Girls_kassa] = true;
        }
        
        V = Girls_kassa + Boys_kassa;
        
        for(int i = 0; i < Girls_kassa; i++){
            for(int j = Girls_kassa; j < Girls_kassa + Boys_kassa;j++){
                if(siriai[i][j])continue;
                add_edge(i, j);
            }
        }
        cout << "Case " << kassa << ": " <<  V - bipartite_matching() << endl;
    }
	return 0;
}
