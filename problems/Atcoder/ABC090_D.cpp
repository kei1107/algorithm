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
<url:https://beta.atcoder.jp/contests/abc090/tasks/arc091_b>
問題文============================================================
 高橋君は、 N 以下の正の整数の 2 つ組 ( a , b ) を持っていましたが、忘れてしまいました。
 高橋君は、 a を b で割ったあまりが K 以上であったことを覚えています。
 高橋君が持っていた組としてあるうるものの個数を求めてください。
=================================================================

解説=============================================================

 b(>= K + 1)を固定する
 
 この時, a の候補となるのは
 b * i + K <= min(bの倍数,N)    // i は0以上の整数であり、 a*i+KがNを超えないような範囲
 となるような値であり
 
 ここで
 b * i + K <= bの倍数 <= N であれば
 個数は b - K 個
 
 b * i + K <= N < bの倍数 であれば
 個数は B - (b*i+K)+1 個となる
 
 条件分岐をしっかりすればO(1)でbを決めうちした時の個数出せるので O(N-K)となるが

 Nの範囲が小さいので
 ソースコードのように順番にbの倍数を繰り上げて行く方法でも十分高速で間に合う
================================================================
*/
ll solve(){
    ll res = 0;
    ll N,K; cin >> N >> K;
    if(K == 0) return res = N*N;
    for(ll b = K+1; b <= N; b++){
        ll x = K;
        ll T = b;
        for(int i = 0; b*i+K <= N; i++){
            if(T <= N){
                res += (b-K);
            }else{
                res += (N - (b*i+K) + 1);
            }
            T += b;
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}

