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
 <url:https://beta.atcoder.jp/contests/mujin-pc-2018/tasks/mujin_pc_2018_c>
 問題文============================================================
 =================================================================
 解説=============================================================
 愚直にやると間に合わない（1WA)
 
 ここで重要なのは、ロボットの２段階の移動は各々独立に考えていいということ
 
 注目すべきは途中の右に回る際にとまるマスであり、
 そのマスに注目したとき、そのマスを一時停止マスとなるような移動方法は
 （そのマスからある方向に進む際の移動可能回数）x (そのマスからさっき決めた方向に対して時計回りの方向に進む際の移動回数）
 となる。
 
 あるマスからそれぞれの方向にどれほど進むことができるかについては、dpの要領で伝播させて行けば良いので
 O(NM)で求まる
 ================================================================
 */

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
ll cnt[2005][2005][4];
ll solve(){
    ll res = 0;
    ll N,M; cin >> N >> M;
    vector<vector<char>> s(N+2,vector<char>(M+2,'#'));
    for(int i = 1; i <= N;i++){
        for(int j = 1; j <= M;j++){
            cin >> s[i][j];
        }
    }

    for(int i = 1 ; i <= N;i++){
        for(int j = 1;j <= M;j++){
            if(s[i][j] == '#') continue;

            for(int k = 0; k < 2;k++){
                int x = i,y = j;
                int nx = x + dx[k],ny = y + dy[k];
                if(s[nx][ny] != '#'){
                    cnt[nx][ny][(k+2)%4] = cnt[x][y][(k+2)%4] + 1;
                }
            }
        }
    }
    for(ll i = N ; i >= 1;i--){
        for(ll j = M;j >= 1;j--){
            if(s[i][j] == '#') continue;

            for(int k = 2; k < 4;k++){
                ll x = i,y = j;
                int nx = x + dx[k],ny = y + dy[k];
                if(s[nx][ny] != '#'){
                    cnt[nx][ny][(k+2)%4] = cnt[x][y][(k+2)%4] + 1;
                }
            }
        }
    }

    for(int i = 1 ; i <= N;i++){
        for(int j =1;j <= M;j++){
            if(s[i][j] == '#') continue;
            for(int k = 0; k < 4;k++){
                int x = i,y = j;
                res += cnt[x][y][k]*cnt[x][y][(k+1)%4];
            }
        }
    }

    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
