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
 <url:https://beta.atcoder.jp/contests/code-festival-2018-quala/tasks/code_festival_2018_quala_a>
 問題文============================================================
 =================================================================
 解説=============================================================
 If A+B+C>=S-3&&A+B+C<=S then “Yes” else “No”
 ================================================================
 */

int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    ll A,B,C,S; cin >> A >> B >> C >> S;
    if(A+B+C >= S-3 && A+B+C <= S){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}
