#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://agc018.contest.atcoder.jp/tasks/agc018_a>
問題文============================================================
 箱に N 個のボールが入っていて、i 番目のボールには整数 Ai が書かれています。
 すぬけ君は、次の操作を好きな回数だけ行うことができます。
 
 箱から二つのボールを取り出し、その二つのボールに書かれている数の差の絶対値を書いた新しいボールと一緒に箱に戻す。
 
 すぬけ君が、整数 K の書かれたボールが箱の中に入っている状態にできるかどうか判定してください。
=================================================================

解説=============================================================

 全ての要素の最大公約数をGCD , 最大値を Mとすれば
 
 K%GCD == 0 and K <= M
 がPOSSIBLEとなる答え
 
 難しいね
 
================================================================
*/

inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N,K; cin >> N >> K;
    vector<ll> A(N);
    for(auto &in:A){ cin >> in;}
    ll GCD = A[0];
    for(int i = 1; i < N;i++) GCD = gcd(GCD,A[i]);
    ll M = *max_element(A.begin(), A.end());
    if(K%GCD == 0 && K <= M){
        cout << "POSSIBLE" << endl;
    }else{
        cout << "IMPOSSIBLE" << endl;
    }
	return 0;
}
