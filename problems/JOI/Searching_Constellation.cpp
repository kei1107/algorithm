#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
 <url:https://www.ioi-jp.org/joi/2007/2008-yo-prob_and_sol/2008-yo-t4/2008-yo-t4.html>
 問題文============================================================
 あなたは星空の写真の中から星座を探している．
 写真には必ず，探したい星座と同じ形・向き・大きさの図形がちょうど一つ含まれている．
 ただし，写真の中には星座を構成する星以外に余分な星が写っている可能性がある．
 
 図略
 
 例えば，図 1 の星座は図 2 の写真に含まれている（丸で囲んで示した）．
 与えられた星座の星の座標を x 方向に 2， y 方向に －3 だけ平行移動すると写真の中の位置になる．
 
 探したい星座の形と写真に写っている星の位置が与えられたとき，
 星座の座標を写真の中の座標に変換するために平行移動するべき量を答えるプログラムを書け．
 =================================================================
 解説=============================================================
 
 星座を構成する星は最大m := 200個、写真に写っている星は最大n := 1000個、そして制約は10s
 最初の一点の星を決め打ちして, 順番に探したい星座が最初の一点の星から相対的な距離に存在するか探せばよい
 探索時間はlog n であるので総計算量はO(mnlog n) 、絶対間に合う
 
 ================================================================
 */
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    int m;
    while(cin >> m,m){
        vector<pii> ps1(m);
        for (int i = 0; i < m;i++) cin >> ps1[i].first >> ps1[i].second;
        int n; cin >> n;
        vector<pii> ps2(n);
        for (int i = 0; i < n;i++) cin >> ps2[i].first >> ps2[i].second;
        
        int idx;
        bool f = false;
        for (int i = 0; i < n;i++) {
            idx = i;
            for (int j = 1; j < m;j++) {
                int nx = ps2[idx].first + (ps1[j].first - ps1[j - 1].first);
                int ny = ps2[idx].second + (ps1[j].second - ps1[j - 1].second);
                auto next_it = find(ps2.begin(), ps2.end(), make_pair(nx, ny));
                if (next_it == ps2.end())break;
                idx = next_it - ps2.begin();
                if (j == m - 1) {
                    cout << ps2[i].first - ps1[0].first << " " << ps2[i].second - ps1[0].second << endl;
                    f = true;
                }
            }
            if (f)break;
        }
    }
    return 0;
}
