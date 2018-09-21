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
 <url:https://onlinejudge.u-aizu.ac.jp/services/room.html#ACPC2018Day2/problems/D>
 問題文============================================================
 =================================================================
 解説=============================================================
 移動経路で近い順に埋めていけば良い
 ================================================================
 */

const ll MOD = 1e9+7;
int d[4] = {1,0,-1,0};
struct edge{
    ll x,y,dist,sum;
    edge(ll x = 0,ll y = 0,ll dist = 0,ll sum = 0)
    :x(x),y(y),dist(dist),sum(sum){}
    bool operator < (const edge& e) const{
        return this->dist < e.dist;
    }
    bool operator > (const edge& e) const{
        return this->dist > e.dist;
    }

};
vector<ll> solve(){
    vector<ll> res;
    ll R,C,ai,aj,bi,bj;
    cin >> R >> C >> ai >> aj >> bi >> bj;
    vector<vector<pll>> dist(R,vector<pll>(C,{LINF,0}));
    priority_queue<edge,vector<edge>,greater<edge>> pq;
    pq.push(edge(ai,aj,0,1));
    dist[ai][aj] = {0,1};
    while(pq.size()){
        edge state = pq.top(); pq.pop();
        state.sum = dist[state.x][state.y].second;
        for(int k = 0; k < 4;k++){
            ll nx = state.x + d[k];
            ll ny = state.y + d[k^1];
            
            if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if(dist[nx][ny].first > state.dist + 1){
                dist[nx][ny] = {state.dist+1,state.sum};
                pq.push(edge(nx,ny,state.dist+1,state.sum));
            }else if(dist[nx][ny].first == state.dist + 1){
                (dist[nx][ny].second += state.sum)%=MOD;
            }
        }
        {
            ll nx = state.x; ll ny = 0;
            
            if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if(dist[nx][ny].first > state.dist + 1){
                dist[nx][ny] = {state.dist+1,state.sum};
                pq.push(edge(nx,ny,state.dist+1,state.sum));
            }else if(dist[nx][ny].first == state.dist + 1){
                (dist[nx][ny].second += state.sum)%=MOD;
            }
        }
        {
            ll nx = state.x; ll ny = C-1;
            
            if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if(dist[nx][ny].first > state.dist + 1){
                dist[nx][ny] = {state.dist+1,state.sum};
                pq.push(edge(nx,ny,state.dist+1,state.sum));
            }else if(dist[nx][ny].first == state.dist + 1){
                (dist[nx][ny].second += state.sum)%=MOD;
            }
        }
        {
            ll nx = 0; ll ny = state.y;
            
            if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if(dist[nx][ny].first > state.dist + 1){
                dist[nx][ny] = {state.dist+1,state.sum};
                pq.push(edge(nx,ny,state.dist+1,state.sum));
            }else if(dist[nx][ny].first == state.dist + 1){
                (dist[nx][ny].second += state.sum)%=MOD;
            }
        }
        {
            ll nx = R-1; ll ny = state.y;
            
            if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if(dist[nx][ny].first > state.dist + 1){
                dist[nx][ny] = {state.dist+1,state.sum};
                pq.push(edge(nx,ny,state.dist+1,state.sum));
            } else if(dist[nx][ny].first == state.dist + 1){
                (dist[nx][ny].second += state.sum)%=MOD;
            }
        }
    }
    
    res = vector<ll>{dist[bi][bj].first,dist[bi][bj].second};
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
