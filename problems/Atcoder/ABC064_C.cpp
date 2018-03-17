#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://abc064.contest.atcoder.jp/tasks/abc064_c>
問題文============================================================
 AtCoderでは、コンテストに参加すると「色」が付き、これはレートによって次のように変化します：
 
 レート 1-399：灰色
 レート 400-799：茶色
 レート 800-1199：緑色
 レート 1200-1599：水色
 レート 1600-1999：青色
 レート 2000-2399：黄色
 レート 2400-2799：橙色
 レート 2800-3199：赤色
 また、レートが 3200 以上になると色を自由に変えることができます。
 現在 N 人の人がAtCoderのコンテストに参加したことがあり、i 人目の人のレートは ai です。
 そのとき、色の種類数の最小値と最大値を求めなさい。
 

=================================================================

解説=============================================================

 レート3200人以上の人が全て（レート色以外も含む）の色を選べることに注意さえすれば
 あとはやるだけ
 
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<int> a(N); for(auto &in:a) cin >> in;
    int color[9] = {0};
    for(int i = 0; i < N;i++){
        color[min(8,a[i]/400)]++;
    }
    
    int color_cnt = 0;
    for(int i = 0; i < 8;i++) if(color[i] != 0) color_cnt++;
    if(color_cnt == 0){
        cout << 1 << " " << color[8] << endl;
    }else{
        cout << color_cnt << " " << color_cnt + color[8] << endl;
    }
	return 0;
}
