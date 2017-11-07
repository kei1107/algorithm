#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
 <url:https://github.com/kei1107/algorithm/blob/master/template/template_for_problems.cpp>
 問題文============================================================
 n個の整数a1, a2, …, anとn個の整数p1, p2, …, pn、整数mが与えられる。
 k番目の整数akをpk[%]の確率で選ぶ、という操作を各k(1 ≤ k ≤ n)について行い、
 0個以上n個以下の整数を選び出す。1以上m以下の整数の中で、
 選ばれた整数の少なくとも1つで割り切れるものの個数の期待値を求めよ。
 =================================================================
 解説=============================================================
 包除定理( := 高速メビウス変換)
 ================================================================
 
 
 <reference:http://d.hatena.ne.jp/simezi_tan/20130522/1369203086>
 
 高速メビウス変換：∩→∪ < rep(j, 0, n) if(j & (1 << i)) f[j] -= f[j ^ (1 << i)]; >
 高速ゼータ変換：∪→∩ <rep(j, 0, n) if(j & (1 << i)) f[j] += f[j ^ (1 << i)];>
 */

inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n;
    long double m;
    cin >> n >> m;
    vector<ll> a(n);
    vector<long double> p(n);
    for(auto &x:a) cin >> x;
    for(auto &x:p) {
        cin >> x;
        x/=100;
    }
    
    // Preprocessing
    // probability
    // 答えを求める時に同時に行っても良さそう
    vector<long double> dp1((1<<n),1.0);
    for(int i = 0; i < n;i ++){
        for(int j = 0; j < (1<<n);j++){
            if((j>>i)&1){
                dp1[j] *= p[i];
            }else{
                dp1[j] *= (1-p[i]);
            }
        }
    }
    
    // 高速メビウス変換
    /* ゼータ変換は +=部分を -=にすればよい*/
    vector<ll> dp2((1<<n),0);
    for(int i = 0; i <(1<<n);i++){
        ll LCM = 1;
        for(int j = 0; j < n;j++){
            if(LCM > m) break;
            if((i>>j)&1){
                ll tmp = a[j] / gcd(LCM,a[j]);
                if(1.0 * tmp * LCM < m + 1) LCM*=tmp;
                else LCM = m+1;
            }
        }
        dp2[i] = m/LCM;
    }
    for(int i = 0; i < n;i++){
        for(int j = 0;j < (1<<n);j++){
            if((j>>i)&1){
                dp2[j] -= dp2[j^1 << i];
            }
        }
    }
    
    long double res = 0;
    for(int i = 0; i < (1<<n);i++){
        res += dp1[i] * (m - abs(dp2[i])); // 絶対値をとる
    }
    cout << fixed << setprecision(10) << res << endl;
    return 0;
}
