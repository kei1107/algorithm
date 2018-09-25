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
 <url:https://beta.atcoder.jp/contests/abc018/tasks/abc018_4>
 問題文============================================================
 =================================================================
 解説=============================================================
 女子の集合と男子の集合を全探索するとTLEする。
 
 ここで、女子だけの集合を全探索することを考える。
 その後、現在考えている女子の集合に対して最適な男子の集合は
 ある男子を選んだ時に得られるコストを大きい人からQ人選べば良い
 
 よって、O(2^N NM)で間に合う
 ================================================================
 */

/* next combination */
int next_combination(int sub) {
    int x = sub & -sub, y = sub + x;
    return (((sub & ~y) / x) >> 1) | y;
}

ll solve(){
    ll res = 0;
    int N,M,P,Q,R; cin >> N >> M >> P >> Q >> R;
    vector<ll> x(R),y(R),z(R);
    vector<vector<ll>> cost(N,vector<ll>(M));
    for(int i = 0; i < R;i++){
        cin >> x[i] >> y[i] >> z[i];
        x[i]--; y[i]--;
        cost[x[i]][y[i]] = z[i];
    }
    
    int bit = (1<<P)-1;
    for(int bit = 0; bit < (1<<N);bit++){
        if(__builtin_popcount(bit) != P) continue;
        vector<ll> path_cost(M);
        for(int i = 0; i < N;i++){
            if((bit>>i)&1){
                for(int j = 0; j < M;j++){
                    path_cost[j] += cost[i][j];
                }
            }
        }
        sort(path_cost.rbegin(),path_cost.rend());
        res = max(res,accumulate(path_cost.begin(),path_cost.begin()+Q,0LL));
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
