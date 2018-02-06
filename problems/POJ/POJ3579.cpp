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
 <url:http://poj.org/problem?id=3579>
 問題文============================================================
 N個の配列が与えられる．
 この中から2つの要素を取り出し，その差を計算し別の数列とする．
 新しく作った配列の中央値を探索する．
 ただし，この問題において偶数長(m)の配列の中央値はm/2番目に小さい値と定義する．
 =================================================================
 
 解説=============================================================
 解を答えにしてにぶたんを行う
 
 その解よりも差が大きいものの個数を計算し、新しい数列の個数が計算した個数以上であるかどうかをみる
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
