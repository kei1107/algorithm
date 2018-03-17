#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://tenka1-2016-quala.contest.atcoder.jp/tasks/tenka1_2016_qualA_b>
問題文============================================================
 ヤマモトくんは、通信環境の悪いネットワークでのアプリケーションの動作検証のために、
 PackDrop という、0.01 の確率でパケットを破棄する装置を発明しました。
 
 ヤマモトくんは N 台の機器からなるネットワークに、いくつかのPackDropを取り付けて、
 以下の条件を満たす必要があります。ただし、使用する PackDrop の個数は最少にしたいです。
 
 このネットワークの各機器には 0 から N−1 の番号がふられています。
 
 機器 0 以外の各機器には 1 台の親機器があり、機器 i の親機器は機器 Pi です。
 機器 Pi から見た機器 i を子機器といいます。
 
 直接親子関係のある機器は直接つなぐか、PackDrop をいくつか直列にはさんでつなぐことができます。
 
 親機器と子機器が n 個の PackDrop をはさんでつながっているとき、
 親機器から子機器へのパケットの到達率は 0.99n となります。
 すなわち、直接つないだとき、パケットの到達率は 1 となります。
 
 機器 x から 機器 y へのパケットの到達率を p、機器 y から 機器 z へのパケットの到達率を q としたとき
 、機器 x から 機器 z へのパケットの到達率は p×q となります。
 
 PackDrop がパケットを破棄する以外の要因によりパケットの到達率が変化することはないものとします。
 
 子機器を持たない機器は M 台あり、その番号は B0,B1,…,BM−1 です。
 各 i ( 0≤i≤N−1 ) に対して、機器 0 から機器 Bi への到達率を 0.99Ci にしたいとき、
 最少の PackDrop の個数を求めてください。
=================================================================

解説=============================================================

 現在の機器から次の機器群を見る時、
 現在の機器には、min(Ci) (i : 次の機器の番号)
 分だけすでにPackDropが繋がっていると最適になり、
 現在の機器から次の機器の間に繋げなければいけないPackDropは Cj - min(Ci) となる
 
 よってdfsを用いて、根から順に繋げなければならない個数を決定していく
================================================================
*/
ll N,M;
vector<vector<int>> G;
vector<ll> S;
ll ans;
ll dfs(ll n){
    if(n == 0){
        for(auto v:G[n]){
            ll tmp = dfs(v);
           if(tmp != INF) ans += tmp;
        }
        return ans;
    }else{
        ll minV = S[n]==-1?INF:S[n];
        vector<ll> C;
        for(auto v:G[n]){
            ll tmp = dfs(v);
            C.push_back(tmp);
            minV = min(minV,tmp);
        }
        if(minV == INF) return INF;
        for(auto c:C){
            ans += c - minV;
        }
        return minV;
    }
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    cin >> N >> M;
    G.resize(N);
    S.assign(N,-1);
    for(int i = 1; i < N;i++){
        ll P; cin >> P;
        G[P].push_back(i);
    }
    for(int i = 0; i < M;i++){
        ll B,C;cin >> B >> C;
        S[B] = C;
    }
    cout << dfs(0) << endl;
	return 0;
}
