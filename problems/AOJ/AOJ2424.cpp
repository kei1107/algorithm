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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2424>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 愚直シミュレーション
 無限回実行する場合は値がループするときであるため、これまで出てきた値を保持しておけば良い
 ================================================================
 */

ll check(ll N){
    ll ret = -1;
    ll base = 10;
    for(;;base*=10){
        if(N%base == N) break;
        ret = max(ret,(N/base)*(N%base));
    }
    return ret;
}
ll solve(){
    ll res = 0;
    ll N; cin >> N;
    map<ll,bool> mp;
    while(true){
        if(N%10 == N) break;
        if(mp[N]){ res = -1; break; }
        N = check(N);
        res++;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    int Q; cin >> Q;
    while(Q--){
        cout << solve() << endl;
    }
    return 0;
}
