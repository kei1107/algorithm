#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
 <url:https://www.ioi-jp.org/joi/2009/2010-ho-prob_and_sol/2010-ho.pdf>
 問題文============================================================
 あるN(2<=N<=10^5)個のつららの長さが与えられる。
 i個目のつららは最初長さがai(>=1)であり、両端(i-1個目及びi+1個目）のつららよりも
 長さが長い時、1時間あたり1cm伸びる
 つららは長さがL(2<=L<=50000)に達した瞬間に根元から折れ、長さが0となる。
 
 全てのつららが折れるまでにかかる時間を求める(最初の段階では隣り合うつららの長さは異なる)
 =================================================================
 解説=============================================================
 
 dp
 
 dp[i] := i番目のつららが解けるまでの時間
 
 各つららを降順に並べ替え、長さが大きい順に見ていく
 そのつららの両端のつららを見て,値の更新が行われていなかったら（:= 自分よりも短い）
  dp[i] = L - a[idx]
 値の更新が行われていたら、大きい方の値を見て
  dp[i] = dp[large_len] + L - a[idx]
 ================================================================
 */
ll N,L;
vector<pll> a;
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> N >> L;
    a.resize(N);
    for(int i = 0; i < N;i++){
        ll l; cin >> l;
        a[i] = {l,i+1};
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    
    vector<ll> dp(N+2,0);
    for(int i = 0; i < N;i++){
        ll idx = a[i].second;
        if(dp[idx - 1] == 0 && dp[idx + 1] == 0){
            dp[idx] += L - a[i].first;
            continue;
        }
        if(dp[idx - 1] > dp[idx + 1]){
            dp[idx] += dp[idx - 1] + L - a[i].first;
            continue;
        }
        if(dp[idx + 1] > dp[idx - 1]){
            dp[idx] += dp[idx + 1] + L - a[i].first;
            continue;
        }
    }
    ll res = 0;
    for(auto v:dp){
        res = max(res,v);
    }
    cout << res << endl;
    return 0;
}
