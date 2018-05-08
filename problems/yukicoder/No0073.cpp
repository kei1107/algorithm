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
 <url:https://yukicoder.me/problems/no/73>
 問題文============================================================
 A君は、helloworldを愛してやまない． 文字列Sのhelloworld数を次を満たす組(i0,⋯,i9)の個数とする．
 
 S[i0]S[i1]⋯S[i9]="helloworld"
 i0<i1<⋯<i9 アルファベットの個数が与えられるので、
 それぞれのアルファベットをちょうどその個数だけ使ってできる文字列におけるhelloworld数の最大値を求めよ．
 =================================================================
 解説=============================================================
 
 helloworldのうち
 
 h,e,w,r,dは１個しかないので、連続して並べるのが最適
 
 oに関しては二個あるが、個数を半分ずつ連続して配置するのが最適
 
 lに関しては細かく計算ができないので、 hell~lloworlll~llld
 と行った形のどれが最大となるのかをその場で計算しておく
 ================================================================
 */

ll calcl(ll lc){
    if(lc <= 2) return 0;
    ll ret = 0;
    for(int l = 1; l <= lc-2;l++){
        ll n = lc - l;
        ret = max(ret,l*(n*(n-1)/2));
    }
    return ret;
}
ll calco(ll oc){
    if(oc <= 1) return 0;
    ll ret = 0;
    
    return ret;
}
ll solve(){
    ll res = 1;
    vector<ll> C(26); for(auto& in:C) cin >> in;
    res *= C['h'-'a'];
    res *= C['e'-'a'];
    res *= calcl(C['l'-'a']);
    res *= (C['o'-'a']/2)*(C['o'-'a']-C['o'-'a']/2);
    res *= C['w'-'a'];
    res *= C['r'-'a'];
    res *= C['d'-'a'];
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
