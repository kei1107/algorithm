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
 <url:https://atcoder.jp/contests/dp/tasks/dp_g>
 問題文============================================================
 =================================================================
 解説=============================================================
 Gが有向閉路を含みまない、という条件から
 mamo[i]:=iから始めた時の最長経路
 といったメモ化再帰ができる
 ================================================================
 */

int memo[100005];
vector<int> G[100005];

int rec(int n){
    int& ret = memo[n];
    if(~ret) return ret;
    ret = 0;
    for(const int& next:G[n]){
        ret = max(ret,rec(next)+1);
    }
    return ret;
}
template<class Type>
Type solve(Type res = Type()){
    int N,M; cin >> N >> M;
    for(int i = 0; i < M;i++){
        int x,y; cin >> x >> y;
        x--; y--;
        G[x].push_back(y);
    }
    fill(memo,memo+N,-1);
    for(int i = 0; i < N;i++){
        res = max(res,rec(i));
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<int>() << endl;
    return 0;
}
