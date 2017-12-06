#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
 <url:https://www.ioi-jp.org/camp/2015/2015-sp-tasks/2015-sp-d1.pdf>
 問題文============================================================
 K 理事長は，日本情報オリンピックの選手を応援するグッズのロゴを考えることとなった．
 ある日 K 理事長は，円状に ‘J’， ‘O’， ‘I’ の文字を並べたものをロゴとすることを思いついた．
 これには JOI を楽しんで (enjoy) もらいたいとする思いが込められている．
 以下のように，0 以上の整数 k に対してレベル k の JOI 列というものを定める．
 
 • レベル 0 の JOI 列とは，‘J’， ‘O’， ‘I’ のいずれかの 1 文字からなる文字列である．
 • レベル k + 1 の JOI 列とは，最初の 4^k 文字がすべて ‘J’，次の 4^k 文字がすべて ‘O’，
 次の 4^k 文字が すべて ‘I’ であり，最後の 4^k 文字がレベル k の JOI 列であるような，
 長さが 4^(k+1) の文字列である．
 
 今，K 理事長は，4^K 個の文字が円状に書かれた紙を持っている．
 紙に書かれた文字は，‘J’， ‘O’， ‘I’ のいずれかである．K 理事長は，いくつかの文字を書き換えて，
 紙に書かれた文字が，ある文字を起点に時計回りに一周読むとレベル K の JOI 列になるようにする．
 このとき，書き換える文字数をなるべく少なくしたい．
 
 紙に円状に書き並べられた長さ 4^K の文字列が与えられたとき，
 これをある文字を起点に時計回りに一周読むとレベル K の JOI 列になるようにするために必要な，
 書き換える文字数の最小値を求めるプログラムを作成せよ．
 =================================================================
 解説=============================================================
 
 累積和
 
 文字列は最大で4^10 = 2^20
 
 累積和を取るとO(4^K)で間に合う
 
 ここで、各区間毎のJ , O , I の個数を保持していけば、その区間の修正に必要な個数がわかる。
 各区間を調べるのでO(K)
 全て始点から始めるのでO(4^K)
 
 よってO(K * 4^K)
 間に合う
 
 ================================================================
 */

struct JOI{
    ll j;
    ll o;
    ll i;
    JOI():j(0),o(0),i(0){}
};
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll K; cin >> K;
    string S; cin >> S; S+=S;
    vector<JOI> cusum(S.length() + 1);
    for(int i = 0; i < S.length();i++){
        cusum[i+1].j = cusum[i].j + (S[i] != 'J');
        cusum[i+1].o = cusum[i].o + (S[i] != 'O');
        cusum[i+1].i = cusum[i].i + (S[i] != 'I');
    }
    ll l,r;
    ll ans = LINF;
    for(ll from = 0; from < S.length()/2; from++){
        l = r = from;
        ll cnt = 0;
        for(ll k = K - 1; k >= 0; k--){
            ll range = 1<<(2*k);
            for(int i = 0;i  < 3;i++){
                l = r; r = l + range;
                if(i == 0){
                    cnt += cusum[r].j - cusum[l].j;
                }
                if(i == 1){
                    cnt += cusum[r].o - cusum[l].o;
                }
                if(i == 2){
                    cnt += cusum[r].i - cusum[l].i;
                }
            }
        }
       ans = min(ans,cnt);
    }
    cout << ans << endl;
    return 0;
}
