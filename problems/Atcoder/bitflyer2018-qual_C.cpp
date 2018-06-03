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
 <url:https://beta.atcoder.jp/contests/bitflyer2018-qual/tasks/bitflyer2018_qual_c>
 問題文============================================================
 =================================================================
 解説=============================================================
 これ400点？？？
 
 i<j<kのjを決め打ちで左側にD以内の個数×右側にD以内の個数でいったん徒歩徒歩の組み合わせをもとめてから，
 今度はiを決め打ちで距離D以内の点から2つ（j,k)を選ぶ組み合わせを求めて引けば良い
 ================================================================
 */

ll solve(){
    ll N,D; cin >> N >> D;
    vector<ll> X(N); for(auto& in:X) cin >> in;
    ll res = 0;
    for(int j = 1; j < N-1;j++){
        auto l = (ll)(lower_bound(X.begin(), X.end(), X[j]-D) - X.begin());
        auto r = (ll)(upper_bound(X.begin(),X.end(),X[j]+D) - X.begin());
        ll lcnt = j - l;
        ll rcnt = r - j - 1;
        res += lcnt*rcnt;
    }
    for(int i = 0; i < N;i++){
        auto it = (ll)(upper_bound(X.begin(),X.end(),X[i]+D) - X.begin());
        ll cnt = it - i - 1;
        res -= (cnt*(cnt-1)/2);
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
