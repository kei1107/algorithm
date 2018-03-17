#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://arc061.contest.atcoder.jp/tasks/arc061_a>
問題文============================================================
 1 以上 9 以下の数字のみからなる文字列 S が与えられます。
 この文字列の中で、あなたはこれら文字と文字の間のうち、いくつかの場所に + を入れることができます。
 一つも入れなくてもかまいません。 ただし、+ が連続してはいけません。
 
 このようにして出来る全ての文字列を数式とみなし、和を計算することができます。
 
 ありうる全ての数式の値を計算し、その合計を出力してください。
=================================================================

解説=============================================================

 文字列に+を挿入する場所を実際に貪欲に決めて計算すれば良い
================================================================
*/

ll ans = 0;
string S;
void dfs(int n,ll v,ll sum){
    if(S.length() == n){
        sum += v; ans += sum;
        return ;
    }
    ll next = v*10 + S[n]-'0';
    dfs(n+1,0,sum+next);
    dfs(n+1,next,sum);
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    cin >> S;
    dfs(0,0,0);
    cout << ans/2 << endl;
	return 0;
}
