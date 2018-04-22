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
 <url:https://yukicoder.me/problems/no/47>
 問題文============================================================
 Saraは、「ふしぎなポケット」を手に入れた。
 
 「ふしぎなポケット」は、いくつかビスケットを入れて叩くと、入れたビスケットの数が２倍になる。
 Saraは最初1枚のビスケットを持っていて、
 「ふしぎなポケット」を使ってちょうどN枚のビスケットにして、全部食べたいと思っている。
 （食べきれないので枚数をオーバーしてはいけない）
 
 この時、ちょうどN枚にするには、Saraは最低何回ポケットを叩く必要があるか求めてください。

 =================================================================
 解説=============================================================
 
 とりあえず、ビスケットはNを超えない範囲では持っているすべてのビスケットを２倍にすることを考える。
 残りの足りない部分に関しては
 
 実は　ビスケット　１枚　＝＞　２枚に　＋１枚
                2   ＝＞  ４     ＋２
                3   ＝＞  ６     ＋３
 
 といれた数だけ増分されるので、足りない部分に関してはどうにかなる。
 
 よって　答えは 2^x >= N となる最小の x
 
 ================================================================
 */

ll solve(){
    ll res = 0;
    ll N; cin >> N;
    ll x = 1;
    while(x < N){res++; x<<=1;}
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
