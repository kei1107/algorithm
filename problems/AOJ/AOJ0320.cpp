#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e16;

/*
<url:https://onlinejudge.u-aizu.ac.jp/#/problems/0320>
問題文============================================================
 会津タカダ市が生産販売する布製コースターは、対称なデザインでとても美しいことで知られている。
 会津タカダ市では品質管理の一環として、製造ラインにカメラを設置し
 、各コースターを撮影して得られた画像が対称になっているかを自動で検証している。
 各コースターは N × N ピクセルの正方形の白黒画像として表される。
 各ピクセルは白または黒の画像に対応して、0 または 1 の値をとる。
 
 この度、生産ラインの機器更新にともなって、画像解析システムのソフトウェアを更新することになった。
 新システムでは、通信データ量を削減する工夫がなされ、
 以下の方法でカメラから解析システムにデータが送られてくる。
 
 ラインに流れてくる最初のコースターの情報は、N × N ピクセルの画像としてシステムに送られてくる。
 ２枚目以降のコースターの情報は、１つ前に送られた画像との差分だけが送られてくる。
 差分は、「0 から 1 」または「1 から 0 」へと変化したピクセルの位置の集合として与えられる。
 C 枚のコースターについて、１枚目の画像のピクセル情報と続く C - 1 枚分の差分情報を入力し、
 上下対称かつ左右対称となっているコースターの枚数を報告するプログラムを作成せよ。
 
=================================================================

解説=============================================================

 クエリは最大で10^7なので、対象判定をO(1)で行わなければならない。
 各マスと、それに対応する４方の情報(何個が1であるかなど）を持っておき、
 反転に合わせてその情報を変化させていき、対称判定を行えばO(1)でできる
 （何個が1であるかを持っていれば、 合計値が0または4であればそのマスは対称であり、
     対称なマスの数がN*N/4となっていれば全体が対称)
 
 
================================================================
*/

int retIdx(int i,int j,int N){
    if(i <= N/2 && j <= N/2){
        return (i-1)*N/2 + j;
    }else if(i > N/2 && j <= N/2){
        return (N-i)*N/2 + j;
    }else if(i <= N/2 && j > N/2){
        return (i-1)*N/2 + (N-j+1);
    }else{
        return (N-i)*N/2 + (N-j+1);
    }
    
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    int C,N; cin >> C >> N;
    vector<int> bit(N*N/4 + 1,0);
    vector<vector<int>> p(N+1,vector<int>(N+1,0));
    for(int i = 1; i <=N;i++){
        for(int j = 1; j <=N;j++){
            char c; cin >> c;
            p[i][j] = c - '0';
            
            if(p[i][j] == 1){
                bit[retIdx(i, j, N)]++;
            }
        }
    }
    int sum = 0;
    for(int i = 1; i <= N*N/4;i++) {
        if(bit[i] == 0 || bit[i] == 4){
            sum++;
        }
    }
    int ans = 0;
    if(sum == N*N/4) ans++;
    for(int i = 0; i < C - 1;i++){
        int D; cin >> D;
        for(int j = 0; j < D;j++){
            int r,c; cin >> r >> c;
            int idx = retIdx(r,c,N);
            
            if(bit[idx] == 0 || bit[idx] == 4) sum--;
            
            if(p[r][c] == 0){
                p[r][c] = 1;
                bit[idx]++;
            }else{
                p[r][c] = 0;
                bit[idx]--;
            }
            if(bit[idx] == 0 || bit[idx] == 4) sum++;
            
        }
        if(sum == N*N/4)ans++;
    }
    cout << ans << endl;
	return 0;
}