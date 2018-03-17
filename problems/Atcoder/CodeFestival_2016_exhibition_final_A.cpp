#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://cf16-exhibition-final-open.contest.atcoder.jp/tasks/cf16_exhibition_final_a>
問題文============================================================
 一次元の世界に N 個のパソコンと N 個の電源があります。
 i 番目のパソコンの座標は ai であり、 i 番目の電源の座標は bi です。
 これらの 2N 個の座標は相異なることが保証されています。
 
 すぬけ君は、それぞれのパソコンをケーブルで電源につなぎたいです。
 それぞれの電源は一つのパソコンにのみつなぐことができます。
 
 何通りの方法で、ケーブルの長さの合計を最小化できるでしょうか？ 答えを modulo 10^9+7 で求めてください。
=================================================================

解説=============================================================
PC の座標を oo_a , 電源の座標を oo_b とする
 
 0_a 10_a 15_a 20_b 25_b 30_b
 
 と並んでいたとすると、 最初の3つのPC座標 0 , 10 ,15 は後半の電源のどの座標を選んでも
 全体の長さは変わらない (一つのPCが一つの電源を選択することによって変化する増(減)分は他方で回収されるから）
 
 よって、 20_b は 0 10 15 の中から自由に選ぶことができ
        25_b は 20_bが使用していない二つから
        30_b は 20_b 25_bが使用していない一つ
 を選ぶことができる
 これは PC を 電源の座標が入れ替わっても同様の考えができる
 
 ex.
 0_b 10_b 15_b 20_a 25_a 30_a
 
 よって、座標を左から順番に見ていって、それぞれ PC と　電源がいくつ選択巣rことができるのかを
 シミュレーションしていけば良い
 
================================================================
*/
const ll MOD = 1e9+7;
ll solve(){
    ll N; cin >> N;
    vector<ll> a(N),b(N);
    for(auto &in:a) cin >> in;
    for(auto &in:b) cin >> in;
    sort(a.begin(),a.end()); sort(b.begin(),b.end());
    
    vector<pll> event(2*N);
    for(int i = 0; i < N;i++){ event[i] = {a[i],0}; }
    for(int i = 0; i < N;i++){ event[i+N] = {b[i],1}; }
    
    sort(event.begin(),event.end());

    ll ret = 1;
    
    ll cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < 2*N;i++){
        if(event[i].second == 0){
            if(cnt2 != 0){
                (ret *= cnt2)%=MOD;
                cnt2--;
            }else{ cnt1++; }
        }else{
            if(cnt1 != 0){
                (ret *= cnt1)%=MOD;
                cnt1--;
            }else{ cnt2++; }
        }
    }
    return ret;
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    cout << solve() << endl;
	return 0;
}
