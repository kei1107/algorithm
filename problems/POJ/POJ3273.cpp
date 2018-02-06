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
<url:http://poj.org/problem?id=3273>
問題文============================================================
 要素数Nの数列{a_i}が与えられる．
 この数列をM個の連続した部分に分け，各部分の要素の合計の最大値を最小化したい．
=================================================================

解説=============================================================
 合計の最大値についてにぶたんすれば良い
 
 最大値をmと定めた時、合計がm以下となるような部分列の個数がM以下かどうかで判定
================================================================
*/

ll N,M;
vector<ll> S;

bool ok(ll m){
    ll Sum = 0;
    ll cnt = 1;
    for(int i = 0; i < N;i++){
        if(Sum + S[i] <= m){
            Sum += S[i];
        }else{
            cnt++;
            Sum = S[i];
        }
    }
    return cnt <= M;
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    cin >> N >> M;
    S.resize(N);
    ll l = 0, r = LINF;
    for(int i = 0; i < N;i++){
        cin >> S[i];
        l = max(l,S[i]);
    }
    l--;
    while(r - l > 1){
        ll m = (l+r)/2;
        if(ok(m)){
            r = m;
        }else{
            l = m ;
        }
    }
    cout << r << endl;
	return 0;
}
