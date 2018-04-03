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
 <url:https://yukicoder.me/problems/no/20>
 問題文============================================================
 太郎君は砂漠を歩く行商人です。
 太郎君はこれから次の街へ行こうとしています。
 
 砂漠には移動しやすい場所とそうでない場所があり、
 太郎君は長年の経験から、
 その場所に行くためにどれくらいの体力を消耗するか知っています。
 
 砂漠は際限なく続いていますが、太郎君が知っているのは N×N マスの範囲だけで、
 その外側に行くと命の危険があるため絶対に行きません。
 砂漠の中には、(Ox,Oy)の場所にオアシスがありこの場所へ行くと、
 「1度だけ」体力を現在の値の「2倍」にすることができます。(オアシスが無い場合もあります)
 
 いま太郎君は (1,1) の場所に立っており、次の街は (N,N) の場所にあります。
 太郎君は、辺を共有する前後左右の隣接マスへのみ移動することができ、
 次のマスへ移動すると、移動した先の砂漠レベル(Lxy)分の体力が減ります。
 移動先の砂漠レベルが0の場合、体力値は減りませんが、
 太郎君の体力が0以下になった時点で太郎君が死んでしまいます。
 
 オアシスがある場所にも砂漠レベルが1以上ある場合もあり、
 その場合は砂漠レベル分の体力が減った後に、オアシスの効果が適用されます。
 
 太郎君が次の街へ無事たどり着けるか教えてあげてください。
 
 オアシスが(1,1)にあることはない。
 =================================================================
 解説=============================================================
 
 dist[x][y][flag] := (x,y)で　flag (0 : オアシスで休んでない 1:オアシスで休んだ）
 で拡張dijkstra

 ================================================================
 */

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
#define MAX_N 210
int L[MAX_N][MAX_N];
int dist[MAX_N][MAX_N][2];
int N,V,Ox,Oy;

string solve(){ cin >> N >> V >> Oy >> Ox;
    fill(*L,*L+MAX_N*MAX_N,-1);
    fill(**dist,**dist+MAX_N*MAX_N*2,0);
    
    for(int i = 1; i <= N;i++) for(int j = 1; j <= N; j++) cin >> L[i][j];
    
    dist[1][1][0] = V;
    using Items = tuple<int,int,int>;
    queue<Items> q; q.push(Items(1,1,0));
    while(q.size()){
        int x,y,f;
        tie(x,y,f) = q.front(); q.pop();
        for(int k = 0; k < 4; k++){
            int nx = x + dx[k], ny = y + dy[k];
            if(L[nx][ny] == -1) continue;
            if(dist[nx][ny][f] < dist[x][y][f] - L[nx][ny]){
                dist[nx][ny][f] = dist[x][y][f] - L[nx][ny];
                if(f == 1){ q.push(Items(nx,ny,f)); }
                else {
                    if(nx == Ox&&ny==Oy){
                        dist[nx][ny][1] = 2*dist[nx][ny][0];
                        q.push(Items(nx,ny,1));
                    }else{
                        q.push(Items(nx,ny,0));
                    }
                }
            }
        }
    }
    if(dist[N][N][0] + dist[N][N][1] == 0) return "NO";
    return "YES";
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
