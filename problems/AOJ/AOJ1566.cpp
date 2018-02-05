#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1566>
問題文============================================================
 太郎君は夏休みの間、毎日１つの映画を近所の映画館で見ることにしました。
 （太郎君の夏休みは8月1日から8月31日までの31日間あります。）
 
 その映画館では、夏休みの間にn つの映画が上映されることになっています。
 それぞれの映画には 1 から n までの番号が割り当てられており、
 i 番目の映画は8月 ai 日から8月 bi 日の間だけ上映されます。
 
 太郎君は映画を見た時、それが初めて見る映画だった場合は 100 の幸福度を得ることができます。
 しかし、過去に 1 度でも見たことのある映画だった場合は 50 の幸福度を得ます。
 
 太郎君は上映される映画の予定表をもとに、夏休みの計画を立てることにしました。
 太郎君が得られる幸福度の合計値が最大になるように映画を見たときの合計値を求めてください。
 
 どの日も必ず1つ以上の映画が上映されていることが保証されます。
=================================================================

解説=============================================================

できるだけ多く初視聴となる映画をみるには
 1日から31日まで順番に見て行き、i日目のとき、その区間を覆う期間のうち
 最も早く期間が終了するもの（bが最も近いもの）を優先して視聴していけば最適となる。
 
 また、その選び方として、sortの他にpriority_queue、フローなどで実装できる
 
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n),b(n);
    for(int i = 0; i < n;i++) {
        cin >> a[i] >> b[i]; a[i]--; b[i]--;
    }
    vector<vector<pii>> G(31);
    vector<int> flag(n,0);
    for(int i = 0; i < n;i++){
        for(int j = a[i]; j <= b[i];j++){
            G[j].push_back(pii(b[i],i));
        }
    }
    for(int i = 0; i < 31;i++) sort(G[i].begin(),G[i].end());
    for(int i = 0; i < 31;i++){
        for(auto e:G[i]){
            if(flag[e.second] == 0){
                flag[e.second] = 1;
                break;
            }
        }
    }
    ll ans = 50*31;
    for(int i = 0; i < n;i++){
        if(flag[i]){
            ans += 50;
        }
    }
    cout << ans << endl;
	return 0;
}
