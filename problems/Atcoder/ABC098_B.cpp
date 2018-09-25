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
 <url:https://beta.atcoder.jp/contests/abc098/tasks/abc098_b>
 問題文============================================================
 =================================================================
 解説=============================================================
 区切る場所全部試す
 ================================================================
 */
ll solve(){
    ll res = 0;
    map<char,bool> mp1,mp2;
    ll N; cin >> N;
    string S; cin >> S;
    for(int i = 0; i < S.length();i++){
        ll T = 0;
        mp1.clear(); mp2.clear();
        string S1 = S.substr(0,i),S2 = S.substr(i);
        for(auto& c:S1) mp1[c] = true;
        for(auto& c:S2) mp2[c] = true;
        for(char c = 'a'; c <= 'z'; c++)if(mp1[c] && mp2[c]) T++;
        res = max(res,T);
    }
    
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
