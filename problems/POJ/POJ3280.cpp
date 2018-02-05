#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <bitset>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <numeric>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <deque>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:http://poj.org/problem?id=3280>
問題文============================================================

 N種類の小文字のアルファベットのみからなる長さMの文字列sが与えられる。
 各N種類の文字について追加・削除したときのコストがそれぞれ与えられる。
 文字の追加・削除は好きな位置に行うことができ、位置によらずコストは一定である。
 このとき、sを回文にするのに必要な最小のコストを答える。
 
=================================================================

解説=============================================================
 参照: https://eagletmt.github.io/contests/blog/poj-3280/
 区間dp
 
 ある区間が既に回文となっている時、そこから回文を広げるには、追加した文字を他方の端に
 追加するか、追加した文字を削除するかのどちらかとなる。
 つまり、ある文字に関して、min(追加コスト,削除コスト）のみを見ていけば良い
 
 dp[i][j] := [i,j)を回文とするときの最小コストとしたとき
 
 漸化式
 dp[i][i] = dp[i][i+1] = 0 (長さが 0, 1 の文字列は回文)
 dp[i-1][j] := dp[i][j] + cost[i-1 番目の文字] (区間を左側にのばす)
 dp[i][j+1] := dp[i][j] + cost[j 番目の文字] (区間を右側にのばす)
 dp[i-1][j+1] := dp[i][j]  (i-1 番目の文字と j 番目の文字が等しいとき、コスト無しで区間を両側にのばす)
 
================================================================
*/

#define MAX_M 2000
ll dp[MAX_M][MAX_M+1];

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N,M; cin >> N >> M;
    string s; cin >> s;
    int Cost[26];
    for(int i = 0; i < N;i++){
        char c;
        int cost1,cost2;
        cin >> c >> cost1 >> cost2;
        Cost[c-'a'] = min(cost1,cost2);
    }
    for(int i = 0; i < M;i++){
        fill(dp[i],dp[i] + M + 1,INF);
        dp[i][i] = dp[i][i+1] = 0;
    }

    for(int i = 0; i < M;i++){
        for(int j = 0; j < M;j++){
            int k = i + j;
            if(j > 0){
                dp[j-1][k] = min(dp[j-1][k],dp[j][k] + Cost[s[j-1] - 'a']);
            }
            if(k < M){
                dp[j][k+1] = min(dp[j][k+1],dp[j][k] + Cost[s[k] - 'a']);
            }
            if(j > 0 && k < M && s[j-1] == s[k]){
                dp[j-1][k+1] = min(dp[j-1][k+1],dp[j][k]);
            }
        }
    }
    cout << dp[0][M] << endl;
    return 0;
}
