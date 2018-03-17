#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream &operator << (ostream& out,const pair<S,T>& o){
    out << "(" << o.first << "," << o.second << ")"; return out;
}

/*
<url:https://arc061.contest.atcoder.jp/tasks/arc061_c>
問題文============================================================
 すぬけ君の住んでいる街には地下鉄が走っています。駅は全部で N 個あり、路線は全部で M 本あります。
 駅には 1 から N までの整数が付けられています。
 また、それぞれの路線はある 1 つの会社によって運営されており、
 それぞれの会社には会社をあらわす整数がつけられています。
 
 i 番目 ( 1≤i≤M ) の路線は、駅 pi と 駅 qi を相互に結んでいます。途中に他の駅はありません。
 また、この路線は会社 ci によって運営されています。
 同じ駅を通る路線が複数あるときは、その駅で乗り換えることができます。
 
 それぞれの会社について、同じ会社の路線を使い続ける限り料金は 1 ですが、
 別の会社の路線に乗り換えるたびに新たに料金が 1 かかります。
 ある会社を利用し、別の会社を利用してからまた最初の会社を利用する場合でも、再び料金を払う必要があります。
 
 すぬけ君は、駅 1 を出発し、地下鉄を利用して駅 N に行きたいです。移動にかかる料金の最小値を求めてください。
 
 2≤N≤10^5
 0≤M≤2×10^5
 1≤pi≤N (1≤i≤M)
 1≤qi≤N (1≤i≤M)
 1≤ci≤10^6 (1≤i≤M)
 pi≠qi (1≤i≤M)
=================================================================

解説=============================================================
 600点代以上の解説はある程度　丁寧に（コード内にもコメントを）書くことにした。
 
 この問題は一見すると拡張dijkstraに見えるが、鉄道会社の数が多く、そのままの形式を
 dijkstraを行うことができない。よって、形式を変更する。
 
 まず、鉄道会社の数が多いが、それよるも貼る辺の数が少ないので、dist[頂点][鉄道会社]で
 対応づけるよりも、dist[(頂点、鉄道会社)]としてある頂点をそれに連なる鉄道会社ごとに
 別の頂点として扱ったほうが辺の数は少なくなる
 
 次にどうやって辺を貼って行くかについてだが、ある頂点v と、それに連なる鉄道会社 ci,cjがあるとすれば
 全体で見て(v,ci) (cost:1)-> (v,cj) へ直接　コスト１の辺を連結するよりも
 (v,ci) (cost:0)-> (v,どの鉄道も利用していない) (cost:1)-> (v,Σcj) へ
 辺をつなげた方が効率が良く、実装が楽である。
 
 よって、次のように辺を貼って行けば良い
 
 (v,どの鉄道も利用していない) -> (v,全てのci) へ　コスト1
 (u,ci) -> (v,ci) へ　コスト 0
 (v,ci) -> (v,どの鉄道も利用していない) へ　コスト 0
 
 
 答えは (1,どの鉄道も利用していない) -> (N,どの鉄道も利用していない）までの最短距離となる

================================================================
*/

struct edge{
    int u,v,c;
    edge(){}
    edge(int u,int v,int c):u(u),v(v),c(c){}
};
int solve(){
    // input
    int N,M; cin >> N >> M;
    vector<edge> G(M); // (u,v,c)
    vector<vector<int>> com(N); // 頂点 v に連なる鉄道会社を列挙
    for(int i = 0; i < M;i++){
        int p,q,c; cin >> p >> q >> c; p--; q--; c--;
        G[i] = edge(p,q,c);
        com[p].push_back(c); com[q].push_back(c);
    }
    
    // com の重複要素を取り除く
    for(int i = 0; i < N;i++){
        sort(com[i].begin(),com[i].end());
        com[i].erase(unique(com[i].begin(),com[i].end()),com[i].end());
    }
    
    int idx = 0; // 変形後の全頂点数
    map<pii,int> mp; // (v,ci)の対応
    for(int i = 0; i < N;i++) mp[pii(i,-1)] = idx++; // (v,どの鉄道も利用していない)の頂点番号
    for(int i = 0; i < N;i++){
        for(int j = 0; j < (int)com[i].size();j++){
            mp[pii(i,com[i][j])] = idx++; // (v,ci) の頂点番号
        }
    }
    
    // make Graph
    vector<vector<edge>> nG(idx);
    for(int i = 0; i < N;i++){
        int v1 = mp[pii(i,-1)];
        for(int j = 0; j < (int)com[i].size();j++){
            int v2 = mp[pii(i,com[i][j])];
            nG[v1].push_back(edge(v1,v2,1)); // (v,どの鉄道も利用していない) -> (v,全てのci) へ　コスト1
            nG[v2].push_back(edge(v2,v1,0)); // (v,ci) -> (v,どの鉄道も利用していない) へ　コスト 0
        }
    }
    for(int i = 0; i < M;i++){
        edge& e = G[i];
        int v1 = mp[pii(e.u,e.c)], v2 = mp[pii(e.v,e.c)];
        nG[v1].push_back(edge(v1,v2,0)); //  (u,ci) -> (v,ci) へ　コスト 0
        nG[v2].push_back(edge(v2,v1,0));
    }
    
    // dijkstra
    vector<int> dist(idx,INF);
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    dist[0] = 0; pq.push(pii(0,0));
    while(pq.size()){
        pii p = pq.top(); pq.pop();
        int d,n; tie(d,n) = p;
        if(d > dist[n]) continue;
        for(edge& e:nG[n]){
            if(dist[e.v] > dist[e.u] + e.c){
                dist[e.v] = dist[e.u] + e.c;
                pq.push(pii(dist[e.v],e.v));
            }
        }
    }
    
    // answer
    return (dist[N-1] == INF ? -1 :dist[N-1]);
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    cout << solve() << endl;
	return 0;
}
