/**
 * 素因数分解 1
 * 与えられる値の上限Nがわかっており、その範囲内で複数の素因数分解を行いたい時
 * 前処理 NloglogN
 * 素因数分解(primefactor) XlogN (Xは与えられる値)
 *
 * 前処理で、事前に値X(1〜N)に対して割るべき最小の素数を計算
 * 前処理で算出した素数で割ることを繰り返すことで、通常の素因数分解時にでる、無駄な除算判定をなくす
 */
struct PrimeFact{
    ll N;
    vector<ll> factor,primes;
    PrimeFact(ll N) : N(N), factor(N+1){
        factor[0] = factor[1] = -1;
        for(ll i = 2; i <= N; i++){
            if(factor[i]) continue;
            primes.emplace_back(i);
            factor[i] = i;
            for(ll j = i*i; j <= N; j+=i){
                if(!factor[j]) factor[j] = i;
            }
        }
    }
    bool isPrime(ll x){
        return factor[x] == x;
    }
    vector<ll> factors(ll x){
        vector<ll> ret;
        while(x != 1){ ret.emplace_back(factor[x]); x /= factor[x]; }
        return ret;
    }
    
    map<ll,ll> primefactor(ll x){
        map<ll,ll> ret;
        for(auto p:factors(x)){
            ret[p]++;
        }
        return ret;
    }
    void primefactor(ll x,map<ll,ll>& ret){
        for(auto p:factors(x)){
            ret[p]++;
        }
        return;
    }
};

/**
 * 素因数分解 2
 * 与えられる値をその都度処理
 * 戻り値 {素因数の配列(未ソート)}
 */
vector<ll> PrimeFact(ll n){
    vector<ll> res;
    while(n!=1){
        if(n == 2 || n == 3){
            res.emplace_back(n); n/=n;
            continue;
        }
        bool prime_flag = false;
        for(ll i = 2;i*i <= n;i++){
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

/**
 * 素因数分解 3
 * 与えられる値をその都度処理
 * 戻り値 {素因数の連想配列(値と個数)}
 */
void PrimeFact(ll n,map<ll,ll>& mp){
    while(n!=1){
        if(n == 2 || n == 3){
            mp[n]++; n/=n;
            continue;
        }
        bool prime_flag = false;
        for(ll i = 2;i*i <= n;i++){
            if(n%i==0){
                mp[i]++; n/=i;
                prime_flag = true;
                break;
            }
        }
        if(!prime_flag){mp[n]++; n/= n;}
    }
}


// ========== 比較 ========== //
// ABC177 E
// 素因数分解 3での逐次処理の結果
// -> https://atcoder.jp/contests/abc177/submissions/16382581   :   AC[1770 ms]
// 素因数分解 1での処理の結果
// -> https://atcoder.jp/contests/abc177/submissions/16383490   :   AC[427 ms]
// 
