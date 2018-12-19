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
 <url:https://atcoder.jp/contests/code-festival-2014-relay/tasks/code_festival_relay_d>
 問題文============================================================
 =================================================================
 解説=============================================================
 駒の位置からXとYがそれぞれ何回動かしたかを確認する。
 互いに同じ数移動させてたら判別不能
 違うのであれば数が多い方が先手
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int n; cin >> n;
    vector<vector<char>> masu(n,vector<char>(n));
    for(auto& vec:masu)for(auto& in:vec) cin >> in;
    ll xcnt = 0,ycnt = 0;
    for(int i = 0; i < n;i++){
        xcnt+=count(masu[i].begin(),masu[i].end(),'X')*i;
        ycnt+=count(masu[i].begin(),masu[i].end(),'Y')*(n-1-i);
    }
    //cout << xcnt << " " << ycnt << endl;
    if(xcnt == ycnt) res = "Impossible";
    else if(xcnt < ycnt){
        res = "Y";
    }else{
        res = "X";
    }
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    //solve<ll>();
    cout << fixed << setprecision(12) << solve<string>() << endl;
    return 0;
}
