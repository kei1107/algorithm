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
#define INF (1<<30)
#define LINF (1LL<<60)

/*
<url:http://poj.org/problem?id=3713>
問題文============================================================
 頂点数V(<500)の無向グラフが与えられる。
 任意の2点間に点素パスが3本以上存在するかどうか判定する問題。
=================================================================

解説=============================================================
まず前提として、
 点素パスが1 := 互いに到達可能
 点素パスが2 := 関節点が存在しない
 と言い換えることができる
 
 ここで、点素パスが3になるには、任意の点を削除した時
 関節点が存在しないことと同値になる
================================================================
*/
#define MAX_N 500
int N, M;
vector<int> G[MAX_N];
bool used[MAX_N];
int low[MAX_N], ord[MAX_N];

void lowlink(int at, int p, int &k, int ng) {
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
        if(!used[n] && n != ng) {
            lowlink(n, at, k, ng);
            low[at] = min(low[at], low[n]);
        }
        else if(n != p && n != ng) low[at] = min(low[at], ord[n]);
    }
}

// return cnt of articulation point
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

int main(void) {
//	cin.tie(0); ios::sync_with_stdio(false);
    while(true){
        scanf("%d%d",&N,&M);
        if(N == 0 && M == 0) break;
        
        for(int i = 0; i < N;i++) G[i].clear();
        
        // input
        for(int i = 0; i < M;i++){
            int a,b; scanf("%d%d",&a,&b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
        
        // solver
        bool f = false;
        for(int i = 0; i < N;i++){
            // initialize
            memset(low,0,sizeof(low));
            memset(used,0,sizeof(used));
            memset(ord,0,sizeof(ord));
            
            /*
             if i == 0 : root = 1
             else : root = 0
             */
            int timer = 0;
            if(i == 0){
                lowlink(1,-1,timer,i);
                memset(used,0,sizeof(used));
                if(dfs(1,1,i)){
                    f = true; break;
                }
            }else{
                lowlink(0, -1, timer, i);
                memset(used,0,sizeof(used));
                if(dfs(0,0,i)){
                    f = true; break;
                }
            }
            
            for(int j = 0;j  < N;j++){
                if(i == j) continue;
                if(used[j]) continue;
                f = true; break;
            }
            if(f)break;
        }
        if(f) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
	return 0;
}
