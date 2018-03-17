#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://ddcc2017-final.contest.atcoder.jp/tasks/ddcc2017_final_a>
問題文============================================================
 直径 200 mmのウェーハ（円盤状の金属の薄い板）と、直径 300 mmのウェーハがあります。
 この 2 つのウェーハから、縦横の長さが K mmの正方形のチップを作成しようとしています。
 
 垂直方向・水平方向の 2 方向に、 円の端から K mmずつ等間隔にウェーハを切断していくことで、
 正方形のチップを作成していきます。
 
 この時、直径 200 mmのウェーハで取れるチップの数と、直径 300 mmのウェーハから取れるチップの数を求めてください。
 
 例えば、 K=20 の時、以下のようにチップを作成することができます。
 直径 200 mmのウェーハからは 60 個、直径 300 mmのウェーハからは 145 個のチップを取ることができます。
=================================================================

解説=============================================================

 K/直径　が偶数の時、
 第一象限に関して、あるマスが円内部に含まれるかどうかを確認して行き、後で4倍すれば良い
         奇数の時、
 同様に第一象限に関して求めるが、中央の十字部分が重複するため、その部分の処理を別途行う
 
================================================================
*/

ll calc(ll K,ll d){
    ll ret = 0;
    ll T = d/K;
    ll r = d/2;
    if(T%2 == 0){
        T/=2;
        for(int i = 1; i <= T;i++){
            for(int j = 1; j <= T;j++){
                if(K*K*(i*i+j*j) <= r*r) ret++;
            }
        }
        ret*=4;
    }else{
        T/=2;
        for(int i = 1; i <= T;i++){
            for(int j = 1; j <= T;j++){
                if((K*i+K/2)*(K*i+K/2)+(K*j+K/2)*(K*j+K/2) <= r*r) ret++;
            }
        }
        ret*=4;
        ret += 4*(T-1)+1;
    }
    return ret;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll K; cin >> K;
    ll ans1 = calc(K,200),ans2 = calc(K,300);
    cout << ans1 << " " << ans2 << endl;
    return 0;
}
