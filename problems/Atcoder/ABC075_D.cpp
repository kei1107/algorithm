#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = LLONG_MAX;

/*
<url:https://abc075.contest.atcoder.jp/tasks/abc075_d>
問題文============================================================
 2次元座標上に N 個の点があります。
 i(1≦i≦N) 番目の点の座標は (xi,yi) です。
 長方形の内部に N 点のうち K 個以上の点を含みつつ、それぞれの辺がX軸かY軸に平行な長方形を考えます。
 このとき、長方形の辺上の点は長方形の内部に含みます。
 それらの長方形の中で、最小の面積となるような長方形の面積を求めてください。
=================================================================

解説=============================================================

 長方形の右上と左下の角が頂点となり得るx、y値（全頂点のx,yの値）
 で全探索、
 
 O(N^4 * N)
 
 N(<=50)から50^4 * 50 ~ 10^7
 間に合う
 
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N,K; cin >> N >> K;
    vector<pll> ps(N);
    vector<ll> X(N),Y(N);
    for(int i = 0; i < N;i++){
        cin >> ps[i].first >> ps[i].second;
        X[i] = ps[i].first; Y[i] = ps[i].second;
    }
    sort(X.begin(),X.end()); sort(Y.begin(),Y.end());
    
    ll ans = LINF;
    for(int xi = 0; xi < N; xi++){
        for(int xj = xi + 1; xj < N; xj++){
            for(int yi = 0; yi < N; yi++){
                for(int yj = 0; yj < N; yj++){
                    
                    int cnt = 0;
                    ll minx = X[xi], miny = Y[yi];
                    ll maxx = X[xj], maxy = Y[yj];
                    for(int k = 0; k < N;k++){
                        if(minx <= ps[k].first &&
                           ps[k].first <= maxx &&
                           miny <= ps[k].second &&
                           ps[k].second <= maxy)
                            cnt++;
                    }
                    if(cnt >= K){
                        ans = min(ans,(maxx-minx)*(maxy-miny));
                    }
                }
            }
        }
    }

    cout << ans << endl;
	return 0;
}
