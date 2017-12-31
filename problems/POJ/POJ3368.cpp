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
 
 ================================================================
 */

struct SegTree {
    int N;
    pii init_v;
    vector<pii> node;
    
    SegTree(int _N) {
        N = 1;
        while (N < _N) N *= 2;
        init_v = make_pair(-INF,-INF); // v , -idx
        node.resize(2 * N - 1, init_v);
    }
    
    void update(int k, int val) {
        int idx = k;
        k += N - 1;
        node[k] = make_pair(val,-idx);
        while (k) {
            k = (k - 1) / 2;
            node[k] = max(node[2 * k + 1], node[2 * k + 2]);
        }
    }
    pii query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return init_v;
        if (a <= l && r <= b) return node[k];
        else {
            pii vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
            pii vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
            return max(vl, vr);
        }
    }
    pii rmq(int a, int b) { return query(a, b, 0, 0, N); }
};

int a[100005];
int v_cnt[100005];
int main(void) {
    int n,q;
    while(true){
        scanf("%d",&n);
        if(n == 0) break;
        scanf("%d",&q);
        SegTree Q(n);
        for(int i = 0; i < n;i++) scanf("%d",&a[i]);
        
        int prev = INF;
        int cnt = 0;
        for(int i = n-1;i>= 0;i--){
            if(a[i] == prev){
                cnt++;
                v_cnt[i] = cnt;
            }else{
                prev = a[i];
                v_cnt[i] = cnt = 1;
            }
            Q.update(i, v_cnt[i]);
        }
        
        for(int kassa = 0; kassa < q;kassa++){
            int A,B; scanf("%d%d",&A,&B);
            A--; B--;
            pii ret = Q.rmq(A,B+1);
            int ans = min(v_cnt[A],B-A+1);
            if(B+1 == n){
                ans = max(ans,ret.first);
            }else{
                if(a[-ret.second] == a[B+1]){
                    ans = max(ans,ret.first-v_cnt[B+1]);
                }else{
                    ans = max(ans,ret.first);
                }
                if(A+v_cnt[A] -1 < -ret.second){
                    pii ret2 = Q.rmq(A+v_cnt[A]-1,-ret.second);
                    ans = max(ans,ret2.first);
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}
