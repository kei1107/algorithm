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
#define MAX_N 100000
int N,Q;
int node[MAX_N+1];
bool marked[MAX_N+1];

int dfs(int v){
    return marked[v] ? v:dfs(node[v]);
}

int main(void) {
    //    cin.tie(0); ios::sync_with_stdio(false);
    while(true){
        scanf("%d%d",&N,&Q);
        if(N == 0 && Q == 0) break;
        memset(marked,false,sizeof(marked));
        for(int i = 2; i <= N;i++){
            int v; scanf("%d",&v);
            node[i] = v;
        }
        marked[1] = true;
        ll ans = 0;
        for(int i = 0; i < Q;i++){
            char c; int v; cin >> c >> v;
            if(c == 'Q'){
                ans += dfs(v);
            }else{
                marked[v] = true;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

