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
 <url:https://yukicoder.me/problems/no/171>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 文字列の種類の数は
 
          (文字列の長さ)!
 -------------------------------     - 1  mod 573
 (Aの個数)!(Bの個数)!・・・(Zの個数)!
 
 である。
 ここで573は合成数なのでいつものフェルマーの小定理から逆数を用いる方法が使えない。
 そこで分母にある素数及びその個数を全列挙し、
 愚直に先に(文字列の長さ)!で生じる値を割れるだけ割っておく。
 そのあとは分子部分の計算だけになるので普通にmodを用いて計算できる
 ================================================================
 */

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
ll solve(){
    ll res = 1;
    string S; cin >> S;
    vector<int> alpha(26,0);
    for(auto& c:S) alpha[c-'A']++;
    
    vector<int> cnt(S.length()+1,0);
    for(int i = 0; i < 26;i++){
        for(int j = 2; j <= alpha[i];j++) cnt[j]++;
    }
    for(int i = 2; i < S.length();i++){
        ll T = cnt[i];
        cnt[i] = 0;
        auto primes = PrimeFact(i);
        for(auto p:primes){
            cnt[p] += T;
        }
    }
    vector<int> mul(S.length()+1,0);
    iota(mul.begin(),mul.end(),0);
    for(ll i = S.length(); i >= 2;i--){
        for(ll j = S.length(); j >= 2;j--){
            while(cnt[j] && (mul[i]%j==0)){
                cnt[j]--;
                mul[i]/=j;
            }
        }
    }
    for(int i = 1; i <= S.length();i++) (res *= mul[i])%=573;
    res+=573-1; res%=573;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
