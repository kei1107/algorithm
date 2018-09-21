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
 <url:https://onlinejudge.u-aizu.ac.jp/services/room.html#ACPC2018Day2/problems/G>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 増加分は累積和で管理するとして、
 
 どのタイミングで減少するのかどうかについてを、列挙して、
 減少に関しても累積和で管理しても間に合う
 ================================================================
 */


int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    ll N,M; cin >> N >> M;
    vector<ll> A(M),B(M);
    for(int i = 0; i < M;i++) cin >> A[i] >> B[i];

    vector<ll> ans(N);
    for(int i = 1; i < N;i++) ans[i] = ans[i-1] + M;
    
    vector<ll> rm(N);
    ll sum = 0;
    for(int i = 0; i < M;i++){
        sum += (A[i] + 1)%B[i];
        
        ll ind = B[i] - ((A[i]+1)%B[i]);
        while(ind < N){
            rm[ind] += B[i];
            ind += B[i];
        }
    }
//    cout << sum << endl;
//    cout << ans << endl;
//    cout << rm << endl;
    
    cout << ans[0] + sum << endl;
    for(int i = 1; i < N;i++){
        rm[i] += rm[i-1];
        
        ans[i] = ans[i] + sum - rm[i];
        cout << ans[i] << endl;
    }
    return 0;
}
