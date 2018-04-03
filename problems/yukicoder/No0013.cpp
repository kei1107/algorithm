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
 <url:https://yukicoder.me/problems/no/13>
 問題文============================================================
 kevinはとあるゲームをしている。
 横W縦H個のマスで構成されるフィールドが与えられる。
 最初にあるマスを選択し、上下左右の同じ数字のみ辿れ、任意の場所で離す事ができる。
 この時、同じ数字のみをたどって、囲みができたら高得点になるゲームである。
 
 囲みとは、辿ったマスの順番に線をつないだ時に、K(≥4)角形ができていることである。
 
 フィールドが与えられた時に囲みができるかどうか判定してください。
 囲みが出来る場合 possible 出来ない場合は impossible を出力してください。
 
 =================================================================
 解説=============================================================
 
 ある数字のマスから初めて、同じマスに戻らないように　かつ　同じ数字のみ進んでいき、
 すでに到達済みのマスに行けるかどうかで impossible か possibleか判定できる。
 よって、dfs
 
 ================================================================
 */

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

bool dfs(int x,int y,int px,int py,vector<vector<int>>& masu,vector<vector<int>>& checked){
    if(checked[x][y] == 1) { return true;}
    checked[x][y] = 1;
    for(int i = 0; i < 4;i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(nx == px&& ny == py) continue;
        if(masu[nx][ny] != masu[x][y]) continue;
        if(dfs(nx,ny,x,y,masu,checked)) return true;
    }
    return false;
}
string solve(){
    int W,H; cin >> W >> H;
    vector<vector<int>> masu(H+2,vector<int>(W+2,-1));
    for(int i = 1; i <= H; i++) for(int j = 1; j <= W; j++) cin >> masu[i][j];
    
    vector<vector<int>> checked(H+2,vector<int>(W+2,0));
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            if(checked[i][j] == 1) continue;
            if(dfs(i,j,-1,-1,masu,checked)) return "possible";
        }
    }
    return "impossible";
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
