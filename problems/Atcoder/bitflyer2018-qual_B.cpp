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
 <url:https://beta.atcoder.jp/contests/bitflyer2018-qual/tasks/bitflyer2018_qual_b>
 問題文============================================================
 =================================================================
 解説=============================================================
 愚直シミュレーション
 ================================================================
 */

void solve(){
    ll A,B,N; cin >> A >> B >> N;
    string X; cin >> X;
    for(int i = 0; i < N; i++){
        if(X[i] == 'S'){
            A = max(0LL,A-1);
        }
        if(X[i] == 'C'){
            B = max(0LL,B-1);
        }
        if(X[i] == 'E'){
            if(A >= B){
                A = max(0LL,A-1);
            }else{
                B = max(0LL,B-1);
            }
        }
    }
    cout << A << endl;
    cout << B << endl;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
