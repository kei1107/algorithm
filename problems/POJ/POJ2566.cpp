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
#define INF (1<<29)
#define LINF (1LL<<60)

/*
 <url:http://poj.org/problem?id=2566>
 問題文============================================================
 長さN(<10^5)の数列が与えられる。長さ正の区間和で、絶対値がtに最も近いものを求める問題。
 =================================================================
 
 解説=============================================================
 しゃくとり方
 絶対値をとるので、そのままだとしゃくとりできないが、
 累積和をソートすれば取れるようになる
 ================================================================
 */

//ll abs(ll a){
//    if(a < 0) return -a;
//    return a;
//}

ll n,k;
pll cusum[100010];
ll a[100010];
int main(void) {
  //  cin.tie(0); ios::sync_with_stdio(false);
    while(cin >> n >> k){
        if(n == 0 && k == 0) break;
        for(int i = 0; i < n;i++){
            scanf("%lld",&a[i]);
        }
        cusum[0] = make_pair(0,0);
        for(int i = 0; i < n;i++){
            cusum[i+1] = make_pair(cusum[i].first + a[i],i+1);
        }
        sort(cusum,cusum+n+1);
        
        //        for(int i = 0; i <= n;i++){
        //            cout << cusum[i].first << " " << cusum[i].second << endl;
        //        }
        
        for(int kassa = 0; kassa < k;kassa++){
            ll S; scanf("%lld",&S);
            ll ans = -(INF),L = -1, R= -1;
            ll l = 0,r = 0,sum = -(INF);
            while(true){
                while(r < n && sum < S){
                    r++;
                    if(l >= r){
                        sum = -INF;
                        continue;
                    }
                    sum = cusum[r].first - cusum[l].first;
                    if(abs(S - sum) < abs(S - ans)){
                        ans = sum;
                        L = min(cusum[l].second,cusum[r].second);
                        R = max(cusum[l].second,cusum[r].second);
                        // cout << "[" << L << " " << R << "]" << endl;
                    }
                }
                if(sum < S) break;
                l++;
                if(l >= r) {
                    sum = -INF;
                    continue;
                }
                sum = cusum[r].first - cusum[l].first;
                if(abs(S - sum) < abs(S - ans)){
                    ans = sum;
                    L = min(cusum[l].second,cusum[r].second);
                    R = max(cusum[l].second,cusum[r].second);
                    //cout << "[" << L << " " << R << "]" << endl;
                }
            }
            cout << ans << " " << min(L,R) + 1 << " " << max(L,R) << endl;
        }
        
    }
    return 0;
}
