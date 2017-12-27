#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define INF 1<<30
#define LINF 1LL<<60

struct UnionFind {
	vector<int> par;
	int n, cnt;
	UnionFind(const int& x = 0) { init(x); }
	void init(const int& x) { par.assign(cnt = n = x, -1); }
	inline int find(const int& x) { return par[x] < 0 ? x : par[x] = find(par[x]); }
	inline bool same(const int& x, const int& y) { return find(x) == find(y); }
	inline bool unite(int x, int y) {
		if ((x = find(x)) == (y = find(y))) return false;
		--cnt;
		if (par[x] > par[y]) swap(x, y);
		par[x] += par[y];
		par[y] = x;
		return true;
	}
	inline int count() const { return cnt; }
	inline int count(int x) { return -par[find(x)]; }
};

//=========================================================================

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
