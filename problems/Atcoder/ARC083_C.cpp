#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
 <url:https://arc083.contest.atcoder.jp/tasks/arc083_a>
 問題文============================================================
 すぬけ君はビーカーに砂糖水を作ろうとしています。
 最初ビーカーは空です。すぬけ君は以下の 4 種類の操作をそれぞれ何回でも行うことができます。
 一度も行わない操作があっても構いません。
 
 操作 1: ビーカーに水を 100A [g] 入れる。
 操作 2: ビーカーに水を 100B [g] 入れる。
 操作 3: ビーカーに砂糖を C [g] 入れる。
 操作 4: ビーカーに砂糖を D [g] 入れる。
 すぬけ君の実験環境下では、水 100 [g] あたり砂糖は E [g] 溶けます。
 
 すぬけ君はできるだけ濃度の高い砂糖水を作りたいと考えています。
 
 ビーカーに入れられる物質の質量 (水の質量と砂糖の質量の合計) が F [g] 以下であり、
 ビーカーの中に砂糖を溶け残らせてはいけないとき、 すぬけ君が作る砂糖水の質量と、
 それに溶けている砂糖の質量を求めてください。 答えが複数ある場合はどれを答えても構いません。
 
 水 a [g] と砂糖 b [g] を混ぜた砂糖水の濃度は  100b/a+b  [%]です。
 また、この問題では、砂糖が全く溶けていない水も濃度 0 [%] の砂糖水と考えることにします。
 
 
 =================================================================
 
 解説=============================================================
 
 A,B,C,Dをそれぞれ何回選んだのかでdfsする。
 余分な遷移を防ぐために、その回数でメモ化しておく
 
 ================================================================
 */

double noudo = -1;
int ans = 0;
int ans2 = 0;
ll A,B,C,D,E,F;
bool f[33][33][103][103];
void dfs(int a,int b,int c,int d){
    if(f[a][b][c][d] == true) return;
    f[a][b][c][d] = true;
    ll AA = a*A,BB = b*B, CC = c*C, DD = d*D;
    if(100*AA + 100*BB + CC + DD > F) return;
    if(CC+DD <= E*(AA+BB)){
        if(a|b|c|d != 0){
            double satousui = 100*AA+100*BB+CC+DD;
            double satou = CC + DD;
            double t_noudo = 100*satou/satousui;
            if(t_noudo > noudo){
                noudo = t_noudo;
                ans = satousui;
                ans2 = satou;
            }
        }
    }
    
    dfs(a+1,b,c,d);
    dfs(a,b+1,c,d);
    dfs(a,b,c+1,d);
    dfs(a,b,c,d+1);
}

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> A >> B >> C >> D >> E >> F;
    dfs(0,0,0,0);
    cout << ans << " " << ans2 << endl;
    return 0;
}
