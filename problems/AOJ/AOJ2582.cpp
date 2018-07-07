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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2582&lang=jp>
 問題文============================================================
 =================================================================
 解説=============================================================
 シミュレーション
 ================================================================
 */

int solve(int n){
    int res = 0;
    vector<string> f(n); for(auto& in:f) cin >> in;
    bool target = true;
    bool l = false,r = false;
    for(int i = 0; i < n;i++){
        if(f[i] == "lu"){
            l = true;
        }
        if(f[i] == "ru"){
            r = true;
        }
        if(f[i] == "ld"){
            l = false;
        }
        if(f[i] == "rd"){
            r = false;
        }
        if(target == l && target == r){
            target = !target;
            res++;
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    int n;
    while(cin >> n,n){
        cout << solve(n) << endl;
    }
    return 0;
}
