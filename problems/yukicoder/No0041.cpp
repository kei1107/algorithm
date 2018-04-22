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
 <url:https://yukicoder.me/problems/no/41>
 問題文============================================================
 太郎くんは六並び国に住んでいます。
 この国では、1 円玉のほか、6 つの数字からなるゾロ目、
 つまり、111111 円玉、222222 円玉、…、999999 円玉の、合計 10 種類の硬貨が使われています。
 
 貯金箱くんは硬貨を貯めに貯めて、どの硬貨も、10^20 枚以上持っています。
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
 
 端数は１円玉を使用するしかなく、結局のところ、
 111111,222222,...,999999の組み合わせが重要となる。
 ここで、全て111111で割り切れるので、M / 111111として、その結果が 1~9円を用いて
 何通りかと置き換えても良い(切り捨てた分は端数であり、1円玉を使用するしかないため一意)
 
 よって、 dp[i] := i (:= M/111111)円を作るのに必要な渡し方
 としたdpを行う。
 
 また、全ての状態から1円玉を使った解法が存在するため。
 
 M/111111 := mとした場合
 
 dp[0]~dp[m]の累積和が答えとなる
 
 ================================================================
 */


const ll MOD = 1e9+9;

ll dp[100005];
ll cusum[100005];
void solve(){
    ll T; cin >> T;
    vector<ll> M(T); for(auto& in:M) cin >> in;
    
    dp[0] = 1;
    for(int i = 1; i <= 9; i++){
        for(int j = 0; j <= 100000;j++){
            (dp[i+j] += dp[j])%=MOD;
        }
    }
    cusum[0] = dp[0];
    for(int i = 1; i <= 100000;i++){
        (cusum[i] = cusum[i-1]+dp[i])%=MOD;
    }
    
    for(int i = 0; i < T;i++){
        cout << cusum[M[i]/111111] << endl;
    }
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
