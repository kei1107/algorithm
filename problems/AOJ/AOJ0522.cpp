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
 与えられた文字列内の連続する3文字が，JOIまたはIOIという並びになっている個所が
 それぞれ何個所あるのかを数え上げるプログラムを作成せよ．
 文字列はアルファベットの大文字だけからなる．
 例えば下図の「JOIOIOI」という文字列にはJOIが1個所，IOIが2個所に含まれている．
 =================================================================
 解説=============================================================
 はい
 ================================================================
 */
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    string S;
    string joi = "JOI",ioi = "IOI";
    int cnt_joi,cnt_ioi;
    while(cin >> S){
        cnt_joi = cnt_ioi = 0;
        for(int i = 0; i < S.length() - 2;i++){
            string subS = S.substr(i,3);
            if(subS == joi) cnt_joi++;
            if(subS == ioi) cnt_ioi++;
        }
        cout << cnt_joi << endl;
        cout << cnt_ioi << endl;
    }
    return 0;
}
