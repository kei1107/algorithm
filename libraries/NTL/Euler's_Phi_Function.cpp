#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60




// =============== //
/* output : 入力 n に対して1~nまでの自然数の中で n と互いに素なものの個数 */


ll Euler_Phi(ll m) {
    if(m==0)return 0;
    ll res = m;
    for (ll i = 2; i * i <= m; i++) {
        if (m % i == 0) {
            res = res / i * (i - 1); while(m % i == 0) m/=i;
        }
    }
    if (m != 1) res = res / m * (m - 1);
    return res;
}

// ============== //

vector<ll> PrimeFact(ll n){
    vector<ll> res;
    while(n!=1){
        if(n == 2 || n == 3){
            res.emplace_back(n); n/=n;
            continue;
        }
        bool prime_flag = false;
        for(int i = 2;i*i <= n;i++){
            if(n%i==0){
                res.emplace_back(i); n/=i;
                prime_flag = true;
                break;
            }
        }
        if(!prime_flag){res.emplace_back(n); n/= n;}
    }
    return res;
}

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n; cin >> n;
    auto primes = PrimeFact(n);
    primes.erase(unique(primes.begin(),primes.end()),primes.end());
    ll res = n;
    for(auto p:primes){
        res = res - res/p;
    }
    cout << res << endl;
    return 0;
}
