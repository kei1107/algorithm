#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://abc057.contest.atcoder.jp/tasks/abc057_c>
問題文============================================================
 整数 N が与えられます。
 ここで、2 つの正の整数 A,B に対して、
 F(A,B) を「10 進表記における、A の桁数と B の桁数のうち大きい方」と定義します。
 例えば、F(3,11) の値は、3 は 1 桁、11 は 2 桁であるため、F(3,11)=2 となります。
 2 つの正の整数の組 (A,B) が N=A×B を満たすように動くとき、F(A,B) の最小値を求めてください。
=================================================================

解説=============================================================

 Aの探索範囲は 1 ... X (X*X <= N) までで良い
 よって貪欲で間に合う
 
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N; cin >> N;
    int ans = INF;
    for(ll A = 1; A*A <= N; A++){
        if(N%A == 0){
            ll B = N/A;
            ans = min(ans,max((int)to_string(A).length(),(int)to_string(B).length()));
        }
    }
    cout << ans << endl;
	return 0;
}
