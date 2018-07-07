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
 <url:https://agc025.contest.atcoder.jp/tasks/agc025_a>
 問題文============================================================
 =================================================================
 解説=============================================================
 Aを決め打ちして、愚直探索
 ================================================================
 */
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    ll N; cin >> N;
    ll ans = LINF;
    for(ll A = 1; A < N; A++){
        ll B = N - A;
        string sA = to_string(A);
        string sB = to_string(B);
        ll sum = 0;
        for(char c:sA) sum += c-'0';
        for(char c:sB) sum += c-'0';
        ans = min(ans,sum);
    }
    cout << ans << endl;
    return 0;
}
