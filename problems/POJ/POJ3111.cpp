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
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:>
問題文============================================================

=================================================================

解説=============================================================

================================================================
*/
ll v[100005];
ll w[100005];
double y[100005];
pair<double,int> yy[100005];
int ans[100005];
ll n,k;

bool ok(double m){
    for(int i = 0; i < n;i++){
        y[i] = v[i] - m*w[i];
    }
    sort(y,y+n);
    double sum = 0;
    for(int i = 0; i < k;i++){
        sum += y[n-1-i];
    }
    return sum >= 0;
}

void solve(double m){
    for(int i = 0; i < n;i++){
        yy[i] = make_pair(v[i] - m*w[i],i+1);
    }
    sort(yy,yy+n);
    for(int i = 0; i < k;i++){
        ans[i] = yy[n-1-i].second;
    }
    sort(ans,ans+k);
    for(int i = 0; i < k;i++){
        cout << ans[i];
        if(i != k-1){
            cout << " ";
        }
    }
    cout << endl;
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    scanf("%lld %lld",&n,&k);
    for(int i = 0; i < n;i++){
        scanf("%lld %lld",&v[i],&w[i]);
    }
    double l = 0, r = LINF;
    for(int i = 0; i < 100;i++){
   //     cout << l << " " << r << endl;
        double m = (l+r)/2;
        if(ok(m)){
            l = m;
        }else{
            r = m;
        }
    }
    solve(r);
    
	return 0;
}
