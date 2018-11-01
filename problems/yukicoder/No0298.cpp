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
 <url:https://yukicoder.me/problems/no/298>
 問題文============================================================
 =================================================================
 解説=============================================================
 これは難しい。
 
 一見 dpで計算ができそうに見えるが、各頂点には親と子の関係があるため独立性が
 担保できずに破綻する。
 
 よって、標本空間上での全列挙を行いO(N*2^N)で解く事が可能
 ================================================================
 */

typedef long double ld;
ld solve(){
    ld res = 0;
    int N,M; cin >> N >> M;
    vector<int> A(M),B(M); vector<ld> C(M);
    vector<vector<pair<int,ld>>> G(N);
    for(int i = 0; i < M;i++){
        cin >> A[i] >> B[i] >> C[i]; C[i]/=100;
        G[B[i]].push_back({A[i],C[i]});
    }
    
    for(int i = 0; i < (1<<N);i++){
        if((i&1) && (i & (1<<(N-1)))){
            ld prob = 1;
            for(int j = 1; j < N;j++){
                ld tprob = 1; // 頂点jに伝播してこない確率
                for(auto p:G[j]){
                    int k; ld c; tie(k,c) = p;
                    if((i>>k)&1){
                        tprob*=1-c;
                    }
                }
                
                if((i>>j)&1){
                    prob*=1-tprob;
                }else{
                    prob*=tprob;
                }
            }
            res += prob;
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(12) << solve() << endl;
    return 0;
}
