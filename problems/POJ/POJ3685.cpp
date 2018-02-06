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
<url:http://poj.org/problem?id=3685>
問題文============================================================
 N次正方行列があって，その(i,j)-成分はi^2+100000*i+j^2-100000*j+i*jで与えられる．
 M番目に小さい要素の値はいくつか．
=================================================================

解説=============================================================
 ok(x) := M番目の要素がx以上であるかどうか（x未満の要素の個数がM未満）
 
 i^2 + 100000*i + j^2 - 100000*j + i*j
 
 にぶたんのにぶたん
 
 解に関してjを固定してしまえば行に関しては単調増加と見做すことができるため、
 まずM番目に小さい要素mについてにぶたんを行い、条件反転の内部に関して、jを固定しmよりも小さいか
 どうかに関してにぶたんを行い個数を求める
================================================================
*/
ll N,M;

inline ll f(ll i,ll j){
    return i*i + 100000LL*i + j*j - 100000LL*j + i*j;
}

bool ok(ll x){
    ll cnt = 0;
    for(int j = 1; j <= N;j++){
        ll l = 0, r = N+1;
        while(r-l > 1){
            ll m = (l+r)/2;
            if(f(m,j) < x){
                l = m;
            }else{
                r = m;
            }
        }
        cnt += min(N,l);
    }
    return cnt < M;
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll T; cin >> T;
    for(int i = 0; i < T;i++){
        cin >> N >> M;
        ll l = -(LINF), r = LINF;
        while(r - l > 1){
            ll m = (l+r)/2;
            if(ok(m)){
                l = m;
            }else{
                r = m;
            }
        }
        cout << l << endl;
    }
	return 0;
}
