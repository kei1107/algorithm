#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <bitset>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <numeric>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <deque>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:http://poj.org/problem?id=1703>
問題文============================================================
 2種類の集合があって，2つの要素が異なる集合に属しているという情報と，
 2つの要素が同じ集合に属すかどうか問うクエリが来る．
=================================================================

解説=============================================================

 a b について AグループとBグループに属する情報を持たせれば良い
 すなわち 「a-Aとb-B」「a-Bとb-A」を統合すれば良い
 => a-A と b-Aが同じ集合 -> 同じ集合といった考えができる
 
================================================================
*/


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


int main(void) {
//	cin.tie(0); ios::sync_with_stdio(false);
    int T; cin >> T;
   UnionFind uf(100010*2);
    for(int t = 1; t <= T;t++){
        int N,M;
        scanf("%d %d",&N,&M);
        fill(uf.parent.begin(),uf.parent.end(),-1);
        fill(uf.rank.begin(),uf.rank.end(),0);
        for(int j = 0; j < M;j++){
            char op[10]; int x,y;
            scanf("%s%d%d",op,&x,&y);
            if(op[0] == 'A'){
                if(uf.same(x*2,y*2)){
                    cout << "In the same gang." << endl;
                }else if(uf.same(x*2,y*2+1)){
                    cout << "In different gangs." << endl;
                }else{
                    cout << "Not sure yet." << endl;
                }
            }else{
                uf.unite(x*2, y*2+1);
                uf.unite(x*2+1, y*2);
            }
        }
    }
	return 0;
}
