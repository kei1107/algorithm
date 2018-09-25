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
 <url:https://beta.atcoder.jp/contests/soundhound2018-summer-final-open/tasks/soundhound2018_summer_final_a>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 条件を満たすCDは
 
 140*2^n <= BPM < 170*2^n
 となるCDである。
 
 ここで 170*2^n < 140*2^(n+1) であるので
 nを順番に大きくしていって範囲内にあるCDの個数を数えあげれば良い
 
 ================================================================
 */

ll solve(){
    ll res = 0;
    ll C,D; cin >> C >> D;
    ll l = 140,r = 170;
    while(r < C){
        l<<=1; r<<=1;
    }
    while(l < D){
        res += min(D-1,r-1)-max(C,l)+1;
        l<<=1; r<<=1;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
