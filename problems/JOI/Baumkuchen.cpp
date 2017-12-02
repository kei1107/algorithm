#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
 <url:https://joi2014ho.contest.atcoder.jp/img/other/joi2014ho/joi2014ho3.pdf>
 問題文============================================================
 円筒形のバームクーヘンを3 つのピースに切り分ける．
 
 バームクーヘンにはあらかじめ N 個の切れ込みが入っており，切れ込みのある位置でのみ切ることができる．
 切れ込みに1 から N まで時計回りに番号をふったとき，1≤i≤N−1 に対し，
 i 番目の切れ込みとi+1 番目の切れ込みの間の部分の大きさは Ai である．
 また N 番目の切れ込みと1 番目の切れ込みの間の部分の大きさは AN である．
 
 切れ込みの個数 N と，各部分の大きさを表す整数 A1,...,AN が与えられる．
 バームクーヘンを3 つに切り分けたときの，最も小さいピースの大きさの最大値を出力するプログラムを作成せよ．
 
 3≤N≤10^5
 1≤Ai≤10^9(1≤i≤N)
 
 =================================================================
 解説=============================================================
 
 円筒形の３カ所を切った時の各ピースの長さを見ればいいので、単純に考えれば、

 ３ヶ所の決め方でO(N^3)  間に合わない
 
 円筒で一周の長さが一定であることを考慮すれば、各ピースの大きさA1,A2,A3、全体の大きさSとした時、
 A3 = S - A1 - A2 となるので、これを用いれば
 二ヶ所の決め方でO(N^2) 間に合わない
 
 ここで別のアプローチ
 切れ込みを一ヶ所決め打ちした時、他の二ヶ所の場所が分からないか？
 問題文より「バームクーヘンを3 つに切り分けたときの，最も小さいピースの大きさの最大値」
 切り口関係なく、切り分けれる時、この最適な切り方は各ピースの大きさが S/3 となれば良い。
 つまり、切り口を一つ決めた時、その切り口から時計回りにS/3離れた位置の周辺が最適な切り口2になる可能性があり、
 S * 2/ 3 離れた位置州へbんが最適な切り口3になる可能性がある。これは、累積和などで、距離を保存しておけば、
 にぶたんO(logN)で求まる
 
 よって、切り口の決め打ちと探索でO(N logN) となり間に合う
 
 ================================================================
 */
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll N; cin >> N;
    vector<ll> A(N);
    vector<ll> cusum; cusum.push_back(0);
    ll sum = 0;
    for(auto& in:A){
        cin >> in;
        sum += in;
        cusum.push_back(cusum[cusum.size()-1] + in);
    }
    for(int i = 0; i < 2*N;i++){
        cusum.push_back(cusum[cusum.size()-1] + A[i%N]);
    }
    ll res = 0;
    ll b1 = sum/3, b2 = sum * 2/3;
    for(int i = 0; i < N;i++){
        int it1 = (int)(lower_bound(cusum.begin(), cusum.end(), cusum[i] + b1) - cusum.begin());
        int it2 = (int)(lower_bound(cusum.begin(), cusum.end(), cusum[i] + b2) - cusum.begin());
        for(int j = -1; j <= 1; j++){
            for(int k = -1; k <= 1;k++){
                if(it1 + j >= it2 + k)continue;
                int i2 = it1+j,i3 = it2 + k;
                if(cusum[i3] - cusum[i] >= sum)continue;
                res = max(res,min({cusum[i] - cusum[i3]%sum,cusum[i2]-cusum[i],cusum[i3]-cusum[i2]}));
            }
        }
    }
    cout << res << endl;
    return 0;
}
