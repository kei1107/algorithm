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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1160&lang=jp>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */

int w,h;
int solve(){
    int res = 0;
    vector<vector<int>> grid(h+2,vector<int>(w+2));
    for(int i = 1; i <= h; i++) for(int j = 1; j <= w;j++) cin >> grid[i][j];
    for(int i = 1; i <= h; i++) for(int j = 1; j <= w;j++){
        if(grid[i][j]){
            queue<pii> q; q.push({i,j});
            while(q.size()){
                int y,x;  tie(y,x) = q.front(); q.pop();
                if(grid[y][x] == 0) continue;
                grid[y][x] = 0;
                for(int dy = -1; dy <= 1; dy++){
                    for(int dx = -1; dx <= 1; dx++){
                        q.push({y+dy,x+dx});
                    }
                }
            }
            res++;
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    while(cin >> w >> h,w){
        cout << solve() << endl;
    }
    return 0;
}
