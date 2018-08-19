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
 <url:https://yukicoder.me/problems/no/133>
 問題文============================================================
 =================================================================
 解説=============================================================
 制約が小さいので next_permutation などを用いて
 全パターン試せば良い
 ================================================================
 */

typedef long double ld;
ld solve(){
    ld res = 0;
    ll N; cin >> N;
    vector<ll> A(N),B(N);
    for(auto& in:A) cin >> in;
    for(auto& in:B) cin >> in;
    
    ld game = 0,win = 0;
    vector<int> ord_A(N),ord_B(N);
    iota(ord_A.begin(),ord_A.end(),0);
    do{
        iota(ord_B.begin(),ord_B.end(),0);
        do{
            int win_A = 0;
            for(int i = 0; i < N;i++){
                win_A += (A[ord_A[i]]>B[ord_B[i]])?1:(A[ord_A[i]]<B[ord_B[i]])?-1:0;
            }
            game++;
            if(win_A>0) win++;
        }while(next_permutation(ord_B.begin(),ord_B.end()));
    }while(next_permutation(ord_A.begin(),ord_A.end()));
    res = win/game;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(12) << solve() << endl;
    return 0;
}
