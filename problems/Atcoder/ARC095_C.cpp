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
 <url:https://beta.atcoder.jp/contests/arc095/tasks/arc095_a>
 問題文============================================================
 l が奇数のとき，l 個の数 a1,a2,…,al の中央値とは，a1,a2,…,al の中で
 l+1/2  番目に大きい値のことを言います．
 
 N 個の数 X1,X2,…,XN が与えられます．ここで，N は偶数です．
 i=1,2,…,N に対して，X1,X2,…,XN から Xi のみを除いたもの，
 すなわち X1,X2,…,Xi−1,Xi+1,…,XN の中央値を Bi とします．
 
 i=1,2,…,N に対して，Bi を求めてください．
 =================================================================
 解説=============================================================
 
 答えはXの中央値or中央値以上で最小の値((l+1)/2 + 1番目)
 しかない。
 
 Xiを見たとき、それが中央値以下であれば、中央値以上で最小の値を、
 より大きければ中央値を出力すれば良い
 
 ================================================================
 */


void solve(){
    ll N; cin  >> N;
    vector<ll> X(N); for(auto& in:X) cin >> in;
    vector<ll> T = X;
    sort(X.begin(),X.end());
    ll M = X[N/2 - 1];
    vector<ll> ans(N);
    for(int i = 0; i < N;i++){
        if(T[i] <= M){
            cout << X[N/2] << endl;
        }else{
            cout << X[N/2 - 1] << endl;
        }
    }
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
