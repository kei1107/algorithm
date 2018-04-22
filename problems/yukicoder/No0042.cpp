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
 <url:https://yukicoder.me/problems/no/42>
 問題文============================================================
 太郎くんは日本国に住んでいます。
 この国では、1 円玉、5 円玉、10 円玉、50 円玉、100 円玉、500 円玉の 6 種類の硬貨が使われています。
 
 貯金箱くんは硬貨を貯めに貯めて、
 1 円玉も 5 円玉も 10 円玉も 50 円玉も 100 円玉も 500 円玉も、10^20 枚以上持っています。
 しかし、太郎くんが M 円のお買い物したかったのです。
 太郎くんは、貯金箱くんに合計でちょうど M 円分の硬貨をくれるように頼みました。
 貯金箱くんは、せっかく貯めた硬貨をあげるのを渋り、問題に答えられたらあげることにしました。
 貯金箱くんは、「僕が M 円をあげるために渡さなければいけない最小の硬貨の枚数は何枚？」
 という問題を出しましたが太郎くんは一瞬で答えてしまいました。
 そこで、もう 1 問、貯金箱くんは、「僕が M 円をあげるために硬貨を渡す方法は何通り？」という問題に切り替えました。
 今度は太郎君が困ってしまいました。
 あなたは、貯金箱くんが M 円を太郎くんに渡す方法のパターン数を 10^9+9 で割った余りを求めるプログラムを書いて下さい。
 
 =================================================================
 解説=============================================================
 
 解説みた。。。
 無理。。。
 <参照：http://mayokoex.hatenablog.com/entry/2015/11/13/163505>
 
 dp[x][a∗c[x]+b]がaのx次式で表されることから、ラグランジュ補間を用いて
 dp[M]を高速に計算する
 ================================================================
 */

const ll MOD = 1e9+9;
ll powmod(ll a,ll b) {ll res=1;a%=MOD;for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
ll mod_inverse(ll a,ll b){ return powmod(a,b-2);}
#define MAX_N 3010
ll dp[MAX_N];
ll C[6] = {1,5,10,50,100,500};
void solve(){
   for(int i = 0; i < MAX_N;i++) dp[i] = 1;
    for(int i = 1; i < 6;i++){
        for(ll j = C[i]; j < MAX_N;j++){
            (dp[j] += dp[j-C[i]])%=MOD;
        }
    }
    ll T; cin >> T;
    while(T--){
        ll M; cin >> M;
        if(M < MAX_N){
            cout << dp[M] << endl;
            continue;
        }
        ll ans = 0;
        ll q = M%500;
        ll m = (M/500)%MOD;
        for(int i = 0; i < 6;i++){
            ll tmp = 1;
            for(int j = 0; j < 6;j++){
                if(i==j) continue;
                (tmp *= m-j)%=MOD;
                (tmp *= mod_inverse(i-j,MOD))%=MOD;
            }
            (tmp *= dp[i*500+q]) %= MOD;
            (ans += tmp) %= MOD;
        }
        ans = (ans+MOD)%MOD;
        cout << ans << endl;
    }
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
