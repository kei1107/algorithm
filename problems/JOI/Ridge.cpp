#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
 <url:https://joi2017yo.contest.atcoder.jp/tasks/joi2017yo_e>
 問題文============================================================
 JOI カルデラは景観の良さが多くの登山家に愛される美しい地形である．
 特に，尾根と呼ばれる場所からの景観は絶景である．
 
 JOI カルデラの土地は南北 H キロメートル，東西 W キロメートルの長方形である．
 南北，東西に 1 キロメートルごとに JOI カルデラの土地を分け，
 これら H×W 個の領域を区域と呼ぶ．
 すべての区域において，その中では標高は等しい．また，異なる区域の標高は異なる．
 
 ある区域に雨が降ると，雨水はその区域に東西南北に隣り合う最大で 4 つの区域のうち，
 標高がその区域より低いような区域のすべてに流れる．そのような区域がない場合，雨水はその区域に溜まる．
 他の区域から流れてきた雨水についても同様である．
 JOI カルデラの外側は，外輪山の急峻な崖に囲まれているため，雨水が JOI カルデラの外に流れ出すことはない．
 
 ある区域について，その区域のみに雨が降った場合，最終的に複数の区域に雨水が溜まるとき，
 その区域を尾根と呼ぶ． 絶景をこよなく愛する登山家たちのために，
 尾根の区域がいくつあるかを求めるプログラムを作成せよ．
 
 
 1 行目には 2 個の整数 H,W(1≦H≦1000,1≦W≦1000) が空白を区切りとして書かれており，
 JOI カルデラが南北に H キロメートル，東西に W キロメートルにわたることを表す．
 
 続く H 行にはそれぞれ W 個の整数が空白を区切りとして書かれており，標高の情報を表す．
 H 行のうちの i 行目の j 番目 (1≦i≦H,1≦j≦W) の整数 Mi,j(1≦Mi,j≦H×W) は，
 JOI カルデラの北から i 行目，西から j 列目の区域の標高を表す． (i,j)≠(k,l) なら，Mi,j≠Mk,l を満たす．
 
 尾根の区域の個数を 1 行で出力せよ．
 
 =================================================================
 解説=============================================================
 標高が低い順に順番に見ていく。
 
 屋根となりうるのは2個以上の水が溜まる区域があること
 すなわち、
 2個以上の水が溜まる区域全てを各区域ごとに保存しておく必要がない。
 
 標高が低い順に見ていき、その四方かつ標高が高い区域において、
 水が溜まる区域が何個になるかを保存して行けば、計算量はO(H*W*4)
 ================================================================
 */
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

struct M{
    int v;
    int I;
    bool f;
    M ():v(0),I(0),f(false){}
};
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll H,W; cin >> H >> W;
    vector<vector<M>> masu(H+2,vector<M>(W+2));
    vector<pii> id(H*W);
    for(int i = 1;  i<= H;i++){
        for(int j = 1; j <=W;j++){
            cin >> masu[i][j].v;
            id[masu[i][j].v] = {i,j};
        }
    }
    
    ll res = 0;
    for(int i = 1; i <= H*W;i++){
        if(masu[id[i].first][id[i].second].f == true) res++;
        if(masu[id[i].first][id[i].second].I == 0){
            masu[id[i].first][id[i].second].I = masu[id[i].first][id[i].second].v;
        }
        for(int j = 0; j < 4;j++){
            int nx = id[i].first + dx[j], ny = id[i].second + dy[j];
            if(masu[nx][ny].v < i) continue;
            if(masu[id[i].first][id[i].second].f == true){
                masu[nx][ny].f = true;
                continue;
            }
            if(masu[nx][ny].I != 0){
                if(masu[id[i].first][id[i].second].I != masu[nx][ny].I){
                    masu[nx][ny].f = true;
                }
                continue;
            }
            if(masu[nx][ny].I == 0){
                masu[nx][ny].I = masu[id[i].first][id[i].second].I;
                continue;
            }
        }
    }
    cout << res << endl;
    return 0;
}
