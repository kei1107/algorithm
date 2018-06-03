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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2766>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 まず、大きい桁から順番に 0 -> 1 にできるのであればしたほうがいい、
 指定のハミング距離がそれでも足りないならば 小さい桁から順番に 1 -> 0 にしておけばいい。
 
 ================================================================
 */

string solve() {
    ll N, D;
    string X;  cin >> N >> X >> D;
    string preX = X;
    for (int i = 0; i < (int)X.length(); i++) {
        if (D == 0) break;
        if (preX[i] == '1') continue;
        X[i] = '1';
        D--;
    }
    for (int i = (int)X.length() - 1; i >= 0; i--) {
        if (D == 0)break;
        if (preX[i] == '0') continue;
        X[i] = '0';
        D--;
    }
    return X;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
