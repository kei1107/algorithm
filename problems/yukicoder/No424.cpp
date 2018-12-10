#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

/*
 <url:https://yukicoder.me/problems/no/424>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 やるだけ
 
 ================================================================
 */

template<class T>
T solve(T res){
    int h,w; cin >> h >> w;
    pii s,g; cin >> s.first >> s.second >> g.first >> g.second;
    vector<vector<int>> b(h+2,vector<int>(w+2,INF));
    for(int i = 1; i <= h;i++) for(int j = 1; j <= w; j++){char c; cin >> c; b[i][j]=c-'0';}
    vector<vector<int>> ok(h+2,vector<int>(w+2,false));
    queue<pii> q; q.push(s);
    int d[4] = {1,0,-1,0};
    while(q.size()){
        pii p = q.front(); q.pop();
        if(ok[p.first][p.second]) continue;
        ok[p.first][p.second] = true;
        for(int k = 0; k < 4;k++){
            int ny = p.first + d[k];
            int nx = p.second + d[k^1];
            
            if(abs(b[p.first][p.second]-b[ny][nx]) <= 1){
                q.push(pii(ny,nx));
            }
            if(b[p.first][p.second]>b[ny][nx]){
                ny+=d[k];
                nx+=d[k^1];
                if(ny<0 || nx < 0 || ny >= h+1 || nx >= w+1) continue;
                if(b[p.first][p.second]==b[ny][nx]){
                    q.push(pii(ny,nx));
                }
            }
        }
    }
    if(ok[g.first][g.second]) res = "YES";
    else res = "NO";
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve<string>("") << endl;
    return 0;
}
