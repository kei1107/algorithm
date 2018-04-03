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
 <url:https://yukicoder.me/problems/no/7>
 問題文============================================================
 あなたと素数を習ったばかりのEveは、素数のゲームを思いついた。
 
 ゲームの内容は以下のとおりです。
 ・まず初めに、先攻のプレイヤーに2以上の自然数Nが与えられます。
 ・その番のプレイヤーはNに対して、「N以下（Nも含む）の素数」のどれかで減算する、
 その数をN′とすると、N′が0または1になってしまったら、そのプレイヤーの負けである。
 ・その後N′を新たなNとし、相手にその数を渡し、以上を繰り返します。
 
 まずあなたが先攻となりゲームを始めます。
 この時、どちらも負けないように動くと考える。自然数Nが与えられた時、
 あなたが勝つことが出来る場合Win、それ以外はLoseを返してください。
 
 =================================================================
 解説=============================================================
 
 小さい順から次遷移先に勝ちパターンが存在するならば勝ち
                                 しないならば負け
 ================================================================
 */

const ll MAX_PRIME = 10005;
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

string solve(){
    ll N; cin >> N;
    vector<int> dp(N+1,0);
    dp[0] = dp[1] = true;
    for(int i = 2; i <= N;i++){
        dp[i] = [&]{
            for(int j = 0; j < primes.size(); j++){
                if(primes[j] > i) break;
                if(!dp[i-primes[j]]) return true;
            }
            return false;
        }();
    }
    return dp[N]?"Win":"Lose";
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    init_primes();
    cout << solve() << endl;
    return 0;
}
