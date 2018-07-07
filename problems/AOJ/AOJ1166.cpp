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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1166&lang=jp>
 問題文============================================================
 =================================================================
 解説=============================================================
 入力に従って移動可能な隣接グリッドのグラフを作っておき、最短経路を求めれば良い
 ================================================================
 */

int w,h;
int getid(int x,int y){
    return w*y+x;
}
ll solve(){
    ll res = 0;
    vector<vector<int>> G(w*h);
    for(int i = 0; i < h;i++){
        for(int j = 0; j < w-1;j++){
            int s; cin >> s;
            if(s == 0){
                int u = getid(j,i),v = getid(j+1,i);
                G[u].push_back(v);
                G[v].push_back(u);
            }
        }
        if(i == h-1) break;
        for(int j = 0; j < w;j++){
            int s; cin >> s;
            if(s == 0){
                int u = getid(j,i),v = getid(j,i+1);
                G[u].push_back(v);
                G[v].push_back(u);
            }
        }
    }
    queue<int> q;
    vector<int> dist(w*h,INF); dist[0] = 1;
    q.push(0);
    while(q.size()){
        int n = q.front(); q.pop();
        for(auto next:G[n]){
            if(dist[next] > dist[n] + 1){
                dist[next] = dist[n] + 1;
                q.push(next);
            }
        }
    }
    res = dist[h*w-1] == INF?0:dist[h*w-1];
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    while(cin >> w >> h,w){
        cout << solve() << endl;
    }
    return 0;
}
