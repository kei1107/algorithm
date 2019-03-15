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
 <url:https://codeforces.com/contest/1087/problem/D>
 問題文============================================================
 木が与えられる。
 辺の長さの総和がsとなるという条件のもと、各辺の長さを自由に決めていいとき、
 直径を最小化せよ
 =================================================================
 解説=============================================================
 
 最も簡単で長さを分割できる形はsample1のような形
 すなわち、2*s/葉の数　となる。
 
 実は、全ての木において、頂点を圧縮していくことでこの形に持っていくことができる
 
 よって答えは　2*s/葉の数
 
 ================================================================
 */

typedef long double ld;
template<class Type>
Type solve(Type res = Type()){
    ll n,s; cin >> n >> s;
    vector<pii> edges(n-1);
    for(auto & in:edges){ cin >> in.first >> in.second; in.first--; in.second--; }
    if(n == 2) return s; // コーナーケース

    vector<ll> childs(n);
    for(auto& p:edges){
        childs[p.first]++;
        childs[p.second]++;
    }
    ll cnt = 0;
    for(int i = 0; i < n;i++){
        if(childs[i] == 1) cnt++;
    }
    res = 2.0;
    res *= s;
    res /= cnt;

    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    //solve<ll>(0);
    cout << fixed << setprecision(15) << solve<ld>() << endl;
    return 0;
}
