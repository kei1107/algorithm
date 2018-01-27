#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://soundhound2018.contest.atcoder.jp/tasks/soundhound2018_a>
問題文============================================================
 kenkooooさんはSoundHound社で働いています。
 彼は会社の知名度を上げるため、SoundHoundに名前が似ている言葉を見つけてマーケティングを行うことにしました。
 手始めに、2 単語からなる言葉で、
 それぞれの単語の頭文字を順につなげるとSHとなるような単語を似ていると見なすことにしました。
 
 あなたの仕事は、2 単語 X Y からなる言葉が与えられたとき、頭文字を順につなげるとSHとなるか判定することです。
 
 制約
 与えられる単語は英大文字からなる
 単語の長さは 1 以上 10 以下である
=================================================================

解説=============================================================
最初の一文字見るだけ
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    string X,Y; cin >> X >> Y;
    if(X[0] == 'S' && Y[0] == 'H'){
        cout << "YES" << endl;
        return 0;
    }
    
    cout << "NO" << endl;
	return 0;
}
