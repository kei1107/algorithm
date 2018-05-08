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
 <url:https://yukicoder.me/problems/no/69>
 問題文============================================================
 同じ長さの文字列Aと文字列Bが与えられる。
 文字列Aの順番を自由に並び替えることができる。
 文字列Aと文字列Bを同じにできるか判定せよ。
 =================================================================
 解説=============================================================
 
 アルファベットの出てくる個数を比較すればよい
 ================================================================
 */

string solve(){
    string A,B; cin >> A >> B;
    for(int i = 0; i < 26;i++){
        if(count(A.begin(),A.end(),'a'+i) != count(B.begin(),B.end(),'a'+i)) return "NO";
    }
    return "YES";
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
