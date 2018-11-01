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
 <url:https://yukicoder.me/problems/no/277>
 問題文============================================================
 =================================================================
 解説=============================================================
 根と葉を始点としてダイクストラすればいい
 ================================================================
 */

void solve(){
    int N; cin >> N;
    vector<vector<int>> G(N+1);
    for(int i = 0; i < N-1;i++){
        int x,y; cin >> x >> y;
        x--; y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    G[N].push_back(0);
    for(int i = 0; i < N;i++){
        if(G[i].size()!=1) continue;
        G[N].push_back(i);
    }
    vector<int> info(N+1,INF);
    info[N] = 0;
    queue<int> q; q.push(N);
    while(q.size()){
        int n = q.front(); q.pop();
        for(auto next:G[n]){
            if(info[next] > info[n] + 1){
                info[next] = info[n] + 1;
                q.push(next);
            }
        }
    }
    for(int i = 0; i < N;i++){
        cout << info[i] - 1 << endl;
    }
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
