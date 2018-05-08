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
 <url:https://yukicoder.me/problems/no/63>
 問題文============================================================
 ハルカちゃんとユウちゃんはとっても仲良しなので、２人でポッキーゲームをすることにしました。
 
 長さが L(mm) のポッキーを２人はそれぞれ両端から中央に向かって齧っていきます。
 ２人とも毎回 K(mm) ずつ同じタイミングでポッキーを齧ります。
 ユウちゃんは恥ずかしがり屋さんなので、
 次のタイミングで２人ともポッキーを齧ろうとしたら唇が触れてしまうと分かった時点で齧り進めるのを止めて、
 残りは全部ハルカちゃんが食べてしまいます。
 
 このとき、ユウちゃんが食べるポッキーの長さは何mmか？
 =================================================================
 解説=============================================================
 
 ((L-1)/(2*K))*K
 
 が答え
 ================================================================
 */

ll solve(){
    ll L,K; cin >> L >> K;
    return ((L-1)/(2*K))*K;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
