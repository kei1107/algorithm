#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <bitset>
#include <iostream>
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
#define INF 1<<30
#define LINF 1LL<<60

/*
 <url:http://poj.org/problem?id=2385>
 問題文============================================================
 
 りんごの木 1・2がある
 t分間に1分間隔でどちらかの木からりんごが落ちてくる。
 どちらかのりんごの木の下にいるとき、その木から落ちてくるりんごは必ず取れる。
 
 このとき、木1と木2の間を移動する回数がw回以下の制限されているもとで、
 取れるりんごの個数の最大値を求める
 
 =================================================================
 
 解説=============================================================
 dp
 
 dp[i][j][k] := i分までにj回の移動回数の時に,kの樹の下にいる時に取れる最大のりんごの数
 
 でもとまる
 ================================================================
 */
ll dp[1010][31][2];
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll T,W; cin >> T >> W;
    vector<ll> apple(T);
    for(int i = 0; i < T;i++){
        cin >> apple[i];
        apple[i]--;
    }
    for(int i = 0; i < T;i++){
        for(int j = 0; j <= W;j++){
            if(apple[i] == 0){
                dp[i+1][j][0] = max(dp[i+1][j][0],dp[i][j][0]+1);
                dp[i+1][j][1] = max(dp[i+1][j][1],dp[i][j][1]);
                
                if(j != W){
                    dp[i+1][j+1][0] = max(dp[i+1][j+1][0],dp[i][j][1]);
                    dp[i+1][j+1][1] = max(dp[i+1][j+1][1],dp[i][j][0] +1);
                }
            }else{
                dp[i+1][j][0] = max(dp[i+1][j][0],dp[i][j][0]);
                dp[i+1][j][1] = max(dp[i+1][j][1],dp[i][j][1]+1);
                
                if(j != W){
                    dp[i+1][j+1][0] = max(dp[i+1][j+1][0],dp[i][j][1]+1);
                    dp[i+1][j+1][1] = max(dp[i+1][j+1][1],dp[i][j][0]);
                }
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i <= W;i++){
        ans = max(ans,max(dp[T][i][0],dp[T][i][1]));
        
    }
    cout << ans << endl;
    return 0;
}
