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
 <url:http://poj.org/problem?id=3977>
 問題文============================================================
N(<35)個の整数が与えられる。
 非空の部分集合を作って和が0にもっとも近くなるようなものをつくり、
 またそのような作り方が複数ある時はサイズが最小になるようにせよ。
 =================================================================
 
 解説=============================================================
 半分全列挙
 
 半分全列挙そのままだが、前処理としてユニークや、空集合を含まないようにする処理を行う
 ================================================================
 */

inline ll Abs(ll a){
    return (a < 0)? -a:a;
}

ll a[40];
pll dp1[1<<20];
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll N;
    ll a[40];
    while(cin >> N){
        if(N == 0) break;
        for(int i = 0; i < N;i++) cin >> a[i];
        if(N == 1){
            cout << Abs(a[0]) << " " << 1 << endl;
            continue;
        }
        ll n1 = N/2, n2 = N - n1;
        pll ans(LINF,0LL);
        dp1[0] = make_pair(0,0);
        for(int i = 1; i < (1<<n1);i++){
            ll t = 0;
            ll cnt = 0;
            for(int j = 0; j < n1;j++){
                if((i>>j)&1){
                    cnt++;
                    t += a[j];
                }
            }
            dp1[i] = make_pair(t, cnt);
        }
        sort(dp1,dp1 + (1<<n1));
        for(int i = 0; i < (1<<n1);i++){
            if(dp1[i] != make_pair(0LL, 0LL)){
                ans = min(ans,make_pair(Abs(dp1[i].first),dp1[i].second));
            }
            if(i == 0)continue;
            if(dp1[i].first == dp1[i-1].first) dp1[i].second = dp1[i-1].second;
        }
        sort(dp1,dp1 + (1<<n1));
        long R = unique(dp1,dp1 + (1<<n1)) - dp1;
        for(int i = 0; i < (1<<n2);i++){
            ll t = 0;
            ll cnt = 0;
            for(int j = 0; j < n2;j++){
                if((i>>j)&1){
                    cnt++;
                    t += a[n1+j];
                }
            }
            long idx = lower_bound(dp1, dp1+R,make_pair(-t,0LL)) - dp1;
            for(int i = -1; i <= 1;i++){
                if(idx + i < 0 || idx + i >= R)continue;
                if(cnt + dp1[idx+i].second <= 0)continue;
                ans = min(ans,make_pair(Abs(t+dp1[idx+i].first),cnt+dp1[idx+i].second));
            }
        }
        cout << ans.first << " " << ans.second << endl;
    }
    return 0;
}
