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
 <url:https://yukicoder.me/problems/no/18>
 問題文============================================================
 太郎君は暗号に興味があり、新しい暗号方式を考えていました。
 そこで大昔に開発されたシーザー暗号を参考にし、
 すこし変更することでもうちょっと複雑な暗号方式を作ろうと思いつきました。
 
 シーザー暗号とは、平文(暗号化されていない文)のアルファベットを、
 右に N回 ずらしたもので、たとえば N=1 の場合、
 'A'は'B'になり、'M'は'N'になり、'Z'は'A'になります。
 
 そこで太郎君は、文字ごとに N の値を変更することを考え、
 1文字目なら N=1、そして2文字目なら N=2、…のように、
 「i文字目の文字をi回右にずらす」ことにしました。
 (ずらした結果、文字'Z'を超える場合はシーザー暗号と同様に文字'A'へ戻ります)
 右にずらすとはアルファベット順の次の文字にするということにします。
 そして太郎君は、この新しい暗号方式を「うーさー暗号」と名づけました。
 
 入力に「うーさー暗号」で暗号化された文字列が与えられるので、
 これを復号した文字列を出力してください。
 =================================================================
 解説=============================================================
 やるだけ
 ================================================================
 */
string solve(){
    string S; cin >> S;
    for(int i = 0; i < S.length();i++){
        int shift = 26*1024 - (i+1);
        S[i] = (S[i] - 'A' + shift ) % 26 + 'A';
    }
    return S;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
