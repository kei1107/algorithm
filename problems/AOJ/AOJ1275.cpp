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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1275>
 問題文============================================================
 ヨセフスの問題を解け
 =================================================================
 解説=============================================================
 https://ja.wikipedia.org/wiki/%E3%83%A8%E3%82%BB%E3%83%95%E3%82%B9%E3%81%AE%E5%95%8F%E9%A1%8C
 wikiの数式通りに書けば良い
 ================================================================
 */

int n,k,m;
int rec(int N){
    if(N == 1) return 0;
    return (rec(N-1)+k)%N;
}
int solve(){
    int res = (rec(n-1)+m)%n + 1;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    while(cin >> n >> k >> m,n){
        cout << solve() << endl;
    }
    return 0;
}
