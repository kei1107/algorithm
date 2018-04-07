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
 <url:https://arc094.contest.atcoder.jp/tasks/arc094_a>
 問題文============================================================
 3 つの整数 A,B,C が与えられます。
 以下の 2 種類の操作を好きな順で繰り返して A,B,C をすべて等しくするために必要な操作の最小回数を求めてください。
 
 A,B,C のうち 2 つを選んで、その両方を 1 増やす
 A,B,C のうち 1 つを選んで、その整数を 2 増やす
 なお、これらの操作を繰り返して A,B,C をすべて等しくできることは証明できます。

 =================================================================
 解説=============================================================
 まぁ此の手のは2選んで行ってとりあえず全て均一に近づけるのが最適だよね
 
 んで、ずれている分を１を使って補填
 ================================================================
 */
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    ll A,B,C; cin >> A >> B >> C;
    ll cnt = 0;
    ll M = max({A,B,C});
    cnt += (M-A)/2; A += (M-A)/2*2;
    cnt += (M-B)/2; B += (M-B)/2*2;
    cnt += (M-C)/2; C += (M-C)/2*2;
    ll cnt2 = 0;
    if(M != A) cnt2++;
    if(M != B) cnt2++;
    if(M != C) cnt2++;
    
    if(cnt2 == 0) cout << cnt << endl;
    else if(cnt2 == 1) cout << cnt + 2 << endl;
    else cout << cnt + 1 <<endl;
    
    return 0;
}
