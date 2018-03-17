#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
 <url:https://arc058.contest.atcoder.jp/tasks/arc058_a>
 問題文============================================================
 いろはちゃんはこだわりもので、嫌いな数字が K 個あり、それぞれ D1,D2,…,DK です。
 
 いろはちゃんはお店でお買い物をしていて、 N 円の品物を買おうとしています。
 もちろん、この品物は N 円以上のお金を支払えば買うことができます。
 しかし、先ほど述べたようにいろはちゃんは強いこだわりがあるので、
 自分がお店に支払う金額の 10 進表記にいろはちゃんの嫌いな数字が出現しないような最も少ない金額を支払おうとします。
 
 いろはちゃんが支払う金額を求めてください。
 =================================================================
 
 解説=============================================================
 制約弱いので順番にインクリメントの貪欲で間に合う
 ================================================================
 */
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    int N; int K; cin >> N >> K;
    bool D[10] = {false};
    for(int i = 0; i < K;i++){
        int x; cin >> x; D[x] = true;
    }
    for(int ans = N;; ans++){
        int tmp = ans;
        while(tmp){ if(D[tmp%10]) break; tmp/=10; }
        if(tmp != 0)continue;
        else{ cout << ans << endl; break; }
    }
    return 0;
}
