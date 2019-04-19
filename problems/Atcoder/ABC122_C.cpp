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
 <url:https://atcoder.jp/contests/abc122/tasks/abc122_c>
 問題文============================================================
 =================================================================
 解説=============================================================
 累積和の要領でACが現れる境界で配列をインクリメントしていき、
 クエリの差分を取る
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    ll N,Q; cin >> N >> Q;
    string S; cin >> S;
    vector<ll> cusum(S.length()+1);
    for(int i = 1; i < S.length();i++){
        cusum[i] = cusum[i-1];
        if(S[i]=='C' && S[i-1]=='A') cusum[i]++;
    }
    for(int i = 0; i < Q;i++){
        int l,r; cin >> l >> r;
        l--; r--;
        cout << cusum[r] - cusum[l] << endl;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve(0);
    //cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
