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
 <url:http://codeforces.com/contest/959/problem/D>
 問題文============================================================
 Mahmoud has an array a consisting of n integers.
 He asked Ehab to find another array b of the same length such that:
 
 b is lexicographically greater than or equal to a.
 bi ≥ 2.
 b is pairwise coprime: for every 1 ≤ i < j ≤ n, bi and bj are coprime,
 i. e. GCD(bi, bj) = 1, where GCD(w, z) is the greatest common divisor of w and z.
 
 Ehab wants to choose a special array so he wants the lexicographically minimal
 array between all the variants. Can you find it?
 
 An array x is lexicographically greater than an array y if there exists an index
 i such than xi > yi and xj = yj for all 1 ≤ j < i.
 An array x is equal to an array y if xi = yi for all 1 ≤ i ≤ n.
 =================================================================
 解説=============================================================
 
 貪欲
 
 あらかじめ使用可能な素数表を作っておき、
 aを順番に見ていった時に、使用可能な素数のみで作られていたら同じ値を使う
 
 使用不可能な素数で作られていたならば、その値　a[i] より大きい値から 使用可能な素数のみで作られて
 いる値を探して、その値を用いる
 
 この後の選択に関しては、すでに辞書順でaより大きいことが確定しているので、使用可能な最小の素数を順番に
 利用していく
 
 ================================================================
 */

const ll MAX_PRIME = 5000000;
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

vector<int> solve(){
    vector<int> res;
    int n; cin >> n;
    vector<int> a(n);
    for(auto& in:a)cin >> in;
    
    set<int> P(primes.begin(),primes.end());
    vector<int> have_prime(101,0);
    auto primeFactorize = [](int v,set<int>& P,vector<int>& have_prime){
        int ret = 0;
        for(int j = 2; j * j <= v; j++){
            if(v%j == 0){
                have_prime[ret++] = j;
                while(v%j == 0) v/=j;
                if(!P.count(j)) return ret = -1;
            }
        }
        if(v > 1){
            have_prime[ret++] = v;
            if(!P.count(v)) return ret = -1;
        }
        return ret;
    };
    
    bool large = false;
    for(int i = 0; i < n; i++){
        if(large){
            res.push_back(*P.begin()); P.erase(P.begin());
            continue;
        }
        int ret = primeFactorize(a[i],P,have_prime);
        if(ret != -1){
            res.push_back(a[i]);
            for(int j = 0; j < ret; j++) P.erase(have_prime[j]);
        }else{
            large = true;
            int R = a[i];
            while(R++){
                ret = primeFactorize(R,P,have_prime);
                if(ret != -1) break;
            }
            res.push_back(R);
            for(int j = 0; j < ret; j++) P.erase(have_prime[j]);
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    init_primes();
    cout << solve() << endl;
    return 0;
}
