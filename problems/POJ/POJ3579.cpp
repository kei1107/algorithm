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

ll N;
ll X[100005];
ll NC2;
bool ok(ll m){
    ll cnt = 0;
    ll l = 0;
    for(int i = 1; i < N;i++){
        while(X[i] - X[l] > m)l++;
        cnt += i - l;
    }
    return cnt <= (NC2-1)/2;
}
int main(void) {
//    cin.tie(0); ios::sync_with_stdio(false);
    while(cin >> N){
        for(int i = 0; i < N;i++) scanf("%lld",&X[i]);
        sort(X,X+N);
        NC2 = N*(N-1)/2;
        
        ll l = 0, r = INF;
        while(r-l > 1){
            ll m = (l+r)/2;
            if(ok(m)){
                l = m;
            }else{
                r = m;
            }
        }
        cout << r << endl;
    }
    return 0;
}
