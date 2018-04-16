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
 <url:https://yukicoder.me/problems/no/34>
 問題文============================================================
 太郎君は砂漠を歩く行商人です。
 太郎君はこれから次の街へ行こうとしています。
 
 砂漠には移動しやすい場所とそうでない場所があり、
 太郎君は長年の経験から、
 その場所に行くとどれくらいの体力を消耗するかを知っています。
 
 砂漠は際限なく続いていますが、太郎君が知っているのは N×N マスの範囲だけで、
 その外側に行くと命の危険があるため絶対に行きません。
 
 いま太郎君は体力 V で (SX,SY) の場所に立っており、次の街は (GX,GY) の場所にあります。
 太郎君は、辺を共有する前後左右の隣接マスへのみ移動することができ、
 今居るマスから隣のマスへ移動するときに1回の移動とみなし、
 さらに、移動した先の砂漠レベル(LXY)分の体力が減ります。
 移動先の砂漠レベルが0の場合、体力値は減りませんが、
 太郎君の体力が 0以下 になった時点で太郎君が死んでしまいます。
 街に着いた瞬間に死んでしまってもいけません。
 
 太郎君は、商品をできるだけ早く捌きたいので、
 「太郎君が死なずに」「最も早く次の街へ着く」には、
 どれくらい時間がかかるか計算してください。
 
 1 行目に、砂漠の1辺の長さを表す整数 N (3≤N≤100)、
 太郎君の体力値を表す整数 V (1≤V≤10000)、
 太郎君の初期位置を表す整数の組 (SX,SY)(1≤SX,SY≤N)、
 次の街の位置を表す整数の組 (GX,GY)(1≤GX,GY≤N)、
 がスペース区切りで与えられます。
 続くN行に、それぞれの場所の砂漠レベル LXY (0≤LXY≤9) が空白区切りで与えられます。
 
 初期位置(SX,SY)と次の街の位置(GX,GY)は、同じ座標になることはありません。
 =================================================================
 解説=============================================================
 
 拡張ダイクストラ
 
 dist[v][y][x] := 座標y,xにおり、残り体力がvの時の最小移動回数で行えば良い
 ================================================================
 */

#define MAX_N 105
#define MAX_V 10001
int dist[MAX_V][MAX_N][MAX_N];
using Item = tuple<int,int,int,int>;
int dir[4] = {1,0,-1,0};
int solve(){
    fill(**dist,**dist + MAX_V*MAX_N*MAX_N,INF);
    int res = 0;
    int N,V,Sx,Sy,Gx,Gy; cin >> N >> V >> Sx >> Sy >> Gx >> Gy;
    vector<vector<int>> L(N+2,vector<int>(N+2,INF));
    for(int i = 1; i <= N; i++) for(int j = 1; j <= N; j++) cin >> L[i][j];
    priority_queue<Item,vector<Item>,greater<Item>> pq;
    dist[V][Sy][Sx] = 0; pq.push(Item(0,-V,Sy,Sx));
    while(pq.size()){
        int d,v,y,x; tie(d,v,y,x) = pq.top(); pq.pop();
        cout << d << endl;
        v = -v;
        if(dist[v][y][x] < d) continue;
        if(y == Gy && x == Gx) return res = d;
        for(int k = 0; k < 4;k++){
            int nx = x + dir[k], ny = y + dir[(k+1)%4];
            if((v - L[ny][nx] > 0) && (dist[v-L[ny][nx]][ny][nx] > dist[v][y][x] + 1)){
                dist[v-L[ny][nx]][ny][nx] = dist[v][y][x] + 1;
                pq.push(Item(d+1,-(v-L[ny][nx]),ny,nx));
            }
        }
    }
    return -1;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
