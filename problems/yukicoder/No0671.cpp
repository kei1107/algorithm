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
 <url:https://yukicoder.me/problems/no/671>
 問題文============================================================
 A君は1000000007という数を入力しようとしました。
 しかし、A君は間違って'1'と'7'の間の'0'の数を間違って入力してしまいました。
 A君の入力した値Nが与えられるので1000000007と0の数がいくつ異なるかを答えよ。
 
 =================================================================
 解説=============================================================
 
 入力を文字列として、取得して、文字の長さから計算するだけ
 ================================================================
 */
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    string N; cin >> N;
    cout << abs(8 - (int)N.length()+2) << endl;
    return 0;
}
