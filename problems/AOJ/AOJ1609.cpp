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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1609&lang=jp>
 問題文============================================================
 =================================================================
 解説=============================================================
 愚直シミュレーション
 ================================================================
 */

int n;
string solve(){
    string res = "#";
    vector<int> cand(26,0);
    vector<char> c(n);
    for(auto& in:c){ cin >> in; in -= 'A';}
    for(int i = 0; i < n;i++){
        cand[c[i]]++;
        int leaf = n - i - 1;
        for(int j = 0; j < 26;j++){
            bool ok = true;
            for(int k = 0; k < 26;k++){
                if(j == k) continue;
                if(cand[j] <= cand[k] + leaf) { ok = false; break;}
            }
            if(ok){
                res = string(1,(char)(j+'A')) + " " + to_string(i+1);
                return res;
            }
        }
    }
    res = "TIE";
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    while(cin >> n,n){
        cout << solve() << endl;
    }
    return 0;
}
