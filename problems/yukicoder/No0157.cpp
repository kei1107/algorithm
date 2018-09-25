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
 <url:https://yukicoder.me/problems/no/157>
 問題文============================================================
 =================================================================
 解説=============================================================
 幅優先探索でぞい
 ================================================================
 */
int d[4] = {1,0,-1,0};
void Fill(int h,int w,vector<vector<char>>& C,char k){
    queue<pii> q; q.push({h,w});
    while(q.size()){
        int i,j; tie(i,j) = q.front(); q.pop();
        if(C[i][j] != '.') continue;
        C[i][j] = k;
        for(int dir = 0; dir < 4; dir++){
            q.push({i+d[dir],j+d[dir^1]});
        }
    }
}
ll solve(){
    int W,H; cin >> W >> H;
    vector<vector<char>> C(H,vector<char>(W));
    for(auto& vec:C) for(auto& in:vec) cin >> in;
    
    char keyword = 'S';
    for(int i = 0; i < H;i++){
        for(int j = 0; j < W;j++){
            if(C[i][j] == '.'){
                Fill(i,j,C,keyword);
                if(keyword == 'S') keyword = 'G';
            }
        }
    }
    
    vector<vector<int>> dist(H,vector<int>(W,INF));
    queue<pii> q;
    for(int i = 0; i < H;i++) for(int j = 0; j < W;j++){
        if(C[i][j] == 'S'){
            dist[i][j] = 0;
            q.push({i,j});
        }
    }
    while(q.size()){
        int h,w; tie(h,w) = q.front(); q.pop();
        for(int k = 0; k < 4;k++){
            int nh = h + d[k],nw = w + d[k^1];
            if(nh <= 0 || nh >= H-1 || nw <= 0 || nw >= W-1)continue;
            if(dist[nh][nw] > dist[h][w] + 1){
                dist[nh][nw] = dist[h][w] + 1;
                q.push({nh,nw});
            }
        }
    }
    int res = INF;
    for(int i = 0; i < H;i++) for(int j = 0; j < W;j++){
        if(C[i][j] == 'G') res = min(res,dist[i][j]-1);
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
