#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
 <url:https://agc006.contest.atcoder.jp/tasks/agc006_b>
 問題文============================================================
 N 段のピラミッドがあります。 段は上から順に 1, 2, …, N と番号が振られています。
 各 1≤i≤N について、i 段目には 2i−1 個のブロックが横一列に並んでいます。
 また、各段の中央のブロックに注目すると、これらは縦一列に並んでいます。
 
 すぬけ君は N 段目のブロックに (1, 2, …, 2N−1) を並べ替えたもの（順列）を書き込みました。
 さらに、次のルールに従い、残りすべてのブロックに整数を書き込みました。
 
 あるブロックに書き込まれる整数は、そのブロックの左下、真下、右下のブロックに書き込まれた整数の中央値である。
 
 その後、すぬけ君はすべてのブロックに書き込まれた整数を消してしまいました。
 すぬけ君は、1 段目のブロックに書き込まれた整数が x であったことだけを覚えています。
 
 N 段目のブロックに書き込まれた順列としてあり得るものが存在するか判定し、存在するならばひとつ求めてください。
 =================================================================
 
 解説=============================================================
 
 x が 1 or 2*n-1 の時、必ず N-1段目で消えるので　no
 それ以外の時は全部作ることができる
 
 以下のような形を取ればいい
 
     x
    oxx
   ooxxo
  oooxxoo
 aaaaaaaaa
 
 よって、このようになるように数列を取ればいいので頑張って復元する
 ================================================================
 */
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    int a[200010] = {0};
    int n,x; cin >> n >> x;
    if(x == 1 || x == 2*n - 1){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    if(n == 2){
        cout << 1 << endl;
        cout << 2 << endl;
        cout << 3 << endl;
        return 0;
    }
    if(x == 2){
        a[n] = 2; a[n-1] = 1; a[n-2] = 3; a[n+1] = 4;
        int cnt = 5;
        for(int i = 0; i < n*2 - 1;i++){
            if(a[i] == 0) a[i] = cnt++;
        }
    }else{
        a[n] = x; a[n-1] = x+1; a[n-2] = x-1; a[n+1] = x-2;
        int used[200010] = {false};
        for(int i = x-2; i <= x+1;i++) used[i] = true;
        int cnt = 1;
        for(int i = 0; i < 2*n-1;i++){
            if(a[i] == 0){
                while(used[cnt]) cnt++;
                a[i] = cnt; used[cnt] = true;
            }
        }
    }
    for(int i = 0; i < 2*n - 1;i++){
        cout << a[i] << endl;
    }
    return 0;
}
