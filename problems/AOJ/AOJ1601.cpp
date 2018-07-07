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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1601&lang=jp>
 問題文============================================================
 =================================================================
 解説=============================================================
 愚直に探索
 ================================================================
 */

int n;
int solve(){
    int res = 0;
    vector<string> w(n); for(auto& in:w) cin >> in;
    vector<int> tanka = {5,7,5,7,7};
    for(int i = 0; i < w.size();i++){
        int I = 0;
        for(int j = i; j < w.size();j++){
           // cout << tanka << endl;
            if(w[j].length() < tanka[I]){
                tanka[I] -= w[j].length();
            }else if(w[j].length() == tanka[I]){
                tanka[I] = 0;
                I++;
                if(I == 5){
                    return i + 1;
                }
            }else{
                tanka = vector<int>{5,7,5,7,7};
                break;
            }
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    while(cin >> n,n){
        cout << solve() << endl;
    }
    return 0;
}
