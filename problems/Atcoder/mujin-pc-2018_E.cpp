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
 <url:https://beta.atcoder.jp/contests/mujin-pc-2018/tasks/mujin_pc_2018_e>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 dist[i][j][k] := マス(i,j)にいるとき、時間が k (mod K)であるときの最短距離
 としたいが、これだとTLEする。
 
 ここで、dist[i][j]がそのマスへの最短距離だとすれば、その最短距離がそのまま経過時間
 と見ることができる。
 経過時間がわかれば、次にある方向に移動したいとき、どれだけ待てば良いのかについては
 あらかじめ計算しておくことができる
 
 ================================================================
 */

int d[4] = {1,0,-1,0};
map<char,int> dir;
ll solve(){
    dir['D'] = 0; dir['R'] = 1; dir['U'] = 2; dir['L'] = 3;
    ll res = 0;
    
    ll N,M,K; cin >> N >> M >> K;
    string D; cin >> D;
    vector<vector<char>> s(N+2,vector<char>(M+2,'#'));
    pii S,G;
    for(int i = 1; i <= N;i++) for(int j = 1; j <= M;j++){
        cin >> s[i][j];
        if(s[i][j] == 'S'){
            S = {i,j};
            s[i][j] = '.';
        }
        if(s[i][j] == 'G'){
            G = {i,j};
            s[i][j] = '.';
        }
    }
    D += D;
    vector<vector<ll>> dirdp(D.length()+1,vector<ll>(4,LINF));
    for(ll n = D.length()-1;n >= 0;n--){
        for(int i = 0; i < 4;i++){
            dirdp[n][i] = dirdp[n+1][i] + 1;
        }
        dirdp[n][dir[D[n]]] = 0;
    }

    vector<vector<ll>> dist(N+2,vector<ll>(M+2,LINF));
    dist[S.first][S.second] = 0;
    queue<pii> q; q.push({S.first,S.second});
    while(q.size()){
        int y,x; tie(y,x) = q.front();  q.pop();
        
        ll T = dist[y][x]%K;
        for(int k = 0; k < 4;k++){
            ll add = dirdp[T][k];
            int ny = y + d[k],nx = x + d[k^1];
            if(s[ny][nx] == '#') continue; // マス的に移動できない
            if(dist[ny][nx] > dist[y][x] + add + 1){
                dist[ny][nx] = dist[y][x] + add + 1;
                q.push({ny,nx});
            }
        }
    }

    res = dist[G.first][G.second];
    if(res == LINF) res = -1;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
