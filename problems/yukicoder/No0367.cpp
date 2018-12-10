#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

/*
 <url:https://yukicoder.me/problems/no/367>
 問題文============================================================
 =================================================================
 解説=============================================================
 拡張ダイクストラでえい
 ================================================================
 */

vector<vector<int>> dx{
    {1,2,2,1,-1,-2,-2,-1},
    {1,1,-1,-1}
};
vector<vector<int>> dy{
    {-2,-1,1,2,2,1,-1,-2},
    {-1,1,1,-1}
};

ll solve(){
    ll res = INF;
    int H,W; cin >> H >> W;
    vector<vector<char>> masu(H,vector<char>(W));
    pii S,G;
    for(int i = 0; i < H;i++){
        for(int j = 0; j < W;j++){
            cin >> masu[i][j];
            if(masu[i][j] == 'S'){ S = {i,j}; masu[i][j] = '.';}
            if(masu[i][j] == 'G'){ G = {i,j}; masu[i][j] = '.';}
        }
    }
    
    vector<vector<vector<int>>> dist(2,vector<vector<int>>(H,vector<int>(W,INF)));
    dist[0][S.first][S.second] = 0;
    using Items = tuple<int,int,int>;
    queue<Items> q; q.push(Items(0,S.first,S.second));
    while(q.size()){
        int state,y,x;
        tie(state,y,x) = q.front(); q.pop();
        for(int i = 0; i < dx[state].size(); i++){
            int ny = y + dy[state][i];
            int nx = x + dx[state][i];
            if(ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
            int next_state = state;
            if(masu[ny][nx] == 'R') next_state = !next_state;
            if(dist[next_state][ny][nx] > dist[state][y][x] + 1){
                dist[next_state][ny][nx] = dist[state][y][x] + 1;
                q.push(Items(next_state,ny,nx));
            }
        }
    }
    res = min(dist[0][G.first][G.second],dist[1][G.first][G.second]);
    if(res == INF) return -1;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
