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
 <url:https://abc038.contest.atcoder.jp/tasks/abc038_c>
 問題文============================================================
 N個の数からなる数列が与えられます。i番目の数をaiと呼びましょう。
 
 al,al+1,…,ar が単調増加、すなわち l≦r であって
 ai<ai+1 がl≦i<r を満たす全てのiに対して成り立つような(l,r)の数を求めてください。
 =================================================================
 解説=============================================================
 
 しゃくとりでも良さそうだけど、
 
 区間[l,r]が条件を満たすとき何個条件を満たす区間があるかを計算で楽に求まりそう。
 
 考察を進めると
 [l,r-1] -> [l,r]
 となったとき、
 条件を満たしたとすれば、加算できる区間の個数は r-l+1となる。
 
 よってO(N)で求まる
 
 
 ================================================================
 */

ll solve(){
    ll res = 0;
    ll N; cin >> N;
    vector<ll> a(N);
    for(auto& in:a) cin >> in;
    ll l = 0;
    for(ll r = 0; r < N; r++){
        if(l == r) res++;
        else if(a[r]>a[r-1]) res += (r-l+1);
        else {l = r; res++;} // a[r] <= a[r-1]
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
