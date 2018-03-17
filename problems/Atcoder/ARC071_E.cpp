#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream &operator << (ostream& out,const pair<S,T>& o){
    out << "(" << o.first << "," << o.second << ")"; return out;
}

/*
<url:https://arc071.contest.atcoder.jp/tasks/arc071_c>
問題文============================================================
 A, B からなる文字列に対して、次の操作を考えます。
 
 文字列中の 1 文字を選ぶ。それが A なら BB で、 B なら AA で置き換える。
 AAA か BBB であるような部分文字列を選び、消す。
 例えば、ABA という文字列で 1 番目の操作を 1 文字目に対して行うと、 BBBA となります。
 また、BBBAAAA に対して 2 番目の操作を 4 文字目から 6 文字目に対して行うと、 BBBA となります。
 
 これらの操作を何回でも好きな順で行うことができます。
 
 文字列 S,T と q 個のクエリ ai,bi,ci,di が与えられます。
 各クエリに対して、
 S の部分文字列 SaiSai+1…Sbi を
 T の部分文字列 TciTci+1…Tdi にすることができるか判定してください。
 
 1≤|S|,|T|≤10^5
 S,T は文字A,Bからなる。
 1≤q≤10^5
 1≤ai≤bi≤|S|
 1≤ci≤di≤|T|

=================================================================

解説=============================================================
 
 SとTの部分文字列 s,t を全て B へ変形した時、
 そのBの数の差が 3 の倍数であるとき、 YESとなる。
 
 前処理で累積和を用いて、Bの数を数え上げておけば　各クエリについて O(1) で回答できる
 
================================================================
*/
void solve(){
    string S,T; cin >> S >> T;
    int Q; cin >> Q;
    vector<int> cusumS(S.length()+1,0),cusumT(T.length()+1,0);
    for(int i = 0; i < S.length();i++){
        if(S[i] == 'A') cusumS[i+1] = cusumS[i] + 2;
        else cusumS[i+1] = cusumS[i] + 1;
    }
    for(int i = 0; i < T.length();i++){
        if(T[i] == 'A') cusumT[i+1] = cusumT[i] + 2;
        else cusumT[i+1] = cusumT[i] + 1;
    }
    while(Q--){
        int a,b,c,d; cin >> a >> b >> c >> d;
        if(abs((cusumS[b]-cusumS[a-1])-(cusumT[d]-cusumT[c-1]))%3 == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    solve();
	return 0;
}
