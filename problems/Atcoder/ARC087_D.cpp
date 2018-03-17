#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://arc087.contest.atcoder.jp/tasks/arc087_b>
問題文============================================================
 二次元平面の原点にロボットが置かれています。 最初、ロボットは x 軸の正の向きを向いています。
 
 このロボットに命令列 s が与えられます。 s は次の 2 文字のみからなり、先頭から末尾まで順に実行されます。
 
 F : 今向いている向きに長さ 1 だけ移動する。
 T : 時計回りまたは反時計回りの好きな方向に 90 度だけ向きを変える。
 ロボットの目標は、命令列をすべて実行し終わった後に座標 (x,y) にいることです。
 この目標が達成可能か判定してください。
 
=================================================================

解説=============================================================

 Tによりロボットは時計回り or 反時計回りに必ず向きを変えるので
 この問題は x方向と y方向の移動座標をそれぞれ独立で考えることができる
 
 よって、 xとyに関して、その移動距離(T ~ T までの距離)を持った配列を用意しておき
 dp[i][j] := i番目の移動をするとき, 開始地点 j である
 
 と行ったdpを行えば良い
 
================================================================
*/

const int Base = 10000;
bool dpx[4050][2*Base];
bool dpy[4050][2*Base];

void solve(){
    string s; cin >> s;
    int x,y; cin >> x >> y;
    vector<int> xs,ys;
    
    bool dir = true;
    int cnt = 0;
    for(int i = 0; i < s.length();i++){
        if(s[i] == 'T'){
            if(dir){
                xs.push_back(cnt);
            }else{
                ys.push_back(cnt);
            }
            cnt = 0;
            dir = !dir;
        }else{
            cnt++;
        }
    }
    if(dir){
        xs.push_back(cnt);
    }else{
        ys.push_back(cnt);
    }
    
    dpx[1][xs[0] + Base] = true;
    for(int i = 1; i < (int)xs.size();i++){
        for(int j = 0; j < 2*Base;j++){
            if(!dpx[i][j]) continue;
            dpx[i+1][j+xs[i]] = dpx[i+1][j-xs[i]] = true;
        }
    }
    
    dpy[0][Base] = true;
    for(int i = 0; i < (int)ys.size();i++){
        for(int j = 0; j < 2*Base;j++){
            if(!dpy[i][j]) continue;
            dpy[i+1][j+ys[i]] = dpy[i+1][j-ys[i]] = true;
        }
    }
    if(dpx[xs.size()][Base + x] && dpy[ys.size()][Base + y]){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    solve();
	return 0;
}
