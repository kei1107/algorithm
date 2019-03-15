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
 <url:https://atcoder.jp/contests/abc112/tasks/abc112_d>
 問題文============================================================
 =================================================================
 解説=============================================================
 嘘解法
 
 ある公約数をDとすると
 
 a1..a_(N-1)まで全部Dとしてしまった時、
 M-D*(N-1)がDの倍数となっていけば、公約数Dがその時の最大公約数となる。
 
 よって、Dを1..Mまで貪欲に確認していけばいい。
 ここで、N=1で時などはTLEする可能性があるのでN=1の時例外処理する。
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    ll N,M; cin >> N >> M;
    if(N == 1) return M;
    for(ll i = 1; i*N <= M;i++){
        if((M-i*(N-1))%i==0) res = i;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
