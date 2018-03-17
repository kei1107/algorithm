#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://code-festival-2017-qualb.contest.atcoder.jp/tasks/code_festival_2017_qualb_c>
問題文============================================================
 りんごさんは N 頂点 の連結な無向グラフを持っています。
 このグラフにはすでに M 本の辺があり、i 本目の辺は頂点 Ai と頂点 Bi を繋いでいます。
 
 りんごさんは以下の操作を行うことで、辺を追加しようと思っています。
 
 操作：頂点 u から辺をちょうど 3 本辿ることによって頂点 v に辿り着けるような u,v(u≠v) をとり、
 頂点 u と頂点 v の間に辺を追加する。
 ただし、すでに頂点 u と頂点 v の間に辺が存在する場合は辺を追加することはできない。
 りんごさんが追加できる辺の本数の最大値を求めて下さい。

=================================================================

解説=============================================================

 与えられたグラフで二部グラフを作ることができれば
     完全二部グラフになる
 作ることができなければ
     完全グラフになる
================================================================
*/
ll N,M;
vector<vector<ll>> G;
vector<int> checked; // 1 : l / 2 : r
set<ll> l,r;

bool check(ll n,bool f){
    if(f){
        if(checked[n] == 1) return false;
        if(checked[n] == 2) return true;
        checked[n] = 1;
        for(auto &v:G[n]){
            if(check(v,false)) return true;
            l.insert(v);
        }
    }else{
        if(checked[n] == 2) return false;
        if(checked[n] == 1) return true;
        checked[n] = 2;
        for(auto &v:G[n]){
            if(check(v,true)) return true;
            r.insert(v);
        }
    }
    return false;
}

ll solve(){
    ll ret = 0;
    cin >> N >> M;
    G.resize(N); checked.resize(N);
    for(int i = 0; i < M;i++){
        ll A,B; cin >> A >> B; A--; B--;
        G[A].push_back(B);
        G[B].push_back(A);
    }
    bool f = check(0,true);
    if(f) ret =  (N*(N-1)/2) - M;
    else ret = l.size()*r.size() - M;
    return ret;
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    cout << solve() << endl;
	return 0;
}
