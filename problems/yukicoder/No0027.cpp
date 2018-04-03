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
 <url:https://yukicoder.me/problems/no/27>
 問題文============================================================
 異なる3種類の長さA、B、Cの板を無数に用意できる。
 A、B、Cは整数の値で自由に決めて良い。
 板と板はつなげて伸ばすことができる。
 指定されたV0、V1、V2、V3の長さの板を作りたい。
 最低何枚の板が必要か？
 
 指定された板の長さが4つ（V0,V1,V2,V3）与えられます。
 1<=V0,V1,V2,V3<=30の整数であり、Vi=Vj (0<=i,j<=3)となる場合もあります。
 
 =================================================================
 解説=============================================================
 
 N := 30
 
 A,B,Cの組み合わせは N^3通り
 
 各組み合わせについて、dp[i] := 長さiとなるのに必要な板の最低枚数 とすれば
 O(N)で求まる
 
 よって O(N^4)ではい
 
 ================================================================
 */

ll solve(){
    int res = INF;
    int V[4];
    vector<int> dp(100,int(1e5));
    for(int i = 0; i < 4;i++) cin >> V[i];
    for(int i = 1; i <= 30;i++){
        for(int j = i + 1; j <= 30; j++){
            for(int k = j + 1; k <= 30;k++){
                fill(dp.begin(),dp.end(),int(1e5));
                dp[0] = 0;
                for(int l = 0; l < 30; l++){
                    if(dp[l] == int(1e5)) continue;
                    dp[l+i] = min(dp[l+i],dp[l]+1);
                    dp[l+j] = min(dp[l+j],dp[l]+1);
                    dp[l+k] = min(dp[l+k],dp[l]+1);
                }
                res = min(res,dp[V[0]]+dp[V[1]]+dp[V[2]]+dp[V[3]]);
            }
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
