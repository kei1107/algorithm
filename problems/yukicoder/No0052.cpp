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
 <url:https://yukicoder.me/problems/no/52>
 問題文============================================================
 文字列Sが与えられる。
 文字列Sの「先頭」または「末尾」から１文字ずつ文字をとってきて、
 取った文字列とは別に、取った文字を順番につなげて新たに文字列を作る。
 Sは、文字を取った後の文字列を新たなSとしてSの文字列がなくなるまで繰り返す。
 
 この時、新たにできる文字列は何通りの文字列ができるか？
 
 =================================================================
 解説=============================================================
 ================================================================
 */

set<string> s;
void dfs(string S,string T){
    if(S.length() == 0){ s.insert(T); return; }
    dfs(S.substr(1),T + S.front());
    dfs(S.substr(0,S.length()-1),T+S.back());
}
ll solve(){
    ll res = 0;
    string S; cin >> S;
    dfs(S,"");
    res = s.size();
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
