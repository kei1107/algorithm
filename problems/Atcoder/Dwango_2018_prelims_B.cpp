#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://dwacon2018-prelims.contest.atcoder.jp/tasks/dwacon2018_prelims_b>
問題文============================================================
 dwango社員のニワンゴくんは2525SNSという新しいSNSを開発しています。
 2525SNSは2525文字列のみ投稿可能な画期的なSNSです。
 
 この問題において、25 の 1 回以上の繰り返しで表される文字列を2525文字列と呼びます。
 例えば、25,2525,2525252525252525 などは2525文字列ですが、
 空文字列や 2255,2552,252 などは2525文字列ではありません。
 
 まず、ニワンゴくんは2525文字列をいくつか作ることにしました。
 ニワンゴくんは手元にあった文字列 s を 1 つ以上の部分列に分解し、
 分解された部分列それぞれが2525文字列となるようにしたいです。
 
 最小でいくつの部分列に分解すればこれを達成可能ですか？どのように分解しても達成不可能な場合は -1 を出力してください。
 分解についてはサンプル 1 の説明も参照してください。
=================================================================

解説=============================================================

 手前から順にニコニコ文字列を作れるだけ作っていく操作が最適
 
 どの文字をとっていったかのフラグ管理をしておけば良い
================================================================
*/

pii check(int n,string& s,vector<int>& f){
    pii ret = {-1,-1};
    for(int i = n; i < s.length();i++){
        if(f[i]) continue;
        if(s[i] == '2' && ret.first == -1){
            ret.first = i;
            continue;
        }
        if(s[i] == '5' && ret.first != -1){
            ret.second = i;
            f[ret.first] = f[ret.second] = 1;
            return ret;
        }
    }
    return ret;
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    string s; cin >> s;
    vector<int> f(s.length(),0);
    int ans = 0;
    while(true){
        bool updated = false;
        for(int l = 0; l < s.length();){
            pii p = check(l,s,f);
            if(p.first == -1 || p.second == -1) break;
            else{
                updated = true;
                l = p.second + 1;
            }
        }
        if(updated){
            ans++;
        }else{
            break;
        }
    }
    if(ans == 0) cout << -1 << endl;
    else{
        for(int i = 0; i < s.length();i++) if(!f[i]){
            cout << -1 << endl;
            return 0;
        }
        cout << ans << endl;
    }
	return 0;
}
