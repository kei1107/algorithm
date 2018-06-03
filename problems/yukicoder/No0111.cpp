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
 <url:https://yukicoder.me/problems/no/111>
 問題文============================================================
 =================================================================
 解説=============================================================
 結局のところこの問題は
 
 全てのaの場所から任意の２箇所を選ぶ個数と
 全てのbの場所から任意の２箇所を選ぶ個数
 を求めよという問題に置き換えることができるため
 
 計算するだけ
 ================================================================
 */

ll solve(){
    ll ret = 0;
    ll L; cin >> L;
    ll cnta = L/2 + 1, cntb = L/2;
    ret += cnta*(cnta-1)/2;
    ret += cntb*(cntb-1)/2;
    return ret;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
