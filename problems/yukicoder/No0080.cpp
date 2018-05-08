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
 <url:https://yukicoder.me/problems/no/80>
 問題文============================================================
 A君は四角形を描こうとしています。
 描く四角形は正方形か長方形でなければなりません。
 また、どの辺の長さも整数cmでなければなりません。
 A君の持っている鉛筆はあとちょうどDcmしか線が引けなさそうです。
 A君が描ける最も大きな四角形の面積を答えなさい。
 なお、四角形が描けないときの面積は0とせよ。
 
 =================================================================
 解説=============================================================
 
 (D/2/2)*((D/2+1)/2);
 が答え
 
 ================================================================
 */

ll solve(){
    ll res = 0;
    ll D; cin >> D;
    res = (D/2/2)*((D/2+1)/2);
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
