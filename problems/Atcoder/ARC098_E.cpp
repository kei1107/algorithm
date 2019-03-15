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
 <url:https://atcoder.jp/contests/arc098>
 問題文============================================================
 =================================================================
 解説=============================================================
 最小値となる値を定めると、
 最適な取り方は、取得可能である最小値以上の値を小さい順にとっていく
 という手段となる。

 
 よって、数列の値を小さい順に見ていき、今見ているものを最小値とした時、
 取得可能な値を保持 => ソートして小さい順にQ個とっていく
 を繰り返せばいい
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    ll N,K,Q; cin >> N >> K >> Q;
    vector<ll> A(N);
    vector<ll> B(N);
    for(int i = 0 ; i<N;i++){
        cin >> A[i];
    }
    B = A;
    sort(A.begin(),A.end());
    res = LINF;
    for(int i = 0; i < N;i++){
        vector<vector<ll>> vals;
        vector<ll> now;
        for(int j = 0; j < N;j++){
            if(B[j] < A[i]){
                vals.push_back(now);
                now.clear();
            }else{
                now.push_back(B[j]);
            }
        }
        vals.push_back(now);
        
        vector<ll> V;
        for(auto& vec:vals){
            sort(vec.begin(),vec.end());
            int sz = (int)vec.size();
            for(int j = 0; j <= sz-K;j++){
                V.push_back(vec[j]);
            }
        }
        sort(V.begin(),V.end());
        if(V.size() < Q) break;
        res = min(res,V[Q-1] - V[0]);

    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
