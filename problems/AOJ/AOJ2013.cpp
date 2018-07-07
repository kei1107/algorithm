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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2013>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 imos法を用いて重複区間の個数を数え上げれば良い
 
 ================================================================
 */

#define Day 2*60*60*24+10
int imos[Day];
int solve(int n){
    int res = 0;
    fill(imos,imos+Day,0);
    for(int i = 0; i < n;i++){
        int h,m,s; char c;
        cin >> h >> c >> m >> c >> s;
        int T = h*3600+60*m+s;
        imos[2*T]++;
        cin >> h >> c >> m >> c >> s;
        T = h*3600+60*m+s;
        imos[2*T]--;
    }
    res = imos[0];
    for(int i = 1; i < Day;i++){
        imos[i] += imos[i-1];
        res = max(res,imos[i]);
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
