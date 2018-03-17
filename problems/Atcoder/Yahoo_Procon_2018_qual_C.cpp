#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://yahoo-procon2018-qual.contest.atcoder.jp/tasks/yahoo_procon2018_qual_c>
問題文============================================================
 高橋君と青木君が取引をします。 はじめ、高橋君の所持金は 0 円です。
 
 高橋君は 1 から N の番号がついた N 個の財宝を持っています。
 高橋君は青木君に財宝 i を売却すると xi 円得ることができます。
 
 青木君は 1 から N の番号がついた N 個の商品を販売しています。
 商品 i は価値 vi を持ち、価格 ci 円で販売されています。
 
 取引は以下の手順で行われます。
 
 高橋君は財宝を売却するか、商品を購入するかを決める。前者ならば手順 2. へ、後者ならば手順 3. へ進む。
 高橋君は持っている財宝のうち、最も番号が小さいものを青木君に売却しお金を得る。
 その後、青木君は商品を 1 つ選び販売を停止する。手順 1. へ戻る。
 高橋君は販売中の 0 個以上の商品を購入し、取引を終了する。
 このとき、高橋君は所持金が 0 円未満になるように購入することはできない。
 高橋君が購入した商品の価値の総和を得点とします。
 
 高橋君は得点を最大化するように、青木君は得点を最小化するように行動するとき、得点はいくつになりますか?

=================================================================

解説=============================================================
解説をみた。　これは難しい。
================================================================
*/
ll N;
vector<ll> x,c,v;
ll dp[20][1<<20]; // dp1[i][j][k] := k(0/taka 1/aoki)のターンの時、i番目までの財宝を売却し、 現状の購入状態が j の時
ll cusum_x[20];
ll cusum_c[1<<20],cusum_v[1<<20];
void init(){
    for(int i = 0; i < 20;i++) for(int j = 0; j < (1<<20); j++) dp[i][j] = -1;
    cin >> N; x.resize(N); c.resize(N); v.resize(N);
    for(auto &in:x) cin >> in;
    for(auto &in:c) cin >> in;
    for(auto &in:v) cin >> in;
    for(int i = 0; i < N;i++){ cusum_x[i+1] = cusum_x[i] + x[i]; }
    for(int i = 0; i < (1<<N);i++){
        cusum_c[i] = cusum_v[i] = 0;
        for(int j = 0; j < N;j++){
            if((i>>j)&1){ cusum_c[i] += c[j]; cusum_v[i] += v[j]; }
        }
    }
}

ll rec(ll n,ll S){
    ll& res = dp[n][S];
    if(res != -1) return res;
    res = 0;
    for(ll s = S; s > 0; s = (s-1)&S){
        if(cusum_x[n] >= cusum_c[s]) res = max(res,cusum_v[s]);
    }
    if(n < N){
        ll T = LINF;
        for(int i = 0; i < N;i++){
            if((S>>i)&1){
                T = min(T,rec(n+1,S - (1<<i)));
            }
        }
        res = max(res,T);
    }
    return res;
}

ll solve(){
    ll res = rec(0,(1<<N)-1);
    return res;
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    init();
    cout << solve() << endl;
	return 0;
}
