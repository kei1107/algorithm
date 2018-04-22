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
 <url:https://yukicoder.me/problems/no/37>
 問題文============================================================
 Raymondは、遊園地に遊びに来ている。
 遊園地の滞在時間はT時間で、各アトラクションの満足度が i番目のアトラクションに乗ったら、満足度Viが得られる。
 
 しかし、遊園地は、どのアトラクションも行列であり、なかなか乗ることが出来ない。
 i番目のアトラクションの行列は、ci時間並ぶことでアトラクションに乗れるとする。
 (アトラクション自体の時間は行列の時間に含まれているとする）
 
 しかし、Raymondは同じアトラクションにはあまり乗りたくない。
 滞在時間中に同じアトラクションに乗った場合は、 満足度は「Viの半分小数切り捨て」しか得られず、その値を新たなViとする。
 それ以降、また同じアトラクションに乗るたびに半減していく。
 
 滞在時間の T時間の間に得られる最大の満足度を得たいとするとき、 その得られる満足度を求めてください。
 
 =================================================================
 解説=============================================================
 
 dp[i][j] := i番目のアトラクションを見たとき、残り時間がjであるときの最大満足度
 
 cが最大100までしかないので同じアトラクションには高々7回程度しか乗らなくて良いことがわかる
 よって、O(NT)で計算できる。
 ================================================================
 */

#define MAX_N 16
#define MAX_T 10010
ll dp[MAX_N][MAX_T];
ll solve(){
    ll res = 0;
    ll T,N; cin >> T >> N;
    vector<ll> c(N),v(N);
    for(auto& in:c) cin >> in;
    for(auto& in:v) cin >> in;
    for(int i = 0; i < N;i++){
        for(int j = 0; j <= T; j++){
            ll nowv = 0;
            ll divv = v[i];
            for(int k = 0; k < 10;k++){
                if(j-c[i]*k < 0) break;
                dp[i+1][j-c[i]*k] = max(dp[i+1][j-c[i]*k],dp[i][j]+nowv);
                nowv += divv;
                divv >>= 1;
            }
        }
    }
    res = dp[N][0];
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
