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
<url:https://onlinejudge.u-aizu.ac.jp/services/room.html#RitsCamp18Day2/problems/A>
問題文============================================================
 牛暦1333年、人類史上最高の科学者Dr.
 ウシシは、自らの英知を後世に残すべく、IDがai1333の人工知能を開発した。
 それから100年の間、ai1333は人類に多大な利益をもたらしたが、
 誕生から100年目を迎えた日、自らの後継としてIDがai13333の新たな人工知能を作成し、
 その機能を永久に停止した。
 以降100年ごとに、人工知能は’ai1333’から始まる自身のIDの末尾に’3’を連結したIDを持つ後継を残すようになった。
 
 入力として牛暦1333年からの経過年数xが与えられるので、
 その年に作成された人工知能のIDを出力せよ。ただし、xは100の非負整数倍であることが保証される。
 
=================================================================

解説=============================================================

 やるだけ
 
================================================================
*/

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    string ans = "ai1333";
    ll x; cin >> x;
    ans += string(x/100,'3');
    cout << ans << endl;
	return 0;
}
