#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://arc082.contest.atcoder.jp/tasks/arc082_b>
問題文============================================================
 1,2,..,N からなる順列 p1,p2,..,pN が与えられます。 次の操作を何回か (0回でもよい) 行うことが出来ます。
 
 操作: 順列で隣り合う二つの数を選んでスワップする。
 
 何回か操作を行って、任意の 1≤i≤N に対して pi≠i となるようにしたいです。 必要な操作の最小回数を求めてください。
 制約
 2≤N≤105
 p1,p2,..,pN は 1,2,..,N の順列である。
=================================================================

解説=============================================================

 数列を最初から順に見ていく、
 ここでpi = i となっているものがあれば、
 swapで pi+1 の値と交換してやれば良い
 
 最後の i == N だけは、異なれば pi-1と交換する
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N; cin >> N;
    vector<ll> p(N+1);
    for(int i = 1; i <= N;i++) cin >> p[i];
    ll cnt = 0;
    for(int i = 1; i <= N;i++){
        if(p[i] == i){
            if(i == N){
                swap(p[i-1],p[i]); cnt++;
                continue;
            }else{
                swap(p[i],p[i+1]); cnt++;
                continue;
            }
        }
    }
    cout << cnt << endl;
	return 0;
}
