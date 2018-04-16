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
 <url:https://yukicoder.me/problems/no/672>
 問題文============================================================
 文字'A'と文字'B'からなる文字列Sがあります。
 Sに含まれる連続した区間で'A'と'B'の数が等しいものの最長の長さを答えよ。
 =================================================================
 解説=============================================================
 
 Aがくれば、＋１、Bがくれば−１としたような累積和を考える。
 
 文字列のある地点 i をみたとき,その累積和の値が x であれば
 [0,i]に置いて累積和がxとなる最小のjについて、
 [j+1,i]が'A'と'B'の個数が等しくなる
 
 これは、文字列を左から順に見て行って、累積和を連想配列などで保持しておけば解ける
 ================================================================
 */

ll solve(){
    ll res = 0;
    string S; cin >> S;
    vector<ll> cusum(S.length()+1,0);
    for(int i = 0; i < S.length();i++){
        cusum[i+1] = cusum[i] + (S[i] == 'A'?1:-1);
    }
    map<ll,ll> mp;
    for(int i = 0; i <= S.length();i++){
        if(mp.count(cusum[i])) res = max(res,i-mp[cusum[i]]);
        else mp[cusum[i]] = i;
    }
    
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
