#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define INF 1<<30
#define LINF 1LL<<60

/* Coordinate_Compression : ���W���k*/
class CC {
public:
	ll N;
	vector<ll> xs; // �����p:xs[x1 or x2�̓Y����] := ���̍��W

	CC(ll N) :N(N) {}
	// x1, x2�����W���k��, ���W���k�����ۂ̕���Ԃ�
	int compress(vector<ll>& x1, vector<ll>& x2, ll MIN_W = -1e10, ll MAX_W = 1e10) {
		for (int i = 0; i < N;i++) {
			/* �ꍇ�ɂ���Ă�d�������Ă��悢 */
			for (int d = -1; d <= 1; d++) {
				ll tx1 = x1[i], tx2 = x2[i];
				if (MIN_W <= tx1 && tx1 <= MAX_W) xs.push_back(tx1);
				if (MIN_W <= tx2 && tx2 <= MAX_W) xs.push_back(tx2);
			}
		}

		sort(xs.begin(), xs.end());
		xs.erase(unique(xs.begin(), xs.end()), xs.end());

		for (int i = 0; i < N;i++) {
			x1[i] = lower_bound(xs.begin(), xs.end(), x1[i]) - xs.begin();
			x2[i] = lower_bound(xs.begin(), xs.end(), x2[i]) - xs.begin();
		}

		return (int)xs.size(); // xs.size�͍ő�ł�6*N
	}
};

/* use example : http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_4_A&lang=jp */
int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	ll N; cin >> N;
	vector<ll> x1(N), y1(N), x2(N), y2(N);
	for (int i = 0; i < N;i++) cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
	CC CCx(N), CCy(N);
	ll W = CCx.compress(x1, x2);
	ll H = CCy.compress(y1, y2);

	/* imos�@��p���Ă̍��W�̖ʐόv�Z�@*/
	vector<vector<int>> imos(H + 2, vector<int>(W + 2, 0)); // �ʐόv�Z
	vector<vector<int>> Sum(H + 2, vector<int>(W + 2, 0));
	for (int i = 0; i < N;i++) {
		imos[y1[i]][x1[i]]++;
		imos[y1[i]][x2[i]]--;
		imos[y2[i]][x1[i]]--;
		imos[y2[i]][x2[i]]++;
	}
	ll ans = 0;
	for (int y = 0; y < H;y++) {
		for (int x = 0; x < W;x++) {
			Sum[y + 1][x + 1] = Sum[y + 1][x] + Sum[y][x + 1] - Sum[y][x] + imos[y][x];
			if (Sum[y + 1][x + 1] > 0) {
				ans += (CCy.xs[y + 1] - CCy.xs[y])*(CCx.xs[x + 1] - CCx.xs[x]);
			}
		}
	}

	cout << ans << endl;
	return 0;
}

// ==============================================
// compress ver2
int N; // num of vertex
int compress(int p[]){
    vector<int> ps;
    ps.resize(N);
    for (int i=0; i<N; ++i) {
        ps[i] = p[i];
    }
    sort(ps.begin(), ps.end());
    ps.erase(unique(ps.begin(), ps.end()), ps.end());
    for (int i=0; i<N; ++i) {
        p[i] = 2 + (int)distance(ps.begin(), lower_bound(ps.begin(), ps.end(), p[i]));
    }
    return 2 + (int)ps.size();
}
