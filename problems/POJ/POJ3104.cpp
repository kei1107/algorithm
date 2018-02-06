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
<url:http://poj.org/problem?id=3104>
問題文============================================================
 洗濯物がn個あって，自然乾燥だと1分間に洗濯物の水が1だけ減る．
 暖房機を使えば，1分間にkだけの水を減らすことができるが，これは1分間に1つの洗濯物についてだけしか使えない．
 暖房機を最適に使った時，すべての洗濯物を乾かすのに必要な最小の時間はいくつか．
=================================================================

解説=============================================================

 洗濯物を乾かすために必要な時間に関してにぶたん
 
 判定の基準として、
 暖房機を使った時1分間にkの水を減らすことができる => 他よりもk-1多く水が減る
 とみなせる
 
 よって水分量が基準時間mよりも多い洗濯物に関して、順番に見て行き、乾かすのに必要な時間を計算すれば良い
 
================================================================
*/

ll n;
ll k;
ll a[100001];
bool ok(ll m){
    ll t = 0;
    for(int i = 0; i < n;i++){
        if(a[i] - m <= 0)continue;
        t += (a[i] - m + (k - 1))/k;
    }
    return t <= m;
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    cin >> n;
    ll l = 0, r = 0;
    for(int i = 0; i< n;i++){
        cin >> a[i];
        r = max(r,a[i]);
    }
    cin >> k;
    k--;
    if(k == 0){
        cout << r << endl;
        return 0;
    }
    while(r-l > 1){
        ll m = (l+r)/2;
        if(ok(m)){
            r = m;
        }else{
            l = m;
        }
    }
    cout << r << endl;
	return 0;
}
