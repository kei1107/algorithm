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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2369>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 与えられた文法規則に沿って構文解析すれば良い
 ================================================================
 */

bool rec(const string& S,int& i){
    if(S[i] != 'm') return false;
    i++;
    if(S[i] == 'm'){
        if(!rec(S,i)) return false;
    }
    if(S[i] != 'e') return false;
    i++;
    if(S[i] == 'm'){
        if(!rec(S,i)) return false;
    }
    if(S[i] != 'w') return false;
    i++;
    return true;
}
string solve(){
    string S;
    cin >> S;
    int i = 0;
    return rec(S,i)?(i!=S.length()?"Rabbit":"Cat"):"Rabbit";
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
