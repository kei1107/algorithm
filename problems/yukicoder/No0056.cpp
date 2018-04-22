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
 <url:https://yukicoder.me/problems/no/56>
 問題文============================================================
 ある国の通貨単位は「ユキコダ」である。
 いまからDユキコダの品物を買おうとしている？
 しかし、品物の金額に対して消費税率P%の消費税が加算される。
 実際に支払う金額はいくらか？
 ただし、小数点以下は切り捨てします。
 
 =================================================================
 解説=============================================================
 計算するだけ
 ================================================================
 */

ll solve(){
    double D,P; cin >> D >> P;
    return (ll)(D+D/100*P);
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << fixed << solve() << endl;
    return 0;
}
