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
<url:https://agc001.contest.atcoder.jp/tasks/agc001_c>
問題文============================================================
 N 頂点の木があり、頂点には 1~N の番号がついています。
 N−1 本の辺について、i(1≦i≦N−1) 本目の辺は頂点 Ai と頂点 Bi を繋いでいます。
 
 この木の直径を K 以下にするために削除する必要のある頂点数の最小値を求めてください。
 ただし、頂点を削除した後のグラフは連結になっていなければなりません。
 
 木の直径とは、2 つの頂点間の距離の最大値のことを指します。
 2 つの頂点間の距離とは、2 つの頂点を結ぶパスに含まれる辺の本数を指します。
 
 制約
 2≦N≦2000
 1≦K≦N−1
 1≦Ai≦N,1≦Bi≦N
 与えられるグラフは木である。

=================================================================

解説=============================================================

 直径がKとなる木の中心について考える
 Kが偶数ならば 中心は ある頂点となり、
 Kが奇数ならば 中心は ある辺となる、
 
 よって、全ての頂点あるいは辺に対して K/2 or (K-2)/2 以内にある頂点が、
 直径Kとなる木を作るのに最大な頂点数となる。
 
 よって、各頂点（辺）(O(N))に対して、探索(O(N))すると
 O(N^2)で解ける
 
================================================================
*/
ll solve(){
    ll res = INF;
    ll N,K; cin >> N >> K;
    vector<vector<ll>> G(N);
    vector<pll> edge(N);
    for(int i = 0; i < N-1;i++){
        ll A,B; cin >> A >> B; A--; B--;
        G[A].push_back(B); G[B].push_back(A);
        edge[i] = {A,B};
    }
    queue<ll> q;
    vector<ll> dist(N,INF);
    dist[0] = 0; q.push(0);
    while(q.size()){
        ll n = q.front(); q.pop();
        for(ll next : G[n]){
            if(dist[next] > dist[n] + 1){
                dist[next] = dist[n] + 1;
                q.push(next);
            }
        }
    }
    ll _n = max_element(dist.begin(), dist.end()) - dist.begin();
    fill(dist.begin(),dist.end(),INF);
    dist[_n] = 0; q.push(_n);
    while(q.size()){
        ll n = q.front(); q.pop();
        for(ll next : G[n]){
            if(dist[next] > dist[n] + 1){
                dist[next] = dist[n] + 1;
                q.push(next);
            }
        }
    }
    
    queue<pll> q2;
    if(K&1){
        ll D = (K-1)/2;
        for(auto& e:edge){
            vector<int> f(N,false);
            ll l = e.first,r = e.second;
            q2.push({l,0}); q2.push({r,0});
            while(q2.size()){
                auto p = q2.front(); q2.pop();
                ll n,d; tie(n,d) = p;
                f[n] = true;
                if(d == D) continue;
                for(auto next:G[n]){
                    if(f[next])continue;
                    q2.push({next,d+1});
                }
            }
            res = min(res,N - accumulate(f.begin(), f.end(), 0));
        }
    }else{
        ll D = K/2;
        for(int i = 0; i < N;i++){
            vector<int> f(N,false);
            q2.push({i,0});
            while(q2.size()){
                auto p = q2.front(); q2.pop();
                ll n,d; tie(n,d) = p;
                f[n] = true;
                if(d == D) continue;
                for(auto next:G[n]){
                    if(f[next])continue;
                    q2.push({next,d+1});
                }
            }
            res = min(res,N - accumulate(f.begin(), f.end(), 0));
        }
    }
    return res;
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    cout << solve() << endl;
	return 0;
}
