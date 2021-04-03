#include "bits/stdc++.h"
#include "atcoder/all"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T>& V){ for(size_t i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> >& Mat){ for(size_t i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T>& mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }
template<typename T>vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}
/*
 <url:https://atcoder.jp/contests/agc014/tasks/agc014_c>
 問題文============================================================
 C - Closed Rooms 
 =================================================================
 解説=============================================================
 ================================================================
 */

int dir[4] = {1,0,-1,0};
template<class Type>
Type solve(Type res = Type()){
    int H,W,K; cin >> H >> W >> K;
    vector<vector<char>> A(H,vector<char>(W));

    pii S;
    for(int i = 0; i < H;i++){
        for(int j = 0; j < W;j++){
            cin >> A[i][j];
            if(A[i][j] == 'S'){
                S = {i,j};
                A[i][j] = '.';
            }
        }
    }

    set<pii> pos;
    int cnt = 1;
    {// init state
        auto dist = make_v<int>(H,W);
        fill_v(dist,INF);
        dist[S.first][S.second] = 0;

        queue<pii> q; q.emplace(S);

        while(q.size()){
            auto [x,y] = q.front(); q.pop();
            if(dist[x][y] >= K) continue;
            for(int k = 0; k < 4;k++){
                int nx = x + dir[k];
                int ny = y + dir[k^1];
                if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
                if(A[nx][ny] == '#') continue;
                if(nx == 0 || nx == H-1 || ny == 0 || ny == W-1) return cnt;
                pos.emplace(nx,ny);
                if(dist[nx][ny] > dist[x][y] + 1){
                    dist[nx][ny] = dist[x][y] + 1;
                    q.emplace(nx,ny);
                }
            }
        }
        pos.emplace(S);
        cnt++;
    }
    while(true){
        
        auto dist = make_v<int>(H,W);
        fill_v(dist,INF);
        queue<pii> q; 

        for(auto p:pos){ 
            dist[p.first][p.second] = 0;
            q.emplace(p);
        }
        pos.clear();

        while(q.size()){
            auto [x,y] = q.front(); q.pop();
            if(dist[x][y] >= K) continue;
            for(int k = 0; k < 4;k++){
                int nx = x + dir[k];
                int ny = y + dir[k^1];
                if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
                if(nx == 0 || nx == H-1 || ny == 0 || ny == W-1) return cnt;
                pos.emplace(nx,ny);
                if(dist[nx][ny] > dist[x][y] + 1){
                    dist[nx][ny] = dist[x][y] + 1;
                    q.emplace(nx,ny);
                }
            }
        }

        cnt++;
    }


    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    //solve<ll>(0);
    cout << fixed << setprecision(12) << solve<ll>() << endl;
    return 0;
}