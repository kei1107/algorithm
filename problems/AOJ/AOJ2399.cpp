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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2399&lang=jp>
 問題文============================================================
 =================================================================
 解説=============================================================
 情報から実際に候補を探り、矛盾があるかどうかを確かめれば良い
 ================================================================
 */
int N;
int solve(){
    int res = 0;
    vector<vector<int>> G(N);
    for(int i = 0; i < N;i++){
        int M; cin >> M;
        for(int j = 0; j < M;j++){
            int p; cin >> p; p--;
            G[p].push_back(i);
        }
    }
    vector<int> f(N);
    int K; cin >> K;
    for(int i = 0; i < K;i++){
        int l; cin >> l; l--;
        for(auto p:G[l]){
            f[p]++;
        }
    }
    //  for(auto v:f) cout << v << " "; cout << endl;
    if(count(f.begin(),f.end(),K) != 1) return -1;
    return res = (int)(find(f.begin(),f.end(),K) - f.begin()) + 1;
}
int main(void){
    cin.tie(0); ios_base::sync_with_stdio(false);
    while(cin >> N,N){
        cout << solve() << endl;
    }
    return 0;
}
