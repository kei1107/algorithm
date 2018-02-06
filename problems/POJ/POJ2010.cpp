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
 <url:http://poj.org/problem?id=2010>
 問題文============================================================
 コストa[i]と評価値s[i]の組の列がある．
 この中から，N（奇数）個の要素をコストの合計がFを超えないように選び，
 メディアンを最大化したい
 =================================================================
 
 解説=============================================================
 median は　決め打ちできるので、
 N = 2K + 1とし、medianを i番目のコストとすれば
 iより小さいインデックスの中からK個選ぶ時のコストの最小 + iより大きいインデックスからK個選ぶ時のコストの最小
 を足し合わせたものが、そのメディアンを選ぶ時のコストの最小となる
 ================================================================
 */
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    int N,C; ll F; cin >> N >> C>> F;
    vector<pll> A(C);
    for(int i = 0; i < C;i++) cin >> A[i].first >> A[i].second;
    
    sort(A.begin(),A.end());
    
    int T = N/2;
    vector<ll> l(C,LINF),r(C,LINF);
    priority_queue<ll> pq1;
    ll Sum = 0;
    for(int i = 0; i <C;i++){
        if((int)pq1.size() == T) l[i] = Sum;
        Sum+=A[i].second;
        pq1.push(A[i].second);
        if((int)pq1.size() > T){
            Sum -= pq1.top();
            pq1.pop();
        }
    }
    
    priority_queue<ll> pq2;
    Sum = 0;
    for(int i = C-1; i >= 0;i--){
        if((int)pq2.size() == T) r[i] = Sum;
        Sum += A[i].second;
        pq2.push(A[i].second);
        if((int)pq2.size() > T){
            Sum -= pq2.top();
            pq2.pop();
        }
    }

    ll res = -1;
    for(int i = 0; i < C;i++){
        if(l[i]+r[i]+A[i].second <= F) res = max(res,A[i].first);
    }
    cout << res << endl;
    return 0;
}
