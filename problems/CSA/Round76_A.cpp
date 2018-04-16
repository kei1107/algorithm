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
 <url:https://csacademy.com/contest/round-76/task/digit-function/>
 問題文============================================================
 整数Xと次のように定義された関数Fが与えられる
 
 F(0) = 0
 F(X) = F(X - Sum of difits of X)
 
 Fが関数Fを呼ぶ回数を述べよ
 =================================================================
 解説=============================================================
 
 そのまま関数作ってやるだけ
 
 ================================================================
 */

ll f(ll x){
    string s = to_string(x);
    ll sum = accumulate(s.begin(),s.end(),0LL) - s.length()*'0';
    return x - sum;
}
ll solve(){
    ll res = 1;
    ll X; cin >> X;
    while(X){
        res++; X = f(X);
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
