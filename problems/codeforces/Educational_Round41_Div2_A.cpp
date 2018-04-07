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
 <url:http://codeforces.com/contest/961/problem/A>
 問題文============================================================
 
 n個の入れ子があって、
 入れ子ciに一個づつ物を入れていく、
 
 n個全てに少なくとも1つ物が存在するようであれば、全ての入れ子から物を一つずつ取り除くことができる

 最大いくつ取り除けるか
 =================================================================
 解説=============================================================
 
 愚直　やるだけ
 
 ================================================================
 */

ll solve(){
    ll res = 0;
    ll n,m; cin >> n >> m;
    vector<ll> c(m);for(auto& in:c) cin >> in;
    vector<int> cnt(n+1,0);
    for(int i = 0; i < m;i++) cnt[c[i]]++;
    return res = *min_element(cnt.begin()+1, cnt.end());
}

int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
