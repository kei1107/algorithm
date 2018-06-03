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
 <url:https://beta.atcoder.jp/contests/agc024/tasks/agc024_c>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 連続して１ずつ増加する山は、まぁ１回の操作で作ることができる。
 
 1個前の山よりも小さい山はその山の高さぶんの操作で作ることができる。
 
 あとは最初が０であったり、１ずつ増加しない山はあり得ないので　矛盾とみなす
 ================================================================
 */

ll solve(){
    ll res = 0;
    ll N; cin >> N;
    vector<ll> A(N); for(auto& in:A) cin >> in;
    if(A[0] != 0) return -1;
    for(int i = 1; i < N;i++){
        if(A[i-1] < A[i] && (A[i] - A[i-1]) != 1) return -1;
        if(A[i] > A[i-1]){
            res++;
        }else {
            res += A[i];
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
