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
 <url:https://onlinejudge.u-aizu.ac.jp/services/room.html#RitsCamp18Day3/problems/C>
 問題文============================================================
 
 (略
 
 =================================================================
 
 解説=============================================================
 
 グラフさえ作れば、やるだけ、、、、
 実装を頑張る
 
 ================================================================
 */

int dy[4] = {0,2,0,-2};
int dx[4] = {2,0,-2,0};
int dir[4] = {0,1,2,3};
int diry[4] = {0,1,0,-1};
int dirx[4] = {1,0,-1,0};

char bar[4] = {'-','|','-','|'};

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll H,W; cin >> H >> W;
    char cs,ct; cin >> cs >> ct;
    ll s,t; s = (cs - 'A'); t = (ct - 'A');
    vector<vector<char>> masu(H+2,vector<char>(W+2,'#'));
    map<char,pii> mp;
    for(int i = 1; i <= H;i++){
        for(int j = 1; j <= W;j++){
            cin >> masu[i][j];
            if(masu[i][j] >= 'A' && masu[i][j] <= 'Z'){
                mp[masu[i][j]] = {i,j};
            }
        }
    }
    
    for(auto m:mp){
        auto p = m.second;
        for(int i = -1;i <= 1; i++){
            for(int j = -1; j <= 1;j++){
                masu[p.first+i][p.second+j] = masu[p.first][p.second];
            }
        }
    }
    
    //    cout << masu << endl;
    
    vector<vector<int>> G(30);
    for(auto m:mp){
        auto p = m.second;
        int u = masu[p.first][p.second] - 'A';
        for(int i = 0; i < 4;i++){
            char masu_c = masu[p.first+dy[i]][p.second+dx[i]];
            if(masu_c == bar[i]){
                int ny = p.first+dy[i],nx = p.second+dx[i];
                while(true){
                    if(ny > H || ny < 1 || nx > W || nx < 1) break;
                    if(masu[ny][nx] == '#') break;
                    if(masu[ny][nx] == bar[i]){
                        ny += diry[dir[i]]; nx += dirx[dir[i]];
                        continue;
                    }
                    if(masu[ny][nx] >= 'A' && masu[ny][nx] <= 'Z'){
                        int v = masu[ny][nx] - 'A';
                        G[u].push_back(v);
                        G[v].push_back(u);
                        break;
                    }
                    break;
                }
            }
        }
    }
    
    
    vector<ll> dist(30,INF);
    dist[s] = 0;
    queue<ll> q; q.push(s);
    while(q.size()){
        ll n = q.front(); q.pop();
        for(auto next:G[n]){
            if(dist[next] > dist[n] + 1){
                dist[next] = dist[n] + 1;
                q.push(next);
            }
        }
    }
//    cout << dist << endl;
    cout << dist[t] << endl;
    return 0;
}
