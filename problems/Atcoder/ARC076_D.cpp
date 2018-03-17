#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://arc076.contest.atcoder.jp/tasks/arc076_b>
問題文============================================================
 平面上に、N 個の街があります。i 個目の街は、座標 (xi,yi) にあります。
 同じ座標に、複数の街があるかもしれません。
 
 座標 (a,b) にある街と座標 (c,d) にある街の間に道を造るのには、min(|a−c|,|b−d|) 円かかります。
 街と街の間以外に、道を造ることはできません。
 
 任意の 2 つの街の間を、道を何本か通って行き来できるようにするためは、最低で何円必要でしょうか。

=================================================================

解説=============================================================
要するにコストの定義が特殊な最小全域木
 
 全ての街との間に辺を張るとTLEするので、辺の張り方を工夫する
 これは、コストの条件より、 x座標と y座標を独立に考えることができ、
 sort済みの x座標と y座標に関して
 あるindex i を見たとき
     (xi-1,xi) , (xi, xi+1)
     (yi-1,yi) , (yi, yi+1)
 に辺を貼ればいいことがわかる
 
 よって、辺の数が大幅に削減できるので通常の最小全域木を作る要領で間に合う
================================================================
*/
struct UnionFind {
    vector<int> data;
    UnionFind(int size) : data(size, -1) { }
    bool unionSet(int x, int y) {
        x = root(x); y = root(y);
        if (x != y) {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y]; data[y] = x;
        }
        return x != y;
    }
    bool findSet(int x, int y) {
        return root(x) == root(y);
    }
    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    int size(int x) {
        return -data[root(x)];
    }
};

struct edge{
    ll u,v,cost;
    edge(){}
    edge(ll u,ll v,ll cost):u(u),v(v),cost(cost){}
    bool operator < (const edge& o) const{
        return cost < o.cost;
    }
    bool operator > (const edge& o) const{
        return cost > o.cost;
    }
};

ll solve(){
    ll N; cin >> N;
    vector<pll> p(N);
    for(int i = 0; i < N;i++) cin >> p[i].first >> p[i].second;
    vector<pll> xs(N),ys(N);
    for(int i = 0; i < N;i++){
        xs[i] = {p[i].first,i};
        ys[i] = {p[i].second,i};
    }
    
    sort(xs.begin(),xs.end()); sort(ys.begin(),ys.end());
    UnionFind uf(N);
    ll ret = 0;
    
    priority_queue<edge,vector<edge>,greater<edge>> pq;
    for(int i = 0; i < N-1;i++){
        pq.push(edge(xs[i].second,xs[i+1].second,xs[i+1].first-xs[i].first));
        pq.push(edge(ys[i].second,ys[i+1].second,ys[i+1].first-ys[i].first));
    }
    
    while(!pq.empty()){
        auto e = pq.top(); pq.pop();
        if(uf.findSet(e.u, e.v)) continue;
        
        ret += e.cost;
        uf.unionSet(e.u, e.v);
    }
    
    return ret;
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    cout << solve() << endl;
	return 0;
}
