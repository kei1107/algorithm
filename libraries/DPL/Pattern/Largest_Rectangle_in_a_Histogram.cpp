#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

struct Rectangle {
	ll h;
	ll p;  // position from left
};

ll max_area_of_histgram(ll n, vector<ll>& height) {
	stack<Rectangle> S;
	ll maxv = 0;

	for (int i = 0; i <= n; i++) {
		Rectangle rect;
		rect.h = height[i];
		rect.p = i;

		if (S.empty()) {
			S.push(rect);
		}
		else if (S.top().h < rect.h) {
			S.push(rect);
		}
		else if (S.top().h > rect.h) {
			ll now = i;
			while ((!S.empty()) && (S.top().h >= rect.h)) {
				Rectangle pre = S.top(); S.pop();
				ll area = 1LL * pre.h * (i - pre.p);
				maxv = max(maxv, area);
				now = pre.p;
			}
			rect.p = now;
			S.push(rect);
		}
	}
	return maxv;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	ll N; cin >> N;
	vector<ll> dp(N + 1, 0);
	for (int i = 0; i < N;i++) cin >> dp[i];
	cout << max_area_of_histgram(N, dp) << endl;
	return 0;
}