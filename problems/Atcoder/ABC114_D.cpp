#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

/*
 <url:https://atcoder.jp/contests/abc114/tasks/abc114_d>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 Nの制約が小さいので100以下の素数について、N!に幾つ持つのかについて全探索すればいい
 
 75 = 75 = 3 * 5 * 5 = 3 * 25 = 5 * 15
 なのでパターンを全部見ればいい
 ================================================================
 */

const ll MAX_PRIME = 100;
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

/* 素因数分解 */
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

template<class Type>
Type solve(Type res = Type()){
    int N; cin >> N;
    map<ll,ll> mp;
    for(int i = 1; i <= N;i++) PrimeFact(i, mp);
    init_primes();
    
    int sz = (int)primes.size();
    for(int i = 0; i < sz;i++){
        for(int j = i+1; j < sz;j++){
            for(int k = j+1; k<sz;k++){
                
                // 75 : 3 5 5
                if(mp[primes[i]]>=2 && mp[primes[j]]>=4 && mp[primes[k]]>=4) res++;
                if(mp[primes[k]]>=2 && mp[primes[i]]>=4 && mp[primes[j]]>=4) res++;
                if(mp[primes[j]]>=2 && mp[primes[k]]>=4 && mp[primes[i]]>=4) res++;
            }
            
            // 75 : 3 25
            if(mp[primes[i]]>=2 && mp[primes[j]]>=24) res++;
            if(mp[primes[j]]>=2 && mp[primes[i]]>=24) res++;
            
            // 75 : 5 15
            if(mp[primes[i]]>=4 && mp[primes[j]]>=14) res++;
            if(mp[primes[j]]>=4 && mp[primes[i]]>=14) res++;
        }
        
        // 75 : 75
        if(mp[primes[i]]>=74) res++;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
