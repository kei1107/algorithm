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
 <url:https://yukicoder.me/problems/no/16>
 問題文============================================================
 Maliaは、与えられた数式を計算しようとしている。
 数式は一つの変数xのみで構成されており、各i項はxのai乗で構成されている。
 ここで xnはxのn乗を表すことにすると
 xa1+xa2+⋯+xaN
 という形になっている。
 xの累乗を計算するのは大変だと気づいたあなたは、代わりに計算してあげることになりました。
 
 xと各ai (1≤i≤n)が与えられた時の計算値を求めてください。
 答えの値が非常に大きくなるので計算値に対して1,000,003 で割ったあまりを求めてください。
 
 計算途中の値が32ビットに収まらないことが有ります。
 =================================================================
 解説=============================================================
 
 繰り返し自乗法　やるだけ
 
 ================================================================
 */

const ll MOD = 1e6+3;
ll powmod(ll a,ll b) {ll res=1;a%=MOD;for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}

ll solve(){
    ll res = 0;
    ll x,N; cin >> x >> N;
    for(int i = 0; i < N;i++){
        ll a; cin >> a;
        (res += powmod(x,a))%=MOD;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
