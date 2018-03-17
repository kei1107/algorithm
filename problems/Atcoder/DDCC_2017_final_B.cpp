#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://ddcc2017-final.contest.atcoder.jp/tasks/ddcc2017_final_b>
問題文============================================================
 高橋君は N 台のロボットを持っています。ロボットには番号 1,2,…,N がついています。
 
 ロボットにはそれぞれ正整数が 1 つ書かれており、番号 i のロボットには ai が書かれています。
 
 番号 i のロボットは、正整数 X,Y を渡すと、gcd(X,ai)=gcd(Y,ai) ならば「似てる」、
 そうでないならば「似てない」と言います。なお、この問題では gcd(X,Y) は X と Y の最大公約数とします。
 
 正整数 X,Y について、N 台のロボット全てが「似てる」と言った時、X と Y はそっくりさんだとすることにします。
 
 正整数 Z が与えられるので、Z とそっくりさんな数のうち、もっとも小さいものを求めてください。
=================================================================

解説=============================================================
 なんかいかにも、gcd 取った後に lcm 取れって形してるので　取る
================================================================
*/

inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N,Z; cin >> N >> Z;
    vector<ll> a(N);
    ll ans = 1;
    for(int i = 0; i < N;i++){
        cin >> a[i];
        ans = lcm(ans,gcd(Z,a[i]));
    }
    cout << ans << endl;
	return 0;
}
