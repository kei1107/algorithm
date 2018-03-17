#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://code-festival-2017-quala.contest.atcoder.jp/tasks/code_festival_2017_quala_c>
問題文============================================================
 縦 H 行、横 W 列の行列 A があります。
 上から i 行目、左から j 列目の要素を aij とします。 各 aij は英小文字です。
 
 すぬけ君は、A の要素を自由に並べ替え、縦 H 行、横 W 列の行列 A' を作ろうとしています。
 このとき、次の条件が成り立つようにします。
 
 A' のどの行およびどの列もそれぞれ回文になっている。
 条件を満たす A' が存在するか判定してください。
 
 1≤H,W≤100
 aij は英小文字である。

=================================================================

解説=============================================================

 まず、全ての行と列が回文となるには、
 ある要素を四方の４つ用いるものを f
 ある要素を左右（or 上下)の2つ用いるものを t
 ある要素を１つ用いるものを o
 とすると、次のパターンしかない
 
 ftf    ffff    ftf     ffff
 tot    tttt    ftf     ffff
 ftf    ffff    ftf     ffff
                ftf     ffff
 
 よって、このいづれか一つのパターンに合うようなアルファベットの個数の組み合わせが
 入力として与えられればYESとなる
================================================================
*/
string solve(){
    int H,W; cin >> H >> W;
    int alpha[26] = {};
    for(int i = 0; i < H;i++){
        for(int j = 0; j < W;j++){
            char c; cin >> c;
            alpha[c-'a']++;
        }
    }
    int four = 0, two = 0, one= 0;
    if(H&1) two += W/2;
    if(W&1) two += H/2;
    if(H&W&1) one = 1;
    four = H*W - two*2 - one; four/=4;

    // 確定で決められるものを先にはじく
    for(int i = 0; i < 26;i++){
        if(alpha[i] == 0) continue;
        if(alpha[i]%2 == 1){
            if(one == 0) return "No";
            one--;
            alpha[i] -= 1;
        }
        if(alpha[i] == 0) continue;
        if(alpha[i]%2 == 0 && alpha[i]%4 != 0){
            if(two == 0) return "No";
            two--;
            alpha[i] -= 2;
        }
        if(alpha[i] == 0) continue;
        if(alpha[i]%4 == 0){
            int minf = min(alpha[i]/4,four);
            alpha[i] -= minf*4;
            four -= minf;
        }
    }
    
    // この時点で four が残っているのはおかしい
    if(four != 0) return "No";
    
    for(int i = 0; i < 26;i++){
        two -= alpha[i]/2;
        if(two < 0) return "No";
    }
    
    return "Yes";
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    cout << solve() << endl;
	return 0;
}
