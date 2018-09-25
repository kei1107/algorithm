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
 <url:https://beta.atcoder.jp/contests/arc098/tasks/arc098_a>
 問題文============================================================
 =================================================================
 解説=============================================================
 累積和作って　チャチャっと
 ================================================================
 */
ll solve(){
    ll res = LINF;
    ll N; cin >> N;
    string S; cin >> S;
    vector<vector<ll>> cusum(2,vector<ll>(S.length()+2));
    for(int i = 0; i < S.length();i++){
        cusum[0][i+1] = cusum[0][i] + (S[i]=='W');
        cusum[1][i+1] = cusum[1][i] + (S[i]=='E');
    }
    cusum[0][S.length()+1] = cusum[0][S.length()];
    cusum[1][S.length()+1] = cusum[1][S.length()];
    for(int i = 0; i < S.length();i++){
        res = min(res,cusum[0][i]+(cusum[1][S.length()+1]-cusum[1][i+1]));
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
