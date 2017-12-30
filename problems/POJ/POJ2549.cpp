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
 半分全列挙
 ================================================================
 */

struct S{
    ll v;
    int idx1;
    int idx2;
    S(){}
    S(ll v,int i,int j):v(v),idx1(i),idx2(j){}
    bool operator < (const S& o) const{
        return v < o.v;
    }
    bool operator > (const S& o) const{
        return v > o.v;
    }
};

ll a[1010];
int main(void) {
    //	cin.tie(0); ios::sync_with_stdio(false);
    ll n;
    while(cin >> n){
        if(n == 0) break;
        for(int i = 0; i < n;i++) scanf("%lld",&a[i]);
        
        vector<S> dp1,dp2;
        for(int i = 0; i < n;i++){
            for(int j = i+1;j < n;j++){
                dp1.push_back(S(a[i]+a[j],i,j));
            }
        }
        for(int i = 0; i < n;i++){
            for(int j = 0;j < n;j++){
                if(i == j) continue;
                dp2.push_back(S(a[i]-a[j],i,j));
            }
        }
        
        sort(dp1.begin(),dp1.end());
        sort(dp2.begin(),dp2.end());
        
        ll ans = -LINF;
        for(int i = 0; i < (int)dp1.size();i++){
            long l = lower_bound(dp2.begin(), dp2.end(),dp1[i]) - dp2.begin();
            long r = upper_bound(dp2.begin(), dp2.end(),dp1[i]) - dp2.begin();
            for(long j = l; j < r;j++){
                if(dp1[i].idx1 == dp2[j].idx1 || dp1[i].idx1 == dp2[j].idx2 || dp1[i].idx2 == dp2[j].idx1 || dp1[i].idx2 == dp2[j].idx2) continue;
                ans = max(ans,a[dp2[j].idx1]);
            }
        }
        
        if(ans == -LINF){
            cout << "no solution" << endl;
        }else{
            cout << ans << endl;
        }
    }
    return 0;
}
