#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1564>
問題文============================================================
 アルファベットの小文字と数字からなる文字列 S が与えられる。次の手順で文字列 S の長さを圧縮する。
 
 1.文字列内の文字の順番を任意の順番に入れ替える。
     例: "0ig3he12fz99" → "efghiz012399"
 2.次の操作を任意の回数行う。
 文字列内にある、"abcdefghijklmnopqrstuvwxyz"の連続した部分文字列を選び、
 (先頭の文字)'-'(末尾の文字)に置き換える。
 例: "efghiz012399" → "e-iz012399"
 文字列内にある、公差が1であるような数字列("0123456789"の連続した部分文字列)を選び、
 (先頭の数字)'-'(末尾の数字)に置き換える。
 例: "e-iz012399" → "e-iz0-399"
 
 文字列 S を圧縮して得られる文字列の長さの最小値を求めよ。
=================================================================

解説=============================================================
文字の置き換えをすることによって得をするのは、対象文字が３つ以上並んでいるときである。
 よって、英語と数字それぞれにおいて、その個数を見て３つ以上の文字を短縮できるようであれば
 短縮するといった動作を繰り返して行えば良い
================================================================
*/

int ans;
int suuzi[10] = {0};
int alpha[26] = {0};

bool suuzi_check(int l){
    if(suuzi[l] != 0 && suuzi[l+1] != 0 && suuzi[l+2] != 0){
        int r = l + 2;
        for(;r < 10;){
            if(suuzi[r] == 0){
                break;
            }
            r++;
        }
        int minv = INF;
        for(int idx = l; idx < r;idx++) minv = min(minv,suuzi[idx]);
        ans = ans - (minv*(r-l)) + 3*minv;
        
        for(int idx = l; idx < r;idx++){
            suuzi[idx]-=minv;
        }
        return true;
    }else{
        return false;
    }
}

bool alpha_check(int l){
    if(l + 2 >= 26) return false;
    if(alpha[l] != 0 && alpha[l+1] != 0 && alpha[l+2] != 0){
        int r = l + 2;
        for(;r < 26;){
            if(alpha[r] == 0){
                break;
            }
            r++;
        }
        int minv = INF;
        for(int idx = l; idx < r;idx++) minv = min(minv,alpha[idx]);
        ans = ans - (minv*(r-l)) + minv*3;
        
        for(int idx = l; idx < r;idx++){
            alpha[idx]-=minv;
        }
        return true;
    }else{
        return false;
    }
}

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    string S; cin >> S;
    ans = (int)S.length();
    for(int i = 0; i < S.length();i++){
        if(isdigit(S[i])){
            suuzi[S[i] - '0']++;
        }else{
            alpha[S[i] - 'a']++;
        }
    }
    for(int i = 0; i < 8;i++){ while(suuzi_check(i)){} }
    for(int j = 0; j < 26;j++){ while(alpha_check(j)){} }
    cout << ans << endl;
    
	return 0;
}
