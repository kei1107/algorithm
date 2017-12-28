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
vector<pll> WS;
bool comp(pll i,pll j){
    return i.first + i.second > j.first + j.second;
}

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N; cin >> N;
    ll W_sum = 0;
    WS.resize(N);
    for(int i = 0; i < N;i++){
        cin >> WS[i].first >> WS[i].second;
        W_sum += WS[i].first;
    }
    
    sort(WS.begin(),WS.end(),comp);
//    for(auto p:WS){
//        cout << p.first << " " << p.second << endl;
//    }
//
    ll ans = -(LINF);
    for(int i = 0; i < N;i++){
        W_sum -= WS[i].first;
        ans = max(ans,W_sum - WS[i].second);
    }
    cout << ans << endl;
	return 0;
}
