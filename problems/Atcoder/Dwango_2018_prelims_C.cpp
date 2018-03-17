#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream &operator << (ostream& out,const pair<S,T>& o){
    out << "(" << o.first << "," << o.second << ")"; return out;
}

/*
 <url:https://dwacon2018-prelims.contest.atcoder.jp/tasks/dwacon2018_prelims_c>
 問題文============================================================
 dwango社員のニワンゴくんはゲームが大好きです。ニワンゴくんは「なんとかトゥーン」というゲームを遊んでいます。
 
 このゲームはチーム戦で、N 人のプレイヤーからなるAチームと、M 人のプレイヤーからなるBチームに分かれて戦闘を行います。
 各プレイヤーは戦闘の間、相手チームのプレイヤーに対して「攻撃」を行うことができます。
 あるプレイヤーからあるプレイヤーに対する攻撃が成立すると、攻撃したプレイヤーの「キル数」が 1 加算され、
 同時に攻撃されたプレイヤーの「デス数」が 1 加算されます。
 どちらのプレイヤーも攻撃の後も戦闘を継続でき、攻撃したりされたりすることが可能です。
 あるプレイヤーが同じプレイヤーを複数回攻撃することもありえます。
 しかし、同じチームのプレイヤーを攻撃することはできません。
 戦闘の開始時点で、すべてのプレイヤーのキル数とデス数は 0 に設定されています。
 
 ニワンゴくんは、戦闘が終わるとその結果を記録しています。ニワンゴくんの記録は以下の様なものです。
 まず、Aチームのプレイヤーをキル数の多い順（同じ場合デス数の少ない順）に並べ、
 それらのキル数を killA=[killA1,killA2,…,killAN] 、
 デス数を deathA=[deathA1,deathA2,…,deathAN] とします。
 同様にしてBチームのプレイヤーからも
 数列 killB=[killB1,killB2,…,killBM] および
 deathB=[deathB1,deathB2,…,deathBM] を定義します。
 ニワンゴくんは killA と killB のみを記録します。
 
 ニワンゴくんは、 killA と killB から必ずしも一意に deathA と deathB を復元できないことに気が付きました。
 与えられた killA と killB に矛盾しない deathA と deathB の組み合わせは何通りあるでしょうか？
 答えは非常に大きくなりうるので、 1,000,000,007(10^9+7) で割った余りを出力してください。
 
 =================================================================
 
 解説=============================================================
 難しい。　分割数をさらに分割して行くイメージ(解説見た
 ================================================================
 */
const ll MOD = 1e9+7;

#define MAX_V 1010
ll dp[MAX_V][MAX_V];
void init(){
    dp[0][0] = 1;
    for(int i = 1; i < MAX_V;i++){
        for(int j = 0; j < MAX_V;j++){
            if(j-i >= 0) {
                dp[i][j] = (dp[i-1][j] + dp[i][j-i]) % MOD;
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
}

ll calc(ll& sum,vector<ll>& vc){
    vector<vector<ll>> tdp(vc.size(),vector<ll>(sum+1,0));
    tdp[0][0] = 1;
    for(int i = 1; i <= sum;i++) tdp[0][i] = dp[vc[0]][i];
    
    for(int i = 1; i < vc.size();i++){
        for(int j = 0; j <= sum;j++){
            for(int k = 0; k <= j;k++){
                (tdp[i][j] += tdp[i-1][k]*dp[vc[i]][j-k]%MOD)%=MOD;
            }
        }
    }
    return tdp[vc.size()-1][sum];
}
ll solve(){
    ll res = 0;
    ll N,M; cin >> N >> M;
    vector<ll> A(N),B(M);
    for(auto &in:A) cin >> in;
    for(auto &in:B) cin >> in;
    ll sumA = accumulate(A.begin(), A.end(), 0LL);
    ll sumB = accumulate(B.begin(), B.end(), 0LL);
    
    vector<ll> va,vb;
    {
        ll cnt = 1;
        for(int i = 1; i < N;i++){
            if(A[i] == A[i-1]) cnt++;
            else { va.push_back(cnt); cnt = 1; }
        }
        va.push_back(cnt);
    }
    {
        ll cnt = 1;
        for(int i = 1; i < M;i++){
            if(B[i] == B[i-1])cnt++;
            else { vb.push_back(cnt); cnt = 1;}
        }
        vb.push_back(cnt);
    }
    res = calc(sumB,va) * calc(sumA,vb) % MOD;
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    init();
    cout << solve() << endl;
    return 0;
}
