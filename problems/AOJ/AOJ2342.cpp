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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2342>
 問題文============================================================
 
 NxMのマスが存在し、その中に始点と終点が存在する。
 始点から下方向にレーザーを発射し、ある規則に従って、それぞれA枚まである
 タイプP,Q鏡を置いてレーザーを曲げることができる(元ページ、要参照)
 
 始点に鏡を置くことができないとした時、終点までレーザーをたどり着かせることが可能か、
 可能ならば使用した鏡の枚数（P,Qの両方の総和）を述べよ
 
 =================================================================
 解説=============================================================
 
 気合拡張dijkstra
 
 前提条件より、 始点に鏡を置かない+最初に発射されて曲がるまでのレーザー以外で
 始点を縦に横断するようなレーザーを照射しないという条件が必要
 ================================================================
 */

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
// (P,Q)
pii mirrorr[4] = {{1,0},{0,1},{1,0},{0,1}};
pii mirrorl[4] = {{0,1},{1,0},{0,1},{1,0}};

bool dist[110][110][4][12][12]; // dist[i][j][dir][usedP][usedQ]
ll solve(){
    ll res = INF;
    ll N,M,A; cin >> N >> M >> A;
    pii S,G;
    vector<vector<char>> masu(N+2,vector<char>(M+2,'#'));
    for(int i = 1; i <= N;i++){
        for(int j = 1; j <= M;j++){
            cin >> masu[i][j];
            if(masu[i][j] == 'S') S = {i,j};
            if(masu[i][j] == 'G') G = {i,j};
        }
    }
    
    using items = tuple<int,int,int,int,int>;
    queue<items> q;
    q.push(make_tuple(S.first,S.second,1,0,0));
    while(q.size()){
        auto item = q.front(); q.pop();
        int i,j,dir,usedP,usedQ;
        tie(i,j,dir,usedP,usedQ) = item;
        if(masu[i][j] == '#') continue;
        if((usedP|usedQ) && masu[i][j] == 'S' && (dir&1)) continue;
        if(usedP > A || usedQ > A) continue;
        if(dist[i][j][dir][usedP][usedQ]) continue;
        dist[i][j][dir][usedP][usedQ] = true;
        
        int ny,nx;
        ny = i + dy[dir]; nx = j + dx[dir];
        q.push(make_tuple(ny,nx,dir,usedP,usedQ));
        
        if(masu[i][j] == 'S') continue;
        
        ny = i + dy[(dir+1)%4]; nx = j + dx[(dir+1)%4];
        q.push(make_tuple(ny,nx,(dir+1)%4,usedP+mirrorr[dir].first,usedQ+mirrorr[dir].second));
        
        ny = i + dy[(dir-1+4)%4]; nx = j + dx[(dir-1+4)%4];
        q.push(make_tuple(ny,nx,(dir-1+4)%4,usedP+mirrorl[dir].first,usedQ+mirrorl[dir].second));
    }
    
    for(int i = 0; i <= A;i++){
        for(int j = 0; j <= A;j++){
            for(int k = 0; k < 4;k++){
                if(dist[G.first][G.second][k][i][j]){
                    res = min(res,(ll)i+j);
                }
            }
        }
    }
    return res == INF?-1:res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
