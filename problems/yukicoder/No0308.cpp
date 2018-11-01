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
 <url:https://yukicoder.me/problems/no/317>
 問題文============================================================
 =================================================================
 解説=============================================================
 REしまくって疲れた。。。
 
 Nが小さい時は愚直に探索すればいい
 
 Nが大きい時は....
  >> 解説　https://yukicoder.me/problems/no/308/editorial
 ミラーラビンテストによる素数判定を行い
 𝑁−8が素数かつ𝑁mod8=1ならば𝑊=14,それ以外なら𝑊=8が解
 ================================================================
 */

typedef __int128 lll;
istream &operator>>(istream &is,lll &value) {
    string in;
    is >> in;
    value = 0;
    for (const char &c : in) {
        if ('0' <= c && c <= '9') value = 10 * value + (c - '0');
    }
    return is;
}

const int MAX_PRIME = 10000;
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
// return (a * b) % m
lll mul_mod(lll a,lll b,lll m){
    lll res = 0;
    lll exp = a % m;
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
lll pow_mod(lll a, lll b, lll m){
    lll res = 1;
    lll exp = a % m;
    while(b){
        if(b& 1) res = mul_mod(res, exp, m);
        exp = mul_mod(exp, exp, m);
        b >>= 1;
    }
    return res;
}

// ミラーラビン素数判定法
// return 判定値 n が 最大times回、乱択的にチェックした時に素数判定されるかどうか
bool miller_rabin(lll n, int times) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (!(n & 1)) return false;
    
    lll q = n-1;
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
        lll a = rand() % (n-1) + 1; // 1,..,n-1からランダムに値を選ぶ
        lll x = pow_mod(a, q, n);
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

ll solve(){
    init_primes();
    ll res = 0;
    lll N; cin >> N;
    if(N <= 1000){
        for(int W=3;;W++){
            vector<int> flag(N+1,0);
            flag[1] = 1;
            queue<int> q; q.push(1);
            int d[4] = {-W,W,-1,1};
            while(q.size()){
                int now = q.front(); q.pop();
                for(int k = 0; k < 4;k++){
                    if(k==3 && now%W==0)continue;
                    if(k==2 && now%W==1)continue;
                    int next = now + d[k];
                    if((1<=next && next <= N) && !flag[next] && !is_prime[next]){
                        flag[next] = 1;
                        q.push(next);
                    }
                }
            }
            if(flag[N]){
                res = W;
                return res;
            }
        }
    }else{
        if(N%8==1){
            if(miller_rabin(N-8, 1000)) res = 14;
            else res = 8;
        }else{
            return res = 8;
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
