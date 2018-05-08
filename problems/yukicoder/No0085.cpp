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
 <url:https://yukicoder.me/problems/no/85>
 問題文============================================================
 yuki君が持っているテレビのリモコンには、ボタンが縦N段、横M列の長方形状に計N×M個並んでいる。
 リモコンのX段目Y列目のボタンを押すと、テレビでチャンネル((X−1)×M+Y)を見ることができる。
 （サンプルケース1の解説に具体例が記載されている）
 
 yuki君はさっきチャンネルCのボタンを押し、そのままチャンネルCを見ている。
 ところがyuki君は途中で他のチャンネルの内容を一通り見てみたくなった。
 yuki君は素早く全チャンネルを巡回して元のチャンネルCに戻るため、以下のルールで順にボタンを押す。
 
 最初に押すボタンは、さっき押したチャンネルCのボタンと上下左右いずれかに隣接したボタンである。
 以降、直前に押したボタンと上下左右いずれかに隣接したボタンを押していく。
 チャンネルC以外の全てのチャンネルのボタンをちょうど1回ずつ押した上で、最後にまたチャンネルCのボタンを押す。
 
 N, M, Cが与えられたとき、上記ルールをすべて満たすボタンの押し順が存在するか答えよ。
 =================================================================
 解説=============================================================
 
 N,M のどちらかが1の時、もう片方が2以外の時は不可能
 
 N,Mが共に1でない時、どちらかが偶数ならば可能
 ================================================================
 */

string solve(){
    ll N,M,C; cin >> N >> M >> C;
    if((N == 1 && M == 2)||(N == 2 && M == 1)) return "YES";
    if(N == 1 || M == 1 ) return "NO";
    if(N%2 == 0 || M%2 == 0) return "YES";
    return "NO";
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
