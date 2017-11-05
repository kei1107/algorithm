#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
 <url:https://www.ioi-jp.org/joi/2010/2011-yo-prob_and_sol/2011-yo-t5/2011-yo-t5.html>
 問題文============================================================
 今年も JOI 町のチーズ工場がチーズの生産を始め，ねずみが巣から顔を出した．
 JOI 町は東西南北に区画整理されていて，各区画は巣，チーズ工場，障害物，空き地のいずれかである．
 ねずみは巣から出発して全てのチーズ工場を訪れチーズを 1 個ずつ食べる．
 この町には，N 個のチーズ工場があり，どの工場も１種類のチーズだけを生産している．
 チーズの硬さは工場によって異なっており，硬さ 1 から N までのチーズを生産するチーズ工場がちょうど 1 つずつある．
 
 ねずみの最初の体力は 1 であり，チーズを 1 個食べるごとに体力が 1 増える．
 ただし，ねずみは自分の体力よりも硬いチーズを食べることはできない．
 
 ねずみは，東西南北に隣り合う区画に 1 分で移動することができるが，障害物の区画には入ることができない．
 チーズ工場をチーズを食べずに通り過ぎることもできる．
 すべてのチーズを食べ終えるまでにかかる最短時間を求めるプログラムを書け．
 ただし，ねずみがチーズを食べるのにかかる時間は無視できる．
 =================================================================
 解説=============================================================
 ねずみが次に向かう工場は一意に確定するため、純粋に
 S -> 1 -> 2 -> ... -> N の最短経路を求めれば良い、
 ================================================================
 */
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll H,W,N; cin >> H >> W >> N;
    vector<vector<char>> masu(H+2,vector<char>(W+2,'X'));
    vector<pii> Ps(N+1);
    for(int i = 1; i <= H;i++){
        for(int j = 1; j<=W;j++){
            cin >> masu[i][j];
            if(masu[i][j] == 'S'){
                masu[i][j] = '.';
                Ps[0] = {i,j};
                continue;
            }
            if('1' <= masu[i][j] && masu[i][j] <= '9'){
                Ps[masu[i][j] - '0'] = {i,j};
                continue;
            }
        }
    }
    
    ll res = 0;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    using Key = tuple<int,int,int>;
    vector<vector<int>> used(H+2,vector<int>(W+2));
    for(int i = 0; i < N;i++){
        used.assign(H+2,vector<int>(W+2,0));
        auto s = Ps[i],t = Ps[i+1];
        queue<Key> q;
        q.push(Key(s.first,s.second,0));
        used[s.first][s.second] = 1;
        while(!q.empty()){
            int x,y,dep;
            tie(x,y,dep) = q.front(); q.pop();
            bool f = false;
            for(int k = 0; k < 4;k++){
                int nx = x + dx[k], ny = y + dy[k];
                if(masu[nx][ny] == 'X')continue;
                if(used[nx][ny] == 1)continue;
                if(masu[nx][ny] - '0' == i + 1){
                    res += dep + 1;
                    f = true;
                    break;
                }
                used[nx][ny] = 1;
                q.push(Key(nx,ny,dep + 1));
            }
            if(f)break;
        }
    }
    cout << res << endl;
    return 0;
}
