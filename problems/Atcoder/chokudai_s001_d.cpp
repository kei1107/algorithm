#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:https://chokudai_s001.contest.atcoder.jp//tasks/chokudai_S001_d>
問題文============================================================
数列 a を昇順ソートしたものを、スペース区切りにして 1 行で出力してください。
=================================================================

解説=============================================================
hai
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n);
    for(auto& in:a) cin >> in;
    sort(a.begin(),a.end());
    for(auto v:a){
        cout << v << " ";
    }
    cout << endl;
	return 0;
}
