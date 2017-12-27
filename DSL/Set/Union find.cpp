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

int par[MAX_N];//親
int rank[MAX_N];//木の深さ

void init(int n){
    for(int i = 0;i < n;i++){
        par[i] = i;
        rank[i] = 0;
    }
}

int find(int x){
    if(par[x] == x){
        return x;
    }else{
        return par[x] = find(par[x]);
    }
}

void unite(int x,int y){
    x = find(x);
    y = find(y);
    if(x == y) return;
    
    if(rank[x] < rank[y]){
        par[x] = y;
    }else{
        par[y] = x;
        if(rank[x] == rank[y])rank[x]++;
    }
}

bool same(int x,int y){
    return find(x) == find(y);
}
