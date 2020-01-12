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
template<class T> ostream& operator << (ostream& out,const vector<T>& V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> >& Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T>& mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }
template<typename T>vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}
/*
 <url:https://atcoder.jp/contests/abc151/tasks/abc151_d>
 問題文============================================================
 D - Maze Master
 =================================================================
 解説=============================================================
 H,Wが小さいのでゴリ押す
 
 https://atcoder.jp/contests/abc151/submissions/9453095
 ================================================================
 */


int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

template<class Type>
Type solve(Type res = Type()){
    ll H,W; cin >> H >> W;
    vector<vector<char>> S(H+2,vector<char>(W+2,'#'));

    for(int i = 1; i <= H;i++){
        for(int j = 1; j <= W;j++){
            cin >> S[i][j];
        }
    }


    for(int sx = 1; sx <= H; sx++){
        for(int sy = 1; sy <= W; sy++){
            if(S[sx][sy] == '#') continue;
            vector<vector<ll>> dist(H+2,vector<ll>(W+2,INF));

            dist[sx][sy] = 0;
            queue<pll> q; q.push(pll(sx,sy));

            while(q.size()){
                ll x,y; tie(x,y) = q.front(); q.pop();
                for(int k = 0; k < 4;k++){
                    ll nx = x + dx[k];
                    ll ny = y + dy[k];

                    if(S[nx][ny] == '#') continue;

                    if(dist[nx][ny] > dist[x][y] + 1){
                        dist[nx][ny] = dist[x][y] + 1;
                        q.push(pll(nx,ny));
                    }
                }
            }

            ll T = 0;
            for(int i = 1; i <= H; i++){
                for(int j = 1; j <= W; j++){
                    if(S[i][j] == '#') continue;
                    if(dist[i][j] == INF) continue;
                    res = max(res,dist[i][j]);
                }
            }
            res = max(res,T);
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
