#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
 <url:https://www.ioi-jp.org/camp/2008/2008-sp-tasks/2008-sp_tr-day1_20.pdf>
 問題文============================================================
 紙 1, 紙 2, · · ·, 紙 N の N(1<=N<=1000) 枚の長方形の紙があり, 色はすべて異なっている.
 これらの紙のすべてと異なる色の長方形のテーブルの上に, N 枚の紙を一枚ずつ順に次のように置く.
     • 紙を置くときは, その辺がテーブルの辺と平行になるように置く.
     • すでに置いてある紙の下に, 新しく置く紙をもぐりこませるようなことはしない (つまり,後に置いた紙の方が常に上にある).
     • テーブルや紙の辺の長さは整数であり, また, 紙は必ずテーブルの各辺から整数の長さだけ離して置く.
 このようにして N 枚の紙を置いた後, 上から写真を撮った. この写真が与えられたとき, 写真
 と矛盾しない紙の置かれた順番を 1 つ出力するプログラムを書け
 
 テーブルの大きさは WxH(1<=W,N<=100)
 =================================================================
 解説=============================================================
 
 トポロジる
 
 ================================================================
 */
int N,W,H;
vector<vector<int>> masu;
vector<vector<int>> corner;
vector<int> ans;
vector<int> used;

void topological_sort(int n){
    for(int i = corner[n][0]; i <= corner[n][1];i++){
        for(int j = corner[n][2]; j <= corner[n][3]; j++){
            if(masu[i][j] == 0)continue;
            if(masu[i][j] == n)continue;
            if(used[masu[i][j]] == 1)continue;
            topological_sort(masu[i][j]);
        }
    }
    ans.push_back(n);
    used[n] = 1;
    return;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> N >> W >> H;
    masu.assign(H, vector<int>(W,0));
    corner.assign(N+1,vector<int>(4,0));
    used.assign(N+1,0);
    
    for(int i = 1; i <= N;i++){
        corner[i][0] = 105;
        corner[i][1] = 0;
        corner[i][2] = 105;
        corner[i][3] = 0;
    }
    for(int i = 0; i < H;i++){
        for(int j = 0; j < W;j++){
            cin >> masu[i][j];
            corner[masu[i][j]][0] = min(i,corner[masu[i][j]][0]);
            corner[masu[i][j]][1] = max(i,corner[masu[i][j]][1]);
            corner[masu[i][j]][2] = min(j,corner[masu[i][j]][2]);
            corner[masu[i][j]][3] = max(j,corner[masu[i][j]][3]);
        }
    }
    for(int i = 1; i <= N;i++){
        if(used[i] == 1)continue;
        topological_sort(i);
    }
    for(int i = N-1; i >= 0;i--){
        if(i == N - 1){
            cout << ans[i];
        }else{
            cout << " " << ans[i];
        }
    }
    cout << endl;
    return 0;
}
