#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
 <url:https://arc065.contest.atcoder.jp/tasks/arc065_b>
 問題文============================================================
 N 個の都市があり、K 本の道路と L 本の鉄道が都市の間に伸びています。
 i 番目の道路は pi 番目と qi 番目の都市を双方向に結び、
 i 番目の鉄道は ri 番目と si 番目の都市を双方向に結びます。
 異なる道路が同じ 2 つの都市を結ぶことはありません。同様に、異なる鉄道が同じ 2 つの都市を結ぶことはありません。
 
 ある都市から別の都市に何本かの道路を通って到達できるとき、
 それらの都市は道路で連結しているとします。
 また、すべての都市はそれ自身と道路で連結しているとみなします。
 鉄道についても同様に定めます。
 
 全ての都市について、その都市と道路・鉄道のどちらでも連結している都市の数を求めてください。
 
 =================================================================
 
 解説=============================================================
 
 UnionFindを用いて、道路と鉄道、それぞれの集合を作っておく、
 あとは、その集合の根の値を用いて、ある頂点iに関して
 （道路の集合の根、鉄道の集合の根）　が等しいペアを数え上げれば良い
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

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll N,K,L; cin >> N >> K >> L;
    vector<ll> p(K),q(K),r(L),s(L);
    
    for(int i = 0; i < K;i++){
        cin >> p[i] >> q[i];
        p[i]--; q[i]--;
    }
    for(int i = 0; i < L;i++){
        cin >> r[i] >> s[i];
        r[i]--; s[i]--;
    }
    
    UnionFind pq(N),rs(N);
    for(int i = 0; i < K;i++) pq.unionSet(p[i], q[i]);
    for(int i = 0; i < L;i++) rs.unionSet(r[i], s[i]);
    map<pii,int> mp;
    for(int i = 0; i < N;i++) mp[pii(pq.root(i),rs.root(i))]++;
    for(int i = 0; i < N;i++){
        cout << mp[pii(pq.root(i),rs.root(i))] << " ";
    }
    cout << endl;
    return 0;
}
