#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://arc088.contest.atcoder.jp/tasks/arc088_b>
問題文============================================================
 0 と 1 からなる文字列 S が与えられます。
 以下の操作を好きな回数繰り返すことで S の要素をすべて 0 にできるような、|S| 以下の最大の整数 K を求めてください。
 
 S の長さ K 以上の連続する区間 [l,r] を選ぶ(すなわち、r−l+1≥K が満たされる必要がある)。
 l≤i≤r なるすべての整数 i に対し、Si が 0 なら Si を 1 に、Si が 1 なら Si を 0 に置き換える。

=================================================================

解説=============================================================
 ある文字を変えようとした時、
 以下のような形になっていれば
     00001000
 
 => 11111000 => 00000000
 or
 => 00001111 => 00000000
 
 で変更可能である
 すなわち k番目とk+1番目で文字が異なるとすれば max(k,N-k)がその文字を変更するのに必要な整数である。
 また、左右の端から順番に見て行けば、都合の良い形に形を変えていけるので
 全ての k について見た時の max(k,N-k)の最小値が答え
================================================================
*/
inline int char2num(char c){ return c == '0'?0:1; }
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    string S; cin >> S;
    int ans = (int)S.length();
    for(int i = 0; i < (int)S.length()-1;i++){
        if(S[i] == S[i+1]) continue;
        ans = min(ans,max(i+1,(int)S.length()-(i+1)));
    }
    cout << ans << endl;
	return 0;
}
