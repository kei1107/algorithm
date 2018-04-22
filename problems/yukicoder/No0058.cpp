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
 <url:https://yukicoder.me/problems/no/58>
 問題文============================================================
 太郎君と二郎君はサイコロで勝負することになりました。
 
 太郎君と二郎君は、お互いにN個のサイコロを持ち、一斉に転がします。
 そして、出た目の合計が大きいほうが勝ち、また、合計が等しければ引き分けという取り決めになっています。
 
 ところが太郎君は卑怯にも、イカサマなサイコロを使ってしまいます。
 
 普通のサイコロは、立方体の6面に1から6までの目が刻印されていますが、
 イカサマなサイコロは、立方体の6面に4から6までの目が2つずつ刻印されており、
 1から3の目は絶対に出ません。
 
 二郎君はN個の普通のサイコロを使用しますが、
 太郎君はN個のサイコロのうちK個に、このイカサマなサイコロを使用し、
 (N−K)個は普通のサイコロを使用します。
 
 普通のサイコロもイカサマなサイコロも、6面のうちどの面が出るかは均等であるとしたとき、
 太郎君が「勝つ」確率を求めてください。
 
 (誤差制約にも注意してください。）
 =================================================================
 解説=============================================================
 
 太郎君と次郎君のサイコロのある合計値が出る確率をdpで求めておく。
 その後、合計値に関して総当たりで勝つ確率を計算する
 ================================================================
 */

double solve(){
    double res = 0;
    ll N,K; cin >> N >> K;
    double dp[2][11][61] = {0};
    dp[0][0][0] = dp[1][0][0] = 1;
    
    // dp[0]
    for(int i = 0; i < N;i++){
        for(int j = 0; j <= 60;j++){
            for(int k = 1; k <= 6;k++){
                dp[0][i+1][j+k] += dp[0][i][j]/6.;
            }
        }
    }
    
    // dp[1]
    for(int i = 0; i < N;i++){
        for(int j = 0; j <= 60;j++){
            if(i < K){
                for(int k = 4; k <= 6;k++){
                    dp[1][i+1][j+k] += dp[1][i][j]/3.;
                }
            }else{
                for(int k = 1; k <= 6;k++){
                    dp[1][i+1][j+k] += dp[1][i][j]/6.;
                }
            }
        }
    }
    
    for(int i = 1; i <= 60; i++){
        for(int j = 0; j < i; j++){
            res += dp[0][N][j]*dp[1][N][i];
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << fixed << solve() << endl;
    return 0;
}
