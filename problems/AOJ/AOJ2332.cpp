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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2332>
 問題文============================================================
 =================================================================
 解説=============================================================

 あるマスnが0であれば n+1 ... n+6までコスト1の辺
 0でなければ n + p[n] へコスト0の辺を貼って
 dijkstraすれば良い
 
 ================================================================
 */

ll solve(){
    ll res = 0;
    ll N; cin >> N;
    vector<ll> p(N); for(auto& in:p) cin >> in;
    vector<ll> dist(N,LINF); dist[0] = 0;
    queue<ll> q; q.push(0);
    while(q.size()){
        ll n = q.front(); q.pop();
        if(p[n] == 0){
            for(int i = 1; i <= 6;i++){
                if(i + n >= N) break;
                if(dist[i+n] > dist[n] + 1){
                    dist[i+n] = dist[n] + 1;
                    q.push(i+n);
                }
            }
        }else{
            if(dist[n+p[n]] > dist[n]){
                dist[n+p[n]] = dist[n];
                q.push(n+p[n]);
            }
        }
    }
    res = dist[N-1];
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
