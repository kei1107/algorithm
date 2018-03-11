#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://beta.atcoder.jp/contests/abc089/tasks/abc089_c>
問題文============================================================
 N 人の人がいて、 i 番目の人の名前は Si です。
 
 この中から、以下の条件を満たすように 3 人を選びたいです。
 
 全ての人の名前が M,A,R,C,H のどれかから始まっている
 同じ文字から始まる名前を持つ人が複数いない
 これらの条件を満たすように 3 人を選ぶ方法が何通りあるか、求めてください。ただし、選ぶ順番は考えません。

=================================================================

解説=============================================================
5種類の対応する頭文字がそれぞれ何人いるか確認する( = num[5] )
 ans = ΣΣΣnum[i]*num[j]*num[k] ( i < j < k)
================================================================
*/

void solve_C(){
    ll N; cin >> N;
    vector<string> S(N);
    for(auto &in:S) cin >> in;
    ll MARCH[5] = {};
    char C[5] = {'M','A','R','C','H'};
    for(int i = 0 ;i < N;i++){
        for(int j = 0; j < 5;j++){
            if(S[i][0] == C[j]) MARCH[j]++;
        }
    }
    ll ans = 0;
    for(int i = 0; i < 5; i++){
        for(int j = i + 1; j < 5;j++){
            for(int k = j + 1; k < 5;k++){
                ans += MARCH[i] * MARCH[j] * MARCH[k];
            }
        }
    }
    cout << ans << endl;
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    solve_C();
	return 0;
}
