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
 <url:https://beta.atcoder.jp/contests/arc098/tasks/arc098_b>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 a+b+c+...+z = a^b^c^....^z
 
 は全てのbit桁に対して、そのbitの桁に1が経つものが1以下であると同義
 
 よって、
 区間l,rを見たとき、lを固定して、rを更新して行けばO(N)で求まる
 ================================================================
 */

ll solve(){
    ll res = 0;
    ll N; cin >> N;
    vector<ll> A(N); for(auto& in:A) cin >> in;
    ll bitflag = 0;
    int r = 0;
    for(int l = 0; l < N;l++){
        while(r < N){
            bool ok = true;
            for(int k = 0; k < 20;k++){
                if((A[r]>>k)&1){
                    if((bitflag>>k)&1){
                        ok = false;
                        break;
                    }
                }
            }
            if(!ok) break;
            bitflag += A[r++];
        }
        res += (r-l);
        
        bitflag -= A[l];
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
