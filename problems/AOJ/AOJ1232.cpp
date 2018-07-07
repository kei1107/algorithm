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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1232>
 問題文============================================================
  pq ≤ m and a/b ≤ p/q ≤ 1 を満たす　pqが最大となるペアを出力せよ
 =================================================================
 解説=============================================================
素数列挙しておいて全探索
 ================================================================
 */

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
int m,a,b;
vector<int> solve(){
    vector<int> res{0,0};
    for(int i(0); primes[i]*primes[i] <= m;i++){
        for(int j(i); primes[i]*primes[j] <= m;j++){
            if(a*primes[j] <= b*primes[i] && primes[j]*primes[i] >= *res.begin()**res.rbegin()){
                *res.begin() = primes[i]; *res.rbegin() = primes[j];
            }
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    init_primes();
    while(cin >> m >> a >> b,m){
        cout << solve() << endl;
    }
    return 0;
}
