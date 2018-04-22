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
 <url:https://yukicoder.me/problems/no/48>
 問題文============================================================
 太郎君はロボットを遠隔で操縦している。
 
 このロボットは現在(0,0)の座標に立っていて北の方向を向いている。
 太郎君はいまこのロボットを(X,Y)の座標に移動させたいと思っている。
 
 ロボットに出来る命令は、1回につき以下のうちいずれかの命令を選んで指示することができる。
 ・時計回りに、90∘ その場で向き(進行方向)を変える。
 ・反時計回りに、90∘ その場で向き(進行方向)を変える。
 ・向いている方向に K距離だけ前進する。Kは、(1≤K≤L) の範囲で、命令のたびに指定することができる。
 
 =================================================================
 解説=============================================================
 
 北方向->(東西方向)->南方向
 で移動の可能性があるかを見るだけ
 ================================================================
 */

ll solve(){
    ll res = 0;
    
    ll X,Y,L; cin >> X >> Y >> L;
    swap(X,Y);
    if(X != 0)res += (abs(X)+L-1)/L;
    if(Y != 0)res += (abs(Y)+L-1)/L + 1;
    
    if(X < 0){
        res += (Y!=0)?1:2;
    }
    
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
