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
 <url:https://yukicoder.me/problems/no/274>
 問題文============================================================
 =================================================================
 解説=============================================================
 貪欲に詰めていけばok
 ================================================================
 */

string solve(){
    int N,M; cin >> N >> M;
    vector<int> imos(M+1);
    for(int i = 0; i < N;i++){
        int L,R; cin >> L >> R;
        imos[L]++; imos[R+1]--;
        imos[M-1-R]++; imos[M-L]--;
    }
    for(int i = 0; i < M;i++) imos[i+1] += imos[i];
    for(int i = 0; i < M;i++){
        if(imos[i] > 2) return "NO";
    }
    return "YES";
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
