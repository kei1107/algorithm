#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://arc071.contest.atcoder.jp/tasks/arc071_b>
問題文============================================================
 2 次元平面上に x 軸と平行な直線が m 本と y 軸と平行な直線が n 本引いてあります。
 x 軸と平行な直線のうち下から i 番目は y=yi で表せます。
 y 軸と平行な直線のうち左から i 番目は x=xi で表せます。
 
 この中に存在しているすべての長方形についてその面積を求め、合計を 109+7 で割ったあまりを出力してください。
 
 つまり、1≤i<j≤n と 1≤k<l≤m を満たすすべての組 (i,j,k,l) について、
 直線 x=xi, x=xj, y=yk, y=yl で囲まれる 長方形の面積を求め、
 合計を 10^9+7 で割ったあまりを出力してください。
 
=================================================================

解説=============================================================

 全ての長方形の面積なので、
     ΣΣ(xj-xi) * ΣΣ(yj-yi)
 が答え
 
 xに関して
 ΣΣ(xj-xi) :
     (x2-x1) + (x3-x1) + (x4-x1) + ... + (xn-x1) +
     (x3-x2) + (x4-x2) +  ... + (xn-x2) +
     .....
     (xn - x_n-1)
 
 よって、各 xiに関して出現回数からいえば
     (i-1)*xi - (n-i)*xi
 
 とO(1)で計算できる
 
 よって 面積は O(n+m)で計算できる
 
================================================================
*/

const ll MOD = 1e9+7;
ll solve(){
    ll n,m; cin >> n >> m;
    vector<ll> x(n),y(m);
    for(auto &in:x) cin >> in;
    for(auto &in:y) cin >> in;
    
    ll x_sum = 0, y_sum = 0;
    for(int i = 0; i < n;i++){
        (x_sum += (i*x[i] - (n-1-i)*x[i] + MOD)%MOD)%=MOD;
    }
    for(int i = 0; i < m;i++){
        (y_sum += (i*y[i] - (m-1-i)*y[i] + MOD)%MOD)%=MOD;
    }
    ll ret = x_sum * y_sum %MOD;
    return ret;
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    cout << solve() << endl;
	return 0;
}
