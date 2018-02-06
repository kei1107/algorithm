#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <bitset>
#include <iostream>
#include <iomanip>
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
const int INF = 1e9;
const ll LINF = 1e16;

/*
<url:http://poj.org/problem?id=3293>
問題文============================================================
2次元格子点上にN(<10^5)個の点がある。
 これらの点を頂点とする単純で辺が軸に平行で連結で穴の無い多角形が作れるかどうか判定する。
 ただし、頂点は必ず垂直な辺と水平な辺にひとつずつ接続していなければならない。
=================================================================

解説=============================================================
 参照 : http://d.hatena.ne.jp/komiyam/20121004/1349358468
 
 平面走査
 
 x座標を小さい順に動かしながらy座標に点の追加/削除を行う
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

struct BIT {
    int N;
    vector<ll> bit;
    BIT(int N):N(N) {
        /* BITは[1..N]で扱う */
        bit.resize(N + 1, 0);
    }
    
    void add(int x, int val)
    {
        while (x <= N) {
            bit[x] += val;
            x += x & -x;
        }
    }
    
    int sum(int x)
    {
        int ret = 0;
        while (x) {
            ret += bit[x];
            x &= (x - 1);
        }
        return (ret);
    }
    int sum(int l,int r){
        return sum(r) - sum(l-1);
    }
};

struct P{
    int x,y;
    P(int a = 0,int b = 0) : x(a),y(b){}
    bool operator < (const P& o) const{
        if(y != o.y) return y < o.y;
        else return x < o.x;
    }
};

#define MAX_N 100000
int N;
int xs[MAX_N+1],ys[MAX_N+1];
P p[MAX_N+1];

void input(){
    scanf("%d",&N);
    for(int i = 1; i <= N;i++){
        scanf("%d %d",&xs[i],&ys[i]);
        p[i] = P(xs[i],ys[i]);
    }
}

void solve(){
    ll ans = 0;
    UnionFind uf(N+1);
    BIT bit(N+1);
    if(N%2 == 1){ cout << -1 << endl; return ; }
    sort(xs+1,xs+N+1); sort(ys+1,ys+N+1);
    int NX = int(unique(xs+1,xs+N+1)-xs-1);
    int NY = int(unique(ys+1,ys+N+1)-ys-1);
    for(int i = 1; i < N+1;i++){
        p[i].x = int(lower_bound(xs+1,xs+N+1,p[i].x)-xs);
        p[i].y = int(lower_bound(ys+1,ys+N+1,p[i].y)-ys);
    }
    sort(p+1,p+N+1);
    for(int i = 1; i < N+1;i+=2){
        if(p[i].y != p[i+1].y){ cout << -1 << endl; return;}
        if(bit.sum(p[i].x+1,p[i+1].x-1)){ cout << -1 << endl; return ;}
        for(int j = 0; j < 2;j++){
            int t = bit.sum(p[i+j].x,p[i+j].x);
            if(t){
                ans += ys[p[i+j].y] - ys[p[t].y];
                uf.unionSet(i+j, t);
                bit.add(p[i+j].x,-t);
            }else{
                bit.add(p[i+j].x,i+j);
            }
        }
        ans += xs[p[i+1].x] - xs[p[i].x];
        uf.unionSet(i, i+1);
    }
    if(bit.sum(1,NX)){ cout << -1 << endl; return ;}
    int XX = uf.root(1);
    for(int i = 2; i < N+1;i++){
        if(XX != uf.root(i)){cout << -1 << endl; return ;}
    }
    cout << ans << endl;
}

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    int _; scanf("%d",&_);
    while(_--){
        input();
        solve();
    }
	return 0;
}
