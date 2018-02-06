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
 <url:http://poj.org/problem?id=3258>
 問題文============================================================
 スタートの石とゴールの石が川の中にあって，その間の距離がLだけ離れている．
 スタートとゴールの間には，N個の石が一列に並んでいて，i番目の石はスタートからd_iだけ離れた位置にある．
 スタートとゴールの間の石をM個以下だけ取り除いて，石（スタートとゴールも含む）の間の距離の最小値を最大化したい．
 =================================================================
 
 解説=============================================================
 にぶたん
 
 互いの距離が小さい順に距離を見ていって、ある距離D以上の距離を必要としないかどうかについてにぶたんすれば良い
 ================================================================
 */
vector<int> R;
int L,N,M;
bool ok(int m){
    int cnt = 0;
    int l = 0;
    for(int i = 1;i<=N;i++){
        if(R[i] - l < m){
            cnt++;
            if(cnt > M)return false;
        }else{
            l = R[i];
        }
    }
    return true;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> L >> N >> M;
    R.resize(N+2);
    R[0] = 0;
    for(int i = 1;i<=N;i++){
        cin >> R[i];
    }
    R[N+1] = L;
    sort(R.begin(),R.end());
    int l = 0,r = L;
    while(l < r){
        //cout << l << " " << r << endl;
        int m = (l+r+1)/2;
        if(ok(m)){
            l = m;
        }else{
            r = m - 1;
        }
    }
    cout << l << endl;
    return 0;
}
