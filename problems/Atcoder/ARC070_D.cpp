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
<url:https://arc070.contest.atcoder.jp/tasks/arc070_b>
問題文============================================================
 シカのAtCoDeerくんは正整数が書かれたカードを N 枚持っています。i(1≦i≦N) 枚目に書かれている数は ai です。
 AtCoDeerくんは大きい数が好きなので、
 カードに書かれた数の総和が K 以上になるようなカードの部分集合をよい集合と呼びます。
 
 そして、各カード i に対して、そのカードが不必要かどうかを次のように判定します。
 
 「カード i を含む任意のよい集合に対して、その集合からカード i を除いたものもよい集合」ならカード i は不必要
 それ以外の場合は、不必要でない
 
 不必要なカードの枚数を求めてください。
 ただし、それぞれの判定は独立に行われ、不必要だからと言ってカードが途中で捨てられたりすることはありません。

 入力は全て整数
 1≦N≦5000
 1≦K≦5000
 1≦ai≦10^9(1≦i≦N)
=================================================================

解説=============================================================

 不必要なカードは昇順(降順）に並べた時、右から（左から）連続するものであるとわかる。
 ここで、
 Kを超えない、集合を作り、そこにa[i]を加えた時、
 全体の総和が Kを超えるかどうかの境目で必要、不必要の判断ができる
 
 さて、Kを超えない最適な集合を作るには
 まず、要素の大きい順から考えて、それぞれの要素を含むべきかどうかを判断しなければならない
 
 よって、降順に要素を並べ
 各i[0..N-1] から　集合を作って言った際に a[i]を含めて Kを超えるギリギリの要素jまで加算して行く、
 K以上となった時、i...j までが必要なカードだとわかる
 さらにjを加算せずにインクリメントして言って、 その　K以上、K未満である境を判断して行く
 
================================================================
*/
ll N,K;
vector<ll> a;
ll solve(){
    ll res = 0;
    cin >> N >> K;
    a.resize(N); for(auto &in:a) cin >> in;
    sort(a.begin(),a.end()); reverse(a.begin(),a.end());
    ll ans = -1;
    for(int i = 0; i < N;i++){
        ll sum = 0;
        for(ll j = i; j < N;j++){
            if(sum + a[j] < K){ sum += a[j]; continue; }
            ans = max(ans,j);
        }
    }
    return res = N - ans - 1;
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    cout << solve() << endl;
	return 0;
}
