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
 <url:https://yukicoder.me/problems/no/251>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 まぁはい。
 M=0の場合につ注意
 ================================================================
 */

const ll MOD = 129402307;
ll powmod(ll a,ll b) {ll res=1;a%=MOD;for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
ll string2ll(const string S,const ll MOD){
    ll ret = 0;
    for(auto c:S){
        ret = ret*10 + c - '0';
        ret%=MOD;
    }
    return ret;
}
ll solve(){
    ll res = 0;
    string strN,strM; cin >> strN >> strM;
    if(strM == "0") return 1;
    ll N = string2ll(strN,MOD);
    ll M = string2ll(strM,MOD-1);
    if(N == 0) return 0;
    res = powmod(N,M);
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
