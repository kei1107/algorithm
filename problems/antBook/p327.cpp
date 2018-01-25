#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <bitset>
#include <iostream>
#include <iomanip>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <numeric>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <deque>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e16;

/*
<url:????>
問題文============================================================

 'A', 'G', 'C', 'T'の４種類の文字のみが含まれるDNAの文字列を考えます。
 k文字の文字列Sが与えられます。ちょうどn文字出会って文字列Sを含まない文字列の個数を
 mod 10009で教えて下さい
 
=================================================================

解説=============================================================

 蟻本p328
 
 生成している文字列の末尾が、Sの先頭何文字に一致しているか、ただし一致のさせ方が複数通り
 ある場合は最長の場合という状態を計算し、
 
 最初にある状態からある文字を加えた場合に、次にどの状態に移動するかをキーにしてdp
 
================================================================
*/

#define MAX_K 100
#define MAX_N 10000
const char *AGCT = "AGCT";
const int MOD = 10009;

// 入力
int N,K;
string S;

int Next[MAX_K][4]; // 1文字加えた際に移動する先の状態
int dp[MAX_N + 1][MAX_K];

void solve(){
    // 前処理
    for(int i = 0; i < K;i++){
        for(int j = 0; j < 4;j++){
            // 一致しているi文字に1文字加えた文字列
            string s = S.substr(0,i) + AGCT[j];
            // Sの先頭に一致するまで先頭から1文字削る
            while(S.substr(0,s.length()) != s){
                s = s.substr(1);
            }
            Next[i][j] = (int)s.length();
        }
    }
    
    // 動的計画法の初期状態
    dp[0][0] = 1;
    for(int i = 1; i < K;i++) dp[0][i] = 0;
    // 動的計画法
    for(int t = 0; t < N; t++){
        for(int i = 0; i < K;i++) dp[t+1][i] = 0;
        for(int i = 0; i < K;i++){
            for(int j = 0; j < 4;j++){
                int ti = Next[i][j];
                if(ti == K) continue;
                (dp[t+1][ti] += dp[t][i])%=MOD;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < K;i++) (ans += dp[N][i])%=MOD;
    cout << ans << endl;
}

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    N = 3; K = 2; S = "AT";
    solve();
	return 0;
}
