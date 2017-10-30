#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60


/*
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0518>
 問題文============================================================
 昔, そこには集落があり, 多くの人が暮らしていた. 人々は形も大きさも様々な建物を建てた.
 だが, それらの建造物は既に失われ, 文献と, 遺跡から見つかった柱だけが建造物の位置を知る手がかりだった.
 文献には神殿の記述がある. 神殿は上から見ると正確に正方形になっており, その四隅には柱があった.
 神殿がどの向きを向いていたかはわからない. また, 辺上や内部に柱があったかどうかもわからない.
 考古学者たちは, 遺跡から見つかった柱の中で, 正方形になっているもののうち,
 面積が最大のものが神殿に違いないと考えた.
 
 柱の位置の座標が与えられるので, 4 本の柱でできる正方形のうち面積が最大のものを探し,
 その面積を出力するプログラムを書け. なお, 正方形の辺は座標軸に平行とは限らないことに注意せよ.
 
 =================================================================
 解説=============================================================
 単純に４点が正方形がなっているか貪欲に探索するとO(n^4)となり間に合わない
 正方形の性質上, ある2点を一辺とすれば、他の2点(対称性を考えれば、もう2点)は一意に定まる。
 とすれば、全点のうちの2点を選べば良いのでO(n^2)
 しかし、計算した他2点が与えられた点として確認する際に探索(O(log n))を行うと制約から
 間に合わなくなるので、hashを用いてO(1)で確認する
 動的にhash及び頂点群を生成するとMLEとなるので注意
 ================================================================
 */

pll ps[3001];
bool m[5001][5001];

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll N;
    while(cin >> N, N){
        for(int i = 0; i < 5001;i++)for(int j = 0; j < 5001;j++) m[i][j] = false;
        vector<pll> ps(N);
        for(int i = 0; i < N; i++){
            cin >> ps[i].first >> ps[i].second;
            m[ps[i].first][ps[i].second] = true;
        }
        ll res = 0;
        for(int i = 0; i < N;i++){
            for(int j = i+1;j <N;j++){
                ll x1 = ps[i].first,y1 = ps[i].second,x2 = ps[j].first,y2 = ps[j].second;
                
                ll area = (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1);
                if(area <= res) continue;
                ll x3 = x1 + (y1 - y2),y3 = y1 + (x2 - x1);
                if(x3 >= 0 && x3 <= 5000 && y3 >= 0 && y3 <= 5000){
                    if(m[x3][y3]){
                        ll x4 = x2 + (x3 - x1), y4 = y2 + (y3 - y1);
                        if(x4 >= 0 && x4 <= 5000 && y4 >= 0 && y4 <= 5000){
                            if(m[x4][y4]){
                                res = area;
                                continue;
                            }
                        }
                    }
                }
                x3 = x1 - (y1 - y2), y3 = y1 - (x2 - x1);
                if(x3 >= 0 && x3 <= 5000 && y3 >= 0 && y3 <= 5000){
                    if(m[x3][y3]){
                        ll x4 = x2 + (x3 - x1), y4 = y2 + (y3 - y1);
                        if(x4 >= 0 && x4 <= 5000 && y4 >= 0 && y4 <= 5000){
                            if(m[x4][y4]){
                                res = area;
                                continue;
                            }
                        }
                    }
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}
