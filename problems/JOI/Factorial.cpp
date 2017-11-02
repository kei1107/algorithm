
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
 <url:https://www.ioi-jp.org/camp/2007/2007-sp-tasks/2007-sp-day1_20.pdf>
 問題文============================================================
 整数 n (2 <= n <= 100000000) が与えられる. m の階乗が n で割り切れるような最小の正の整
 数 m を求めるプログラムを書け. ただし, 正の整数 m に対し, m の階乗とは 1 から m までの
 整数の積のことである.
 =================================================================
 解説=============================================================
 貪欲にやると時間も間に合わないし、オーバーフローする（当たり前）
 nを素因数分解して、各素数が何個あり、何乗でその個数を満たすのかを確認し、
 全ての素因数についてのその最大が求める答え
 
 ex. 12 ならば 2^2 * 3 /
 素数2について着目すれば 4!で2が3個となり満足
 素数3について着目すれば 3!で3が1個となり、満足
 よって答えは4
 ================================================================
 */


vector<pll> Primes(ll n){
    vector<pll> res;
    ll p_cnt = 0;
    ll temp_n = n;
    while(temp_n%2 == 0){
        p_cnt++;
        temp_n/=2;
    }
    if(p_cnt != 0) res.emplace_back(pll(2LL,p_cnt));
    for(int i = 3; i*i <= n;i++){
        p_cnt = 0;
        while(temp_n%i == 0){
            p_cnt++; temp_n/=i;
        }
        if(p_cnt != 0) res.emplace_back(pll((ll)i,p_cnt));
    }
    if(temp_n > 1) res.emplace_back(pll(temp_n,1));
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n; cin >> n;
    auto primes = Primes(n);
    ll res = 0;
    for(auto p:primes){
        ll prime = p.first;
        ll p_cnt = p.second;
        ll temp_prime = 0;
        while(p_cnt > 0){
            temp_prime += prime;
            ll temp_n = temp_prime;
            while(temp_n%prime == 0){
                temp_n/=prime;
                p_cnt--;
            }
        }
        res = max(res,temp_prime);
    }
    cout << res << endl;
    return 0;
}
