#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
 <url:https://www.ioi-jp.org/camp/2007/2007-sp-tasks/2007-sp-day3_23.pdf>
 問題文============================================================
 文字列が与えられる。
 与えられた文字列はその文字列によって生成できるアナグラムの中で、辞書順何番目になるか？
 =================================================================
 解説=============================================================
 
 左から昇順に英単語を見ていってその文字を置いた時の右側のパターンがいくつあるかを
 計算すればよい
 
 ================================================================
 */

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    string S; cin >> S;
    vector<ll> fact(S.length()+1,0);
    int cnt_alpha[26] = {0};
    
    /* preprocessing */
    fact[0] = 1;
    for(int i = 1; i <= S.length();i++){
        fact[i] = fact[i-1] * i;
    }
    for(int i = 0; i < S.length();i++) cnt_alpha[S[i] - 'A']++;
    
    ll res = 0;
    for(int i = 0; i < S.length();i++){
        for(int j = 0;j < 26;j++){
            if(cnt_alpha[j] == 0)continue;
            if((S[i] - 'A') == j){
                cnt_alpha[S[i]-'A']--;
                break;
            }
            ll tmp = fact[S.length()-i-1];
            for(int k = 0;k < 26;k++){
                if(cnt_alpha[k] == 0)continue;
                tmp/= (fact[cnt_alpha[k] - ((j == k)?1:0)]);
            }
            res += tmp;
        }
    }
    cout << res + 1 << endl;
    return 0;
}
