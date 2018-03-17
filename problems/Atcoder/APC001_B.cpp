#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://apc001.contest.atcoder.jp/tasks/apc001_b>
問題文============================================================
 長さ N の数列 a1,a2,..,aN と b1,b2,..,bN が与えられます。
 以下の操作を 0 回以上好きなだけ繰り返して、数列 a と b を一致させられるか判定してください。
 
 操作： 1 以上 N 以下の整数 i,j (一致していてもよい)を選び、次の2つのことを同時に行う。
 
 ai に 2 を足す
 bj に 1 を足す

=================================================================

解説=============================================================
全体で必要な操作回数は
 Σb - Σa
 
 ここで、 ai < bi であり Σ(bi - ai + 1)/2 の個数が全体で必要な操作回数以下であればyes
 そうでなければ no となる
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N; cin >> N;
    vector<ll> a(N),b(N);
    for(auto&in:a) cin >> in;
    for(auto&in:b) cin >> in;
    ll Cnt = accumulate(b.begin(),b.end(),0LL) - accumulate(a.begin(), a.end(),0LL);
    for(int i = 0; i < N;i++){
        if(a[i] < b[i]){
            Cnt -= (b[i]-a[i]+1)/2;
        }
    }
    if(Cnt >= 0) cout << "Yes" << endl;
    else cout << "No" << endl;
	return 0;
}
