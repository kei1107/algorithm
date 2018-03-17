#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://dwacon2018-final-open.contest.atcoder.jp/tasks/dwacon2018_final_a>
問題文============================================================
 太郎君と次郎君はアナログ時計が好きです。
 太郎君と次郎君が持っているアナログ時計は普通のアナログ時計と同じように
 秒針が1分で1周し、分針が1時間で1周し、時針が12時間で1周します。
 また、秒針、分針、時針はなめらかに一定の角速度で動き、12時0分0秒ちょうどに全ての針が重なります。
 
 太郎君は突然眠くなり、ちょうど H:M:S (H 時 M 分 S 秒) に眠りについてしまいました。
 その後、目が覚めたとき、次郎君から以下の情報を聞きました。
 
 眠っている間にアナログ時計の分針と秒針が重なった回数が C1 回だった
 眠っている間にアナログ時計の時針と分針が重なった回数が C2 回だった
 太郎君が眠っていた時間はちょうど整数秒間だった
 太郎君が眠りについた時刻・目が覚めた時刻に、アナログ時計の分針と秒針は重なっていない
 太郎君が眠りについた時刻・目が覚めた時刻に、アナログ時計の時針と分針は重なっていない
 
 これらの情報から、太郎君が眠っていた時間の最小秒数 t1 と最大秒数 t2 を出力してください。
 そのような範囲が存在しない場合は −1 を出力してください。
 

 入力は全て整数
 1≤H≤12
 0≤M,S≤59
 1≤C1≤10,000
 0≤C2≤10,000
=================================================================

解説=============================================================

 時針と分針、分針と秒針が重なる回数は 12時間(=43200s)で固定であり,それぞれ 11回と708回である
 
 また、C1とC2の回数から 1sづつインクリメントしていき、各秒数に関して探索しても問題がない
 
 よって、まず、初期時間において 00h:00m:00s から何回針が重なったかについては十二時間のうちに重なる
 回数から計算することができ、1sづつ回数を繰り上げて行った時に条件を満たすかどうか見て行けば良い
 
 条件式
     C1 == (T*708)/43200 && C2 == (T*11)/43200 && (T*408)%43200 > 0

 で条件を満たす時間帯が存在することを示す(T*408)%43200>0 に関しては 12時ちょうどの秒針が全て重なっている
 時間を除くため
 
================================================================
*/

void solve(){
    ll H,M,S; cin >> H >> M >> S;
    ll C1,C2; cin >> C1 >> C2;
    ll m1 = INF,m2 = -INF;
    ll T = 3600*H + 60*M + S,TT = T;
    C1 += (T*708)/43200; C2 += (T*11)/43200;
    while(true){
        if(C1 == (T*708)/43200 && C2 == (T*11)/43200 && (T*408)%43200 > 0){
            m1 = min(m1,T); m2 = max(m2,T);
        }
        if(C1 < (T*708)/43200 || C2 < (T*11)/43200) break;
        T++;
    }
    if(m1 == INF){
        cout << -1 << endl; return;
    }else{
        cout << m1 - TT << " " << m2 - TT << endl; return;
    }
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    solve();
	return 0;
}
