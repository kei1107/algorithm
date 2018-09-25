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
 <url:https://atcoder-scores.herokuapp.com/index.html?user=clavis1107>
 問題文============================================================
 =================================================================
 解説=============================================================
 これが200点かー、まぁAGCだしな、、、、
 
 ある連続する部分列が０になるということは
 その連続する部分列の区間を[l,r]とすれば
 
 rまでの総和 - l-1までの総和　= 0
 となる。
 
 よって累積和をとって、同じindex部分が条件を満たすl,rの候補となる
 ================================================================
 */
ll solve(){
    ll res = 0;
    ll N; cin >> N;
    vector<ll> A(N); for(auto& in:A) cin >> in;
    map<ll,ll> mp;
    ll sum = 0;
    mp[sum]++;
    for(auto v:A){ sum+=v; mp[sum]++;}
    for(auto p:mp){
        res += p.second*(p.second-1)/2;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
