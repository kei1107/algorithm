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
 <url:https://yukicoder.me/problems/no/77>
 問題文============================================================
 Vegaはレンガで平面ピラミッドを作りたいと考えてる。
 
 庭には、すでにN列分のレンガが隙間なく積まれていて、それぞれのi列目の積まれている個数はAiで表される。
 最初の配置から、レンガをいくつか動かして、ピラミッドの配置になるように並び替えたいです。
 
 ピラミッドの配置とは、1から始めて[1,2,3,4,3,2,1]のように中心の位置まで１ずつ増え、中心以降は1ずつ減るような配置である。
 (つまり、ピラミッド配置の列数は奇数になる。）
 
 ピラミッドとは別の場所に、捨て置き場も設けられており、ピラミッドの配置に使われなかったレンガを置くこともできる。
 
 移動とは、任意の列の一番上にある１つのレンガを持ち、別の列に移動するか、もしくは捨て置き場に移動することである。
 このとき、ピラミッド配置は、最初の配置の1列目のレンガの場所から始めるとする。
 与えられた列数よりか大きい列になる場合がある。
 最初の配置から0個以上のレンガを移動しできるピラミッド配置への最小の移動数を求めてください。
 
 
 ビラミッドの場所には１つのピラミッドのみがあるとして、不要なレンガはすべて捨て置き場に移動するとする。
 レンガはどれも同じサイズの立方体であるとする。
 =================================================================
 解説=============================================================
 
 愚直シミュレーションする
 
 ================================================================
 */

ll solve(){
    ll res = LINF;
    ll N; cin >> N;
    vector<ll> A(500);
    for(int i = 0; i < N;i++) cin >> A[i];
    ll sum = accumulate(A.begin(),A.end(),0LL);
    ll X = 1;
    while(X*X <= sum) X++;
    X--;
    for(int i = 0; i < N;i++){
        int now = 1;
        ll tmp = 0;
        for(int j = i; j < i+2*X-1;j++){
            if(now - A[j] > 0) tmp += (now - A[j]);
            if(j < i+X-1) now++;
            else  now--;
        }
        now = 1;
        tmp += (sum - X*X);
        res = min(res,tmp);
        if(i + X >= N) break;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
