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
 <url:https://yukicoder.me/problems/no/94>
 問題文============================================================

 日本語なので略
 
 =================================================================
 解説=============================================================
 
 互いに通信可能な中継局の集合をUnionFindを用いて得る
 その後、通信可能な中継局同士を用いた場合のギリギリの通信距離を全ペアに関して見て行けば良い
 
 N = 0の場合や互いに通信可能な中継局が存在しない場合に注意
 ================================================================
 */

struct UnionFind {
    vector<int> data;
    UnionFind(int size) : data(size, -1) { }
    bool unionSet(int x, int y) {
        x = root(x); y = root(y);
        if (x != y) {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y]; data[y] = x;
        }
        return x != y;
    }
    bool findSet(int x, int y) {
        return root(x) == root(y);
    }
    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    int size(int x) {
        return -data[root(x)];
    }
};

typedef long double ld;
const ld eps = 1e-9;
ld solve(){
    ld res = 0;
    int N; cin >> N;
    if(N == 0) res = 1;
    else res = 2;
    vector<complex<ld>> ps(N);
    for(int i = 0; i < N;i++){
        ld x,y; cin >> x >> y;
        ps[i] = complex<ld>(x,y);
    }
    UnionFind UF(N);
    for(int i = 0; i < N;i++){
        for(int j = i+1; j < N;j++){
            if(abs(ps[i]-ps[j]) < 10 + eps){
                UF.unionSet(i, j);
            }
        }
    }
    
    for(int i = 0; i < N;i++){
        for(int j = i+1; j < N;j++){
            if(UF.findSet(i, j)){
                res = max(res,abs(ps[i]-ps[j])+2);
            }
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(12) << solve() << endl;
    return 0;
}
