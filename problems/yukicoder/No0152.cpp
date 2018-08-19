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
 <url:https://yukicoder.me/problems/no/152>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 ピタゴラス数の列挙式より
 m と n は互いに素
 m > n
 m − n は奇数
 
 の条件を満たすm,nに対して
 (a, b, c) = (m^2 − n^2, 2mn, m^2 + n^2)
 
 として求まる
 
 よって、 c に対して m*m+n*n <= Lとなるm,nを全探索すれば良い

 ================================================================
 */

const ll MOD = 1000003;
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }
ll solve(){
    ll res = 0;
    ll L; cin >> L;
    for(ll n = 1; n*n <= L; n++){
        for(ll m = n+1; n*n + m*m <= L; m++){
            if(((m-n)&1) == 0) continue;
            if(gcd(n,m) != 1) continue;
            ll a = m*m-n*n,b = 2*m*n, c = m*m+n*n;
            if(4*(a+b+c) <= L) res++;
        }
    }
    res%=MOD;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
