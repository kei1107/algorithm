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
#define INF (1<<30)
#define LINF (1LL<<60)

/*
 <url:http://poj.org/problem?id=3735>
 問題文============================================================
 猫がN匹いる。3種類の命令が存在し、それが「g i」ならi番目の猫の持つピーナツをひとつ増やす。
 「e i」ならi番目の猫が持つピーナツの数をゼロにする。
 「s i j」ならi番目とj番目の猫が所有するピーナツを交換する。
 これらの命令が１セット中にk回与えられる。
 ｍセット行った後に各猫が持つピーナツの数を求める問題。
 =================================================================
 
 解説=============================================================
 N = 3 k = 3
 g 1
 s 1 2
 e = 2
 とすると、mステップ目でi番目の猫のピーナッツの個数をxm,ym,zmとすると
 初期状態は
 |xm    |       |1 0 0 0||xm-1  |
 |ym    |   =   |0 1 0 0||ym-1  |
 |zm    |       |0 0 1 0||zm-1  |
 |const |       |0 0 0 1||const |
 
 g 1
 |xm    |       |1 0 0 1||xm-1  |
 |ym    |   =   |0 1 0 0||ym-1  |
 |zm    |       |0 0 1 0||zm-1  |
 |const |       |0 0 0 1||const |
 
 s 1 2
 |xm    |       |0 1 0 0||xm-1  |
 |ym    |   =   |1 0 0 1||ym-1  |
 |zm    |       |0 0 1 0||zm-1  |
 |const |       |0 0 0 1||const |

 e 2
 |xm    |       |0 1 0 0||xm-1  |
 |ym    |   =   |0 0 0 0||ym-1  |
 |zm    |       |0 0 1 0||zm-1  |
 |const |       |0 0 0 1||const |
 
 となり、これが１ステップでの遷移行列
 mステップ目では
 |xm    |       |0 1 0 0|^m |x0  |
 |ym    |   =   |0 0 0 0|   |y0  |
 |zm    |       |0 0 1 0|   |z0  |
 |const |       |0 0 0 1|   |const |
 が答えとなる
 x0 = y0 = z0 = 0
 
 よって、この形を生成して行列累乗で解ける
 ================================================================
 */

typedef vector<ll> vec;
typedef vector<vec> mat;

int n,m,k;

mat mul(mat&A,mat&B){
    mat C(A.size(),vec(B[0].size()));
    for(int i = 0; i < (int)A.size();i++){
        for(int k = 0; k < (int)B.size();k++){
            if(A[i][k] == 0) continue;
            for(int j = 0; j < B[0].size();j++){
                C[i][j] = (C[i][j] + A[i][k]*B[k][j]);
            }
        }
    }
    return C;
}

mat pow(mat A,ll n){
    mat B(A.size(),vec(A.size()));
    for(int i = 0; i < A.size();i++){
        B[i][i] = 1;
    }
    while(n > 0){
        if(n&1) B= mul(B,A);
        A = mul(A,A);
        n>>=1;
    }
    return B;
}


int main(void) {
    //	cin.tie(0); ios::sync_with_stdio(false);
    while(true){
        scanf("%d%d%d",&n,&m,&k);
        if(n == 0 && m == 0 && k == 0) break;
        mat A(n+1,vec(n+1,0));
        for(int i = 0; i <=n;i++) A[i][i] = 1;
        for(int i = 0;i < k;i++){
            char buf[5];
            scanf("%s",buf);
            if(buf[0] == 'g'){
                int x; scanf("%d",&x); x--;
                A[x][n]++;
            }
            if(buf[0] == 's'){
                int x,y; scanf("%d%d",&x,&y); x--; y--;
                for(int i = 0; i <= n;i++) swap(A[x][i],A[y][i]);
            }
            if(buf[0] == 'e'){
                int x; scanf("%d",&x); x--;
                for(int i = 0;i <= n;i++) A[x][i] = 0;
            }
        }
        
        mat res = pow(A,m);
        
        for(int i = 0; i < n;i++){
            if(i != n - 1){
                printf("%lld ",res[i][n]);
            }else{
                printf("%lld\n",res[i][n]);
            }
        }
    }
    return 0;
}
