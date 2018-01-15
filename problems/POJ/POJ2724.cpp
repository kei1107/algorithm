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

#define MAX_N 10
char buf[MAX_N+1];
bool one_hamming_dist[1<<MAX_N][1<<MAX_N];
bool exist[1<<MAX_N];

ll V;
vector<vector<ll> > G(1<<MAX_N);
vector<ll> match(1<<MAX_N);
vector<int> used(1<<MAX_N);

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
    for(int i = 0; i < (1<<MAX_N);i++) G[i].clear();
    fill(used.begin(),used.end(),0);
    fill(match.begin(),match.end(),0);
    fill(exist,exist + (1<<MAX_N),0);
}

int N,M;
void preprocessing(){
    for(int i = 0; i < (1<<MAX_N);i++){
        for(int j = 0; j < MAX_N;j++){
            one_hamming_dist[i][i^(1<<j)] = true;
        }
    }
}
int main(void) {
    //	cin.tie(0); ios::sync_with_stdio(false);
    preprocessing();
    while(true){
        scanf("%d%d",&N,&M);
        if(N == 0 && M == 0) break;
        init();
        V = (1<<N);
        // check exist command
        for(int i = 0; i < M;i++){
            scanf("%s",buf);
            int com1 = 0, com2 = 0; // com1(* := 0), com2(* := 1)
            for(int j = 0; j < N;j++){
                int bit = N - 1 - j;
                if(buf[j] == '*'){
                    com1 += (0&1) << bit;
                    com2 += (1&1) << bit;
                }else{
                    com1 += ((buf[j] - '0')&1) << bit;
                    com2 += ((buf[j] - '0')&1) << bit;
                }
            }
            exist[com1] = exist[com2] = true;
        }
        
        int Cnt = 0;
        for(int i = 0; i < (1<<N);i++){
            if(!exist[i]) continue;
            Cnt++;
            for(int j = 0; j < (1<<N);j++){
                if(!exist[j]) continue;
                if(one_hamming_dist[i][j]){
                    G[i].push_back(j);
                }
            }
        }
        cout << Cnt - bipartite_matching() << endl;
    }
    return 0;
}
