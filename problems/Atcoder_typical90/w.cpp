#include "bits/stdc++.h"
#include "atcoder/all"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T>& V){ for(size_t i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> >& Mat){ for(size_t i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T>& mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }
template<typename T>vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}
/*
 <url:https://atcoder.jp/contests/typical90/tasks/typical90_w>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */

int H,W; 
char c[25][25];

// Map
int cnt[25];
bool used[25][25];
int nex0[25][1 << 18];
int nex1[25][1 << 18];
int state[25][1 << 18];
map<int, pair<int, bool>> Map[25];

// DP
int dp[25][25][1 << 18];

const int dx[8] = { 1, 1, 1, 0, -1, -1, -1, 0 };
const int dy[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

bool hantei(int x, int y) {
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || ny < 0 || ny >= W) continue;
		if (used[nx][ny] == true) return false;
	}
	return true;
}

void dfs(int pos, int dep, int str) {
	int x = pos / W, y = pos % W;
	if (dep == W + 1) {
		int idx = cnt[y];
		bool flag = hantei(x, y);
		state[y][idx] = str;
		Map[y][str] = make_pair(idx, flag);
		cnt[y] += 1;
		return;
	}

	dfs(pos + 1, dep + 1, str);
	if (hantei(x, y) == true) {
		used[x][y] = true;
		dfs(pos + 1, dep + 1, str + (1 << dep));
		used[x][y] = false;
	}
}

const ll MOD = 1e9+7;

template<class Type>
Type solve(Type res = Type()){
    cin >> H >> W;
    for(int i = 0; i < H;i++)for(int j = 0; j < W;j++) cin >> c[i][j];

    for(int i = 0; i < W;i++){
        dfs(i,0,0);
    }
	for (int i = 0; i < W; i++) {
		for (int j = 0; j < cnt[i]; j++) {
			int t = state[i][j];
			int t0 = (t >> 1);
			int t1 = (t >> 1) + (1 << W);
			nex0[i][j] = Map[(i + 1) % W][t0].first;
			if (Map[i][t].second == true) {
				nex1[i][j] = Map[(i + 1) % W][t1].first;
			}
			else {
				nex1[i][j] = -1;
			}
		}
	}

	// Step #3. DP
	dp[0][0][0] = 1;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			int n1 = i, n2 = j + 1;
			if (n2 == W) { n1 += 1; n2 = 0; }

			for (int k = 0; k < cnt[j]; k++) {
				if (dp[i][j][k] == 0) continue;
				(dp[n1][n2][nex0[j][k]] += dp[i][j][k])%=MOD;
				if (nex1[j][k] != -1 && c[i][j] == '.') {
					(dp[n1][n2][nex1[j][k]] += dp[i][j][k])%=MOD;
				}
			}
		}
	}
    for(int i = 0; i < cnt[0];i++) (res += dp[H][0][i])%=MOD;
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    //solve<ll>(0);
    cout << fixed << setprecision(12) << solve<ll>() << endl;
    return 0;
}