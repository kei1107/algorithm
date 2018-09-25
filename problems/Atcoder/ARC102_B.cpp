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
 <url:>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */

void solve(){
    ll L; cin >> L;
    ll r = 0;
    ll n = 1;
    while((n*2) <= L){
        n *= 2;
        r++;
    }
    ll N = r+1;
    ll M = 0;
    vector<vector<pll>> G(N+1);
    for(int i = 1; i < N;i++){
        G[i].push_back(pll(i+1,1<<(i-1)));
        G[i].push_back(pll(i+1,0));
        M+=2;
    }
    for(ll t = N-1; t >= 1;t--){
        if((L-(1<<(t-1)))>=n){
            G[t].push_back(pll(N,L-(1<<(t-1))));
            M++;
            L -= (1<<(t-1));
        }
    }
    cout << N << " " << M << endl;
    for(int i = 1; i < N;i++){
        for(auto e:G[i]){
            cout << i << " " << e.first << " " << e.second << endl;
        }
    }
//    cout << G << endl;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
