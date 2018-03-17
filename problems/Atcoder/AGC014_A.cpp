#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://agc014.contest.atcoder.jp/tasks/agc014_a>
問題文============================================================
 高橋君と青木君とすぬけ君はそれぞれクッキーを A,B,C 個持っています。
 
 この 3 人はお互いにクッキーを交換することにしました。具体的には、以下の操作を繰り返します。
 
 3 人は同時に、各々が持っているクッキーを半分ずつに分けて、残りの 2 人にそれぞれ一方を渡す。
 ただし、誰かの持っているクッキーの個数が奇数個になったら、そこで操作を繰り返すのをやめます。
 
 さて、クッキーの交換は何回行うことができるでしょうか。 ただし、無限に続けられる場合もあることに注意してください。
=================================================================

解説=============================================================

 貪欲シミュレーションでok
 
================================================================
*/

bool check(ll A,ll B,ll C){
    return (A|B|C)&1;
}
void exchange(ll &A,ll& B,ll &C){
    ll tA = B/2 + C/2;
    ll tB = A/2 + C/2;
    ll tC = A/2 + B/2;
    A = tA;
    B = tB;
    C = tC;
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll A,B,C; cin >> A >> B >> C;
    for(int i = 0; i < 10000000;i++){
        if(check(A,B,C)){
            cout << i << endl;
            return 0;
        }
        exchange(A,B,C);
    }
    cout << -1 << endl;
	return 0;
}
