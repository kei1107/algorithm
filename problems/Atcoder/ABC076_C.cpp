#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://abc076.contest.atcoder.jp/tasks/abc076_c>
問題文============================================================
 E869120 は、宝物が入ってそうな箱を見つけました。
 しかし、これには鍵がかかっており、鍵を開けるためには英小文字からなる文字列 S が必要です。
 彼は文字列 S' を見つけ、これは文字列 S の 0 個以上 |S| 個以内の文字が ? に置き換わった文字列であることも分かりました。
 ただし、文字列 A に対して、|A| を「文字列 A の長さ」とします。
 
 そこで、E869120 はヒントとなる紙を見つけました。
 
 条件1：文字列 S の中に連続する部分文字列として英小文字から成る文字列 T が含まれている。
 条件2：S は、条件1を満たす文字列の中で辞書順最小の文字列である。
 そのとき、鍵となる文字列 S を出力しなさい。
 ただし、そのような文字列 S が存在しない場合は代わりに UNRESTORABLE と出力しなさい。
=================================================================

解説=============================================================
文字列最小であるには 文字列Sに関係のない ? を全て a にすれば良い
 よって、文字列Sに関係のある　？　を判別さえすればもとまる
================================================================
*/
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    string S,T; cin >> S >> T;
    string ans(S.length(),'z');
    bool f = false;
    for(int i = 0; i < S.length();i++){
        if(i + T.length() >S.length())break;
        string tmp = "";
        for(int j = 0; j < i;j++){
            if(S[j] == '?') tmp+="a";
            else tmp += S[j];
        }
        bool dame = false;
        for(int j = i; j < i + T.length();j++){
            if(S[j] == '?') tmp += T[j-i];
            else{
                if(S[j] == T[j-i]){
                    tmp += T[j-i];
                }else{
                    dame = true;
                    break;
                }
            }
        }
        if(dame)continue;
        for(int j = i + T.length(); j < S.length();j++){
            if(S[j] == '?') tmp += "a";
            else tmp += S[j];
        }
        
        f = true;
        ans = min(ans,tmp);
    }
    
    if(f){
        cout << ans << endl;
    }else{
        cout << "UNRESTORABLE" << endl;
    }
    return 0;
}
