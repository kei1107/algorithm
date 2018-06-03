#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

/*
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2768>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 memo[i][x][y] := i番目を見た時　1個目のスキャナーがx、2個目のスキャナーがyであるか否か
 でメモ化再帰
 
 3つ全てのスキャナーが1000を超えることがないため、途中で打ち切ることができる
 ================================================================
 */

#define MAXT 1005
ll N;
vector<int> T;
bool memo[55][MAXT][MAXT];

void dfs(int n, int x, int y,ll sum) {
    if (memo[n][x][y]) return;
    memo[n][x][y] = true;
    if (n == N) return;
    if (x + T[n] < MAXT) dfs(n + 1, x + T[n], y,sum + T[n]);
    if (y + T[n] < MAXT) dfs(n + 1, x, y + T[n],sum + T[n]);
    if (sum - x - y + T[n] < MAXT) dfs(n + 1, x, y, sum + T[n]);
}

ll solve() {
    cin >> N;
    T.resize(N);
    for (auto& in : T) { cin >> in; }
    sort(T.begin(), T.end());
    reverse(T.begin(), T.end());
    dfs(0, 0, 0, 0);
    int sum = accumulate(T.begin(), T.end(), 0);
    
    ll ans = LINF;
    for (int i = 0; i < MAXT; i++) {
        for (int j = 0; j < MAXT; j++) {
            if (memo[N][i][j] == false) continue;
            ll t = -1;
            t = max({ i,j,sum - i - j });
            ans = min(ans, t);
        }
    }
    return ans;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
