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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1130&lang=jp>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 シミュレーションしてやるだけ
 
 ================================================================
 */

int solve(int w,int h){
    int res = 0;
    vector<vector<char>> masu(h+2,vector<char>(w+2,'#'));
    pii S;
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            cin >> masu[i][j];
            if(masu[i][j] == '@'){
                masu[i][j] = '.';
                S = {i,j};
            }
        }
    }
    vector<vector<int>> flag(h+2,vector<int>(w+2,0));
    queue<pii> q; q.push(S);
    int dxy[5] = {1,0,-1,0,1};
    while(q.size()){
        int x,y; tie(x,y) = q.front(); q.pop();
        if(masu[x][y] == '#') continue;
        if(flag[x][y] == 1) continue;
        flag[x][y] = 1;
        for(int k = 0; k < 4;k++){
            int nx = x + dxy[k],ny = y + dxy[k+1];
            q.push({nx,ny});
        }
    }
    for(auto& vec:flag) res += accumulate(vec.begin(),vec.end(),0);
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    int w,h;
    while(cin >> w >> h, w|h){
        cout << solve(w,h) << endl;
    }
    return 0;
}
