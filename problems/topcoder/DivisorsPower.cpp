#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <bitset>
#include <iostream>
#include <iomanip>
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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

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

// nの約数を列挙する
vector<ll> getdivisor(ll n){
    vector<ll> res;
    for(ll i = 1; i*i <= n;i++){
        if(n%i == 0) {
            res.push_back(i);
            if(n/i != i) res.push_back(n/i);
        }
    }
    sort(res.begin(),res.end());
    return res;
}

class DivisorsPower {
    public:
    long long findArgument(long long n) {
        init_primes();
        ll res = -1;
        map<ll,int> factors;
        factorize(n,factors);
        
        ll GCD = 0;
        ll maxv = LINF;
        for(auto p:factors){ GCD = gcd(GCD,p.second); maxv = min(maxv,(ll)p.second);}
        
        for(ll v = 1; v <= maxv; v++){
            bool ok = true;
            ll T = 1;
            ll X = 1;
            for(auto p:factors){
                if(p.second%v!=0){
                    ok = false;
                    break;
                }
                T *= (p.second/v + 1);
                
                X *= pow_mod(p.first, p.second/v, LLONG_MAX);
                if(T > v){
                    break;
                }
            }
            if(!ok) continue;
            if(T!=v) continue;
            if(res == -1) res = X;
            else res = min(res,X);
            break;
        }
        return res;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 4LL; long long Arg1 = 2LL; verify_case(0, Arg1, findArgument(Arg0)); }
	void test_case_1() { long long Arg0 = 10LL; long long Arg1 = -1LL; verify_case(1, Arg1, findArgument(Arg0)); }
	void test_case_2() { long long Arg0 = 64LL; long long Arg1 = 4LL; verify_case(2, Arg1, findArgument(Arg0)); }
	void test_case_3() { long long Arg0 = 10000LL; long long Arg1 = 10LL; verify_case(3, Arg1, findArgument(Arg0)); }
	void test_case_4() { long long Arg0 = 2498388559757689LL; long long Arg1 = 49983883LL; verify_case(4, Arg1, findArgument(Arg0)); }

// END CUT HERE


};

// BEGIN CUT HERE
//int main(){
//    DivisorsPower ___test;
//    ___test.run_test(-1);
//    return 0;
//}
// END CUT HERE
