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
 <url:https://beta.atcoder.jp/contests/agc022/tasks/agc022_a>
 問題文============================================================
 ゴトウは辞書をもらいました。ところが、その辞書は知らない言語で書かれていました。
 分析した結果、その辞書にはありうるすべての 多彩 な単語が辞書順に載っていることがわかりました。
 
 単語は、それが英小文字からなる空でない文字列であって、単語内の文字がすべて異なる場合、
 そしてその場合に限って 多彩 であると呼ばれます。
 例えば、atcoder、zscoder、agc は多彩な単語ですが、gotou、connect は多彩な単語ではありません。
 
 多彩な単語 S が与えられるので、この辞書で S の次に載っている単語、
 すなわち、S より辞書順で大きいような、辞書順で最小の多彩な単語を求めてください。
 あるいは、そのような単語は存在しないと判定してください。
 
 なお、X=x1x2…xn、Y=y1y2…ym を二つの異なる文字列とするとき、
 Y が X の接頭辞であるか、j を xj≠yj であるような最小の整数として xj>yj である場合、
 そしてその場合に限って X は Y より辞書順で大きいといいます。
 
 制約
 1≤|S|≤26
 S は多彩な単語である。

 =================================================================
 解説=============================================================
 
 zyxwvutsrqponmlkjihgfedcba
 の時に -1 は明らか
 
 それ以外の時、文字以外で使われていない最小の単語があるならば末尾に加えたものが候補
 また、後ろから見ていって、それよりも今見ている文字よりも大きく、かつ左側にあるものではない
 最小の文字に変更したものも候補となるので探索する
 
 ================================================================
 */

void solve(){
    string S; cin >> S;
    int a[26] = {0};
    for(auto c:S) a[c-'a']++;
    if(S == "zyxwvutsrqponmlkjihgfedcba"){
        cout << -1 << endl; return;
    }
    
    string ans(26,'z');
    for(int i = 0; i < 26;i++){
        if(a[i] == 0){
            char c = i + 'a';
            ans = min(ans,S+c);
        }
    }
    for(int i = (int)S.length()-1;i>=0;i--){
        int x = S[i] - 'a';
        for(int j = x+1; j < 26;j++){
            if(a[j] == 0){
                char c = j + 'a';
                ans = min(ans,S.substr(0,i)+c);
                break;
            }
        }
        a[x]--;
    }
    cout << ans << endl;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    solve();
    return 0;
}
