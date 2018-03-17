#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://abc088.contest.atcoder.jp/tasks/abc088_d>
問題文============================================================
 縦 H マス, 横 W マスに広がるマス目があり, 各マスは白または黒で塗られている.
 上から i 番目で左から j 番目のマスを (i,j) で表す.
 すぬけ君は, このマス目を使って次のようなゲームをしたい.
 ゲームの開始時点ではマス (1,1) にゲームキャラクター「けぬす君」がいる.
 プレイヤーはけぬす君を上下左右の 4 方向のいずれかに 1 マスだけ動かすことを繰り返す.
 けぬす君が白いマスだけを通って (H,W) にたどり着けばゲームクリアとなる.
 
 ゲームを開始する前に, すぬけ君はいくつかの白いマス目の色を黒に変えることができる.
 ただし, マス (1,1) と (H,W) の色を変えることはできず,
 ゲームを開始するまでにすべての色の変更を行わなければならない.
 
 ゲームをクリアしたとき, ゲームの開始前にマスの色を変えた回数がすぬけ君のスコアとなる.
 そのとき, すぬけ君が取る可能性のある最大のスコアを求めなさい.
 ただし,すぬけ君がどのようにマス目の色を変えてもけぬす君が (H,W) にたどり着くことが出来ない場合、−1 と出力しなさい.
 
 ただし, 各マスの色の情報は文字 si,j として与えられる.
 マス (i,j) が最初白で塗られている場合 si,j は .
 であり, マス (i,j) が最初黒で塗られている場合 si,j は # である.
 

=================================================================

解説=============================================================

 左上から右下までで少なくとも通らなければならないマスの数は 最短経路問題なので
 ダイクストラ等でもとまる
 
 ここで、たどり着けなければ -1
 たどり着く場合
 答えは H*W - (右下までの最短距離+1) - '#' の数
 
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    int H,W;
    cin >> H >> W;
    vector<vector<char>> masu(H+2,vector<char>(W+2,'#'));
    int cnt = 0;
    for(int i = 1; i <= H;i++){
        for(int j = 1; j <=W;j++){
            cin >> masu[i][j];
            if(masu[i][j] == '#') cnt++;
        }
    }
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    vector<vector<int>> G(H+1,vector<int>(W+1,INF));
    G[1][1] = 0;
    queue<pii> q; q.push(pii(1,1));
    while(!q.empty()){
        auto p = q.front(); q.pop();
        int x,y; tie(x,y) = p;
        for(int i = 0; i < 4;i++){
            int nx = x + dx[i] , ny = y + dy[i];
            if(masu[nx][ny] == '#') continue;
            if(G[nx][ny] > G[x][y] + 1){
                G[nx][ny] = G[x][y] + 1;
                q.push(pii(nx,ny));
            }
        }
    }
    
    if(G[H][W] == INF) cout << -1 << endl;
    else cout << H*W - G[H][W] - 1 - cnt << endl;
	return 0;
}
