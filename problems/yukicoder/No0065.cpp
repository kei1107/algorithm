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
 <url:https://yukicoder.me/problems/no/65>
 問題文============================================================
 1個のサイコロを何回か振って目の合計をK以上にしたい。
 サイコロを振る回数の期待値を求めよ。
 
 なお、今回のサイコロの場合に回数の期待値(E(x)の公式は以下であることが知られている
 E(x) := これまでの目の合計が x のとき、合計が K に達するまでにあと振ることになる回数の期待値
 E(x)=E(x+1)∗1/6+E(x+2)∗1/6+E(x+3)∗1/6+E(x+4)∗1/6+E(x+5)∗1/6+E(x+6)∗1/6+1

 =================================================================
 解説=============================================================
 問題文で与えれらた式をそのまま実装すればよい
 ================================================================
 */

double E(ll x,ll K){
    if(x >= K) return 0.;
    double res = 0.0;
    for(ll a = 1; a <=6; a++){
        res += E(x+a,K)/6.;
    }
    res += 1.;
    return res;
}
double solve(){
    double res = 0;
    ll K; cin >> K;
    res = E(0,K);
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << fixed << solve() << endl;
    return 0;
}
