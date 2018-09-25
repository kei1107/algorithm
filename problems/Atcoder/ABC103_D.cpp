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
 <url:https://beta.atcoder.jp/contests/abc103/tasks/abc103_d>
 問題文============================================================
 =================================================================
 解説=============================================================
 こういった、[l,r]の区間スケジューリングみたいなやつはrでソートして愚直にとって
 いくのが正解
 ================================================================
 */

ll solve(){
    ll res = 0;
    ll N,M; cin >> N >> M;
    vector<pll> ab(M); for(auto& in:ab) cin >> in.first >> in.second;
    sort(ab.begin(),ab.end(),[](const pll& o1,const pll& o2){return o1.second < o2.second; });
    ll l = 0;
    for(int i = 0; i < M;i++){
        if(ab[i].first >= l){
            res++;
            l = ab[i].second;
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
