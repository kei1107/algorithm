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
<url:https://soundhound2018.contest.atcoder.jp/tasks/soundhound2018_d>
問題文============================================================

 kenkooooさんはSoundHound社で働いています。
 建物は H 階建てで、1 つのフロアは W 個の東西に直線上につながった部屋からなります。
 上から i 番目の階の、西から j 番目の部屋を部屋 (i,j) と呼ぶことにします。
 
 いま、kenkooooさんは部屋 (1,1) にいます。kenkooooさんは以下の動作を繰り返すことで、
 地上階(上から H 番目の階)の部屋から建物を出ることにしました:
 
 部屋 (i,j) にいるとき、存在するなら部屋 (i,j−1)に移動する。
 部屋 (i,j) にいるとき、存在するなら部屋 (i,j+1)に移動する。
 部屋 (i,j) にいるとき、存在するなら部屋 (i+1,j)に移動する。
 
 ただし、地上階にたどり着いてからも移動をしてもかまいません。
 
 さらに、部屋 (i,j) には Pi,j 円が落ちており、その部屋に初めて入るときkenkooooさんはこれを拾います。
 
 一方で、部屋 (i,j) に入るたびに、入室料として Fi,j 円を払う必要があります。
 
 kenkooooさんはすでに十分大きい金額を今持っているため、途中で手持ちのお金がなくなってしまうことはありません。
 部屋 (H,j) から建物を出るとき、この建物で最大いくら得ることができるかをすべての 1≦j≦W について求めてください。
 
=================================================================

解説=============================================================

 dp(H+2,vector<ll>(W+2,-LINF)),  // (i,j)の時の最大値
 dpl(H+2,vector<ll>(W+2,-LINF)), // 左から右に遷移した時の最大
 dpr(H+2,vector<ll>(W+2,-LINF)), // 右から左に       ""
 L(H+2,vector<ll>(W+2,-LINF)), // [1,i)の範囲で得られるお金の最大
 R(H+2,vector<ll>(W+2,-LINF)); // (1,W]    ""
 
 地点 SからTへ向かうとき
    S < T であれば
        S -> (左　→) 右　→ T (→ 右　-> 左　→ T)
 
    S > T であれば
        その逆
 といったルートが考えられる
 
 まず、独立に、 [1,S) ,(S,W] までで得られるお金の最大値を取得する。
 その後 これらを用いて　考えられるルートを用いた時の最大値をdpを用いて計算する
 
 
================================================================
*/

ll solve(){
    ll res = -LINF;
    int H,W; cin >> H >> W;
    vector<vector<ll>> P(H+2,vector<ll>(W+2,0)),F(H+2,vector<ll>(W+2,0));
    for(int i = 1; i <= H; i++) for(int j = 1; j <= W; j++) cin >> P[i][j];
    for(int i = 1; i <= H; i++) for(int j = 1; j <= W; j++) cin >> F[i][j];
    
    vector<vector<ll>>  dp(H+2,vector<ll>(W+2,-LINF)),  // (i,j)の時の最大値
                        dpl(H+2,vector<ll>(W+2,-LINF)), // 左から右に遷移した時の最大
                        dpr(H+2,vector<ll>(W+2,-LINF)), // 右から左に       ""
                        L(H+2,vector<ll>(W+2,-LINF)), // [1,i)の範囲で得られるお金の最大
                        R(H+2,vector<ll>(W+2,-LINF)); // (1,W]    ""

    dp[1][1] = 0;
    for(int i = 1; i <= H;i++){
        L[i][1] = 0;
        for(int j = 2; j <= W; j++){
            L[i][j] = max({P[i][j-1]-F[i][j-1],L[i][j-1]+P[i][j-1]-2*F[i][j-1]});
        }
        //cout << "l : " << dpl[i] << endl;
        
        R[i][W] = 0;
        for(int j = W-1; j >= 1; j--){
            R[i][j] = max({P[i][j+1]-F[i][j+1],R[i][j+1]+P[i][j+1]-2*F[i][j+1]});
        }
        //cout << "r : " << dpr[i] << endl;
        
        ll Max = -LINF;
        for(int j = 1; j <= W; j++){
            Max = max({Max+P[i][j]-F[i][j],dp[i][j]+L[i][j]+P[i][j]-2*F[i][j],dp[i][j]+P[i][j]-F[i][j]});
            dpl[i][j] = max(Max,Max+R[i][j]-F[i][j]);
        }
        
        Max = -LINF;
        for(int j = W; j >= 1; j--){
            Max = max({Max+P[i][j]-F[i][j],dp[i][j]+R[i][j]+P[i][j]-2*F[i][j],dp[i][j]+P[i][j]-F[i][j]});
            dpr[i][j] = max(Max,Max+L[i][j]-F[i][j]);
        }
        for(int j = 1; j <= W;j++){
            dp[i+1][j] = max({dpl[i][j],dpr[i][j]});
        }
    }
    for(int i = 1; i <= W;i++){ cout << dp[H+1][i] << endl; }
    return res;
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    solve();
	return 0;
}
