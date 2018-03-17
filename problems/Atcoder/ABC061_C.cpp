#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://abc061.contest.atcoder.jp/tasks/abc061_c>
問題文============================================================
 空の配列が 1 つあります。
 この配列に、整数を配列に挿入する操作を N 回行います。
 i(1≦i≦N) 回目の操作では、配列に整数 ai を bi 個挿入します。
 N 回の挿入操作後の配列の中で、K 番目に小さい数を求めてください。
 例えば、配列が {1,2,2,3,3,3} の時、4 番目に小さい数は 3 となります。
 
=================================================================

解説=============================================================
シミュレーション
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N,K; cin >> N >> K;
    vector<pii> ab(N);
    for(auto &in:ab) cin >> in.first >> in.second;
    sort(ab.begin(),ab.end());
    for(int i = 0; i < N;i++){
        if(ab[i].second < K){
            K -= ab[i].second;
        }else{
            cout << ab[i].first << endl;
            break;
        }
    }
	return 0;
}
