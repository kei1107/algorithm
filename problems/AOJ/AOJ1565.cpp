#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1565>
問題文============================================================

 近年、イカたちの間では縄張り争いが頻繁に起きている。
 複数のイカたちがチームを組み、自らのイカスミを武器に戦うのが近年のイカの戦闘スタイルである。
 
 現在も縄張り争いが起こっており、その戦場は R×C のグリッドで表される。
 縄張り争いに参加しているイカのゲソ太はこのグリッド上のある場所にいる。
 この争いでは、重要な場所を敵よりも早く占拠することで戦況を有利にすることができる。
 そのため、ゲソ太は重要そうな場所を1つ決め、そこになるべく早く移動したいと考えている。
 
 ゲソ太は隣接する上下左右のマスに移動することができる。
 グリッドの各マスには味方、または敵のイカスミが塗られている場合がある。
 なにも塗られていないマスに移動する場合、2秒かかるが、
 味方のイカスミが塗られているマスに移動する場合、その半分の時間(1秒)で済む。
 敵のイカスミが塗られているマスには移動することができない。壁があるマスや戦場の外へは当然移動することができない。
 
 また、ゲソ太は上下左右のいずれかの方向を向き、イカスミを吐くことができる。
 すると、前方の3マスが味方のイカスミで上書きされる。
 ただし途中に壁がある場合はその手前までしかイカスミは届かない。この動作には2秒かかる。
 
 戦場の情報とゲソ太の位置と目的の位置が与えられるので、最短で何秒で移動できるか求めてほしい。
 
=================================================================

解説=============================================================
ダイクストラ法
 
 遷移の方法としては、純粋に四方４マスで移動できるようであればその遷移をみる。
 さらに、四方について３マス分色ぬりを行ったとして、遷移を取っていけば良い
================================================================
*/

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll R,C; cin >> R >> C;
    pii s,g;
    vector<vector<char>> masu(R+2,vector<char>(C+2,'#'));
    for(int i = 1; i <= R;i++){
        for(int j = 1; j <= C;j++){
            cin >> masu[i][j];
            if(masu[i][j] == 'S'){
                masu[i][j] = '.';
                s = pii(i,j);
            }
            if(masu[i][j] == 'G'){
                masu[i][j] = '.';
                g = pii(i,j);
            }
        }
    }
    
    vector<vector<int>> dist(R+2,vector<int>(C+2,INF));
    dist[s.first][s.second] = 0;
    queue<pii> q;
    q.push(s);
    while(!q.empty()){
        auto n = q.front(); q.pop();
        int x = n.first, y = n.second;
        for(int i = 0; i  < 4;i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(masu[nx][ny] == '#') continue;
            if(masu[nx][ny] == '.'){
                if(dist[nx][ny] > dist[x][y] + 2){
                    dist[nx][ny] = dist[x][y] + 2;
                    q.push(pii(nx,ny));
                }
            }
            if(masu[nx][ny] == 'o'){
                if(dist[nx][ny] > dist[x][y] + 1){
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push(pii(nx,ny));
                }
            }
        }
        for(int i = 0; i < 4;i++){
            for(int j = 1; j <= 3;j++){
                int nx = x + j*dx[i], ny = y + j*dy[i];
                if(masu[nx][ny] == '#') break;
                if(dist[nx][ny] > dist[x][y] + 2 + j){
                    dist[nx][ny] = dist[x][y] + 2 + j;
                    q.push(pii(nx,ny));
                }
            }
        }
    }
    cout << dist[g.first][g.second] << endl;
	return 0;
}
