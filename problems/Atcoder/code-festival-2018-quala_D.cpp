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
 <url:https://beta.atcoder.jp/contests/code-festival-2018-quala/tasks/code_festival_2018_quala_d>
 問題文============================================================
 =================================================================
 解説=============================================================
 解説AC
 https://img.atcoder.jp/code-festival-2018-quala/editorial.pdf
 ================================================================
 */

const ll MOD = 1e9+7;
ll solve(){
    ll res = 0;
    ll D,F,T,N; cin >> D >> F >> T >> N;
    
    vector<ll> X(N+1);
    X[0] = 0;
    for(int i = 1; i <= N;i++) cin >> X[i];
    
    
    vector<ll> Pow(N+2);
    Pow[0] = 1;
    for(int i = 1; i < N+2;i++) (Pow[i]=Pow[i-1]*2)%=MOD;
    
    vector<ll> imos(N+2);
    imos[0] = 1;
    imos[1] = -1;
    for(int i = 0; i <= N;i++){
        ll x = X[i];
        ll l = upper_bound(X.begin(),X.end(),x+F-T) - X.begin();
        ll r = upper_bound(X.begin(),X.end(),x+F) - X.begin();
        ll num = max(l-i-1,0LL);
        
        (imos[i+1] += imos[i] + MOD)%=MOD;
        
        ll add = imos[i]*Pow[num]%MOD;
        (imos[l] += add)%=MOD;
        (imos[r] += MOD-add)%=MOD;
        
        if(D <= x + F){
            (res += add)%=MOD;
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
