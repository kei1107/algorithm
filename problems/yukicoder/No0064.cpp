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
 <url:https://yukicoder.me/problems/no/64>
 問題文============================================================
 整数列 {Fk} を次の漸化式で定義する。
 
 Fk=Fk−1⊕Fk−2(k≥2)
 
 ただし、⊕ はビット XOR の記号である。
 F0,F1 が与えられたとき、FN を計算せよ。
 =================================================================
 解説=============================================================
 
 xorの性質より
 
 a^b = c
 c^b = a
 
 となる。
 
 今回の場合
 F0^F1 = F2
 F1^F2 = F2^F1 = F3 = F0
 F2^F3 = F0^F2 = F1
 
 となり、周期３で同一の値が繰り返される
 ================================================================
 */

ll solve(){
    ll res = 0;
    ll F[3],N; cin >> F[0] >> F[1] >> N;
    F[2] = F[0]^F[1];
    res = F[N%3];
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
