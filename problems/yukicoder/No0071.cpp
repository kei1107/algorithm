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
 <url:https://yukicoder.me/problems/no/71>
 問題文============================================================
 コンピュータが登場する前、計算する道具といえば「そろばん」だった。
 今回は、そのそろばんがテーマの問題である。
 
 一般的なそろばんは、一列だけ見ると、５つ珠があり０〜9まで表すことができる。
 
 これは、１列に串刺し状の上部１つの珠と下部４つの珠に分けて、
 下部の動いている珠の数、上部の動いている珠分さらに5を足すという数の表現方法を行う。
 つまり上部は、下部の数の繰り上がり数と見ることができる。
 
 このとき、Ursaは特殊なそろばんを思いついた。
 一列に使える珠の合計をN個とし、上部と下部に使える珠の数は、合計でN個であれば自由に決めることができるとする。
 この時、一列分で表現できる最大の数を求めてください。
 
 ただし、表現方法としてできるのは、それぞれの珠の上げ下げの状態のみで判断するとする。
 中途半端に動かすなどできないとし、上部・下部はそれぞれ連続に並んでいる珠なので３つ目が動くなら、
 １つ目２つ目も連動して動くような機構であるとする。
 また、0から最大の数まで一意的な表現ができるとする。

 =================================================================
 解説=============================================================
 
 上部の珠の数を c1 , 下部の珠の数を c2とすれば
 その場合表現できる最大の数は c1*(c2+1) + c2
 となる
 ================================================================
 */

ll solve(){
    ll res = 0;
    ll N; cin >> N;
    for(int i = 1; i < N;i++){
        res = max(res,i*(N-i+1)+(N-i));
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
