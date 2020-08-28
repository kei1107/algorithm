#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define INF 1<<30
#define LINF 1LL<<60

struct UnionFind{
    vector<int> parent, rank;
    UnionFind(int n) : parent(n, -1), rank(n, 0) { }
    int find(int x){
        if(parent[x] == -1) return x;
        else return (parent[x] = find(parent[x]));
    }
    bool unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return false;
        if(rank[x] < rank[y])
            parent[x] = y;
        else
            parent[y] = x;
        if(rank[x] == rank[y]) rank[x]++;
        return true;
    }
    bool same(int x, int y){
        return find(x) == find(y);
    }
};

// =========================================================

/*
 UnionFind
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


// =========================================================

/*
 UnionFind　区間付き
 */

struct UnionFind {
    vector<int> data;
    vector<int> left_v,right_v;

    UnionFind(int size) : data(size, -1) {
        left_v.resize(size);
        right_v.resize(size);
        for(int i = 0; i < size;i++) left_v[i] = right_v[i] = i; 
    }

    bool unite(int x, int y) {
        x = root(x); y = root(y);
        if(x == y) return false;
        if (data[x] > data[y]) swap(x, y);
        left_v[x] = min(left_v[x],left_v[y]);
        right_v[x] = max(right_v[x],right_v[y]);
        data[x] += data[y]; 
        data[y] = x;
        return true;
    }

    // 区間[l,r]を結合
    void unite_range(int x,int y){
        if(x > y) return;
        while(right(x) < y){
            unite(right(x),right(x)+1);
        }
    }

    int left(int k){
        return left_v[root(k)];
    }
    int right(int k){
        return right_v[root(k)];
    }
    pair<int,int> range(int k){
        k = root(k);
        return make_pair(left_v[k],right_v[k]);
    }
    bool same(int x, int y) {
        return root(x) == root(y);
    }
    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    int size(int x) {
        return -data[root(x)];
    }
};

// 区間付き verified : https://yukicoder.me/problems/no/1170
template<class Type>
Type solve(Type res = Type()){
    int N,A,B; cin >> N >> A >> B;
    vector<ll> x(N); for(auto& in:x) cin >> in;

    UnionFind UF(N);
    for(int i = 0; i < N;i++){
        int l = max(0,(int)(lower_bound(x.begin(),x.end(),x[i]+A)-x.begin()));
        int r = min(N-1,(int)(upper_bound(x.begin(),x.end(),x[i]+B)-x.begin()-1));
        UF.unite_range(l,r);
        if(l <= r) UF.unite(i,l);
    }

    for(int i = 0; i < N;i++){
        cout << UF.size(i) << endl;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    solve<ll>(0);
    // cout << fixed << setprecision(12) << solve<ll>() << endl;
    return 0;
}
