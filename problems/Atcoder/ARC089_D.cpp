#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://arc089.contest.atcoder.jp/tasks/arc089_b>
問題文============================================================
シカのAtCoDeerくんは無限に広がる二次元グリッドを一辺が K の市松模様で塗ろうと考えています。
 ただし、一辺が K の市松模様とは、各マスが白か黒で塗られたパターンであって、
 各色の各連結成分が K × K の正方形となっているようなものです。
 
 AtCoDeerくんは N 個の希望を持っています。 i 個目の希望は、 xi,yi,ci で表されます。
 これは、ci が B ならマス (xi,yi) を黒で塗る、 W なら白で塗ることを意味しています。
 同時に最大でいくつの希望を叶えることが出来るか答えてください。
 
=================================================================

解説=============================================================

 市松模様の性質を考えると、次のような変換ができる
 (x,y,W) := 位置x,yが'W'であることを希望 とすると
 
 (x,y,W) = (x+K,y,B)
 (x,y,B) = (x%2K,y%2K,B)
 
 よって、全ての希望は W or B でありx,yの範囲を[0,2K)に収めることができる
 よって、二次元累積和を用いて各パターンに関してO(1)で希望を満たすものの個数を答えることができ、
 O(4*K^2)の計算量で解ける
 
================================================================
*/
vector<vector<int>> cusum;
inline int f(int lx,int ly,int rx,int ry){
    return cusum[rx][ry] - cusum[rx][ly] - cusum[lx][ry] + cusum[lx][ly];
}

int solve(){
    int N,K; cin >> N >> K;
    vector<ll> x(N),y(N);
    vector<char> c(N);
    for(int i = 0; i < N;i++) cin >> x[i] >> y[i] >> c[i];

    // (x,y,B) := (x+K,y,W)
    for(int i = 0; i < N;i++){
        if(c[i] == 'B') x[i] += K; c[i] = 'W';
    }
    
    // (x,y,W) := (x%2K,y%2K,W)
    for(int i = 0; i < N;i++){
        x[i] %= 2*K; y[i] %= 2*K;
    }
    // init cusum
    cusum.resize(2*K+1,vector<int>(2*K+1,0));
    for(int i = 0; i < N;i++){
        cusum[x[i]+1][y[i]+1]++;
    }
    
    for(int i = 1; i <= 2*K;i++){
        for(int j = 1; j <= 2*K;j++){
            cusum[i][j] += cusum[i][j-1] + cusum[i-1][j] - cusum[i-1][j-1];
        }
    }
    
    // solver
    int ans = 0;
    for(int i = 1; i <= 2*K;i++){
        for(int j = 1; j <= 2*K;j++){
            if(i <= K && j <= K){
                ans = max(ans,
                          f(0,0,i,j)+
                          f(i,j,i+K,j+K)+
                          f(0,j+K,i,2*K)+
                          f(i+K,0,2*K,j)+
                          f(i+K,j+K,2*K,2*K)
                          );
            }
            if(i > K && j > K){
                ans = max(ans,
                          f(i-K,j-K,i,j)+
                          f(0,0,i-K,j-K)+
                          f(0,j,i-K,2*K)+
                          f(i,0,2*K,j-K)+
                          f(i,j,2*K,2*K)
                          );
            }
            if(i <= K && j > K){
                ans = max(ans,
                          f(0,j-K,i,j)+
                          f(i,j,i+K,2*K)+
                          f(i,0,i+K,j-K)+
                          f(i+K,j-K,2*K,j)
                          );
            }
            if(i > K && j <= K){
                ans = max(ans,
                          f(i-K,0,i,j)+
                          f(i,j,2*K,j+K)+
                          f(0,j,i-K,j+K)+
                          f(i-K,j+K,i,2*K)
                          );
            }
        }
    }
    return ans;
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    cout << solve() << endl;
	return 0;
}
