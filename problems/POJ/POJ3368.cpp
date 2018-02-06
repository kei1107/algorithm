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
 <url:http://poj.org/problem?id=3368>
 問題文============================================================
 n 項からなる単調非減少な数列 a が与えられる。
 以下のようなクエリを処理せよ。
 
 区間 [ l, r ] の内で最も多く出現する数字の出現している個数を答えよ
 =================================================================
 
 解説=============================================================
 先に、前処理として自分自身と同じ番号が数列の右側に自分を含めていくつ現れるかについての配列を作る
 
 この数列のi番目について {i番目の値、-i} のデータを持ったセグ木を作る
 こうすることによって、クエリは最も左側にある最も大きな値を返す
 
 ここで、区間[A,B]での対象数字の候補としては次の３種類
     Aよりも左から現れ区間内に入る数字
     区間内にのみ現れる数字
     区間内で現れ区間外に出て行く数字
 
 これで次のような動作を行えば答えが出る。
 範囲[A,B]が与えられた時
 [A,B]のクエリを求める。
 この時、帰ってきたデータの位置ret_idxがAであれば明らかにそれが答え([A,B]よりも右に数字が続く場合に注意)
 そうでなければ
 区間[A,ret_idx)に関して再度クエリを求めて、大きい個数を返却する
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
