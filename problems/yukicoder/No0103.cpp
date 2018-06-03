#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

/*
 <url:https://yukicoder.me/problems/no/103>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 まず、一つのMについて考える
 Mは素数という山から最大2個まで石を取ることがNimと考えることができる為,
 各素数のgrundy数(今回の場合は山の数%3=素数の個数%3)となる為、
 
 Mを構成する素数の個数から、そのgrundy数が分かる。
 
 二つ以上Mがある場合に関しても、
 同様の考えができ、結局のところ、各Mについて、それぞれのgrundy数を求め、
 そのxorを取ることによって判定することができる
 ================================================================
 */

/* 素因数分解 */
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

string solve(){
    ll N; cin >> N;
    vector<ll> M(N); for(auto& in:M) cin >> in;
    map<ll,ll> mp;
    ll XOR = 0;
    for(int i = 0; i < N;i++){
        mp.clear();
        auto primes = PrimeFact(M[i]);
        for(auto prime:primes) mp[prime]++;
        for(auto p:mp){
            XOR ^= (p.second%3);
        }
    }
    if(!XOR){
        return "Bob";
    }else{
        return "Alice";
    }
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
