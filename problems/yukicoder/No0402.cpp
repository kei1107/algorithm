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
 <url:https://yukicoder.me/problems/no/402>
 問題文============================================================
 =================================================================
 解説=============================================================
 海を始点としたbfsでえいすると解ける
 ================================================================
 */

int solve(){
    int res = 0;
    int H,W; cin >> H >> W;
    vector<vector<char>> S(H+2,vector<char>(W+2,'.'));
    vector<vector<int>> F(H+2,vector<int>(W+2,0));
    for(int i = 1; i <= H;i++) for(int j = 1; j <= W;j++) cin >> S[i][j];
    
    queue<pii> ps;
    for(int i = 0; i <= H+1;i++){
        for(int j = 0; j <= W+1;j++){
            if(S[i][j] == '.'){
                ps.push(pii(i,j));
            }else{
                F[i][j] = INF;
            }
        }
    }
    int dx[8] = {1,1,1,0,-1,-1,-1,0};
    int dy[8] = {-1,0,1,1,1,0,-1,-1};
    while(ps.size()){
        int y,x; tie(y,x) = ps.front(); ps.pop();
        
        for(int k = 0; k < 8;k++){
            int ny = y + dy[k];
            int nx = x + dx[k];
            if(ny < 0 || nx < 0 || ny >= H+2 || nx >= W+2) continue;
            if(S[ny][nx] == '#'){
                if(F[ny][nx] > F[y][x] + 1){
                    F[ny][nx] = F[y][x] + 1;
                    ps.push(pii(ny,nx));
                }
            }
        }
    }
    for(auto vec:F) for(auto out:vec) res = max(res,out);
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
