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
 <url:https://yukicoder.me/problems/no/12>
 問題文============================================================
 '0'から'9'までの数字が重複せずN個与えられる。
 
 次に、1以上5000000以下の範囲からK以上L以下の範囲を選ぶ。
 K以上L以下の範囲から素数のみをすべて取り出す。
 すべての素数について使われている数字を調べる。
 例えば、K以上L以下の範囲で10以上20以下の範囲を選んだとき、
 すべての素数は"11"、"13"、"17"、"19"の4つ。
 使われている数字は'1'と'3'と'7'と'9'の4つである。
 この使われている数字と最初に与えられた数字を等しくしたい。
 （すべて使われないといけない）
 この時のKとLの差L−Kの最大値を求めよ。
 そのような場合がなければ−1を答えとせよ。
 
 以下は無効な例
 与えられた数字が[3,5,7]の場合
 4以上7以下の範囲での素数は 5,7となるので3が含まれてないので無効な範囲である。
 2以上10以下の範囲での素数は 2,3,5,7となるので2が余計に含まれており無効な範囲である。
 
 この場合、「3以上7以下」や「3以上10以下」などが有効な範囲である。
 

 =================================================================
 解説=============================================================
 
 あらかじめ、素数について値、および使用する値を保存しておき
 しゃくとり法にて範囲を探す。
 
 ================================================================
 */


const ll MAX_PRIME = 5000000;
vector<int> primes;
vector<int> is_prime(MAX_PRIME + 1,true);
void init_primes(){
    /* この問題のみ */ primes.push_back(0);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i <= MAX_PRIME;i++){
        if(is_prime[i]){
            primes.push_back(i);
            for(int j = i*2; j <= MAX_PRIME; j+=i) is_prime[j] = false;
        }
    }
    /* この問題のみ */ primes.push_back(5000001);
}

void prime2num(vector<int>& nums){
    for(int i = 1; i < primes.size()-1;i++){
        string s = to_string(primes[i]);
        for(auto c:s) nums[i] |= (1<<(c-'0'));
    }
}

int check(int f,int A){
    if(f == A) return 1;
    if((f|A) <= A) return 0;
    return -1;
}
int solve(){
    int res = 0;
    int N; cin >> N;
    int A = 0;
    for(int i = 0; i < N;i++){ int a; cin >> a; A |= (1<<a); }
    vector<int> nums(primes.size());
    
    int f = 0;
    int K = 1, L = 1;
    prime2num(nums);
    while(true){ // [K,L)
        int ret=0;
        while(L < primes.size() && ((ret = check(f,A)) >= 0)){
            if(ret == 1){
                res = max(res,(primes[L]-1)-(primes[K-1]+1));
            }
            f |= nums[L];
            L++;
        }
        if(ret >= 0){
            if(ret == 1) res = max(res,(primes[L-1]-1)-(primes[K-1]+1));
            break;
        }
        K = L;
        f = 0;
    }
    return res==0?-1:res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    init_primes();
    cout << solve() << endl;
    return 0;
}
