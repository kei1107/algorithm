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

unsigned xor128_x = 123456789, xor128_y = 362436069, xor128_z = 521288629, xor128_w = 88675123;
unsigned xor128() {
    unsigned t = xor128_x ^ (xor128_x << 11);
    xor128_x = xor128_y; xor128_y = xor128_z; xor128_z = xor128_w;
    return xor128_w = xor128_w ^ (xor128_w >> 19) ^ (t ^ (t >> 8));
}

void solve(){
    ll N,Q; cin >> N >> Q;
    vector<ll> A(N),q(Q);
    for(int i = 0; i < N;i++) A[i] = xor128() % 100003;
    for(int i = 0; i < Q;i++) cin >> q[i];
    for(int i = 0; i < Q;i++){
        if(q[i] == 0){
            cout << 0 << endl;
            continue;
        }
        
    }
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
