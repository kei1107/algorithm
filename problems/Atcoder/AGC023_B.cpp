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
 <url:https://beta.atcoder.jp/contests/agc023/tasks/agc023_b>
 問題文============================================================
 =================================================================
 解説=============================================================
 愚直に考えると O(N^4)となって間に合わない。
 
 しかし、 あるA,Bを定めた時、A+1,B+1も同値となることに気づけば
 O(N^3)で判定できる
 ================================================================
 */

ll solve(){
    ll res = 0;
    ll N; cin >> N;
    vector<vector<char>> S(N,vector<char>(N));
    for(auto& vec:S) for(auto& in:vec) cin >> in;
    for(int B = 0; B < N;B++){
        bool ok = true;
        for(int i = 0; i < N;i++){
            for(int j = 0; j < N;j++){
                if(S[i][(j+B)%N] == S[j][(i+B)%N]) continue;
                ok = false;
            }
        }
        if(ok) res += N;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
