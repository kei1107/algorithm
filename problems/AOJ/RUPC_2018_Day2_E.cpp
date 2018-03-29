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
<url:https://onlinejudge.u-aizu.ac.jp/services/room.html#RitsCamp18Day2/problems/E>
問題文============================================================

 W×H  の二次元のマス上にN個の街灯がある。
 がっちょ君は(1,1)からスタートして(W,H)に行きたい。
 がっちょ君は暗いところが怖いので、街灯により明るくなっているマスしか歩きたくない。
 最初、すべての街灯はその街灯のあるマスのみを明るくしている。
 そこで、がっちょ君は好きな街灯iに対してコストriを設定することにした。なお、コストを設定しない街灯があってもよい。
 街灯iはコストriを消費することにより、その街灯を中心にマンハッタン距離でri以内の範囲を明るくすることができる。ただしコストは正の整数とする。
 がっちょ君は上下左右のいずれかの方向に隣接するマスに移動する事ができる。
 がっちょ君はriの合計値を最小になるように設定することにした。そのときの合計値を求めよ。
 2つの地点 (a,b) と (c,d) 間のマンハッタン距離は |a−c|+|b−d| で表される。
 

 
=================================================================

解説=============================================================

 dist[i][j] := i頂点で明るさがjである地点への最小コストで
 
 拡張dijkstra
 
================================================================
*/

ll dist[105][505*505];
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll W,H,N; cin >> W >> H >> N;
    vector<ll> x(N+1),y(N+1);
    x[0] = y[0] = 1;
    for(int i = 1; i <= N;i++) cin >> x[i] >> y[i];
    vector<vector<ll>> G(N+1);
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N;j++){
            if(i == j) continue;
            //if(x[i] <= x[j]){// && y[i] <= y[j]){
                G[i].push_back(j);
            //}
        }
    }

    for(int i = 0; i < 105;i++)for(int j = 0; j < 505*505; j++) dist[i][j] = LINF;
    
    typedef pair<ll,pll> plpll;
 //   dist[0][0] = 0;
    priority_queue<plpll,vector<plpll>,greater<plpll>> pq;
    for(int i = 1; i <= N;i++){
        ll cost = abs(x[i]-x[0])+abs(y[i]-y[0]);
        pq.push({cost,{i,cost}});
        dist[i][cost] = cost;
    }
//    pq.push({0,{0,0}});
    while(pq.size()){
        auto p = pq.top(); pq.pop();
        ll d = p.first, n = p.second.first, r = p.second.second;
        if(dist[n][r] < d) continue;
        for(ll next : G[n]){
            ll mdis = abs(x[n]-x[next]) + abs(y[n]-y[next]);
            if(r >= mdis-1){
                if(dist[next][0] > dist[n][r]){
                    dist[next][0] = dist[n][r];
                    pq.push({dist[next][0],{next,0}});
                }
            }else{
                ll cost = mdis-r-1;
                if(dist[next][cost] > dist[n][r] + cost){
                    dist[next][cost] = dist[n][r] + cost;
                    pq.push({dist[next][cost],{next,cost}});
                }
            }
        }
    }
    ll ans = LINF;
    for(int i = 1; i <= N;i++){
        for(int j = 0; j < 505*505;j++){
            if(dist[i][j]==LINF)continue;
            ll mdis = abs(W-x[i])+abs(H-y[i]);
            ans = min(ans,dist[i][j]+max(mdis-j,0LL));
        }
    }
    cout << ans << endl;
	return 0;
}
