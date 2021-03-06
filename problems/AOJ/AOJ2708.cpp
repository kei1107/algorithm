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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2708>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 実際にありえるパターンを逆算して全通り試してやれば良い
 ================================================================
 */

string replace(string S,string from,string to){
    auto pos = S.rfind(from);
    while(pos != string::npos){
        S.replace(pos,from.size(),to);
        pos = S.rfind(from);
    }
    return S;
}

bool rec(string s){
    if(s.length() <= 2) return false;
    if(s == "ABC") return true;
    string tmpS = replace(s,"ABC","@");
    for(int i = 0; i < 3;i++){
        if(!count(tmpS.begin(),tmpS.end(),"ABC"[i])){
            string tmpS2 = replace(tmpS,"@",string(1,"ABC"[i]));
            if(tmpS2 == s) continue;
            if(rec(tmpS2)) return true;
        }
    }
    return false;
}
string solve(){
    string res;
    string S; cin >> S;
    res = rec(S)?"Yes":"No";
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
