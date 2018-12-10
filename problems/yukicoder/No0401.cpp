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
 <url:https://yukicoder.me/problems/no/401>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 実装
 
 ================================================================
 */

vector<vector<string>> solve(){
    int N; cin >> N;
    vector<vector<string>> res(N,vector<string>(N,"@"));
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};

    int dir = 0;
    int cnt = 1;
    int x = 0,y = 0;
    while(cnt<=N*N){
        ostringstream ss; ss << std::setw(3) << setfill('0') << cnt;
        res[y][x] = ss.str();
        
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if(ny < 0 || nx < 0 || ny >= N || nx >= N || res[ny][nx] != "@"){
            (dir += 1)%=4;
        }
        y = y + dy[dir];
        x = x + dx[dir];
        cnt++;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
