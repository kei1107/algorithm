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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1587 >
 問題文============================================================
 =================================================================
 解説=============================================================
 やるだけ
 ================================================================
 */
ll solve(){
    ll res = 0;
    ll W,H,T; cin >> W >> H >> T;
    ll p; cin >> p;
    vector<pll> query(p);
    for(int i = 0; i < p;i++){
        cin >> query[i].first >> query[i].second;
        ll t; cin >> t;
    }
    vector<vector<ll>> s(H,vector<ll>(W));
    for(auto& vec:s) for(auto& in:vec) cin  >>in;
    
    vector<vector<ll>> plant(H,vector<ll>(W,0));
    for(int i = 0; i < p;i++){
        if(s[query[i].second][query[i].first]){
            plant[query[i].second][query[i].first]++;
        }
    }
    for(auto& vec:plant) res += accumulate(vec.begin(),vec.end(),0LL);
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
