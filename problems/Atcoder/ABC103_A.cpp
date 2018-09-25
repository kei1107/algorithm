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
 <url:https://beta.atcoder.jp/contests/abc103/tasks/abc103_a>
 問題文============================================================
 =================================================================
 解説=============================================================
 ソートして順番に選択して行けば良い
 ================================================================
 */
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    vector<ll> A(3); for(auto& in:A) cin >> in;
    sort(A.begin(),A.end());
    ll ans = 0;
    for(int i = 0; i < 2;i++){
        ans += A[i+1] - A[i];
    }
    cout << ans << endl;
    return 0;
}
