#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
 最大長方形
 */
struct Rectangle {
	int h;
	int p;  // position from left
};

int max_area_of_histgram(int n, vector<int>& height) {
	stack<Rectangle> S;

	/*  initialize  */
	int maxv = 0;

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
			int now = i;
			while (!(S.empty()) && (S.top().h >= rect.h)) {
				Rectangle pre_rect = S.top(); S.pop();
				maxv = max(maxv, pre_rect.h * (i - pre_rect.p));
				now = pre_rect.p;
			}
			rect.p = now;
			S.push(rect);
		}
	}
	return maxv;
}

int get_Largest_Rectangle(int H, int W, vector<vector<int>>& dp) {
	for (int h = 1; h < H; h++) {
		for (int w = 0; w < W; w++) {
			if (dp[h][w] == 0) continue;
			dp[h][w] = dp[h - 1][w] + 1;
		}
	}

	int maxv = 0;
	for (int h = 0; h < H; h++) {
		maxv = max(maxv, max_area_of_histgram(W, dp[h]));
	}
	return maxv;
}
int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	int H, W; cin >> H >> W;
	vector<vector<int>> c(H + 1, vector<int>(W + 1, 0)), dp(H + 1, vector<int>(W + 1, 0));

	for (int h = 0; h < H; h++) {
		for (int w = 0; w < W; w++) {
			cin >> c[h][w];
			if (c[h][w] == 0) { dp[h][w] = 1; }
			else { dp[h][w] = 0; }
		}
	}
	cout << get_Largest_Rectangle(H, W, dp) << endl;
	return 0;
}
