#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
 <url:https://www.ioi-jp.org/joi/2013/2014-yo/2014-yo-t5/2014-yo-t5.html>
 問題文============================================================
 IOI 国は町 1 から町 N までの N 個の町からなり，町と町とは道路で結ばれている．
 IOI 国には K 本の道路があり，すべての道路は異なる 2 つの町を結んでいる．
 車は道路を双方向に自由に移動できるが，道路以外を通ってある町から別の町に行くことはできない．
 
 IOI 国の町 1 に住む JOI 君は，町 N に住む祖母の家までタクシーで行くことにした．
 IOI 国にはタクシー会社 1 からタクシー会社 N までの N 個のタクシー会社がある．
 IOI 国のタクシー会社には次のような少々特殊な規則がある．
 
     タクシー会社 i のタクシーには，町 i でのみ乗車できる．
     タクシー会社 i のタクシーの運賃は，利用した距離によらず Ci である．
     タクシー会社 i のタクシーは，乗車してから連続して最大 Ri 本の道路しか通ることができない．
 
 たとえば R1 = 2 の場合，町 1 からタクシー会社 1 のタクシーに乗車すると，
 最大 2 本の道路しか通ることができないため，
 道路を 3 本以上通るためには途中の町でタクシーを乗り換える必要がある．
 
 JOI 君は町以外の地点でタクシーに乗ったりタクシーから降りたりすることはできない．
 また，タクシー以外の移動手段を用いることもできない．
 JOI 君が町 N に到達するために必要な運賃の合計の最小値を求めるプログラムを作成せよ．
 
 N, K (2 ≦ N ≦ 5000, N - 1 ≦ K ≦ 10000)
 Ci, Ri (1 ≦ Ci ≦ 10000, 1 ≦ Ri ≦ N)
 =================================================================
 解説=============================================================
 
 dijkstra
 
 問題を簡単にするため、先にタクシーによってある町から到達できる町へ、
 その運賃分をコストとした辺を張る(有向)
 
 そうすれば、単純に始点から終点までの最短距離を求めれば良い
 ================================================================
 */
struct edge{
    int u;
    int v;
    int cost;
    edge(){}
    edge(int u,int v,int c):u(u),v(v),cost(c){}
};
vector<vector<edge>> G;
vector<vector<int>> TG;
vector<int> C,R;
vector<int> used;

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    int N,K; cin >> N >> K;
    G.resize(N); TG.resize(N);
    C.resize(N); R.resize(N);
    used.resize(N);
    for(int i = 0; i < N;i++) cin >> C[i] >> R[i];
    for(int i = 0; i < K;i++){
        int a,b; cin >> a >> b;
        a--; b--;
        TG[a].push_back(b); TG[b].push_back(a);
    }
    queue<pii> q;
    for(int i = 0; i < N;i++) {
        fill(used.begin(),used.end(),0);
        used[i] = 1;
        q.push({i,0});
        while(!q.empty()){
            auto p = q.front(); q.pop();
            int n = p.first, r = p.second;
            for(auto next:TG[n]){
                if(used[next] == 0){
                    used[next] = 1;
                    G[i].push_back(edge(i,next,C[i]));
                    if(r + 1 < R[i]) q.push({next,r+1});
                }
            }
        }
    }
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    vector<ll> dist(N,LINF);
    dist[0] = 0;
    pq.push({0LL,0});
    while(!pq.empty()){
        auto p = pq.top(); pq.pop();
        ll d = p.first; int n = p.second;
        if(dist[n] < d) continue;
        for(auto e:G[n]){
            if(dist[e.v] > dist[e.u] + e.cost){
                dist[e.v] = dist[e.u] + e.cost;
                pq.push({dist[e.v],e.v});
            }
        }
    }
    cout << dist[N-1] << endl;
    return 0;
}
