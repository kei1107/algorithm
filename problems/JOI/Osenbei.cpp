#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
 <url:https://www.ioi-jp.org/joi/2007/2008-yo-prob_and_sol/2008-yo-t5/2008-yo-t5.html>
 問題文============================================================
 縦 R (1<=R<=10), 横 C(1<=C<=10000)の1or0の盤面が与えられる
 最初に縦の行をいくつか選択し、その行の0,1を反転させる。
 そののち、縦の列をいくつか選択し、その列の0,1を反転させる
 
 操作終了時の1の最大数を求める
 =================================================================
 解説=============================================================
 
 どの行をひっくり返すかに関しては制約が10と小さいので2^10=1024の全通りが試せる
 列についてはその各列に1が過半数あれば裏返さなくてよく、なければ裏返せばいいのでO(RC)
 で求まる
 よって O(2^R * RC) := O(10^8)
 ================================================================
 */
vector<vector<int>> masu;
vector<int> Inv;
int R,C;
int dfs(int r){
    int res = 0;
    if(r == R){
        for(int i = 0; i < C;i++){
            int tmp = 0;
            for(int j = 0; j < R;j++){
                if(masu[j][i] == 1 && Inv[j] == 0){
                    tmp++;
                    continue;
                }
                if(masu[j][i] == 0 && Inv[j] == 1){
                    tmp++;
                    continue;
                }
            }
            res += max(tmp,R-tmp);
        }
        return res;
    }
    Inv[r] = 0;
    res = max(res,dfs(r+1));
    Inv[r] = 1;
    res = max(res,dfs(r+1));
    
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> R >> C;
    masu.assign(R,vector<int>(C,0));
    Inv.assign(R,0);
    for(int i = 0; i < R;i++){
        for(int j = 0; j < C;j++){
            cin >> masu[i][j];
        }
    }
    cout << dfs(0) << endl;
    return 0;
}
