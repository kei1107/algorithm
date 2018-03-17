#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream &operator << (ostream& out,const pair<S,T>& o){
    out << "(" << o.first << "," << o.second << ")"; return out;
}

/*
<url:https://arc079.contest.atcoder.jp/tasks/arc079_b>
問題文============================================================
 長さ N の非負整数列 ai に対し、数列の最大値が N−1 以下になるまで以下の操作を繰り返し行うことを考えます。
 
 数列のうち最も大きい要素を求める、複数ある場合はどれか 1 つ選ぶ。
 この要素の値を N 減らす。これ以外の要素の値を 1 増やす。
 なお、この操作を行い続けると、いつかは数列の最大値が N−1 以下になることが証明できます。
 
 ここで、整数 K が与えられるので、
 この操作を行う回数がちょうど K 回になるような数列 ai を 1 つ求めてください。
 なお、この問題の入出力の制約下では、かならず 1 つは条件を満たすような数列が存在することが示せます。
=================================================================

解説=============================================================
 
 問題を逆から考える
 
 全ての数列がN-1以下であるものから
 要素を一つ選択して、値をN増やす。それ以外を1減らすという
 という条件でK回行うと考える
 
 ここで,
 
 0,1,2,...,N-1
 という数列を考え
 左から順番に要素を選択していけば N 回の施行において 全ての数列の値は +1 される
 
 よって、K/N加算された数列を K%N 回シュミレーションをすればいい
 
================================================================
*/
void solve(){
    ll K; cin >> K;
    const ll N = 50;
    vector<ll> a(N,0);
    iota(a.begin(),a.end(),0);
    for(int i = 0; i < N;i++) a[i] += K/N;
    K %= N;
    for(int i = 0; i < K;i++){
        a[i] += (N+1);
        for(int j = 0; j < N;j++) a[j]--;
    }
    cout << N << endl;
    for(int i = 0; i< N;i++){
        cout << a[i] << " ";
    }
    cout << endl;
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    solve();
	return 0;
}
