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
 <url:http://poj.org/problem?id=2236>
 問題文============================================================
 N台のコンピュータがそれぞれ二次元座標上の格子点 (xi,yi)にあり、初期状態ではすべて壊れている。
 2台のコンピュータは、距離 D 以下でどちらも修復されていれば、直接通信することができる。
 また、別のコンピュータを経由して通信することもできる。 このとき、
 
     p 番目のコンピュータを修復する
     p 番目のコンピュータと q 番目のコンピュータは通信できるか?
 という2種類の M 個のクエリに答える。
 =================================================================
 
 解説=============================================================
 union find
 
 コンピュータが故障しているか修復されているかをフラグ管理して、union-findすればいい
 ================================================================
 */

int par[1002];//親
int Rank[1002];//木の深さ

void init(int n){
    for(int i = 0;i < n;i++){
        par[i] = i;
        Rank[i] = 0;
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
    
    if(Rank[x] < Rank[y]){
        par[x] = y;
    }else{
        par[y] = x;
        if(Rank[x] == Rank[y])Rank[x]++;
    }
}

bool same(int x,int y){
    return find(x) == find(y);
}


int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    int N,d; cin >> N >> d;
    
    vector<pii> p(N+1);
    vector<int> repaired(N+1,0);
    for(int i = 1; i <= N;i++){
        cin >> p[i].first >> p[i].second;
    }
    init(N+1);
    
    char op;
    while(cin >> op){
        if(op=='O'){
            int n; cin >> n;
            repaired[n] = 1;
            
            for(int i = 1; i <= N;i++){
                if(i == n) continue;
                if(repaired[i] != 1)continue;
                int _x = p[i].first - p[n].first;
                int _y = p[i].second - p[n].second;
                if(_x*_x + _y*_y <= d*d){
                    unite(n,i);
                }
            }
        }else{
            int x,y; cin >> x >> y;
            if(same(x,y)){
                cout << "SUCCESS" << endl;
            }else{
                cout << "FAIL" << endl;
            }
        }
        
    }
    return 0;
}
