#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <bitset>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <numeric>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <deque>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:http://poj.org/problem?id=2429>
問題文============================================================
最小公倍数(LCM)と最大公約数(GCD)が与えられた時、それを満たす整数のペア(a,b)を求めよ。
 複数あり得る場合は、a+bが最も小さくなるペアを答えよ
 
 a, b < 2^63
=================================================================

解説=============================================================
 参照:http://quiz.fuqinho.net/blog/2012/06/12/poj-2429-gcd-and-lcm-inverse/
 
 LCM/GCDを素因数分解して、互いに素になるように２つに分けた後でGCDを掛ければ答えの候補になる。
 が、整数の範囲がめちゃくちゃ大きいので、素因数分解できない。
 乱択アルゴリズムを使って確率的に求める。
 素数判定はミラー-ラビン素数判定法、
 合成数であることが分かればポラード・ロー素因数分解法を使って約数を取り出して分解する。
================================================================
*/

// return (a * b) % m
ll mul_mod(ll a,ll b,ll m){
    ll res = 0;
    ll exp = a % m;
    while(b){
        if(b&1){
            res += exp;
            if(res > m) res -= m;
        }
        exp <<= 1;
        if(exp > m) exp -= m;
        b >>= 1;
    }
    return res;
}

// return (x ^ k) % m
ll pow_mod(ll a, ll b, ll m){
    ll res = 1;
    ll exp = a % m;
    while(b){
        if(b& 1) res = mul_mod(res, exp, m);
        exp = mul_mod(exp, exp, m);
        b >>= 1;
    }
    return res;
}

// ミラーラビン素数判定法
// return 判定値 n が 最大times回、乱択的にチェックした時に素数判定されるかどうか
bool miller_rabin(ll n, ll times) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (!(n & 1)) return false;
    
    ll q = n-1;
    int k = 0;
    while (q % 2 == 0) {
        k++;
        q >>= 1;
    }
    // n - 1 = 2^k * q (qは奇素数)
    // nが素数であれば、下記のいずれかを満たす
    // (i) a^q ≡ 1 (mod n)
    // (ii) a^q, a^2q,..., a^(k-1)q のどれかがnを法として-1
    //
    // なので、逆に(i)(ii)いずれも満たしていない時は合成数と判定できる
    //
    for (int i = 0; i < times; i++) {
        ll a = rand() % (n-1) + 1; // 1,..,n-1からランダムに値を選ぶ
        ll x = pow_mod(a, q, n);
        // (i)をチェック
        if (x == 1) continue;
        // (ii)をチェック
        bool found = false;
        for (int j = 0; j < k; j++) {
            if (x == n-1) {
                found = true;
                break;
            }
            x = mul_mod(x, x, n);
        }
        if (found) continue;
        
        return false;
    }
    return true;
}

inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }

// ポラード・ロー素因数分解法
ll pollard_rho(ll n, int c){
    ll x = 2, y = 2, d = 1;
    while(d == 1){
        x = mul_mod(x, x, n) + c;
        y = mul_mod(y, y, n) + c;
        y = mul_mod(y, y, n) + c;
        d = gcd((x-y >= 0 ? x-y : y-x), n);
    }
    if(d == n) return pollard_rho(n, c+1);
    return d;
}

const ll MAX_PRIME = 200000;
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

bool isPrime(ll n){
    if(n <= MAX_PRIME) return is_prime[n];
    else return miller_rabin(n, 20);
}

// 素因数分解, テーブルを用い, 大きければポラード・ローを用いる
void factorize(ll n, map<ll, int>& factors){
    if(isPrime(n)){
        factors[n]++;
    }else{
        for(int i = 0; i < (int)primes.size(); i++){
            int p = primes[i];
            while(n % p == 0){
                factors[p]++;
                n /= p;
            }
        }
        if(n != 1){
            if(isPrime(n)){
                factors[n]++;
            }else{
                ll d = pollard_rho(n, 1);
                factorize(d, factors);
                factorize(n/d, factors);
            }
        }
    }
}

pll solve(ll a, ll b) {
    ll c = b / a;
    map<ll, int> factors;
    factorize(c, factors);
    
    vector<ll> mult_factors;
    for (map<ll, int>::iterator it = factors.begin(); it != factors.end(); it++) {
        ll mul = 1;
        while (it->second) {
            mul *= it->first;
            it->second --;
        }
        mult_factors.push_back(mul);
    }
    
    ll best_sum = 1e18, best_x = 1, best_y = c;
    for (int mask = 0; mask < (1 << mult_factors.size()); mask++) {
        ll x = 1;
        for (int i = 0; i < mult_factors.size(); i++) {
            if (mask & (1 << i)) x *= mult_factors[i];
        }
        ll y = c / x;
        if (x < y && x + y < best_sum) {
            best_sum = x + y;
            best_x = x;
            best_y = y;
        }
    }
    return make_pair(best_x * a, best_y * a);
}

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    init_primes();
    ll a,b;
    while(cin >> a >> b){
        pll ans = solve(a,b);
        cout << ans.first << " " << ans.second << endl;
    }
	return 0;
}
