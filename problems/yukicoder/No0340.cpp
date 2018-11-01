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
 <url:https://yukicoder.me/problems/no/340>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 一回のクエリ毎に愚直に辺をつなげていくと当然TLE
 
 移動可能な辺というのは縦or横でまとまって与えられるので、
 imos法で移動可能な辺を高速で求めて、
 あとはdijkstraすればいい
 ================================================================
 */

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int coord2idx(const pii& coor,const int H,const int W){
    return coor.first*W + coor.second;
}
pii idx2coord(const int idx,const int H,const int W){
    return make_pair(idx/W, idx%W);
}

int yoko[1010][1010];
int tate[1010][1010];

int dist[1010][1010];
string solve(){
    string res;
    int W,H,N; cin >> W >> H >> N;
    for(int _ = 0; _ < N; _++){
        int M; cin >> M;
        vector<int> B(M+1);
        for(auto& in:B) cin >> in;
        for(int i = 0; i < M; i++){
            int S = B[i],T = B[i+1];
            
            pii sc = idx2coord(S, H, W),tc = idx2coord(T, H, W);
            if(sc.first == tc.first){ // 縦方向移動
                yoko[sc.first][min(sc.second,tc.second)]++;
                yoko[sc.first][max(sc.second,tc.second)]--;
            }

            if(sc.second == tc.second){ // 横方向移動
                tate[min(sc.first,tc.first)][sc.second]++;
                tate[max(sc.first,tc.first)][sc.second]--;
            }
        }
    }
    for(int i = 0; i < H;i++){
        for(int j = 1; j <= W;j++){
            yoko[i][j] += yoko[i][j-1];
        }
    }
    for(int j = 0; j < W;j++){
        for(int i = 1; i <= H;i++){
            tate[i][j] += tate[i-1][j];
        }
    }
    
    fill(*dist,*dist+1010*1010,INF);
    dist[0][0] = 0;
    queue<pii> q; q.push(make_pair(0, 0));
    while(q.size()){
        int y,x;
        tie(y,x)= q.front(); q.pop();
        if(tate[y][x]>0){
            if(dist[y+1][x] > dist[y][x] + 1){
                dist[y+1][x] = dist[y][x] + 1;
                q.push(make_pair(y+1, x));
            }
        }
        if(yoko[y][x]>0){
            if(dist[y][x+1] > dist[y][x] + 1){
                dist[y][x+1] = dist[y][x] + 1;
                q.push(make_pair(y, x+1));
            }
        }
        if(y){
            if(tate[y-1][x]>0){
                if(dist[y-1][x] > dist[y][x] + 1){
                    dist[y-1][x] = dist[y][x] + 1;
                    q.push(make_pair(y-1, x));
                }
            }
        }
        if(x){
            if(yoko[y][x-1]>0){
                if(dist[y][x-1] > dist[y][x] + 1){
                    dist[y][x-1] = dist[y][x] + 1;
                    q.push(make_pair(y, x-1));
                }
            }
        }
    }
    res = to_string(dist[H-1][W-1]);
    if(dist[H-1][W-1] == INF) return "Odekakedekinai..";
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
