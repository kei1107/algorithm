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
<url:https://onlinejudge.u-aizu.ac.jp/services/room.html#RitsCamp18Day1/problems/F>
問題文============================================================

 ごちうさが大好きなAORイカちゃんは「ごちうさ数」を定義した。
 ごちうさ数とは、 10 進表記において「 51?3 」を含む自然数のことである。
 ? は 0 〜 9 のどの数字であってもよい。
 
 N 以下の自然数のうち、ごちうさ数の個数を求めよ。
 
=================================================================

解説=============================================================

 dp[i桁目][下3桁][超えうるか][出現済] で桁dp
 
================================================================
*/

string S;
// dp[i桁目][下3桁][超えうるか][出現済]
ll dp[20][1000][2][2];
ll rec(int idx,int thdigit,bool tight = true,bool ok = false){
    if(idx == S.length()) return ok;
    ll& ret = dp[idx][thdigit][tight][ok];
    if(~ret) return ret;
    ret = 0;
    int x = S[idx] - '0';
    int r = (tight?x:9);
    for(int i = 0; i <= r; i++){
        int next_thdigit = (10*thdigit+i)%1000;
        ret += rec(idx+1,next_thdigit,(tight?!(i<r):tight),ok||((thdigit/10)==51 && i == 3));
    }
    return ret;
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    cin >> S;
    fill(***dp,***dp + 20*1000*2*2,-1);
    cout << rec(0,0) << endl;
	return 0;
}
