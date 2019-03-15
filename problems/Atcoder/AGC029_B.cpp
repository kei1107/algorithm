#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

/*
 <url:https://beta.atcoder.jp/contests/agc029/tasks/agc029_b>
 問題文============================================================
 =================================================================
 解説=============================================================
 大きい値から見ていくとき、2^tとなる値はその値より大きい2^tとなる値になると
 一意に定まる。
 よって大きい値から貪欲に見ていけばいい
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int N; cin >> N;
    vector<ll> A(N); for(auto& in:A) cin >> in;
    sort(A.begin(),A.end());
    map<ll,ll> mp; for(auto a:A) mp[a]++;
    for(int i = N-1;i>=0;i--){
        if(mp[A[i]]==0) continue;
        ll v = 1; while(v <= A[i]) v *= 2;
        ll r = v-A[i];
        mp[A[i]]--;
        if(mp[r]==0) continue;
        mp[r]--;
        res++;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
