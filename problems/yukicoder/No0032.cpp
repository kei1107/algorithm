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
 <url:https://yukicoder.me/problems/no/32>
 問題文============================================================
 太郎君はいつも小銭を貯金していて、硬貨を貯金箱に入れています。
 貯金箱の中身がある程度たまったので、
 太郎君は銀行に行って両替をしてもらうことにしました。
 
 太郎君の国では通貨として1000円札の紙幣と、100円、25円、1円の硬貨があります。
 それ以外の金額の紙幣や硬貨はありません。
 
 両替は、
 ・1円硬貨25枚で25円硬貨1枚に
 ・25円硬貨4枚で100円硬貨1枚に
 ・100円硬貨10枚で1000円札1枚に
 それぞれ替えることができます。
 
 入力に、貯金箱の中身としてそれぞれの硬貨の枚数が与えられるので、
 硬貨の枚数が最も少なくなるように両替したとき、
 最終的に太郎君が所持する硬貨の合計枚数を出力してください。
 
 両替は手数料無く何度でもすることができます。
 また、両替の前後で総額が変化してはいけません。
 

 =================================================================
 解説=============================================================
 まぁできるだけ1000円にした方がいいよね
 ================================================================
 */

ll solve(){
    ll L,M,N; cin >> L >> M >> N;
    ll res = 0;
    M += N/25; N%=25;
    L += M/4; M%=4;
    L%=10;
    res = L + M + N;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
