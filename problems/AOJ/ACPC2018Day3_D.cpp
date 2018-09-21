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
 <url:https://onlinejudge.u-aizu.ac.jp/services/room.html#ACPC2018Day3/problems/D>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 Dはdijkstra or dpのD
 
 dijkstraでやる
 
 1. 0-1-2-..-N までコスト1の辺を貼る
 2. 0...N-1 の各頂点から冗長時の削除時の経路として 0-0' 1-1' , ... (N-1)-(N-1)'
    へコスト0の辺をはる
 3. (頂点番号)' - (頂点番号) にコスト1の辺をはる
 4. 文字列の先頭が同一の頂点vsに関して、頂点番号が小さい順に
    (頂点番号)' - (頂点番号+1)' へコスト0の辺をはる
 
 これで 0 - Tまでの最短距離が求める答え
 ================================================================
 */

const int MAXN = 100005;
vector<pii> G[MAXN*2];
int dist[MAXN*2];
vector<int> verbose[26];

ll solve(){
    ll res = 0;
    int N; cin >> N;
    for(int i = 0; i < N;i++){
        string str; cin >> str;
        verbose[str.front()-'a'].push_back(i);
    }
    for(int i = 0; i < N;i++) G[i].push_back({i+1,1});
    for(int i = 0; i < 26;i++){
        for(int j = 0; j < verbose[i].size();j++){
            G[verbose[i][j]].push_back({verbose[i][j]+N+1,0});
            G[verbose[i][j]+N+1].push_back({verbose[i][j]+1,1});
            if(j != 0){
                G[verbose[i][j-1]+N+1].push_back({verbose[i][j]+N+1,0});
            }
        }
        
    }
    queue<int> q;
    fill(dist,dist+2*(N+1),INF);
    dist[0] = 0; q.push(0);
    while(q.size()){
        int n = q.front(); q.pop();
        for(const pii& e:G[n]){
            if(dist[e.first] > dist[n]+e.second){
                dist[e.first] = dist[n] + e.second;
                q.push(e.first);
            }
        }
    }
    res = dist[N];
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
