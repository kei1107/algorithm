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
 <url:https://yukicoder.me/problems/no/66>
 問題文============================================================
 太郎君は、「輝け☆全国たこやき杯」に参加することになりました。
 
 この大会は、総勢2M人の選手が出場し、
 トーナメント形式で戦い、勝った選手がさらに勝ち残った選手と戦う方式で
 優勝者を決定するものになっています。
 
 2^M人の選手にはそれぞれ、N1～N2Mまでの選手番号が割り当てられており、
 太郎君にはN1番が割り当てられました。
 
 トーナメントの1回戦では、N_2j−1の選手とN2jの選手が戦います。 (1≤j≤2^M−1)
 そして、そのそれぞれの勝者を N′_j とし、
 次の2回戦では、N′_2k−1の選手とN′_2kの選手が戦うといったように、(1≤k≤2^M−2)
 合計でM回戦行うことにより、1人の優勝者が決まります。
 
 2M人の選手はそれぞれ、強さパラメータSiを持っており、
 とあるA選手とB選手が勝負するとき、それぞれの強さパラメータを Sa,Sb とすると
 A選手が勝つ確率は Pa=Sa^2/(Sa^2+Sb^2)、 B選手が勝つ確率は Pb=Sb^2/(Sa^2+Sb^2)
 で表されます。
 選手ごとの相性など、上記以外の要素は勝敗に影響されません。
 
 入力に2^M人の選手の強さパラメータが与えられるので、
 太郎君が優勝する確率を求めてください。

 =================================================================
 解説=============================================================
 
 dp[i][j] := i回戦目にjが勝つ確率
 
 としてdpを行う。(但し、0回戦目は全員１で初期化)
 
 ここで、n回戦目に選手Nが戦う相手の候補は
 S := (1<<n)-1と置くと
 [j&(~S),j|S]
 に該当する相手となる
 すなわち N = (111010110)_2 , n = 5とすれば
 戦う相手の候補は [111000000,111011111] = 1110*****
 となる。
 この中から既に戦っている相手、すなわち、n-1回線目で戦っている相手を同様にして求めて考慮しないようにすれば
 n回戦目に戦う実際の相手が分かる。
 
  したがって、O(M*2^M*2^M)で求まる
 
 ================================================================
 */

typedef long double ld;
ld solve(){
    ld res = 0.;
    ll M; cin >> M;
    vector<ld> S(1<<M);
    for(auto& in: S) cin >> in;
    vector<vector<ld>> dp(M+1,vector<ld>(1<<M,0.));
    for(int i = 0; i < (1<<M);i++) dp[0][i] = 1.;
    
    for(int i = 1; i <= M;i++){
        int S1 = (1<<i) - 1;
        int S2 = (1<<(i-1)) - 1;
        for(int j = 0; j < (1<<M);j++){
            int battlel = j&(~S1),battler = j|S1;
            int nbattlel = j&(~S2),nbattler = j|S2;
            for(int k = battlel; k <= battler; k++){
                if(nbattlel <= k && k <= nbattler) continue;
                dp[i][j] += dp[i-1][j]*dp[i-1][k]*(S[j]*S[j]/(S[j]*S[j]+S[k]*S[k]));
            }
        }
    }
    res = dp[M][0];
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(12) << solve() << endl;
    return 0;
}
