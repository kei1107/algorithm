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
 <url:https://atcoder.jp/contests/past201912-open/tasks/past201912_j>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

template<class Type>
Type solve(Type res = Type()){
    int H,W; cin >> H >> W;
    vector<vector<ll>> A(H,vector<ll>(W));
    for(auto& vec:A) for(auto& in:vec) cin >> in;
    
    auto dijkstra = [&](int h,int w){
        auto dist = make_v<ll>(H,W); fill_v(dist,LINF);
        
        queue<pii> q; q.push(pii(h,w));
        dist[h][w] = 0;
        
        while(q.size()){
            int x,y; tie(x,y) = q.front(); q.pop();
            
            for(int k = 0; k < 4;k++){
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
                
                if(dist[nx][ny] > dist[x][y] + A[nx][ny]){
                    dist[nx][ny] = dist[x][y] + A[nx][ny];
                    q.push(pii(nx,ny));
                }
            }
        }
        
        return dist;
    };
    
    auto distH1 = dijkstra(H-1,0);
    auto distHW = dijkstra(H-1,W-1);
    auto dist1W = dijkstra(0,W-1);
    
    res = LINF;
    for(int i = 0; i < H;i++){
        for(int j = 0; j < W;j++){
            res = min(res,distH1[i][j] + distHW[i][j] + dist1W[i][j] - 2*A[i][j]);
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
