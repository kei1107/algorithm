#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://soundhound2018.contest.atcoder.jp/tasks/soundhound2018_b>
問題文============================================================
 kenkooooさんはSoundHound社で働いています。彼は今日、音量を調整する機能を作ることにしました。
 
 この機能では、n 秒の間毎秒与えられる入力に対し、ある大きさの音量を出力します。
 i 秒目の入力を ai とします。もし、 ai が出力の下限 L を下回っていた場合、
 出力は L とし、ai が上限 R を上回っていた場合、出力を R とします。
 どちらでもないときは、出力を ai とします。
 n 秒間の入力 ai、L と R が与えられるので、n 個の出力 bi を得るプログラムを書いてください。
 
 制約
 1≦n≦105
 1≦ai≦105
 1≦L≦R≦105
=================================================================

解説=============================================================

 出力は min(max(L,a[i]),R)
================================================================
*/
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n,L,R; cin >> n >> L >> R;
    vector<ll> a(n);
    for(auto& in:a) cin >> in;
    for(int i = 0; i < n;i++){
        cout << min(max(L,a[i]),R);
        if(i != n-1){
            cout << " ";
        }else{
            cout << endl;
        }
    }
    return 0;
}

