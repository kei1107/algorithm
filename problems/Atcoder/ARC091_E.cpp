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
 <url:https://beta.atcoder.jp/contests/arc091/tasks/arc091_c>
 問題文============================================================
 =================================================================
 解説=============================================================
 見た　http://kmjp.hatenablog.jp/entry/2018/03/11/1100
 
 構築ゲー嫌い
 ================================================================
 */

vector<ll> solve(){
    ll N,A,B; cin >> N >> A >> B;
    if(A + B > N + 1) return vector<ll>{-1};
    if(A*B < N) return vector<ll>{-1};
    vector<ll> res;
    ll tA = N - A;
    ll now = N;
    for(int i = 0; i < A;i++){
        ll num = min(B-1,tA)+1;
        tA -= num - 1;
        for(int j = 0; j < num;j++) res.push_back(now-num+1+j);
        now -= num;
    }
    reverse(res.begin(),res.end());
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
