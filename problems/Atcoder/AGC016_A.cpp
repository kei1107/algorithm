#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://agc016.contest.atcoder.jp/tasks/agc016_a>
問題文============================================================
 すぬけ君は、次のルールに従い、長さ N の文字列 t を長さ N−1 の文字列 t' へ変えることができます。
 
 各 i (1≤i≤N−1) について、t' の i 文字目は t の i, i+1 文字目のどちらかである。
 
 英小文字のみからなる文字列 s があります。
 すぬけ君の目標は、s に上記の操作を繰り返し行い、s が単一の文字のみからなるようにすることです。
 目標を達成するために必要な操作回数の最小値を求めてください。

=================================================================

解説=============================================================

 最終的な単一文字が実際に何にするかを最初に決めておいて、あとはその文字になるように
 （できるだけその文字が多くなるように）シミュレーションすれば良い
 
================================================================
*/

int ans = INF;
void dfs(string s,int dep,char c){
    string tmp = s;
    tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
    if(tmp.length() == 1){
        ans = min(ans,dep);
        return ;
    }
    for(int i = 0; i < (int)s.length() - 1;i++){
        if(s[i] == c || s[i+1] == c){
            s[i] = c;
        }
    }
    s.pop_back();
    dfs(s,dep+1,c);
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    string s; cin >> s;
    bool alpha[26] = {false};
    for(auto c:s) alpha[c-'a'] = true;
    for(int i = 0; i < 26;i++){
        if(alpha[i]){
            dfs(s,0,'a'+i);
        }
    }
    cout << ans << endl;
	return 0;
}
