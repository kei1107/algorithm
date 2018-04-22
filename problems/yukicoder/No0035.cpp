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
 <url:https://yukicoder.me/problems/no/35>
 問題文============================================================
 高橋くんは高速なプログラミングにはタイピング力が不可欠と考えています。
 そこで、タイピングゲームでタイピング力を鍛えます。
 この問題では簡単のために、タイピングする文字列はアルファベット小文字のみからなる文字列を考えます。
 
 あるタイピングゲームでは、1 ゲームは N 個の区間に分かれており、
 区間 k では、Tk ミリ秒以内に Sk という文字列をタイピングしなければいけません。
 高橋くんは 1 秒あたり 12 文字まで正しくタイプすることができます。
 これは、1000 ミリ秒では 12 文字まで、999 ミリ秒では 11 文字までタイプできるということで、
 m ミリ秒では ⌊12m/1000⌋ 文字までタイプできることになります。（⌊x⌋ は x を超えない最大の整数を表します）
 
 高橋くんはできるだけ多くの文字をタイプするとして、1 ゲーム全体で、
 高橋くんが正しくタイプできる文字数、および、タイプできずに逃してしまう文字数を求めるプログラムを書いてください。
 =================================================================
 解説=============================================================
 
 問題分通りにタイピング可能回数を求めて計算するだけ
 ================================================================
 */

void solve(){
    ll ans1 = 0, ans2 = 0;
    ll N; cin >> N;
    for(int i = 0; i < N;i++){
        ll T; cin >> T; string S; cin >> S;
        ll Can = 12*T/1000;
        ans1 += min(Can,(ll)S.length());
        ans2 += S.length() - min(Can,(ll)S.length());
    }
    cout << ans1 << " " << ans2 << endl;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
