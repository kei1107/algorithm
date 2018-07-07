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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2012&lang=jp>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 x+y*y+z*z*z = e
x = e - y*y - z*z*z >= 0
 
 yとzを決め打ちすれば間に合う
 ================================================================
 */

ll solve(ll e){
    ll res = LINF;
    for(ll y = 0; y*y <= e; y++){
        for(ll z = 0; z*z*z <= e; z++){
            ll x = e - y*y - z*z*z;
            if(x >= 0) res = min(res,x+y+z);
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    int e;
    while(cin >> e,e){
        cout << solve(e) << endl;
    }
    return 0;
}
