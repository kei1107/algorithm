#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://arc058.contest.atcoder.jp/tasks/arc058_b>
問題文============================================================
 縦 H マス、横 W マスのマス目があります。
 いろはちゃんは、今一番左上のマス目にいます。
 そして、右か下に1マス移動することを繰り返し、一番右下のマス目へと移動します。
 ただし、下から A 個以内、かつ左から B 個以内のマス目へは移動することは出来ません。
 
 移動する方法は何通りあるか求めてください。
 なお、答えは非常に大きくなることがあるので、答えは 10^9+7 で割ったあまりを出力してください。
=================================================================

解説=============================================================
移動経路の組み合わせ問題。
 
 先に通過しなければならない部分は絞られるので、
 通過しなければならないあるマスに関して
 
 始点からそのマスへの移動経路　＊　そのマスから終点までの移動経路
 を加算していけば良い
================================================================
*/

const ll MAX_N = 2e5 + 10;
const ll MOD = 1e9+7;
ll Inv[MAX_N];
ll fact[MAX_N];
ll factInv[MAX_N];
void Inv_init(){
    Inv[1] = 1;
    for(int i = 2; i < MAX_N; i++) {
        Inv[i] = Inv[MOD%i] * (MOD - MOD/i) % MOD;
    }
}
void fact_init(){
    fact[0] = fact[1] = factInv[0] = factInv[1] = 1;
    for(int i = 2; i < MAX_N; i++){
        fact[i] = (fact[i-1] * i) % MOD;
        factInv[i] = (factInv[i-1] * Inv[i])%MOD;
    }
}

// a^b % MOD;
ll powmod(ll a,ll b) {ll res=1;a%=MOD; for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
// 逆元 1/a % MOD
ll inversemod(ll a) { return powmod(a,MOD - 2);}
ll nCr(int n,int r) {
    if(n < r) return 0;
    return (fact[n] * (factInv[r] * factInv[n-r] % MOD)) % MOD;
}

void init(){
    Inv_init();
    fact_init();
}

ll calc(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1, dy = y2 - y1;
    return nCr(dx + dy, dx);
}

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    init();
    int H,W,A,B; cin >> H >> W >> A >> B;
    ll ans = 0;
    for(int i = 1; i <= H - A;i++){
        ans += (calc(1,1,i,B)*calc(i,B+1,H,W))%MOD; ans%=MOD;
    }
    cout << ans << endl;
	return 0;
}
