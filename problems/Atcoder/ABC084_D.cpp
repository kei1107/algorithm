#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://abc084.contest.atcoder.jp/tasks/abc084_d>
問題文============================================================
 「N も (N+1)÷2 も素数」を満たす奇数 N を 2017に似た数 とします。
 
 Q 個のクエリが与えられます。
 
 クエリ i(1≦i≦Q) では奇数 li,ri が与えられるので、
 li≦x≦ri かつ 2017に似た数 となる奇数 x の個数を求めてください。
=================================================================

解説=============================================================

 1..N までに2017素数であるものの個数を累積和で確保しておき
 一つのキューに対して O(1) でもとまる
 
================================================================
*/
const ll MAX_PRIME = 100000;
vector<int> primes(MAX_PRIME + 1);
vector<int> is_prime(MAX_PRIME + 1,true);
vector<int> prime2017(MAX_PRIME + 1,0);
vector<int> cusum(MAX_PRIME + 1,0);
void init_primes(){
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i <= MAX_PRIME;i++){
        if(is_prime[i]){
            primes.push_back(i);
            for(int j = i*2; j <= MAX_PRIME; j+=i) is_prime[j] = false;
        }
    }
}

void init(){
    init_primes();
    for(int i = 1; i <= MAX_PRIME; i++){
        if(is_prime[i] && is_prime[(i+1)/2]){
            prime2017[i] = true;
        }
    }
    for(int i = 0; i < MAX_PRIME;i++){
        cusum[i+1] = cusum[i] + prime2017[i+1];
    }
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    init();
    ll Q; cin >> Q;
    while(Q--){
        ll l,r; cin >> l >> r;
        cout << cusum[r] - cusum[l-1] << endl;
    }
	return 0;
}
