#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream &operator << (ostream& out,const pair<S,T>& o){
    out << "(" << o.first << "," << o.second << ")"; return out;
}

/*
 重み付きUnionFind
 辺の重さも状態として持つ
 */
const int MAX_UF = 110000;
struct PotentialUnionFind{
    typedef ll TYPE;
    const TYPE SUM_UNITY = 0;
    TYPE par[MAX_UF],rank[MAX_UF];
    TYPE diff_weight[MAX_UF];
    int N;
    PotentialUnionFind(int n = 0):N(n){ for(int i = 0; i < n;i++){ par[i] = i; rank[i] = 0; diff_weight[i] = SUM_UNITY; } }
    void init(){ for(int i = 0; i < N;i++){ par[i] = i; rank[i] = 0; diff_weight[i] = SUM_UNITY; } }
    void init(int n){ for(int i = 0; i < n; i++){ par[i] = i; rank[i] = 0; diff_weight[i] = SUM_UNITY; } }
    
    TYPE root(TYPE x){
        if(par[x] == x) return x;
        else {
            TYPE r = root(par[x]);
            diff_weight[x] += diff_weight[par[x]];
            return par[x] = r;
        }
    }
    TYPE weight(TYPE x){ root(x); return diff_weight[x]; }
    bool same(TYPE x,TYPE y){
        return root(x) == root(y);
    }
    bool merge(TYPE x,TYPE y,TYPE w){
        w += weight(x); w -= weight(y);
        x = root(x); y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) {swap(x, y); w = -w; }
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x; diff_weight[y] = w;
        return true;
    }
    TYPE diff(TYPE x,TYPE y){ return weight(y) - weight(x); }
};

// verify : https://beta.atcoder.jp/contests/abc087/tasks/arc090_b
void solve(){
    int N,M; cin >> N >> M;
    PotentialUnionFind PUF(N);
    for(int i = 0; i < M; i++){
        int l,r,d; cin >> l >> r >> d; l--; r--;
        if(PUF.same(l,r)){
            ll diff = PUF.diff(l,r);
            if(diff != d) { cout << "No" << endl; return; }
        }else{ PUF.merge(l,r,d); }
    }
    cout << "Yes" << endl;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    solve();
    return 0;
}
