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
 <url:https://yukicoder.me/problems/no/348>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 ただただ面倒
 
 連なるグリッドのグループを作って、木DPでかぞえあげるだけ
 ================================================================
 */

int dx[8] = {1,1,0,-1,-1,-1, 0, 1};
int dy[8] = {0,1,1,1 ,0 ,-1,-1,-1};
map<ll,ll> mp;
vector<int> Flag;
vector<set<int>> G;
pll rec(int n,int par = -1){
    ll sum1 = 0,sum2 = 0;
    if(Flag[n] == 0){
        for(auto next:G[n]){
            if(next == par) continue;
            auto ret = rec(next,n);
            sum1 += max(ret.first,ret.second);
            sum2 += ret.second;
        }
    }else{
        sum1 = mp[n];
        for(auto next:G[n]){
            if(next == par) continue;
            auto ret = rec(next,n);
            sum2 += max(ret.first,ret.second);
            sum1 += ret.second;
        }
    }
    return {sum1,sum2};
}
ll solve(){
    ll res = 0;
    int N,M; cin >> N >> M;
    vector<vector<char>> grid(N+2,vector<char>(M+2,'.'));
    for(int i = 1; i <= N; i++) for(int j = 1; j <= M;j++) cin >> grid[i][j];
    
    vector<vector<int>> checked(N+2,vector<int>(M+2,-1));
    int cnt = 0;
    // 連なる.やxをグループ分け
    for(int i = 0; i < N+2; i++){
        for(int j = 0; j < M+2; j++){
            if(checked[i][j]!=-1) continue;
            char c = grid[i][j];
            int add = 0;
            if(c == '.'){ Flag.push_back(0); add = 2;}
            else{ Flag.push_back(1); add = 1;}
            queue<pii> q; q.push({i,j});
            while(q.size()){
                int x,y;
                tie(y,x) = q.front(); q.pop();
                if(checked[y][x]!=-1) continue;
                checked[y][x] = cnt;
                for(int k = 0; k < 8; k+=add){
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if(ny < 0 || nx < 0 || ny >= N+2 || nx >= M+2) continue;
                    if(checked[ny][nx]!=-1) continue;
                    if(grid[ny][nx] != c) continue;
                    q.push({ny,nx});
                }
            }
            cnt++;
        }
    }

    G.resize(cnt);
    // グループ分けしたものからグラフを作る
    for(int i = 0; i < N+2; i++){
        for(int j = 0; j < M+2; j++){
            mp[checked[i][j]]++;
            int S = checked[i][j];
            for(int k = 0; k < 8; k+=2){
                int nx = j + dx[k];
                int ny = i + dy[k];
                if(ny < 0 || nx < 0 || ny >= N+2 || nx >= M+2) continue;
                if(checked[i][j] == checked[ny][nx]) continue;
                
                int T = checked[ny][nx];
                G[S].insert(T);
                G[T].insert(S);
            }
        }
    }
    
    auto ret = rec(0);
    res = max(ret.first,ret.second);
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
