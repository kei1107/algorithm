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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1276>
 問題文============================================================
 ある値 k が与えられる
 k以上の最小の素数 p1 と k以下の最大の素数p2を求め
 p1 - p2 を出力せよ
 =================================================================
 解説=============================================================
 あらかじめ素数を列挙しておき、にぶたんで探せば良い
 ================================================================
 */

const ll MAX_PRIME = 1299710;
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

int K;
ll solve(){
    ll res = 0;
    if(is_prime[K]) return 0;
    auto it = upper_bound(primes.begin(),primes.end(),K);
    res = *it - *(it-1);
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    init_primes();
    while(cin >> K,K){
        cout << solve() << endl;
    }
    return 0;
}
