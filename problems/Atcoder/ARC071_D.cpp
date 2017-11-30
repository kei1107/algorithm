#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
 <url:https://arc071.contest.atcoder.jp/tasks/arc071_b>
 問題文============================================================
 2 次元平面上に x 軸と平行な直線が m 本と y 軸と平行な直線が n 本引いてあります。
 x 軸と平行な直線のうち下から i 番目は y=yi で表せます。
 y 軸と平行な直線のうち左から i 番目は x=xi で表せます。
 
 この中に存在しているすべての長方形についてその面積を求め、 合計を 10^9+7 で割ったあまりを出力してください。
 
 つまり、1≤i<j≤n と 1≤k<l≤m を満たすすべての組 (i,j,k,l) について、
 直線 x=xi, x=xj, y=yk, y=yl で囲まれる 長方形の面積を求め、
 合計を 10^9+7 で割ったあまりを出力してください。
 =================================================================
 解説=============================================================
 
 よく考えると答えたはx軸、y軸について独立して、Σ(xj - xi) * Σ(yj - yi) となる。
 ここでΣ(xj - xi)について考える。このままだとO(n^2)となりTLEするが、
 この式は Σ((k+1)xk - (n-k)xk))と書き換えることができるためO(n)となる
 
 ================================================================
 */

const ll MOD = 1e9+7;
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n,m; cin >> n >> m;
    vector<ll> x(n),y(m);
    for(auto& xin:x) cin >> xin;
    for(auto& yin:y) cin >> yin;
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    ll x_sum = 0,y_sum = 0;
    for(int i = 0; i < n;i++){
        (x_sum += ((i*x[i])%MOD - (n-(i+1))*x[i])%MOD + MOD)%=MOD;
    }
    for(int i = 0; i < m;i++){
        (y_sum += ((i*y[i])%MOD - (m-(i+1))*y[i])%MOD + MOD)%=MOD;
    }
    ll res = x_sum * y_sum;
    res%=MOD;
    cout << res << endl;
    return 0;
}
