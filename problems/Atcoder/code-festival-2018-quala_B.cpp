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
 <url:https://beta.atcoder.jp/contests/code-festival-2018-quala/tasks/code_festival_2018_quala_b>
 問題文============================================================
 =================================================================
 解説=============================================================
 房がついているみかんの個数を愚直に数え上げてほい
 ================================================================
 */

ll solve(){
    ll res = 0;
    ll N,M,A,B; cin >> N >> M >> A >> B;
    vector<int> L(M),R(M);
    for(int i = 0; i < M;i++) cin >> L[i] >> R[i];
    vector<int> flag(N+1);
    for(int i = 0; i < M;i++){
        for(int j = L[i]; j <= R[i];j++){
            flag[j] = true;
        }
    }
    int cnt = accumulate(flag.begin(), flag.end(), 0);
    res = cnt *A;
    res += (N-cnt)*B;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
