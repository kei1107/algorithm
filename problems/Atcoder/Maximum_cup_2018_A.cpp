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
 <url:https://beta.atcoder.jp/contests/maximum-cup-2018/tasks/maximum_cup_2018_a>
 問題文============================================================
 実況「素晴らしい！フィギュアスケート界に彗星の如く現れた埼大選手、魅せました！この演技どうご覧になりましたか？」
 
 解説「えーそうですね。ミスらしいミスもなく、技の完成度も高かったので、かなりの高得点を期待できます。」
 
 実況「そんな埼大選手ですが、彼はファンサービスにも一流のこだわりを持つことで知られていまして、
 滑走後の挨拶中は以下の動作を行います。」
 
 1つあるゲートから滑り始め、1周5000mのスケートリングを丁度時計回りに1周してゲートから退場し、
 キス&クライに向かいます。
 
 常に寸分狂わず 1 m/s の速さで滑ります。
 滑っている場所に落ちているぬいぐるみを全部自分で拾っていきます。
 滑っている場所にちょうど投げ入れられたぬいぐるみもキャッチしていきます。
 実況「また、観客も訓練されていまして、以下のように洗練されたぬいぐるみの投げ入れを行います。」
 
 埼大選手が挨拶周りを開始してから、リストに書いた指定時刻の10秒後にぴったり指定した位置に届くように、
 ぬいぐるみを投げ込みます。
 解説「このぬいぐるみは大きさが無視できる程度に小さいので、
 同じ場所に複数のぬいぐるみが落ちていることがあるようですね。
 また、埼大選手はスピードを緩めることなく、いくつでもぬいぐるみを拾う事ができます。すごいですよね。」
 
 実況「それはすごい。さあ埼大選手、いくつのぬいぐるみを拾うのでしょうか！」
 =================================================================
 解説=============================================================
 
 単純に t+10 <= d であれば m個拾える
 
 ================================================================
 */

ll solve(){
    ll res = 0;
    ll N; cin >> N;
    vector<ll> t(N),d(N),m(N);
    for(int i = 0;i < N;i++) cin >> t[i] >> d[i] >> m[i];
    for(int i = 0; i < N; i++){
        if(t[i]+10 <= d[i]) res += m[i];
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
