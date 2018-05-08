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
 <url:https://yukicoder.me/problems/no/89>
 問題文============================================================
 とある高校のアニメーション同好会が文化祭に向けドーナツで誓いを立てていた。
 彼女たちは女子高生なのでカロリーが気になる。しかし、買ってきたドーナツにはカロリーが記載されていなかった。
 買ってきたドーナツを上から見るときれいな２重円に見え、
 またドーナツの輪っかを切断するときれいな円になっていた。(つまり円環体ということ)
 そこで彼女たちはドーナツが1cm3あたりCkcalであることを利用してカロリーを求めることにした。

 =================================================================
 解説=============================================================
 
 普通に体積計算するだけ
 
 ================================================================
 */

typedef long double ld;
const ld eps = 1e-9, pi = acos(-1.0);

ld solve(){
    ld res = 0.;
    int C,Rin,Rout; cin >> C >> Rin >> Rout;
    double r = (Rout - Rin)/2.;
    double lr = Rin + r;
    res = C*(pi*r*r)*(2*pi*lr);
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(12) << solve() << endl;
    return 0;
}
