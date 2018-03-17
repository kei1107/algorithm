#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://abc052.contest.atcoder.jp/tasks/arc067_a?lang=en>
問題文============================================================
整数 N が与えられます。 N! の正の約数の個数を 10^9+7 で割った余りを求めてください。
=================================================================

解説=============================================================
 
 約数の個数は、その整数にある素因数がいくつ含まれているかどうかでもとまる（ggr)
 
 N!の素因数はそれぞれ 1,2,3....N の素因数の個数と等しいため
 独立に求め、最後に総数を求めれば良い
 
================================================================
*/
const ll MAX_PRIME = 1000;
vector<int> primes;
vector<int> is_prime(MAX_PRIME + 1,true);
void init_primes(){
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i <= MAX_PRIME;i++){
        if(is_prime[i]){
            primes.push_back(i);
            for(int j = i*2; j <= MAX_PRIME; j+=i) is_prime[j] = false;
        }
    }
}
const ll MOD = 1e9+7;
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N; cin >> N;
    
    init_primes();
    
    vector<ll> primes_cnt(primes.size(),0);
    for(int i = 2; i <=N;i++){
        ll T = i;
        for(int j = 0; j < (int)primes.size();j++){
            while(T%primes[j] == 0){
                primes_cnt[j]++;
                T/=primes[j];
            }
        }
    }
    ll ans = 1;
    for(int i = 0; i <= (int)primes.size();i++){
        ans *= primes_cnt[i]+1;
        ans %=MOD;
    }
    cout << ans << endl;
	return 0;
}
