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
 <url:https://atcoder.jp/contests/code-festival-2014-relay/tasks/code_festival_relay_f>
 問題文============================================================
 =================================================================
 解説=============================================================
 閉路が一個ある連結なグラフなだけなのでdfsで潜っていって探索済みの頂点を見つければ
 そこが閉路の基準点とできる
 ================================================================
 */

ll rec(ll n,ll dep,ll rev,vector<int>& flag,vector<vector<ll>>& G){
    if(flag[n] != 0){
        return dep-flag[n];
    }
    flag[n] = dep;
    for(auto next:G[n]){
        if(next == rev) continue;
        ll ret =rec(next,dep+1,n,flag,G);
        if(ret == 0) continue;
        return ret;
    }
    return 0;
}
template<class Type>
Type solve(Type res = Type()){
    ll n; cin >> n;
    vector<vector<ll>> G(n);
    for(int i = 0; i < n;i++){
        int x,y; cin >> x >> y;
        x--; y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    vector<int> flag(n);
    res = rec(0,1,-1,flag,G);
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    //solve<ll>();
    cout << fixed << setprecision(12) << solve<ll>() << endl;
    return 0;
}
