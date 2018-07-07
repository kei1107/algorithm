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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1173&lang=jp>
 問題文============================================================
 =================================================================
 解説=============================================================
 stackで管理してやるだけ
 ================================================================
 */

string S;
string solve(){
    stack<char> st;
    for(auto c:S){
        if(c != '(' and c != ')' and c != '[' and c != ']') continue;
        if(c == '(' or c == '[') st.push(c);
        if(c == ')'){ if(st.empty() or st.top() != '(') return "no"; st.pop(); }
        if(c == ']'){ if(st.empty() or st.top() != '[') return "no"; st.pop(); }
    }
    return st.empty()?"yes":"no";
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    while(getline(cin,S)){
        if(S == ".") break;
        cout << solve() << endl;
    }
    return 0;
}
