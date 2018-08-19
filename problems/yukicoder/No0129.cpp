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
 <url:https://yukicoder.me/problems/no/129>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 予算の余りを V円としたとき
 x := V/1000 とすれば
 
 M個からx個選ぶ組み合わせすうが答え
 
 modが素数ではないが、Mが小さいのでパスカルの三角形を用いてあらかじめテーブルを作っておけば良い
 ================================================================
 */


const ll MOD = 1e9;
const int MAX_M = 10000;
int comb[MAX_M+1][MAX_M+1];
ll solve(){
    ll res = 0;
    ll N,M; cin >> N >> M;
    ll x = N-N/(1000*M)*(1000*M);
    x /= 1000;
    
    for (int i = 0; i <= M; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i)
                comb[i][j] = 1;
            else
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j])%MOD;
        }
    }
    res = comb[M][x];
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
