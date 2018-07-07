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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2773>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 N = kt より
 tを1から順番に見ていってもkが整数になるパターンが少ないことがわかる。
 よって順番に見ていき、条件を満たすかどうか確認すれば良い
 ================================================================
 */

ll solve(){
    ll N; cin >> N;
    ll res = 1;
    vector<ll> S(N); for(auto& in:S) cin >> in;
    for(ll t = 1; t <= N; t++){
        if(N%t != 0) continue;
        ll k = N/t;
        
        bool flag = false;
        for(int i = 0; i < N-t;i++){
            if(S[i] == S[i+t]) continue;
            flag = true;
        }
        if(flag) continue;
        res = k;
        break;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
