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
 <url:https://yukicoder.me/problems/no/8>
 問題文============================================================
 
 あなたとGrantは、いわゆる「21言っちゃダメゲーム（棒取りゲームというところも）」をしている。
 
 あなたが先攻で、このゲームを何度やっても負けてばかりなので、ルールを拡張して
 
 自然数 NとKを使って以下のゲームを考える。
 
 1. まず先攻のプレイヤーは0が与えられる。
 2. そこからN以上を宣言しないように（宣言したら負けになる）与えられた数字の[1,K](1～K)の
    どれかを加算したものを宣言し相手プレイヤーに渡す。
 3. 勝負がつくまで代わり代わりに 2. を繰り返す。
 
 まずあなたが先攻となりゲームを始めます。
 この時、どちらも負けないように動くと考え、自然数N,Kが与えられた時、
 あなたが勝つことが出来る場合 Win、それ以外は Lose を返す。
 
 このとき、N,Kを変えて、P回ゲームを行うことにする。
 それぞれの勝敗を求めてください。
 
 (それっぽいことを知ってる方は簡単ですが、知らない方は難しい考え方が必要かもしれません）
 
 =================================================================
 解説=============================================================
 ================================================================
 */

void solve(){
    ll P; cin >> P;
    while(P--){
        ll N,K; cin >> N >> K;
        if((N-1)%(K+1)==0){
            cout << "Lose" << endl;
        }else{
            cout << "Win" << endl;
        }
    }
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    solve();
    return 0;
}
