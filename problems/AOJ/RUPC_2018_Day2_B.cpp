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
<url:https://onlinejudge.u-aizu.ac.jp/services/room.html#RitsCamp18Day2/problems/B>
問題文============================================================

 非負整数xを2進数表記したときの各桁の和をf(x)とする。
 正整数Nが与えられるのでf(0),f(1),...,f(N)の中で最大のものを出力せよ。
 関数f(5)の計算の例:
 5を2進数表記すると101で各桁の和は1+0+1=2
 よってf(5)=2となる。
 
=================================================================

解説=============================================================

 1を極力建てたい
     => 2^n - 1 は 0..n の全てのbitがたつ
 
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    int N; cin >> N;
    int ans = __builtin_popcount(N);
    int x = 1;
    while(x <= N) x<<=1;
    ans = max(ans,__builtin_popcount(min(x-1,N)));
    x>>=1;
    ans = max(ans,__builtin_popcount(x-1));
    cout << ans << endl;
	return 0;
}
