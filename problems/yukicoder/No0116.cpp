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
 <url:https://yukicoder.me/problems/no/116>
 問題文============================================================
 =================================================================
 解説=============================================================
 やるだけ
 ================================================================
 */

ll solve(){
    ll res = 0;
    ll N; cin >> N;
    vector<ll> A(N); for(auto& in:A) cin >> in;
    for(int i = 0; i < N-2;i++){
        vector<ll> kado = {A[i],A[i+1],A[i+2]};
        sort(kado.begin(),kado.end()); kado.erase(unique(kado.begin(),kado.end()),kado.end());
        if(kado.size() != 3) continue;
        if(A[i] == kado[1] || A[i+2] == kado[1]) res++;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
