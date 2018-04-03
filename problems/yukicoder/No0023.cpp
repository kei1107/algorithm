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
 <url:https://yukicoder.me/problems/no/23>
 問題文============================================================
 体力の初期値がHの敵を倒したい。
 敵は体力が0以下になると倒せる。
 攻撃方法は通常攻撃と必殺技の2通りがある。
 通常攻撃は1回の攻撃でAのダメージを与える。
 通常攻撃はかならず当たる。
 必殺技は1回の攻撃でDのダメージを与える。
 ただし、必殺技が当たる確率は2/3である。
 必殺技は1/3の確率でダメージは0である。
 最終的に敵を倒すまでの回数の期待値を
 最小にするように攻撃を選んでいく。
 敵を倒すまでの攻撃数の期待値はいくつか？
 =================================================================
 解説=============================================================
 
 タグにdpってあるけど、、、dp??
 
 通常攻撃及び必殺技を行うタイミングは任意でいいので、
 
 通常攻撃を行うなら最初に一気に通常攻撃を行っておく
 
 よって、 i回通常攻撃を行った時、必殺技での必要回数をjとした時  min(i+j)が答え
 なお、必殺技の攻撃回数は 必要とするダメージ以上のダメージを与えることができる回数*1.5回となる
 ================================================================
 */

double solve(){
    double res = INF;
    ll H,A,D; cin >> H >> A >> D;
    for(int i = 0; i <= (H+A-1)/A;i++){
        if(i*A >= H) {res = min(res,(double)i); break;}
        ll dif = H - i*A;
        res = min(res,(double)i+1.5*((dif+D-1)/D));
    }
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
