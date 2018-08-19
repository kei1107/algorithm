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
 <url:https://yukicoder.me/problems/no/124>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 dist[y][x][b][c] := マス(x,y)にいるとき、直近のマスの値がb,2個前のマスの値がcのときの最小ステップ数
 
 とすれば,dijkstraできる
 ================================================================
 */

ll dist[200][200][10][10];

bool isKadomatsuSequence(int a,int b,int c){
    vector<int> kadomatsu{a,b,c};
    sort(kadomatsu.begin(),kadomatsu.end());
    kadomatsu.erase(unique(kadomatsu.begin(),kadomatsu.end()),kadomatsu.end());
    if(kadomatsu.size()!=3) return false;
    return kadomatsu[1] != b;
}
ll solve(){
    fill(***dist,***dist+200*200*10*10,INF);
    ll res = -1;
    ll W,H; cin >> W >> H;
    vector<vector<int>> M(H,vector<int>(W));
    for(auto& vec:M) for(auto& in:vec) cin >> in;
    dist[0][1][M[0][1]][M[0][0]] = 1;
    dist[1][0][M[1][0]][M[0][0]] = 1;
    
    using Items = tuple<int,int,int,int>;
    queue<Items> q;
    q.push(Items(0,1,M[0][1],M[0][0])); q.push(Items(1,0,M[1][0],M[0][0]));
    int d[4] = {1,0,-1,0};
    while(q.size()){
        int x,y,a,b; tie(y,x,b,a) = q.front(); q.pop();
        for(int k = 0; k < 4;k++){
            int ny = y + d[k],nx = x + d[k^1];
            if(ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
            int c = M[ny][nx];
            if(isKadomatsuSequence(a, b, c)){
                if(dist[ny][nx][c][b] > dist[y][x][b][a]+1){
                    dist[ny][nx][c][b] = dist[y][x][b][a]+1;
                    q.push(Items(ny,nx,c,b));
                }
            }
        }
    }
    ll T = INF;
    for(int i = 1; i <= 9;i++){
        for(int j = 1; j <= 9; j++){
            T = min(T,dist[H-1][W-1][i][j]);
        }
    }
    if(T!=INF) res = T;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
