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
 <url:https://atcoder.jp/contests/abc170/tasks/abc170_f>
 問題文============================================================
 F - Pond Skater
 =================================================================
 解説=============================================================
 
 考慮すべき状態量はほとんど無い
 
 ある位置から四方にいどうしたとき、途中でその位置までの最短距離が元々の位置の
 最短距離以下の場所に到達すれば、それ以上見る必要はない
 
 問題は、
 
   @o
   ox
 
 のようにoからxへ移動する場合、異なる方向へ伝播する可能性がある
 
   @o
   oxx.
    x
    .
 
 通常のダイクストラではこういった場合を考慮できない。
 
 解決策として、最短距離の集合を逐次作っていき、すべての等距離の位置を同時に更新することを行う。
 ある地点を複数回見る可能性はあるが、以前に探索済みの位置に到達すればそれ以降見る必要がなくなるため
 ほぼO(HW)で解ける
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int H,W,K; cin >> H >> W >> K;
    pii s,g; cin >> s.first >> s.second >> g.first >> g.second;
    s.first--; s.second--; g.first--; g.second--;
    auto c = make_v<char>(H,W);
    for(auto& vec:c) for(auto& in:vec) cin >> in;
    
    int dir[4] = {1,0,-1,0};
    auto dist = make_v<int>(H,W);
    fill_v(dist,INF);
    
    set<pii> st[2];
    int cur = 0,next = 1;
    st[cur].emplace(s);
    dist[s.first][s.second] = 0;
    while(st[cur].size()){
        for(auto& p:st[cur]){
            int x,y; tie(x,y) = p;
            for(int k = 0; k < 4;k++){
                for(int cnt = 1; cnt <= K; cnt++){
                    int nx = x + dir[k]*cnt;
                    int ny = y + dir[k^1]*cnt;
                    if(nx < 0 || nx >= H || ny < 0 || ny >= W) break;
                    if(c[nx][ny] == '@') break;
                    // if(dist[nx][ny] != INF) break;
                    if(dist[nx][ny] <= dist[x][y]) break;
                    dist[nx][ny] = dist[x][y] + 1;
                    st[next].emplace(nx,ny);
                }
            }
        }
        swap(cur,next);
        st[next].clear();
    }
    // cout << dist << endl;
    res = dist[g.first][g.second];
    
    if(res == INF) res = -1;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
