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
 <url:https://beta.atcoder.jp/contests/abc100/tasks/abc100_d>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 x,y,zをそれぞれ、正・負の方向へ最大化する全8パターンを全て試せば良い
 
 ================================================================
 */

ll solve(){
    ll res = -LINF;
    ll N,M; cin >> N >> M;
    vector<ll> x(N),y(N),z(N);
    for(int i = 0; i < N;i++) cin >> x[i] >> y[i] >> z[i];
    vector<ll> val(N);
    for(int i = 0; i < 8;i++){
        for(int j = 0; j < N;j++){
            val[j] = 0;
            val[j] += (i&1?-1:1)*x[j];
            val[j] += (i&2?-1:1)*y[j];
            val[j] += (i&4?-1:1)*z[j];
        }
        sort(val.rbegin(),val.rend());
        res = max(res,accumulate(val.begin(),val.begin()+M,0LL));
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
