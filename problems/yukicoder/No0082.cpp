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
 <url:https://yukicoder.me/problems/no/82>
 問題文============================================================
 幅Wと高さHと左上の色が指定されるので市松模様を描け。
 市松模様は、黒と白が交互に現れる模様である。
 模様は黒を'B'、白を'W'を使って描くものとする。
 =================================================================
 解説=============================================================
 ================================================================
 */

void solve(){
    int W,H; cin >> W >> H;
    char C; cin >> C;
    vector<vector<char>> res(H,vector<char>(W));
    char e = C, o = (C=='B'?'W':'B');
    for(int i = 0; i < H;i++){
        for(int j = 0; j < W;j++){
            if((i+j)%2==0) res[i][j] = e;
            else res[i][j] = o;
            cout << res[i][j];
        }
        cout << endl;
    }
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
