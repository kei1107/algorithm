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

const ll MAX_PRIME = 100000;
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
vector<int> solution(int N, vector<int> &P, vector<int> &Q) {
    init_primes();
    vector<int> ret;
    
    vector<int> semi_primes;
    for(int i = 0; i < (int)primes.size(); i++){
        for(int j = 0; j < (int)primes.size(); j++){
            if(N < primes[i]*primes[j]) break;
            semi_primes.push_back(primes[i]*primes[j]);
        }
    }
    sort(semi_primes.begin(),semi_primes.end());
    semi_primes.erase(unique(semi_primes.begin(),semi_primes.end()),semi_primes.end());
    int M = (int)P.size();
    for(int i = 0; i < M;i++){
        ret.push_back((int)(upper_bound(semi_primes.begin(),semi_primes.end(),Q[i])-lower_bound(semi_primes.begin(),semi_primes.end(),P[i])));
    }
    return ret;
}
