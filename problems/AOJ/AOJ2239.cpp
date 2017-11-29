#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2239>
問題文============================================================
うさぎがある電車のチケットをn 枚持っている. チケットにはそれぞれ0 からn － 1 までの番号がついていて, 
k 番のチケットを使うと, p⋅a^k + q⋅b^k 駅進むことができる.

うさぎは今いる駅からm 駅進んだ駅にあるニンジン食べ放題の店に行きたいが,なるべく歩く距離を短くしたい.
駅は等間隔に並んでいる.
チケットを電車の上り線で進むことのみに用いるとき, うさぎは最小何駅分の徒歩で店に着けるか.

1 ≤ n, m, a, b, p, q ≤ 10^12 (整数)
=================================================================
解説=============================================================

制約範囲は10^12以下 := 2^40 
よって、aとbが1以外のとき、チケットは41番目以降になることはない
=> 半分全列挙(オーバーフローに注意)
================================================================
*/

ll powmod(ll a, ll b) { ll res = 1; assert(b >= 0); for (;b;b >>= 1) { if (b & 1)res = res*a;a = a*a; }return res; }
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	ll n, m, a, b, p, q; cin >> n >> m >> a >> b >> p >> q;
	ll res = m;
	if (a == 1 && b == 1) {
		ll k = m / (p + q);
		res = min({ m,abs(m - min(k,n)*(p + q)),abs(min((k + 1),n)*(p + q) - m )});
	}else {
		ll N = min(40LL, n);
		vector<ll> dist;
		for (int i = 0; i < N;i++) {
			ll d = p * powmod(a, i) + q*powmod(b, i);
			if (d > 2 * m)break;
			dist.push_back(d);
		}
		int n1 = (int)dist.size() / 2;
		int n2 = (int)dist.size() - n1;
		vector<ll> L;
		for (int i = 0; i < (1 << n1);i++) {
			ll T = 0;
			for (int j = 0; j < n1;j++) {
				if ((i >> j) & 1) {
					T += dist[j];
				}
			}
			if (T > 2 * m)continue;
			L.push_back(T);
		}
		sort(L.begin(), L.end());
		for (int i = 0; i < (1 << n2);i++) {
			ll T = 0;
			for (int j = 0; j < n2;j++) {
				if ((i >> j) & 1) {
					T += dist[n1 + j];
				}
			}
			if (T > 2 * m)continue;
			auto it = lower_bound(L.begin(), L.end(), m - T);
			if(it != L.end())res = min(res, abs(m - T - *it));
			if (it != L.begin()) res = min(res, abs(m - T - *(it - 1)));
		}
	}
	cout << res << endl;
	return 0;
}