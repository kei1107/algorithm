#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://arc061.contest.atcoder.jp/tasks/arc061_b>
問題文============================================================
 縦 H 行、横 W 列のマス目からなる盤があります。最初、どのマス目も白く塗られています。
 
 すぬけ君が、このうち N マスを黒く塗りつぶしました。
 i 回目 ( 1≤i≤N ) に塗りつぶしたのは、 上から ai 行目で左から bi 列目のマスでした。
 
 すぬけ君がマス目を塗りつぶした後の盤の状態について、以下のものの個数を計算してください。
 
 各整数 j ( 0≤j≤9 ) について、盤の中に完全に含まれるすべての 3 行 3 列の連続するマス目のうち、
 黒いマスがちょうど j 個あるもの。

 制約
 3≤H≤10^9
 3≤W≤10^9
 0≤N≤min(10^5,H×W)
 1≤ai≤H (1≤i≤N)
 1≤bi≤W (1≤i≤N)
 (ai,bi)≠(aj,bj) (i≠j)
=================================================================

解説=============================================================

 範囲が広い。　＝＞　座標圧縮してもいいけど400にしては面倒臭いしメモリが心配
 
 別の考え方をする。
 今回調べるますは3x3と小さく限定されている。
 ここであるマスが3x3の正方形の領域に含まれる可能性があるのは
 
 正方形の左上のマスを基準とした書き方だと
 マス(a,b)に対して
 
 (a - i, b - j) : ΣΣ{i,j} { -2 -> 0 }
 
 の9通り（範囲外に注意）
 
 黒塗りの頂点数は高々10^5 なので、
 黒ますを内部にもつ正方形としてあり得る個数は 高々 9 * 10^5 個
 ０個の個数に関しては後であり得る正方形の個数から引けばいいので すぐもとまる。
 
 連想配列などで特定マスの位置だけ所持しておけば O(NlogN)で求まる
 
 
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll H,W,N; cin >> H >> W >> N;
    vector<ll> a(N),b(N);
    for(int i = 0; i < N;i++) cin >> a[i] >> b[i];
    
    map<pll,ll> mp;
    for(int i = 0; i < N;i++){
        for(int j = -2; j <= 0; j++){
            for(int k = -2; k <= 0; k++){
                ll nx = a[i] + j,ny = b[i] + k;
                if(nx <= 0 || nx >= H - 1 || ny <= 0 || ny >= W - 1) continue;
                mp[pll(nx,ny)]++;
            }
        }
    }
    ll ans[10] = {0};
    for(auto it = mp.begin(); it != mp.end(); it++) ans[it->second]++;
    
    ll sum = (H - 2) * (W - 2);
    for(auto v:ans){
        sum -= v;
    }
    ans[0] += sum;
    for(auto v:ans){
        cout << v << endl;
    }
    
	return 0;
}
