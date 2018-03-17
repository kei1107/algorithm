#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://arc089.contest.atcoder.jp/tasks/arc089_a>
問題文============================================================
 シカのAtCoDeerくんは二次元平面上で旅行をしようとしています。
 AtCoDeerくんの旅行プランでは、時刻 0 に 点 (0,0) を出発し、
 1 以上 N 以下の各 i に対し、時刻 ti に 点 (xi,yi) を訪れる予定です。
 
 AtCoDeerくんが時刻 t に 点 (x,y) にいる時、
 時刻 t+1 には 点 (x+1,y), (x−1,y), (x,y+1), (x,y−1) のうちいずれかに存在することができます。
 その場にとどまることは出来ないことに注意してください。
 AtCoDeerくんの旅行プランが実行可能かどうか判定してください。

=================================================================

解説=============================================================

 次地点に時間が間に合わない時はいうまでもなく no
 時間が間に合う時、
     シカは同一地点に留まることができないので、
     次地点に到達した時の残り時間が偶数のとき、時間ぴったしに到達できる
 
================================================================
*/
struct plan{
    int t,x,y;
    plan():t(0),x(0),y(0){}
};
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N; cin >> N;
    vector<plan> P(N+1);
    for(int i = 1; i <= N;i++) cin >> P[i].t >> P[i].x >> P[i].y;
    for(int i = 1; i <= N;i++){
        int diff = abs(P[i].x - P[i-1].x) + abs(P[i].y - P[i-1].y);
        if(diff > P[i].t - P[i-1].t){
            cout << "No" << endl;
            return 0;
        }else{
            if((P[i].t - P[i-1].t - diff )% 2 != 0){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
	return 0;
}
