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
 <url:https://yukicoder.me/problems/no/83>
 問題文============================================================
 あなたは「最大マッチング問題」という有名問題に取り組んでいる。
 これは、何本かのマッチ棒が与えられたとき、それらを並べて表記できる最大の数を求める問題である。
 
 数の表記は、0 から 9 までの数字を横に並べることによって行う。
 
 数字の表記法は下図の通りである。
 (略)
 
 マッチ棒は折ってはいけないが、すべて使い切る必要はない。
 さて、N 本のマッチ棒が与えられたとき、それらを並べて表記できる最大の数を求めよ。
 =================================================================
 解説=============================================================
 
 表現できる数字とマッチの本数の関係から
 奇数なら 7111111...
 偶数なら 1111111...
 
 とするのが最適

 ================================================================
 */

string solve(){
    string res;
    ll N; cin >> N;
    if(N&1) { res += '7'; N-=3;}
    res += string(N/2,'1');
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
