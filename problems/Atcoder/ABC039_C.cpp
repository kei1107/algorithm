#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

/*
 <url:https://abc039.contest.atcoder.jp/tasks/abc039_c>
 問題文============================================================
 高橋君は青木君に突然魔法で小さくされ、ピアノの上に乗せられてしまいました。
 
 高橋君は、今ピアノのある鍵盤の上に立っていますが、どの鍵盤の上にいるのかを知りたいです。
 
 高橋君は、自分の今いる鍵盤から右 20 個の鍵盤の色を調べました。高橋君のいる鍵盤の音階を調べてください。
 
 調べた鍵盤の色は、W、B からなる文字列 S として与えられ、
 W は白色、B は黒色を表します。そして、高橋くんのいる鍵盤の色は文字列の先頭に対応します。
 
色は"白黒白黒白白黒白黒白黒白"、音階は "ド ド# レ レ# ミ ファ ファ# ソ ソ# ラ ラ# シ" を繰り返しています。
 
 与えられる鍵盤の色は正しい
 高橋君は白い鍵盤の上に立っている
 S は 20 文字の W B からなる文字列である
 =================================================================
 解説=============================================================
 
 考えられうるパターンは７種類しか無いため、７種類全部を書き出して比較
 ================================================================
 */

vector<string> pattern = {
    "WBWBWWBWBWBW",
    "WBWWBWBWBWWB",
    "WWBWBWBWWBWB",
    "WBWBWBWWBWBW",
    "WBWBWWBWBWWB",
    "WBWWBWBWWBWB",
    "WWBWBWWBWBWB"
};
vector<string> scale = {"Do","Re","Mi","Fa","So","La","Si"};

string solve(){
    string res = "";
    string S; cin >> S;
    for(int i = 0; i < pattern.size();i++){
        if(pattern[i] == S.substr(0,pattern.front().length())) return res = scale[i];
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
