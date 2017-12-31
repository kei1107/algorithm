#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
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
RM(AX and IN)Q
================================================================
*/

struct SegTree {
public:
    int N;
    pii init_val;
    vector<pii> node;
    
    SegTree(int _N) {
        N = 1;
        while (N < _N) N *= 2;
        init_val = make_pair(INF,-INF);
        node.resize(2 * N - 1, init_val);
    }
    
    void update(int k, int val) {
        k += N - 1;
        node[k] = make_pair(val,val);
        while (k) {
            k = (k - 1) / 2;
            node[k].first = min(node[2*k+1].first,node[2*k+2].first);
            node[k].second = max(node[2*k+1].second,node[2*k+2].second);
        }
    }
    pll query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return init_val;
        if (a <= l && r <= b) return node[k];
        else {
            pll vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
            pll vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
            return make_pair(min(vl.first,vr.first),max(vl.second,vr.second));
        }
    }
    pll rmq(int a, int b) { return query(a, b, 0, 0, N); }
};

int main(void) {
//	cin.tie(0); ios::sync_with_stdio(false);
    int N,Q;
    scanf("%d%d",&N,&Q);
    SegTree cow(N);
    for(int i = 1; i <= N;i++){
        int h;
        scanf("%d",&h);
        cow.update(i, h);
    }
    for(int i = 0; i < Q;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        pll ret = cow.rmq(a, b+1);
        cout << ret.second - ret.first << endl;
    }
	return 0;
}
