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
 <url:http://mayokoex.hatenablog.com/entry/2016/08/10/082045>
 問題文============================================================
 H*W の迷路が与えられる。この迷路には小文字のアルファベットで表される宝石と,
 大文字のアルファベットで表されるそれに対応する宝石を埋め込む穴がある
 (例えば 'a' とそれに対応する 'A' がある, という感じ)。
 
 あなたは (0, 0) から (H-1, W-1) に (y, x) -> (y+1, x), (y, x) -> (y, x+1)
 という移動のみを許して進んでいきたい。
 また, この際になるべく多くの宝石を対応する穴に埋め込んでいきたい。最大でいくつの宝石を埋め込めるか。
 =================================================================
 解説=============================================================
 
 解説を見た。やっぱり区間dp的なのは嫌いだと改めて思った
 
 -> http://mayokoex.hatenablog.com/entry/2016/08/10/082045
 ================================================================
 */


int dx[2] = {1,0};
int dy[2] = {0,1};

#define MAX_WH 55
vector<pii> alpha[30];
int dp[MAX_WH][MAX_WH][MAX_WH][MAX_WH];
bool can[MAX_WH][MAX_WH][MAX_WH][MAX_WH];

int dfs(ll y1,ll x1,ll y2,ll x2,vector<vector<char>>& maze){
    int& ret = dp[y1][x1][y2][x2];
    if(ret != -1) return ret;
    if(y1 == y2 && x1 == x2) return ret = 0;
    ret = -INF;
    if(maze[y1][x1] == '#') return ret;
    if(y1+1 <= y2 && maze[y1+1][x1] != '#'){ ret = max(ret,dfs(y1+1,x1,y2,x2,maze)); }
    if(x1+1 <= x2 && maze[y1][x1+1] != '#'){ ret = max(ret,dfs(y1,x1+1,y2,x2,maze));}
    char c = maze[y1][x1];
    if(c >= 'a' && c <= 'z'){
        int idx = c - 'a';
        for(auto p:alpha[idx]){
            ll ny = p.first, nx = p.second;
            if(ny > y2 || nx > x2) continue;
            if(abs(ny-y1) + abs(nx-x1) == 1) ret = max(ret,dfs(ny,nx,y2,x2,maze) + 1);
            else{
                for(int i = 0; i < 2;i++){
                    for(int j = 0; j < 2;j++){
                        ll innery1 = y1+dy[i], innerx1 = x1+dx[i];
                        ll innery2 = ny - dy[j], innerx2 = nx - dx[j];
                        if(innery1 > y2 || innerx1 > x2 || innery2 < y1 || innerx2 < x1 ) continue;
                        if(!can[innery1][innerx1][innery2][innerx2]) continue;
                        ret = max(ret,dfs(innery1,innerx1,innery2,innerx2,maze) + dfs(ny,nx,y2,x2,maze) + 1);
                    }
                }
            }
        }
    }
    return ret;
}

int solve(ll H,ll W){
    int res = -1;
    vector<vector<char>> maze(H+2,vector<char>(W+2,'#'));
    for(int i = 0; i < 30;i++) alpha[i].clear();
    for(int i = 1; i <= H;i++){
        for(int j = 1; j <= W;j++){
            char c; cin >> c;
            maze[i][j] = c;
            if(c >= 'A' && c <= 'Z') alpha[c-'A'].push_back({i,j});
        }
    }
    memset(can,false,sizeof(can));
//    fill(***can,***can+MAX_WH*MAX_WH*MAX_WH*MAX_WH,false);
    
    for(ll i = H; i >= 1; i--){
        for(ll j = W; j >= 1; j--){
            if(maze[i][j] == '#')continue;
            can[i][j][i][j] = 1;
            if(maze[i+1][j] != '#'){
                for(ll ii = i+1; ii <= H; ii++){
                    for(ll jj = j; jj <= W; jj++){
                        can[i][j][ii][jj] |= can[i+1][j][ii][jj];
                    }
                }
            }
            if(maze[i][j+1] != '#'){
                for(ll ii = i; ii <= H; ii++){
                    for(ll jj = j+1; jj <= W; jj++){
                        can[i][j][ii][jj] |= can[i][j+1][ii][jj];
                    }
                }
            }
        }
    }
    //cout << maze << endl;
    //fill(***dp,***dp+MAX_WH*MAX_WH*MAX_WH*MAX_WH,-1);
    memset(dp,-1,sizeof(dp));
    res = max(res,dfs(1,1,H,W,maze));
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    ll H,W;
    while(cin >> H >> W,H|W){
        cout << solve(H,W) << endl;
    }
    return 0;
}
