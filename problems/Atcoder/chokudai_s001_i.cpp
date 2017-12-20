#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:https://chokudai_s001.contest.atcoder.jp/tasks/chokudai_S001_i>
問題文============================================================
数列 a に含まれる連続した区間のうち、和が N になるものがいくつ存在するかを出力しなさい。
=================================================================

解説=============================================================
しゃくとり
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N; cin >> N;
    vector<ll> a(N);
    for(auto& in:a) cin >> in;
    ll l = 0,r = 0;
    ll ans = 0;
    ll Sum = 0;
    while(true){
        if(r > N) break;
        if(Sum < N){
            if(r == N) break;
            Sum += a[r];
            r++;
            continue;
        }
        if(Sum == N){
            ans++;
            if(r == N) break;
            Sum += a[r];
            r++;
            continue;
        }
        if(Sum > N){
            Sum-=a[l];
            l++;
            continue;
        }
    }
    cout << ans << endl;
	return 0;
}
