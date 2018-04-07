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
 <url:https://csacademy.com/contest/round-75/task/escape-the-matrix/>
 問題文============================================================
 You are given a matrix TT of dimensions H \times WH×W.
 Each element of the matrix will contain one of the four characters U, R, D, L
 If at any point you are located in cell (i, j), T_{i,j} will determine where you move next.
 
 T_{i,j} = U you will move to cell (i - 1, j)(i−1,j)
 T_{i,j} = R you will move to cell (i, j + 1)(i,j+1)
 T_{i,j} = D you will move to cell (i + 1, j)(i+1,j)
 T_{i,j} = L you will move to cell (i, j - 1)(i,j−1)
 Your task is to find out for how many cells,
 if you start the journey from there, you will eventually escape the matrix.

 =================================================================
 解説=============================================================
 Atcoder とかで出てそう
 
 各頂点から初めて、枠外に出たかどうかをシミュレーション
 各頂点ごとにメモ化しとくと楽
 ================================================================
 */

int dir[26];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

bool dfs(int y,int x,vector<vector<char>>& masu,vector<vector<int>>& ret,vector<vector<int>>& checked){
    checked[y][x] = 1;
    
    int ny = y + dy[masu[y][x]];
    int nx = x + dx[masu[y][x]];
    
    if(masu[ny][nx] == '#'){
        ret[y][x] = 1;
        return true;
    }
    
    if(checked[ny][nx] == 0){
        if(dfs(ny,nx,masu,ret,checked)){
            ret[y][x] = 1;
            return true;
        }
    }else{
        if(ret[ny][nx] == 1){
            ret[y][x] = 1;
            return true;
        }
    }
    return false;
}

ll solve(){
    ll res = 0;
    ll H,W; cin >> H >> W;
    vector<vector<char>> masu(H+2,vector<char>(W+2,'#'));
    vector<vector<int>> checked(H+2,vector<int>(W+2,0));
    vector<vector<int>> ret(H+2,vector<int>(W+2,0));
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            cin >> masu[i][j];
            if(masu[i][j] == 'U') masu[i][j] = 0;
            if(masu[i][j] == 'R') masu[i][j] = 1;
            if(masu[i][j] == 'D') masu[i][j] = 2;
            if(masu[i][j] == 'L') masu[i][j] = 3;
            
        }
    }
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            if(checked[i][j] == 0) dfs(i,j,masu,ret,checked);
        }
    }
    
    for(int i = 1; i <= H;i++) res += accumulate(ret[i].begin(), ret[i].end(),0LL);
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    dir['U'-'A'] = 0; dir['R'-'A'] = 1; dir['D'-'A'] = 2; dir['L'-'A'] = 3;
    cout << solve() << endl;
    return 0;
}
