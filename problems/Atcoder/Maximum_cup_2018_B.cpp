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
 <url:https://beta.atcoder.jp/contests/maximum-cup-2018/tasks/maximum_cup_2018_b>
 問題文============================================================
 サイタマでは年に一度の山車のお披露目会がある。
 もっとも美しい山車には賞金が出ると聞いた埼大くんと埼大くんの友達はお披露目会に参加することにした。
 お披露目会の会場に向かう途中、隣街の男衆が山車に乗って邪魔をしてきた。
 男衆が山車の右側にa人、左側にb人乗っているようだ。
 どうしても賞金が欲しい埼大くんたちは完璧な山車を披露したいため、会場に到着するまでに男衆を全員振り払う必要がある。
 
 単位時間内にとりうる山車の動きは次の3パターンである。
 
 左に 90 度向きを変えてから一マス前進する。
 右に 90 度向きを変えてから一マス前進する。
 向きを変えずに一マス前進する。
 
 1.の動きにより右側に乗っている人を、2.の動きにより左側に乗っている人を、一人づつ振り落とすことができる。
 しかし必要以上に向きを変えたくないため、
 1.の動きを a 回行った以後は1.の、2.の動きを b 回行った以後は2.の動きを行わない。
 
 埼大くんたちは地図を見てルートを決めることにした。
 地図の縦の長さは h 、横の長さは w で、通れる場所は ′.′ 、
 通れない場所は '#' である。通過する街はマス目状に区切られており、
 地図上では i 行 j 列目のマス は c(i,j)で表される。
 現在地はc(2,2)、会場はc(h−1,w−1)である。
 現在地と、会場は′.′であることが保証されている。
 地図の一番外側はすべて '#' で囲まれている。c(1,1)～c(1,w)
 に面している方面の方角が北であり、埼大くんたちは最初南を向いている。
 
 埼大くんたちは無事にお披露目会に参加できるかどうかを判定せよ。
 
 =================================================================
 解説=============================================================
 
 dfsで全状態を探索する。
 フラグ付けをして同じ遷移を二度辿らないようにする。
 ================================================================
 */

int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};
bool f[16][16][4][16][16];
void dfs(int y,int x,int dir,int a,int b,vector<vector<char>>& c){
    if(f[y][x][dir][a][b]) return;
    f[y][x][dir][a][b] = true;
    
    for(int k = -1; k <= 1;k++){
        int ny = y + dy[(dir+k+4)%4], nx = x + dx[(dir+k+4)%4];
        if(c[ny][nx] == '#') continue;
        if(k == -1 && b == 0) continue;
        if(k == 1 && a == 0) continue;
        
        if(k == -1){
            dfs(ny,nx,(dir+k+4)%4,a,b-1,c);
        }
        if(k == 0){
            dfs(ny,nx,dir,a,b,c);
        }
        if(k == 1){
            dfs(ny,nx,(dir+k+4)%4,a-1,b,c);
        }
    }
}
string solve(){
    int a,b,h,w; cin >> a >> b >> h >> w;
    vector<vector<char>> c(h+1,vector<char>(w+1,'#'));
    for(int i = 1; i <= h; i++) for(int j = 1; j <= w; j++) cin >> c[i][j];
    dfs(2,2,0,a,b,c);
    
    for(int k = 0; k < 4;k++){
        if(f[h-1][w-1][k][0][0]) return "Yes";
    }
    return "No";
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
