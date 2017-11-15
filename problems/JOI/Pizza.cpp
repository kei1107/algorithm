#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
 <url:https://www.ioi-jp.org/joi/2008/2009-ho-prob_and_sol/2009-ho.pdf>
 問題文============================================================
 全長dの環状線がある。沿線上に開始点候補群と到達点候補群が与えられる。
 
 ある到達点が指定された時、最も近い開始点から出発し、移動距離を最小としたい
 出力は、移動距離の総和
 =================================================================
 解説=============================================================
 
 単純にクエリが与えられるたびに全店舗との距離を確認するとO(NM)でTLE
 ここで、環状線の形になっていることから始点diを di - d 及び di + d の位置も同時に
 保存しておく
 そうすれば、同一直線上の点群として各始点をみなせるため、あとはにぶたんでO(M log N)
 
 ================================================================
 */
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll d,n,m; cin >> d >> n >> m;
    vector<ll> dist(3*n,0);
    for(int i = 0; i < n;i++){
        ll D = 0;
        if(i != 0)cin >> D;
        dist[3*i] = D;
        dist[3*i + 1] = D+d;
        dist[3*i + 2] = D-d;
    }
    sort(dist.begin(),dist.end());
    dist.erase(unique(dist.begin(),dist.end()),dist.end());
    ll res = 0;
    for(int i = 0; i < m;i++){
        ll k; cin >> k;
        int idx = lower_bound(dist.begin(), dist.end(), k) - dist.begin();
        res += min(abs(k - dist[idx]),abs(k-dist[idx-1]));
    }
    cout << res << endl;
    return 0;
}
