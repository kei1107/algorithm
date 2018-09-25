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
 <url:https://beta.atcoder.jp/contests/soundhound2018-summer-final-open/tasks/soundhound2018_summer_final_b>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 A[i] := i番目まで見たとき、効用の最大値
 としたdpを考えれば良い
 
 ここで、i-1番目までの最大値を保存して起き、遷移に利用すればO(N)でできる
 ================================================================
 */

ll solve(){
    ll res = 0;
    int N,K; cin >> N >> K;
    vector<ll> b(N); for(auto& in:b) cin >> in;
    vector<ll> A(N+1,-LINF);
    ll Max = -LINF;
    A[0] = 0;
    for(int i = 0; i < N;i++){
        Max = max(Max,A[i]);
        
        A[i+1] = max(A[i+1],A[i] + b[i]);
        if(i+K<=N){
            A[i+K] = max(A[i+K],Max);
        }
        
    }
    res = A[N];
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
