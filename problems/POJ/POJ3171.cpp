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

struct SegTree {
    int N;
    ll init_v;
    vector<ll> node;
    
    SegTree(int _N) {
        init_v = LINF;
        N = 1;
        while (N < _N) N *= 2;
        node.resize(2 * N - 1, init_v);
    }
    
    ll get(int k){
        return node[k + N - 1];
    }
    
    void update(int k, ll val) {
        k += N - 1;
        node[k] = val;
        while (k) {
            k = (k - 1) / 2;
            node[k] = min(node[2 * k + 1], node[2 * k + 2]);
        }
    }
    ll query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return init_v;
        if (a <= l && r <= b) return node[k];
        else {
            ll vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
            ll vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
            return min(vl, vr);
        }
    }
    ll rmq(int a, int b) { return query(a, b, 0, 0, N); }
};

vector<pii> Sec[86400];
int main(void) {
    int N,M,E; scanf("%d%d%d",&N,&M,&E);
    for(int kassa = 0; kassa < N;kassa++){
        int t1,t2,s; scanf("%d%d%d",&t1,&t2,&s);
        Sec[t2+1].push_back(make_pair(t1,s));
    }
    
    SegTree _rmq(E+2);
    _rmq.update(M,0);
    for(int i = (int)M; i <= E+1;i++){
        for(int j = 0; j < (int)Sec[i].size();j++){
            _rmq.update(i,min(_rmq.get(i),_rmq.rmq(Sec[i][j].first,i) + Sec[i][j].second));
        }
    }
    
    ll ans = _rmq.get(E+1);
    if(ans == LINF){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
}
