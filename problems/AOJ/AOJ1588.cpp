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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1588>
 問題文============================================================
 =================================================================
 解説=============================================================
 全探索
 ================================================================
 */

ll solve(){
    ll res = 0;
    int N,M,K; cin >> N >> M >> K;
    vector<ll> a(N),b(N);
    for(auto& in:a) cin >> in;
    for(auto& in:b) cin >> in;
    for(int i = 0; i < (1<<N);i++){
        if(__builtin_popcount(i) > K) continue;
        vector<pll> score;
        for(int j = 0; j < N;j++){
            if((i>>j)&1){
                score.push_back(make_pair(a[j],b[j]));
            }
        }
        sort(score.rbegin(),score.rend());
        ll T = 0,L = M;
        for(auto p:score){
            T += min(L,p.second)*p.first;
            L -= min(L,p.second);
        }
        res = max(res,T+L);
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
