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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2014&lang=jpd>
 問題文============================================================
 =================================================================
 解説=============================================================
 シミュレーションする
 ================================================================
 */
int w,h;
vector<int> solve(){
    vector<int> res{0,0};
    vector<vector<char>> a(h+2,vector<char>(w+2,'#'));
    for(int i = 1; i <= h;i++) for(int j = 1; j <= w;j++) cin >> a[i][j];
    vector<vector<int>> flag(h+2,vector<int>(w+2,0));
    for(int i = 1; i <= h;i++){
        for(int j = 1; j <= w;j++){
            if(a[i][j] == '.') continue;
            int cost = (a[i][j]=='W')?2:1;
            int d[4] = {1,0,-1,0};
            queue<pii> q;
            for(int k = 0; k < 4;k++){
                int ni = i + d[k], nj = j + d[k^1];
                if(a[ni][nj] == '.') q.push(make_pair(ni,nj));
            }
            while(q.size()){
                int x,y; tie(x,y) = q.front(); q.pop();
                if(flag[x][y]&cost) continue;
                flag[x][y] += cost;
                for(int k = 0; k < 4;k++){
                    int nx = x + d[k], ny = y + d[k^1];
                    if(a[nx][ny] != '.') continue;
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }
    for(int i = 1; i <= h;i++){
        res[0] += count(flag[i].begin(),flag[i].end(),1);
        res[1] += count(flag[i].begin(),flag[i].end(),2);
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
