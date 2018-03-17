#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://code-thanks-festival-2017-open.contest.atcoder.jp/tasks/code_thanks_festival_2017_d>
問題文============================================================
 あなたはバスツアーを計画しています。
 
 バスツアーの参加者は必ず 1 グループ N 人で申し込みます。運転手を除いた各バスの定員は必ず M 人です。
 このバスツアーは、全ての参加者がバスに乗り切れるようなバスの最小台数で行います。
 同じグループに属する人が必ずしも同じバスに乗り込む必要はありません。
 
 このバスツアーに参加するグループ数には上限がないため、
 申し込みを締め切るまでバスツアーに参加するグループ数は分かりません。
 したがって、参加者の申し込み具合によってはバスに空席が生じてしまいます。
 最大で何席の空席ができるでしょうか?
=================================================================

解説=============================================================
N,2N,3N,4N,....,MN
 
 グループ数 x , バス数 y
 ans = M*y - N*x mod M
     = -Nx mod M
     = M - (Nx mod M)
     = M - k        (ただし、k ≡ Nx mod M となる最小のk)
 
 kについて考える
     k*Ma = N*x
     k = N*x / Ma
 
 N*x/Ma が整数 => x が Maの倍数
 
 k は gcd(N,M)の倍数 => 最小の値は gcd(N,M)
 
 よって
 ans = M - gcd(N,M);
================================================================
*/
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N,M; cin >> N >> M;
    cout << M - gcd(N,M) << endl;
	return 0;
}
