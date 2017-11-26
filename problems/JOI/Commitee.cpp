#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
 <url:>
 問題文============================================================
 根を０とした木構造が与えられる。
 各辺にはコストが与えられており、根から子を辿って行った時のそのコストが最大となる時の値を求める
 根を除いた頂点数n(<=100000), i番目の頂点の親をsi(0<=si<i), コストai(-100<=ai<=100)
 =================================================================
 解説=============================================================
 
 ================================================================
 */

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n; cin >> n;
    vector<pair<int,int>> sa(n+1,{0,0});
    vector<int> cusum(n+1,0);
    for(int i = 1; i <= n;i++){
        cin >> sa[i].first >> sa[i].second;
        cusum[i] = cusum[sa[i].first] + sa[i].second;
    }
    
    return 0;
}
