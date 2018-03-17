#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://agc010.contest.atcoder.jp/tasks/agc010_b>
問題文============================================================
 N 個の箱が円環状に並んでおり、i 番目の箱には Ai 個の石が入っています。
 
 以下の操作を繰り返して、全ての石を取り除くことができるか判定してください。
 
 箱を一か所選ぶ。それを i 番目としたとき、1 から N の各 j に対して、i+j 番目の箱から石をちょうど j 個取り除く。
 ただし、N+k 番目と表される箱は k 番目の箱と同一視するものとする。
 各操作において、取り除きたい個数の石がない箱があるときは、その操作を行えないことに注意してください
=================================================================

解説=============================================================

 操作回数 k = (石の総和) / (N*(N+1)/2) でわかる
 
 ここで
 d[i] = Ai+1 - Ai
 とすると
 
 一回の操作で d[i] は　一箇所だけ +(n-1)され　その他は (-1) される。
 ここで問題は d[i] を k回操作を行うことによって　全て 0 にできるかどうかということになる
 
 操作に関して、もっと簡単にすると
 
 d[i]をk回全て一様に -1 にして、その後　k回の操作毎に 1つ選んで+N すると言い換えることができるので
 条件として
 
 d[i] - k が 負であり　N の倍数　となることが必要十分となる
 =============================================================
*/
string solve(){
    ll N; cin >> N;
    vector<ll> A(N);
    ll sum = 0;
    for(auto &in:A){ cin >> in; sum += in; }
    if(sum%(N*(N+1)/2) != 0) return "NO";
    ll k = sum / (N*(N+1)/2);
    for(int i = 0; i < N;i++){
        ll d = A[(i+1)%N] - A[i];
        if(d - k > 0 || abs(d-k)%N != 0) return "NO";
    }
    return "YES";
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    cout << solve() << endl;
	return 0;
}
