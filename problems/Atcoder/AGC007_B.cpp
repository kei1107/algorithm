#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://agc007.contest.atcoder.jp/tasks/agc007_b>
問題文============================================================
 集合 {1,2,…,N} の要素を並び替えた順列 p が与えられます。
 以下の条件をすべて満たす 2 つの正整数列 a1, a2, ..., aN および b1, b2, ..., bN を構成してください。
 
     すべての i に対し、1≤ai,bi≤109
     a1<a2<…<aN
     b1>b2>…>bN
     a_p1+b_p1<a_p2+b_p2<…<a_pN+b_pN

 制約
 2≤N≤20,000
 p は集合 {1,2,…,N} の要素を並び替えた順列である。
=================================================================

解説=============================================================
r_pi = i ( 1<= i <= n)
 
 Ai = 30000*i               条件を満たす
 Bi = 30000*(n-i) + ri      条件を満たす
 
 
 =>
     Api + Bpi = 30000*pi + 30000*(n-pi)+r_pi = 30000*n + i
         < 30000*n + i+1 = 30000*p_i+1 + 30000*(n - p_i+1) + r_p_i+1 = Ap_i+1 + Bp_i+1

 
 難しい
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N; cin >> N;
    vector<ll> p(N);
    for(auto &in:p) cin >> in;
    for(int i = 1; i <= N;i++){
        cout << 30000 * i << " ";
    }
    cout << endl;
    vector<ll> r(N+1);
    for(int i = 1; i <= N;i++){
        r[p[i-1]] = i;
    }
    for(int i = 1; i <= N;i++){
        cout << 30000 * (N - i) + r[i] << " ";
    }
    cout << endl;
	return 0;
}
