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
 <url:https://yukicoder.me/problems/no/10>
 問題文============================================================
 あなたは、Isaacから借りたノートをコピーしようとしてOCRにかけようとしている。
 ある計算式をOCRしようとしたら、演算子を正しく認識されてなく、文字化けしていることに気づいた。
 ここに出てくる演算子は+と*のみで、すべて?と表示されてしまっている。
 元の数式の正しい数式を求めてください。
 複数回答がある場合は、{+,*} の順の辞書列順の最初のものを求めてください。
 例えば辞書順は
 ++ → +* → *+ → **　の順番である。
 
 重要：この問題では優先順位は同じとし、左結合とする。
 簡単に言うと左から順に処理するだけである。
 例えば1 ? 2 ? 10 ? 1=31の場合 1+2*10+1が答えで
 実際の世界では((1+2)*10)+1=31　となるので注意。
 
 =================================================================
 解説=============================================================
 
 優先順位が左結合であるので
 Totalから逆算する形で計算ルートを求めることができる。
 
 よって、dpで移動経路を求めて
 その経路を今度は左から順に復元する形で行えば良い
 
 ================================================================
 */

void solve(){
    int N; cin >> N;
    int T; cin >> T;
    vector<int> A(N);
    for(auto& in:A) cin >> in;
    vector<vector<int>> dp(N+1,vector<int>(T+1,0));

    
    // よくよく考えたらこの部分全く必要なかった。
    dp[1][A[0]] = 1;
    for(int i = 1; i < N;i++){
        for(int j = 0; j <= T; j++){
            if(dp[i][j] == 0) continue;
            if(j + A[i] <= T) dp[i+1][j+A[i]] = 1;
            if(j*A[i] <= T) dp[i+1][j*A[i]] = 1;
        }
    }
    // でも一応残しておく
    
    vector<vector<int>> dp2(N+1,vector<int>(T+1,0));
    dp2[N][T] = 1;
    for(int i = N;i>1;i--){
        for(int j = 0; j <= T;j++){
            if(dp2[i][j] == 0) continue;
            if(j-A[i-1] >= 0 && dp[i-1][j-A[i-1]]){
                dp2[i-1][j-A[i-1]] = 1;
            }
            if(j%A[i-1] == 0 && dp[i-1][j/A[i-1]]){
                dp2[i-1][j/A[i-1]] = 1;
            }
        }
    }
    //cout << endl << dp2 << endl;
    
    string ans = "";
    int now = A[0];
    for(int i = 1; i < N;i++){
        if(now+A[i] <= T && dp2[i+1][now+A[i]]){
            ans += "+";
            now += A[i];
            continue;
        }
        if(now*A[i] <= T && dp2[i+1][now*A[i]]){
            ans += "*";
            now *= A[i];
            continue;
        }
    }
    cout << ans << endl;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    solve();
    return 0;
}
