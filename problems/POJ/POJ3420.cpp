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
 <url:>
 問題文============================================================
 
 =================================================================
 
 解説=============================================================
 
 ================================================================
 */

typedef vector<ll> vec;
typedef vector<vec> mat;

mat mul(mat&A,mat&B,ll M){
    mat C(A.size(),vec(B[0].size()));
    for(int i = 0; i < (int)A.size();i++){
        for(int k = 0; k < (int)B.size();k++){
            for(int j = 0; j < B[0].size();j++){
                C[i][j] = (C[i][j] + A[i][k]*B[k][j])%M;
            }
        }
    }
    return C;
}

mat pow(mat A,ll n,ll M){
    mat B(A.size(),vec(A.size()));
    for(int i = 0; i < A.size();i++){
        B[i][i] = 1;
    }
    while(n > 0){
        if(n&1) B= mul(B,A,M);
        A = mul(A,A,M);
        n>>=1;
    }
    return B;
}

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll tmpA[6][6] = {
        { 1, 1, 1, 1, 0, 1 },
        { 1, 0, 0, 1, 0, 0 },
        { 1, 0, 0, 0, 1, 0 },
        { 1, 1, 0, 0, 0, 0 },
        { 0, 0, 1, 0, 0, 0 },
        { 1, 0, 0, 0, 0, 0 }
    };
    ll tmpB[6][1] = {
        { 1 },
        { 1 },
        { 1 },
        { 1 },
        { 0 },
        { 1 }
    };
    mat A(6,vec(6,0));
    mat B(6,vec(1,0));
    for(int i = 0; i < 6;i++)for(int j = 0; j < 6;j++) A[i][j] = tmpA[i][j];
    for(int i = 0; i < 6;i++)for(int j = 0; j < 1;j++) B[i][j] = tmpB[i][j];
    ll N,M;
    while(cin >> N >> M){
        if(N == 0 && M == 0) break;
        mat retA = pow(A,N-1,M);
        mat res = mul(retA, B,M);
        cout << res[0][0] << endl;
    }
    return 0;
}
