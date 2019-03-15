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
 <url:https://yukicoder.me/problems/no/429>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 初期状態から X-1番目までの結果と
 最終状態から X+1番目までの結果を復元する。
 
 あとは、各要素を比較すればいい
 ================================================================
 */

template<class T>
T solve(T res){
    int N,K,X; cin >> N >> K >> X; X--;
    vector<int> A(K),B(K);
    for(int i = 0; i < K;i++){ if(i!=X){cin >> A[i] >> B[i]; A[i]--; B[i]--;}else{char c; cin >> c >> c;}}
    vector<int> F(N); iota(F.begin(),F.end(),0);
    for(int i = 0; i < X;i++) swap(F[A[i]],F[B[i]]);
    vector<int> C(N); for(auto &in:C) {cin >> in; in--;}
    for(int i = K-1; i > X; i--) swap(C[A[i]],C[B[i]]);
    for(int i = 0; i < N;i++) if(F[i] != C[i]) res.push_back(i+1);
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve(vector<int>()) << endl;
    return 0;
}
