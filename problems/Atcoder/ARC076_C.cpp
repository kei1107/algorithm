#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://arc076.contest.atcoder.jp/tasks/arc076_a>
問題文============================================================
 すぬけ君は、犬を N 匹と猿を M 匹飼っています。すぬけ君は、この N+M 匹を一列に並べようと思っています。
 
 文字通り犬猿の仲の犬たちと猿たちを仲直りさせたいすぬけ君は、
 犬同士、または猿同士が隣り合うところができないように並べようと思っています。
 
 このような並べ方は何通りあるでしょうか。
 犬と猿は 10^9+7 以上の数を理解できないので、並べ方の個数を 10^9+7 で割ったあまりを求めてください。
 ただし、犬同士、また猿同士は互いに区別します。また、左右が反転しただけの列も異なる列とみなします。
=================================================================

解説=============================================================

 良くある組み合わせ問題
 
 NとMの差が２以上であれば、交互に配置することができないので 1
 差が1であれば、 N!*M!
 差が0であれば 2*N!*M!
================================================================
*/
const ll MOD = 1e9+7;
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N,M; cin >> N >> M;
    ll ans = 1;
    if(abs(N-M)>=2){
        ans = 0;
    }else if(abs(N-M)==1){
        if(M < N) swap(N,M);
        for(ll i = 1; i <= N; i++){
            (ans *= i)%=MOD;
        }
        ans = (ans * ((ans*M)%MOD))%MOD;
    }else{
        for(ll i = 1; i <= N; i++){
            (ans *= i)%=MOD;
        }
        ans = (((ans * ans)%MOD)*2)%MOD;
    }
    cout << ans << endl;
	return 0;
}
