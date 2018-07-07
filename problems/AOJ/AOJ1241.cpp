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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1241>
 問題文============================================================
 
 多くても4つの数字の2乗和がnとなるようなものの個数を求めよ
 
 =================================================================
 解説=============================================================
 
 深さが4までと制限が存在するのでDFSで間に合う
 
 ================================================================
 */
ll n;
void rec(ll N,ll sum,ll dep,ll& res){
    if(sum == n){
        res++;
        return;
    }
    if(dep == 3) return;
    for(ll i = N; i*i+sum <= n;i++){
        rec(i,sum+i*i,dep+1,res);
    }
}
ll solve(){
    ll res = 0;
    for(ll i = 1; i*i <= n;i++){
        rec(i,i*i,0,res);
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    while(cin >> n,n){
        cout << solve() << endl;
    }
    return 0;
}
