#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://beta.atcoder.jp/contests/abc089/tasks/abc089_d>
問題文============================================================
長いので(略)
=================================================================

解説=============================================================
整数への移動は x -> x+D と確定されているので、 始点を1..D とする D本のルートが作れる
 それぞれの始点からの距離をdistとすると dist[R] - dist[L] が答え
================================================================
*/

#define MAX_V 100000
ll dist[MAX_V];
void solve_D(){
    ll H,W,D; cin >> H >> W >> D;
    vector<vector<ll>> A(H,vector<ll>(W));
    vector<pll> loc(H*W+1);
    for(int i = 0; i < H;i++){
        for(int j = 0; j < W;j++){
            cin >> A[i][j];
            loc[A[i][j]] = {i,j};
        }
    }
    
    for(int i = 1; i <= H*W; i++){
        if(i <= D){
            dist[i] = 0;
        }else{
            dist[i] = dist[i-D] + abs(loc[i-D].first - loc[i].first) + abs(loc[i-D].second - loc[i].second);
        }
    }
    
    ll Q; cin >> Q;
    for(int q = 0; q < Q; q++){
        ll L,R; cin >> L >> R;
        cout << dist[R] - dist[L] << endl;
    }
}

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    solve_D();
	return 0;
}
