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
#define INF (1<<30)
#define LINF (1LL<<60)

/*
 <url:http://poj.org/problem?id=3109>
 問題文============================================================
 無限平面上にN(N≤10^5)個の黒点が与えられる。
 それ以外は白点である。上下左右に黒点がある場合は、その点は黒点になる。黒点の総数を求めよ。
 =================================================================
 
 解説=============================================================
 最初に座標圧縮を行なっておく
 
 BITを使う
 次にy,x の優先度でソートを行う。
 順番に数列を見ていった時,xで囲まれている範囲に＋１をaddし、現在のxの値で、
 範囲で指定した合計を取る。この時、フラグ管理等で交差していると判定できれば答ええが+1
 ================================================================
 */

#define MAX_N 100050

ll bit0[MAX_N],bit1[MAX_N];
ll sum(ll *b,int i){
    int s = 0;
    while (i > 0) {
        s += b[i];
        i -= (i & -i);
    }
    return s;
}

void add(ll *b,int i,ll x){
    while (i <= MAX_N) {
        b[i] += x;
        i += (i & -i);
    }
}

//[0,n]
ll sum(int i){
    return sum(bit1, i)*i + sum(bit0, i);
}

//(l,r]
ll range_sum(int l,int r){
    return sum(r) - sum(l);
}

//[l,r]
void range_add(int l,int r,ll x){
    add(bit0, l, -x*(l-1));
    add(bit1, l,  x);
    add(bit0, r,  x*r);
    add(bit1, r, -x);
}
int N;
int xs[MAX_N],ys[MAX_N];

vector<int> G[MAX_N];
bool check[MAX_N];
int compress(int p[]){
    vector<int> ps;
    ps.resize(N);
    for (int i=0; i<N; ++i) {
        ps[i] = p[i];
    }
    sort(ps.begin(), ps.end());
    ps.erase(unique(ps.begin(), ps.end()), ps.end());
    for (int i=0; i<N; ++i) {
        p[i] = 2 + (int)distance(ps.begin(), lower_bound(ps.begin(), ps.end(), p[i]));
    }
    return 2 + (int)ps.size();
}

int main(void) {
    //	cin.tie(0); ios::sync_with_stdio(false);
    scanf("%d",&N);
    for(int i = 0 ; i < N;i++) scanf("%d %d",&xs[i],&ys[i]);
    int X = compress(xs);
    int Y = compress(ys);
    
    for(int i = 0; i < N;i++){
        G[ys[i]].push_back(xs[i]);
    }
    for(int i = 0; i < Y;i++) sort(G[i].begin(),G[i].end());
    
    ll ans = N;
    for(int y = 0; y < Y;y++){
        int _Size = (int)G[y].size();
        
        for(int i = 0; i < _Size;i++){
            int x = G[y][i];
            int s = range_sum(x-1, x);
            
            if(check[x]){
                ans += s;
            }
            
            check[x] = true;
            add(bit0,x,-s);
            if(i + 1 < _Size){
                if(x + 1 < G[y][i+1]-1){
                    range_add(x+1,G[y][i+1]-1,1);
                }else if(x+1 == G[y][i+1]-1){
                    add(bit0,x+1,1);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
