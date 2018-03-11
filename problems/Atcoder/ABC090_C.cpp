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
<url:https://beta.atcoder.jp/contests/abc090/tasks/arc091_a>
問題文============================================================
 縦横に無限に広がるマス目があり、そのうちの連続する N 行 M 列の領域のすべてのマスに表裏の区別できるカードが置かれています。
 最初はすべてのカードが表を向いています。
 
 以下の操作を、カードが置かれている全てのマスについて 1 度ずつ行います。
 
 そのマスと辺または点で接する 8 つのマスと、そのマスの合計 9 マスについて、カードが存在するなら裏返す。
 すべての操作を行った後の各カードの状態は操作を行う順番に依らないことが証明できます。
 すべての操作を行った後、裏を向いているカードの枚数を求めてください。
 
=================================================================

解説=============================================================

 あるマスに注目した時,そのマスが裏を向いている状態で終了するには、
 奇数回、そのマスが裏返されることが条件となる。
 よって、マスの大きさにより、奇数回裏返されるものを数えると
 
 if(N >= 2 && M >= 2) res = (N-2)*(M-2);
 else if(N >= 2 && M == 1) res = N - 2;
 else if(M >= 2 && N == 1) res = M - 2;
 else if(N == 1 && M == 1) res = 1;
 
 と場合分けできる
================================================================
*/
ll solve(){
    ll res = 0;
    ll N,M; cin >> N >> M;
    if(N >= 2 && M >= 2) res = (N-2)*(M-2);
    else if(N >= 2 && M == 1) res = N - 2;
    else if(M >= 2 && N == 1) res = M - 2;
    else if(N == 1 && M == 1) res = 1;
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}

