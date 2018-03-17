#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://abc085.contest.atcoder.jp/tasks/abc085_d>
問題文============================================================
 あなたが散歩していると、突然一体の魔物が出現しました。
 幸い、あなたは N 本の刀、刀 1、刀 2、…、刀 N を持っていて、次の二種類の攻撃を自由な順番で行うことができます。
 
 持っている刀のうち一本を振る。
     刀 i (1≤i≤N) を振ると、魔物は ai ポイントのダメージを受ける。同じ刀を何度振ることもできる。
 持っている刀のうち一本を投げつける。
     刀 i (1≤i≤N) を投げつけると、魔物は bi ポイントのダメージを受け、あなたはその刀を失う。
     すなわち、あなたは以後その刀を振ることも投げつけることもできなくなる。
 
 魔物は、受けたダメージの合計が H ポイント以上になると消滅します。
 魔物を消滅させるには、最小で合計何回の攻撃が必要でしょうか。
=================================================================

解説=============================================================

 刀を振る時、一番大きいダメージのある刀だけを振ることを考えれば最適
 
 また、投げる時は、振るダメージの大きいもの以上の刀を投げつければいい。
 よって、先に投げつけるものだけ投げておいて、後から一番大きいダメージの刀のみでダメージを与えれば良い
 
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N,H; cin >> N >> H;
    vector<ll> a(N),b(N);
    for(int i = 0; i < N;i++) cin >> a[i] >> b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end()); reverse(b.begin(),b.end());
    ll Maxa = *max_element(a.begin(), a.end()) , cnt = 0;
    for(int i = 0; i < N;i++){
        if(H <= 0) break; if(Maxa > b[i]) break;
        cnt++; H -= b[i];
    }
    if(H <= 0){
        cout << cnt << endl; return 0;
    }
    cout << cnt + (H + Maxa-1)/Maxa << endl;
	return 0;
}
