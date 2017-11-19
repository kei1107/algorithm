#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
 <url:https://joi2014ho.contest.atcoder.jp/img/other/joi2014ho/joi2014ho1.pdf>
 問題文============================================================
 JOI旗がある。JOI旗は、正方形が縦にM(2<=M<=1000)行、横にN(2<=N<=1000)列並んだ
 形をしており、各正方形にはJ,O,Iのいずれかの文字が1つずつ書かれている
 
 情報オリンピック日本委員会はJOI 旗とは別にJOI 紋章というものを決めている．
 JOI 紋章は，正方形が縦に2 行，横に2 列並んだ形をしており，
 各正方形にはJ，O，I のいずれかの文字が1 つずつ書かれている．
 
 JOI 旗に含まれるJOI 紋章の個数とは，JOI 旗に含まれる縦2 行，横2 列の領域のうち，
 その領域のJ，O，I の配置がJOI 紋章と(回転や裏返しをせずに) 一致しているものの個数のことである．
 条件を満たす縦2 行，横2 列の領域同士が重なっていてもそれらを別々に数えるものとする．
 
 情報オリンピック日本委員会は古いJOI 旗と1 枚の白紙を持っている．
 白紙はJOI 旗を構成する正方形1 個分の大きさで，J，O，I のうち好きな1 文字を書き込むことができる．
 情報オリンピック日本委員会は以下のいずれか1 つの操作をして，新しいJOI 旗を作成することにした．
 
 ・古いJOI 旗に対して何も操作せず，そのまま新しいJOI 旗とする．白紙は使用しない．
 ・白紙に1 文字書き込み，古いJOI 旗のいずれかの正方形に重ねて貼り付けることで古いJOI 旗のうち1 箇所を変更する
 ．変更後のJOI 旗を新しいJOI 旗とする．
 
 情報オリンピック日本委員会は新しいJOI 旗に含まれるJOI 紋章の個数をできるだけ多くしたいと思っている．
 あなたは新しいJOI 旗に含まれるJOI 紋章の個数の最大値を求めることになった．
 =================================================================
 解説=============================================================
 
 やるだけ
 
 ある地点(y,x)の旗を変えた時、影響が出るのはその８方向１マスのみ
 あとはシミュレーション
 ================================================================
 */
vector<vector<char>> m;
char flag[2][2];
ll Cnt = 0;
ll res = 0;
ll M,N;

ll calc(int y,int x,char c){
    ll cnt1 = 0;
    for(int i = y - 1; i <= y;i++){
        for(int j = x - 1; j<=x;j++){
            bool f = false;
            for(int ii = 0; ii < 2;ii++){
                for(int jj = 0; jj < 2;jj++){
                    if(flag[ii][jj] == m[i + ii][j + jj])continue;
                    f = true; break;
                }
                if(f)break;
            }
            if(f)continue;
            cnt1++;
        }
    }
    char C = m[y][x];
    m[y][x] = c;
    ll cnt2 = 0;
    for(int i = y - 1; i <= y;i++){
        for(int j = x - 1; j<=x;j++){
            bool f = false;
            for(int ii = 0; ii < 2;ii++){
                for(int jj = 0; jj < 2;jj++){
                    if(flag[ii][jj] == m[i + ii][j + jj])continue;
                    f = true; break;
                }
                if(f)break;
            }
            if(f)continue;
            cnt2++;
        }
    }
    m[y][x] = C;
    return cnt2 - cnt1;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> M >> N;
    m.assign(M+2,vector<char>(N+2,'#'));
    for(int i = 1; i <= M;i++)for(int j = 1; j<=N;j++) cin >> m[i][j];
    for(int i = 0; i < 2;i++)for(int j = 0; j < 2;j++) cin >> flag[i][j];
    for(int i = 1; i < M;i++){
        for(int j = 1; j < N;j++){
            bool f = false;
            for(int ii = 0; ii < 2;ii++){
                for(int jj = 0; jj < 2;jj++){
                    if(flag[ii][jj] == m[i + ii][j + jj])continue;
                    f = true; break;
                }
                if(f)break;
            }
            if(f)continue;
            Cnt++;
        }
    }
    res = Cnt;
    ll tmp = 0;
    for(int i = 1; i <= M;i++){
        for(int j = 1; j <= N;j++){
            tmp = max(tmp,calc(i,j,'J'));
            tmp = max(tmp,calc(i,j,'O'));
            tmp = max(tmp,calc(i,j,'I'));
        }
    }
    
    cout << res + tmp << endl;
    return 0;
}
