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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2508>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 先に復元用の操作リストを作っておいて、復元してやれば楽
 ================================================================
 */

string alpha;
map<char,int> c2i;
void init(){
    for(int i = 0; i < 26;i++){
        char c = 'a'+i;
        alpha += c;
        c2i[c] = i;
    }
    for(int i = 0; i < 26;i++){
        char c = 'A'+i;
        alpha += c;
        c2i[c] = 26+i;
    }
    alpha += alpha;
    alpha += alpha;
}
string solve(ll n){
    string res;
    vector<int> key(n); for(auto& in:key) cin >> in;
    string s; cin >> s;
    for(int i = 0; i < s.length();i++){
        char c = s[i];
        res += (alpha[c2i[c]+52-key[i%n]]);
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    init();
    int n;
    while(cin >> n,n){
        cout << solve(n) << endl;
    }
    return 0;
}
