#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream &operator << (ostream& out,const pair<S,T>& o){
    out << "(" << o.first << "," << o.second << ")"; return out;
}

/*
<url:https://arc067.contest.atcoder.jp/tasks/arc067_c>
問題文============================================================
 1 から N までの番号のついた N 人の人がいます。
 以下の二つの条件を満たすように、彼らをいくつかのグループに分けたいです。
 
 どのグループも、そのグループに含まれる人数が A 人以上 B 人以下である。
 
 ちょうど i 人の人が含まれるようなグループの数を Fi で表したとき、
 すべての i について、Fi=0 または C≦Fi≦D が成り立っている。
 
 このようなグループ分けが何通りあり得るか求めてください。
 ただし、ある二つのグループ分けが異なるとは、二人の人の組であって、
 片方のグループ分けでは同じグループに含まれ、
 他方では同じグループに含まれないようなものが存在することを意味します。
 なお、答えは非常に大きくなることがあるので、109+7 で割った余りを出力してください。

 1≦N≦10^3
 1≦A≦B≦N
 1≦C≦D≦N
=================================================================

解説=============================================================
　memo[n][a] := 残り人数が n で 指定人数が a 以上の時の総数
 
 としてmemo化再帰
 
 逆元のテーブルを作っておくと楽
================================================================
*/
#define MAX_N 1005
const ll MOD = 1e9+7;
ll Inv[MAX_N];
ll fact[MAX_N];
ll factInv[MAX_N];
void Inv_init(){
    Inv[1] = 1;
    for(int i = 2; i < MAX_N; i++) Inv[i] = Inv[MOD%i] * (MOD - MOD/i) % MOD;
}
void fact_init(){
    fact[0] = fact[1] = factInv[0] = factInv[1] = 1;
    for(int i = 2; i < MAX_N; i++){
        fact[i] = (fact[i-1] * i) % MOD; factInv[i] = (factInv[i-1] * Inv[i])%MOD;
    }
}

// a^b % MOD;
ll powmod(ll a,ll b) {ll res=1;a%=MOD; for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
// 逆元 1/a % MOD
ll inversemod(ll a) { return powmod(a,MOD - 2);}
ll nCr(ll n,ll r) {
    if(n < r) return 0;
    return (fact[n] * (factInv[r] * factInv[n-r] % MOD)) % MOD;
}

void init(){
    Inv_init();
    fact_init();
}

ll N,A,B,C,D;
ll memo[MAX_N][MAX_N]; // memo[n][a] := 残り人数が n で 指定人数が a 以上の時の総数
void init2(){ // memo init
    for(int i = 0; i < MAX_N;i++)for(int j = 0; j < MAX_N;j++) memo[i][j] = -1;
}

ll dfs(ll n,ll a){
    ll &res = memo[n][a];
    if(res != -1) return res;
    if(n == 0) return res = 1;
    if(n < a || a > B) return res = 0;
    
    res = 0;
    (res += dfs(n,a+1))%=MOD;
    ll F = 1;
    for(ll x = 1; x <= D; x++){ // F = x*nCa/x!
        if(a > n) break;
        (F *= nCr(n,a))%=MOD; // F*nCa
        (F *= Inv[x])%=MOD; // F/x
        n-=a;
        if(x >= C){ (res += F*dfs(n,a+1))%=MOD; }
    }
    return res;
}
ll solve(){
    ll res = 0;
    cin >> N >> A >> B >> C >> D;
    res = dfs(N,A);
    return res;
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    init();
    init2();
    cout << solve() << endl;
	return 0;
}
