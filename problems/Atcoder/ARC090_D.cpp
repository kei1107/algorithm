#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://beta.atcoder.jp/contests/arc090/tasks/arc090_b>
問題文============================================================
 x  軸上に N 人の人が立っています。 人 iの位置を xi とします。
 任意のi に対して、 xi は0 以上10^9 以下の整数です。同じ位置に複数の人が立っていることもありえます。
 
 これらの人の位置に関する情報が M 個与えられます。 このうち i 個めの情報は (Li,Ri,Di) という形をしています。
 この情報は、人 Ri は人 Li よりも距離 Di だけ右にいること、 すなわち、
 xRi−xLi=Di が成り立つことを表します。
 
 これら M 個の情報のうちのいくつかに誤りがある可能性があることがわかりました。
 与えられる M 個すべての情報と矛盾しないような値の組 (x1,x2,...,xN) が存在するかどうか判定してください。
 
 制約
 1≤N≤100,000
 0≤M≤200,000

 1≤Li,Ri≤N ( 1≤i≤M)
 0≤Di≤10,000 ( 1≤i≤M)
 Li≠Ri ( 1≤i≤M)
 i≠j のとき、 (Li,Ri)≠(Lj,Rj) かつ (Li,Ri)≠(Rj,Lj) Di は整数である
=================================================================

解説=============================================================

 ある頂点uから頂点vに互いに到達可能なグループに分ける。
 各グループの基準位置(適当なグループ内の任意の頂点の位置)は独立して考えることができるので
 各グループごとに最初の基準位置を決めうちして、dfsで頂点間を辿っていき、矛盾がないか見ていけば良い。
 各頂点での操作は高々１回の行われるだけなので間に合う
 
================================================================
*/

struct edge{
    ll u;
    ll v;
    ll cost;
    
    ll l;
    ll r;
    edge(){}
    edge(ll u,ll v,ll cost,ll l,ll r):u(u),v(v),cost(cost),l(l),r(r){}
};

ll N,M;
vector<ll> L,R,D;
vector<vector<edge>> G;
vector<ll> loc;
vector<ll> check;

bool dfs(ll n,bool from){
    if(check[n] == 1) return true;
    check[n] = 1;
    if(from){
        loc[n] = 0;
    }
    for(auto e:G[n]){
       if(loc[e.l] == INF){
            loc[e.l] = loc[e.r] - e.cost;
            if(!dfs(e.l,false)) return false;
            
            continue;
        }
        
        if(loc[e.r] == INF){
            loc[e.r] = loc[e.l] + e.cost;
            if(!dfs(e.r,false)) return false;
            
            continue;
        }
        
        if(loc[e.r] - loc[e.l] != e.cost) return false;
    }
    return true;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> N >> M;
    L.resize(M);R.resize(M);D.resize(M);
    loc.resize(N,INF); check.resize(N);
    for(int i = 0; i < M;i++){
        cin >> L[i] >> R[i] >> D[i];
        L[i]--; R[i]--;
    }
    
    G.resize(N);
    for(int i = 0; i < M;i++){
        G[L[i]].push_back(edge(L[i],R[i],D[i],L[i],R[i]));
        G[R[i]].push_back(edge(R[i],L[i],D[i],L[i],R[i]));
    }
    
    for(int i = 0; i < N;i++){
        if(!dfs(i,true)){
            cout << "No" << endl;
            return 0;
        }
    }
    
 //   cout << loc[6] << " " << loc[7] << " " << loc[8] << endl;
    cout << "Yes" << endl;
    return 0;
}

