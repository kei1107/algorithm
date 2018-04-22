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
 <url:https://yukicoder.me/problems/no/51>
 問題文============================================================
 Thomasのやる気は、簡単に計算できる。
 
 締め切りまでの残りの日数をD日とし、
 残りの作業量をWとすると その日のやる気はWD2となる。
 そして、やる気の小数切り捨ての値が、その日の作業量になる。
 
 Thomasは、最終日にどれだけ作業をしないといけなくなるかが気になっている。
 
 最初の日に与えられた作業量Wと締め切りまでの日数Dが与えられるので
 あなたは、Thomasが最後の日にどれだけの作業量があるか計算してあげてください。

 =================================================================
 解説=============================================================
 計算するだけ
 ================================================================
 */

ll solve(){
    ll res = 0;
    ll W, D; cin >> W >> D;
    for(ll i = D; i > 1; i--){ W -= (W/(i*i)); if(W <= 0) return 0;}
    res = W;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
