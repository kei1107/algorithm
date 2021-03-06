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
 <url:http://poj.org/problem?id=2226>
 問題文============================================================
 R×C のグリッドが与えられ、いくつかのマスはぬかるんでいる。
 すべてのぬかるんでいるマスを板で覆いたい。
 この板は幅は1であるが、長さは好きなだけ長くできる。
 板同士が重なっても構わないが、ぬかるんでいないマスを板で覆ってはならない。
 このとき、必要な最小の板の枚数を答える。
 =================================================================
 
 解説=============================================================
 マッチングの最小パス被膜
 
 考え方は蟻本p205 206を参照
 
 板はマスの一番左側から右側へ伸ばせるだけ伸ばした方がよく
 一番上から下へ伸ばせるだけ伸ばした方がいい。このような板の置き方を前提として
 グリッドの各頂点に対して被膜できる板に対して辺を貼る。
 
 こうすることによって二部グラフの最小頂点被膜問題に帰着できる
 ================================================================
 */

ll V;
vector<vector<ll> > G;
vector<ll> match;
vector<int> used;

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


int R,C;
char masu[52][52];
pii rc[52][52];
int main(void) {
    for(int i = 0; i < 52;i++) for(int j = 0; j < 52;j++){ masu[i][j] = '#'; }
    scanf("%d%d",&R,&C);
    for(int i = 1; i <= R;i++){
        for(int j = 1; j <= C;j++){
            cin >> masu[i][j];
        }
    }
    
    int r = 0, c = 0;
    for(int i = 1; i <= R;i++){
        for(int j = 1; j <= C;j++){
            if(masu[i][j] == '.') continue;
            if(rc[i][j].first == 0){
                r++;
                for(int k = i; k <= R;k++){
                    if(masu[k][j] != '*') break;
                    rc[k][j].first = r;
                }
            }
            
            if(rc[i][j].second == 0){
                c++;
                for(int k = j; k <= C;k++){
                    if(masu[i][k] != '*') break;
                    rc[i][k].second = c;
                }
            }
        }
    }

    V = r + c;
    G.resize(V); match.resize(V); used.resize(V);
    for(int i = 1; i <= R;i++){
        for(int j = 1; j<= C;j++){
            if(rc[i][j].first == 0) continue;
            add_edge(rc[i][j].first - 1, rc[i][j].second - 1 + r);
        }
    }
    cout << bipartite_matching() << endl;
    return 0;
}
