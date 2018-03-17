#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
 <url:https://agc002.contest.atcoder.jp/tasks/agc002_c>
問題文============================================================
 N 本のロープがあります。 ロープは 1 から N まで番号が振られています。 ロープ i の長さは ai です。
 
 最初、1≤i≤N−1 について、ロープ i の右端とロープ i+1 の左端が結ばれています。
 高橋君は次の操作を N−1 回行い、すべての結び目をほどこうとしています。
 
 ひと繋がりのロープのうち、長さの総和が L 以上のものをひとつ選ぶ。
 選んだひと繋がりのロープに結び目があれば、結び目のうちどれかひとつをほどく。
 
 高橋君は結び目をほどく順番を工夫し、すべての結び目をほどくことができるでしょうか？
 可能か判定し、可能ならば結び目をほどく順番をひとつ求めてください。

=================================================================

解説=============================================================

 結び目を解く順番によらず、いずれ紐は二本が繋がった ai + a_i+1 := len の長さを扱わなくては行けなくなる
 逆にこの len が len >= L であれば、この二本が入ったグループが残されるように両端から紐を解いて行けば良いので
 
 possible か impossibleかどうかの判定は ai + a_i+1 >= L の判定でできる
 
================================================================
*/

struct sec{
    ll l,r,len;
    sec(){}
    sec(ll l,ll r,ll len):l(l),r(r),len(len){}
};
void solve(){
    int N,L; cin >> N >> L;
    vector<int> a(N);
    for(auto &in:a) cin >> in;
    for(int i = 0; i < N-1;i++){
        if(a[i] + a[i+1] >= L){
            cout << "Possible" << endl;
            for(int j = 1; j <= i;j++) cout << j << endl;
            for(int j = N - 1; j > i; j--) cout << j << endl;
            return;
        }
    }
    cout << "Impossible" << endl;
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    solve();
	return 0;
}
