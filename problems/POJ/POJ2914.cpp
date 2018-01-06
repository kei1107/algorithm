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
<url:>
問題文============================================================

=================================================================

解説=============================================================

================================================================
*/

ll global_min_cut(vector<vector<int> >& G){
    int n = (int)G.size(); ll res = LINF;
    vector<int> redV(n);
    for(int i = 0; i < n;i++) redV[i] = i;
    
    for(int rem=n; rem>1;rem--){
        // calc MA order
        int u = 0, v = 0; ll cut = 0;
        vector<int> w(rem,0);
        for(int i = 0; i < rem;i++){
            u = v; v = max_element(w.begin(), w.end()) - w.begin();
            cut = w[v]; w[v] = -1;
            for(int p = 0; p < rem;p++){
                if(w[p]>=0) w[p] += G[redV[v]][redV[p]];
            }
        }
        
        // merge graph
        for(int i = 0; i < rem;i++){
            G[redV[u]][redV[i]] += G[redV[v]][redV[i]];
            G[redV[i]][redV[u]] += G[redV[i]][redV[v]];
        }
        redV.erase(redV.begin() + v);
        
        // update min_cut
        res = min(res,cut);
    }
    return res;
}

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    int N,M;
    while(cin >> N >> M){
        vector<vector<int> > G(N,vector<int>(N,0));
        for(int i = 0;i  < M;i++){
            int s,t,c; cin >> s >> t >> c;
            G[s][t] += c;
            G[t][s] += c;
        }
        ll res = global_min_cut(G);
        cout << res << endl;
    }
	return 0;
}
