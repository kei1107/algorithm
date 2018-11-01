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
 <url:https://yukicoder.me/problems/no/174>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 期待値を求めるに当たって
 
 i試合目にj番目のカードを引く場合の確率が知りたい。
 これは直接求めるのは難しいが
 bitDPを用いることによって、間接的に集計することができる。
 
 よって、先にbitDPで dp[i][j] := 集合iのカードが選択済みであり最後にカードjを引いた場合の確率
 (自分はわかりやすいように最後に引いたカードもbitDPに含めたが選択済集合だけでも作ることはできる)
 を求めておき
 後からi試合目にj番目のカードを引く場合の確率
 を計算する
 
 あとは、各試合でA君がB君に勝つ場合の確率の期待値を求めれば良い
 ================================================================
 */

typedef double ld;
ld dp[1<<20][20];
vector<vector<ld>> get(vector<int>& V,ld P){
    int N = (int)V.size();
    sort(V.begin(),V.end());
    
    fill(*dp,*dp+(1<<20)*20,0);
    if(N!=1)dp[1<<0][0] = P;
    else dp[1<<0][0] = 1;
    for(int i = 1; i < N;i++) dp[1<<i][i] = (1-P)/(N-1);
    for(int i = 0; i < (1<<N);i++){
        for(int j = 0; j < N;j++){
            if(dp[i][j] == 0) continue;
            int leafN = N - __builtin_popcount(i);
            if(leafN == 1){
                for(int k = 0; k < N;k++){
                    if((i>>k)&1)continue;
                    dp[i|(1<<k)][k] += dp[i][j];
                }
            }else{
                bool first = true;
                for(int k = 0; k < N;k++){
                    if((i>>k)&1)continue;
                    if(first){
                        dp[i|(1<<k)][k] += dp[i][j]*P;
                        first = false;
                    }else{
                        dp[i|(1<<k)][k] += dp[i][j]*(1-P)/(leafN-1);
                    }
                }
            }
        }
    }
    
    vector<vector<ld>> ret(N+1,vector<ld>(N));
    for(int i = 0; i < (1<<N);i++){
        for(int j = 0; j < N;j++){
            int SZ = __builtin_popcount(i);
            ret[SZ][j] += dp[i][j];
        }
    }
    return ret;
}
ld solve(){
    ld res = 0;
    int N; cin >> N;
    ld P[2]; for(int i = 0; i < 2;i++) cin >> P[i];
    vector<int> A(N),B(N);
    for(auto& in:A) cin >> in;
    for(auto& in:B) cin >> in;
    
    auto infoA = get(A,P[0]);
    auto infoB = get(B,P[1]);
    
    for(int i = 1; i <= N;i++){
        for(int j = 0;j<N;j++){
            ld selectA = infoA[i][j];
            for(int k = 0;k<N;k++){
                if(A[j]>B[k]){
                    ld selectB = infoB[i][k];
                    ld score = A[j]+B[k];
                    res += selectA*selectB*score;
                }
            }
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(12) << solve() << endl;
    return 0;
}
