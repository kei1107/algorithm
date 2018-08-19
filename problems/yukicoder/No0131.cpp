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
 <url:https://yukicoder.me/problems/no/131>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 条件より
 格子点候補(X,Y)の範囲は
 0 <= X <= x
 0 <= Y <= y
 X + Y = d
 
 よって Y = d - X と 0 <= Y <= y より
 
 max(0,d-X) <= Y <= min(Y,d)
 の範囲内の整数が答え
 ただし、この不等号を満たさない場合は 0個
 ================================================================
 */

ll solve(){
    ll res = 0;
    ll x,y,d; cin >> x >> y >> d;
    res = min(y,d) - max(0LL,d-x) + 1;
    res = max(res,0LL);
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
