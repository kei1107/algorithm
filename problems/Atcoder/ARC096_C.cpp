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
 <url:https://arc096.contest.atcoder.jp/tasks/arc096_a>
 問題文============================================================
 ファーストフードチェーン「ピザアット」のメニューは「A ピザ」「B ピザ」「AB ピザ」の 3 種類です。
 A ピザと B ピザは全く異なるピザで、これらをそれぞれ半分に切って組み合わせたものが AB ピザです。
 A ピザ、B ピザ、AB ピザ 1 枚あたりの値段はそれぞれ A 円、B 円、C 円です。
 
 中橋くんは、今夜のパーティーのために A ピザ X 枚と B ピザ Y 枚を用意する必要があります。
 これらのピザを入手する方法は、A ピザや B ピザを直接買うか、
 AB ピザ 2 枚を買って A ピザ 1 枚と B ピザ 1 枚に組み替える以外にはありません。
 このためには最小で何円が必要でしょうか？なお、ピザの組み替えにより、必要な量を超えたピザが発生しても構いません。
 =================================================================
 解説=============================================================
 
 Z = min(X,Y)とする。
 
 まず、Aピザ、Bピザ共にZ枚入手しようと考えると
 min(A*Z+B*Z,C*2*Z)円で最小金額として、手に入れルことができる。
 
 またの、残ったピザに関しても
 同様にして、ABピザを考慮した比較で金額がわかる
 
 ================================================================
 */

ll solve(){
    ll res = 0;
    ll A,B,C,X,Y; cin >> A >> B >> C >> X >> Y;
    ll minc = min(X,Y);
    res += min(A*minc + B*minc,C*minc*2);
    X-=minc; Y-=minc;
    
    if(X){
        res += min(A*X,C*X*2);
    }
    if(Y){
        res += min(B*Y,C*Y*2);
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
