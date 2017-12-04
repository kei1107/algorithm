#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
 <url:https://www.ioi-jp.org/joi/2014/2015-ho/2015-ho.pdf>
 問題文============================================================
 20XX 年に IOI 国で行われるオリンピックに備え，IOI 国にある JOI 公園を整備することになった．
 JOI公園には N 個の広場があり，広場には 1 から N の番号がついている．
 広場を繋ぐ M 本の道があり，道には 1 から M の番号がついている．
 道 i (1 ≦ i ≦ M) は広場 Ai と広場 Bi を双方向に繋いでおり，長さは Di である．
 どの広場からどの広場へもいくつかの道を辿って行くことができる．
 整備計画では，まず，
 0 以上の整数 X を選び，広場 1 からの距離が X 以下であるような広場(広場 1 を含む)
 どうしをすべて相互に地下道で結ぶ．
 ただし，広場 i と広場 j の距離とは，広場 i から広場 j に行くときに通る道の長さの和の最小値である．
 整備計画では地下道の整備コストに関する整数 C が定まっている．地下道の整備にかかるコストは C × X である．
 次に，地下道で結ばれた広場どうしを結ぶ道をすべて撤去する．道の撤去にコストはかからない．
 最後に，撤去されずに残った道をすべて補修する．長さ d の道を補修するためにかかるコストは d である．
 整備計画実施前の JOI 公園には地下道はない．JOI 公園の整備にかかるコストの和の最小値を求めよ．
 
 JOI 公園の広場の情報と，地下道の整備コストに関する整数が与えられたとき，
 JOI 公園の整備にかかるコストの和の最小値を求めるプログラムを作成せよ．
 =================================================================
 解説=============================================================
 
 dijkstra + 累積和
 
 先に1からN頂点までの最短距離を求める
 その後、近い点から順に1からその点まで構成している辺のコストを累積和で求める
 答えは min(C*dist[i] + (sum_dist[N] - sum_dist[i])
 ================================================================
 */
struct edge{
    ll u;
    ll v;
    ll cost;
    edge(){}
    edge(ll u,ll v,ll c):u(u),v(v),cost(c){}
};
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll N,M,C; cin >> N >> M >> C;
    vector<vector<edge>> G(N+1);
    for(int i = 0;i < M;i++){
        ll A,B,D; cin >> A >> B >> D;
        G[A].push_back(edge(A,B,D));
        G[B].push_back(edge(B,A,D));
    }
    vector<pll> dist(N+1);
    for(int i = 0; i <= N;i++) {dist[i].first = LINF; dist[i].second = i;}
    queue<ll> q;
    dist[1].first = 0;
    q.push(1);
    while(!q.empty()){
        auto n = q.front(); q.pop();
        for(auto e:G[n]){
            if(dist[e.v].first > dist[e.u].first + e.cost){
                dist[e.v].first = dist[e.u].first + e.cost;
                q.push(e.v);
            }
        }
    }
    sort(dist.begin(),dist.end());
    vector<ll> cusum(N+1,0); vector<int> used(N+1,0);
    used[0] = used[dist[0].second] = 1;
    for(int i = 1; i < N;i++){
        used[dist[i].second] = 1;
        ll tc = 0;
        for(auto e:G[dist[i].second]){
            if(used[e.v] == 1){
                tc += e.cost;
            }
        }
        cusum[i] = cusum[i-1] + tc;
    }
    ll ans = LINF;
    for(int i = 0; i < N;i++){
        ans = min(ans,C*dist[i].first + (cusum[N-1] - cusum[i]));
    }
    cout << ans << endl;
    return 0;
}
