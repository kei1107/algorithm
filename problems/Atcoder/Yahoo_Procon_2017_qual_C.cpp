#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://yahoo-procon2017-qual.contest.atcoder.jp/tasks/yahoo_procon2017_qual_c>
問題文============================================================
 高橋君は Yafoo という検索エンジンをよく利用しています。
 
 Yafoo には N 個のサイトが登録されており、i 個目のサイトの登録名は Si です。
 また、文字列 T を検索ワードとして検索を行うと、登録されている N 個のサイトのうち、
 登録名の長さが |T| 以上でかつ登録名の先頭 |T| 文字が T に一致するようなサイト全てが検索結果として得られます。
 
 今、高橋君は検索結果として A1, A2, …, AK 番目のサイトが得られるようにしたいです。
 そのような検索結果がちょうど得られるような検索ワードが存在するかどうかを判定し、
 存在する場合はその中で長さが最小のものを求めてください。

=================================================================

解説=============================================================

 検索結果を希望する文字列の中で一番長さが短いものを基準として、一文字づつ見ていく
 
 i文字目を見て、検索ワードに追加するとき、検索結果として希望しない文字列であり、
 除外されるもののフラグ、および検索結果として希望して、かつ、除外されないようなフラグ
 を持ち、　検索結果として希望するもののみが検索結果として現れるようになったらその時点での
 ワードを出力すれば良い
 
================================================================
*/

void solve(){
    ll N,K; cin >> N >> K;
    vector<ll> A(K);
    for(auto &in:A){cin >> in; in--;}
    vector<string> S(N);
    for(auto &in:S) cin >> in;
    
    if(N == K){
        cout << "" << endl;
        return;
    }
    
    string key_s; ll len = INF;
    for(int i = 0; i < K;i++){
        if(len > S[A[i]].length()){
            len = S[A[i]].length();
            key_s = S[A[i]];
        }
    }
    
    string ans = "";
    vector<int> flag(N,0);
    for(int i = 0; i < K;i++) flag[A[i]] = -1;
    for(int i = 0; i < (int)key_s.length();i++){
        for(int j = 0; j < N;j++){
            if(flag[j] == 0){
                if(i >= S[j].length()) flag[j] = 1;
                else{
                    if(S[j][i] != key_s[i]) flag[j] = 1;
                }
            }
            if(flag[j] == -1){
                if(S[j][i] != key_s[i]){
                    cout << -1 << endl;
                    return;
                }
            }
        }
        ans += key_s[i];
        bool f = [&]{
            for(int j = 0; j < N;j++){
                if(flag[j] == 0) return false;
            }
            return true;
        }();
        if(f){
            cout << ans << endl; return;
        }
    }
    cout << -1 << endl;
}
int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    solve();
    return 0;
}
