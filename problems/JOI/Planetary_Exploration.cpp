
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
 <url:https://www.ioi-jp.org/joi/2010/2011-ho-tasks_data/2011-ho.pdf>
 問題文============================================================
 あなたを乗せた超時空移民船は長旅の末，ついに居住可能と思われる惑星を発見した．
 JOI 星と名付けられたその惑星は，
 その名の通り「ジャングル (Jungle)」，「海 (Ocean)」，「氷 (Ice)」の 3 種類の地形が
 入り組んだ過酷な惑星である．簡単な調査により，居住予定地近辺の地図が作成された．
 居住予定地は南北 M km, 東西 N km の長方形の形をしており， 1 km 四方の正方形の区画に分けられている．
 区画は全部で MN 個あり，北から p 行目，西から q 列目の区画を (p, q) で表す．
 北西の角の区画が(1, 1) であり，南東の角の区画が (M, N) である．
 各区画の地形は，「ジャングル」，「海」，「氷」のいずれかで
 あり，「ジャングル」は J, 「海」は O, 「氷」は I の英字 1 文字で表される.
 さて，詳細な移住計画を立てるにあたり，
 K 箇所の長方形領域内に「ジャングル」，「海」，「氷」がそれぞれ何区画含まれるかを調べることにした．
 
 居住予定地の情報と，調査対象となる領域の情報が与えられたとき，
 それぞれの領域について， 「ジャングル」，「海」，「氷」 が何区画含まれているかを求めるプログラムを作成せよ．
 =================================================================
 解説=============================================================
 二次元累積和で計算すればはい
 ================================================================
 */
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll M,N; cin >> M >> N;
    ll K; cin >> K;
    vector<vector<char>> masu(M+1,vector<char>(N+1));
    for(int i = 1; i<=M;i++){
        for(int j = 1; j <= N;j++){
            cin >> masu[i][j];
        }
    }
    vector<vector<int>> dpJ(M+1,vector<int>(N+1,0));
    vector<vector<int>> dpO(M+1,vector<int>(N+1,0));
    vector<vector<int>> dpI(M+1,vector<int>(N+1,0));
    
    for(int i = 1; i <= M;i++){
        for(int j = 1;j<=N;j++){
            int costJ = 0, costO = 0,costI = 0;
            
            if(masu[i][j] == 'J') costJ = 1;
            else if(masu[i][j] == 'O') costO = 1;
            else costI = 1;
            
            dpJ[i][j] = dpJ[i-1][j] + dpJ[i][j-1] - dpJ[i-1][j-1] + costJ;
            dpO[i][j] = dpO[i-1][j] + dpO[i][j-1] - dpO[i-1][j-1] + costO;
            dpI[i][j] = dpI[i-1][j] + dpI[i][j-1] - dpI[i-1][j-1] + costI;
        }
    }
    
    for(int k = 0; k < K;k++){
        int a,b,c,d; cin >> a >> b >> c >>d;
        int resJ = dpJ[c][d] - dpJ[a-1][d] - dpJ[c][b-1] + dpJ[a-1][b-1];
        int resO = dpO[c][d] - dpO[a-1][d] - dpO[c][b-1] + dpO[a-1][b-1];
        int resI = dpI[c][d] - dpI[a-1][d] - dpI[c][b-1] + dpI[a-1][b-1];
        
        cout << resJ << " " << resO << " " << resI << endl;
    }
    
    return 0;
}
