#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e16;

/*
<url:https://abc037.contest.atcoder.jp/tasks/abc037_d?lang=en>
問題文============================================================

 (略)
 
=================================================================

解説=============================================================

 メモ化再帰
 
================================================================
*/

const ll mod = 1e9 + 7;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


ll dfs(int h,int w,vector<vector<ll>> &dp,vector<vector<ll>>& a){
    ll & res = dp[h][w];
    if(res != 0) return res;
    
    for(int i = 0; i < 4;i++){
        int nx = h + dx[i], ny = w + dy[i];
        if(a[nx][ny] == -1) continue;
        if(a[nx][ny] < a[h][w]){
            (res += dfs(nx,ny,dp,a))%=mod;
        }
    }
    res++;
    res%=mod;
    return res;
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll H,W; cin >> H >> W;
    vector<vector<ll> > a(H+2,vector<ll>(W+2,-1));
    ll maxv = 0;
    for(int i = 1; i <= H;i++){
        for(int j = 1; j <= W;j++){
            cin >> a[i][j];
            maxv = max(maxv,a[i][j]);
        }
    }
    ll sum = 0;
    vector<vector<ll> > dp(H+2,vector<ll>(W+2,0));
    for(int i = 1; i <= H;i++){
        for(int j = 1; j <= W;j++){
            (sum += dfs(i,j,dp,a))%=mod;
        }
    }
    cout << sum << endl;
	return 0;
}
