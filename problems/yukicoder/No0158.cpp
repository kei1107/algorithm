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
 <url:https://yukicoder.me/problems/no/158>
 問題文============================================================
 =================================================================
 解説=============================================================
 なんか無理くりごり押したら通ってしまった。
 
 なんとなくdpっぽいのでdpを考える。
 まず、支払う時の最適な支払いを考える
 結論から言うと、支払いの優先度は 1000円札 > 100円玉 > 1円玉
 の順に使っていくといい。
 なぜならば、100円玉は1000円分にもなれるし、1円玉は100円にも1000円にもなれるから。
 
 ここで、次繊維が固定されるので
 dp[i][j][k] := 1000円がi枚,100円がj個,1円がk個持っている時の最大お使い回数
 でdpを考えることができる。
 が、これは罠でサンプル4のような支払い後の状態が増加するパターンに対応できない。
 
 ここで、なんとなく、そもそも状態が増加するパターンが利用できる場合って少ないんじゃね？
 と思いつく
 そこで、dpのループの外側にさらに時間ギリギリぐらい回せる範囲のもう一個のループを追加したら通った
 ================================================================
 */

ll dp[11][101][10001];

tuple<int,int,int> can_pay(int i,int j,int k,int D){
    int t;
    
    t = min(i,D/1000);
    i -= t; D -= t*1000;
    
    t = min(j,D/100);
    j -= t; D -= t*100;
    
    t = min(k,D);
    k -= t; D -= t;
    if(D) return tuple<int,int,int>{-1,-1,-1};
    return tuple<int,int,int>{i,j,k};
}
ll solve(){
    fill(**dp,**dp+11*101*10001,-1);
    ll res = 0;
    vector<ll> A(3),B(3),C(3);
    int Db,Dc;
    for(auto& in:A) cin >> in;
    cin >> Db;
    for(auto& in:B) cin >> in;
    cin >> Dc;
    for(auto& in:C) cin >> in;
    
    dp[A[0]][A[1]][A[2]] = 0;
    for(int kassa = 0; kassa < 100; kassa++){
   
        for(int i = 10; i >= 0; i--){
            for(int j = 100; j >= 0; j--){
                for(int k = 10000; k >= 0; k--){
                    if(dp[i][j][k] == -1) continue;
                    {
                        int ni,nj,nk; tie(ni,nj,nk) = can_pay(i, j, k, Db);
                        if(ni != -1){
                            dp[ni+B[0]][nj+B[1]][nk+B[2]] = max(dp[ni+B[0]][nj+B[1]][nk+B[2]],dp[i][j][k]+1);
                        }
                    }
                    {
                        int ni,nj,nk; tie(ni,nj,nk) = can_pay(i, j, k, Dc);
                        if(ni != -1){
                            dp[ni+C[0]][nj+C[1]][nk+C[2]] = max(dp[ni+C[0]][nj+C[1]][nk+C[2]],dp[i][j][k]+1);
                        }
                    }
                }
            }
        }
    }
    for(int i = 10; i >= 0; i--){
        for(int j = 100; j >= 0; j--){
            for(int k = 10000; k >= 0; k--){
                res = max(res,dp[i][j][k]);
            }
        }
    }
    
    
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
