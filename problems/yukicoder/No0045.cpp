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
 <url:https://yukicoder.me/problems/no/45>
 問題文============================================================
 あなたは、回転寿司にきている。
 お寿司はN皿が順番に流れてくる。N皿のお寿司のそれぞれの美味しさがViで表される。
 
 流れてくるお寿司が自分の前に来た時に取ることができるが、このお店のルールで、
 連続で皿を取ることが出来ない。
 もちろん、自分の前を過ぎたお寿司も取ることが出来ない。
 
 この時、あなたが得られる美味しさの最大の合計値を求めてください。
 お寿司は一周回ってくることはないとする。
 =================================================================
 解説=============================================================
 
 与えるdp
 
 連続で皿を取ることができないということは
 i番目の皿を取らなければ, i+1番目の皿を取ることができ
 i番目の皿を取れば、i+2番目の皿から取ることができる
 と言い換えることができるa
 
 これを踏まえた上で
 dp[i][j] := i番目の皿を見た時、満足度がjとなっているか否か
 といったdpでO(N*N*V)で解くことができる
 ================================================================
 */

ll solve(){
    ll res = 0;
    ll N; cin >> N;
    vector<ll> V(N); for(auto& in:V) cin >> in;
    vector<vector<int>> dp(N+2,vector<int>(N*100+1,0));
    dp[0][0] = 1;
    for(int i = 0; i < N;i++){
        for(int j = 0; j <= N*100; j++){
            if(dp[i][j] == 0) continue;
            dp[i+1][j] = 1;
            dp[i+2][j+V[i]] = 1;
        }
    }
    for(ll j = N*100; j >= 0; j--){
        if(dp[N][j] | dp[N+1][j]) return res = j;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
