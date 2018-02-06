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
 <url:http://poj.org/problem?id=2155>
 問題文============================================================
 N*N(N≤1000)の配列が与えられる。
 各要素は、1か0しか値をとることができない。
 
 ふたつのクエリに対する処理を実行せよ。
     (x,y)の要素が1なのか0なのか求めよ
     (x1,y1,x2,y2)の範囲をフリップせよ
 =================================================================
 
 解説=============================================================
 二次元BITを使い、指定区間の範囲にある値の合計を取る。
 それが偶数か奇数かによって判定することができる
 ================================================================
 */

struct TwoDimBIT {
    int H,W;
    vector<vector<ll> > bit;
    TwoDimBIT(int H,int W):H(H),W(W) {
        /* BITは[1..H][1..W]で扱う */
        bit.assign(H+1,vector<ll>(W+1,0));
    }
    
    void add(int a,int b,int val)
    {
        for(int x = a; x<= H; x+= (x&-x)){
            for(int y = b; y<=W;y+=(y&-y)){
                (bit[x][y] += val)%=2;
            }
        }
    }
    
    int sum(int a,int b)
    {
        int ret = 0;
        for(int x = a; x > 0; x-= (x& -x)){
            for(int y = b; y > 0; y-= (y&-y)){
                (ret += bit[x][y])%=2;
            }
        }
        return (ret);
    }
};

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    int Kassa; cin >> Kassa;
    for(int kassa = 0; kassa < Kassa; kassa++){
        int N,T; cin >> N >> T;
        TwoDimBIT _bit(N+1,N+1);
        for(int i = 0; i < T;i++){
            char op; cin >> op;
            if(op == 'C'){
                int x1,y1,x2,y2; cin >> x1 >>y1 >> x2 >> y2;
                _bit.add(x1,y1,1);
                _bit.add(x1,y2+1,1);
                _bit.add(x2+1,y1,1);
                _bit.add(x2+1,y2+1,1);
            }else{
                int x,y; cin >> x >> y;
                ll cnt = 0;
                cnt += _bit.sum(x,y);
                cout << (cnt%2) << endl;
            }
        }
        cout << endl;
    }
    return 0;
}
