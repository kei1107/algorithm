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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2756>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 制約条件から台風の移動候補を絞ることができる
 
 その後、移動候補から台風の発生・消失箇所に関して矛盾点を取り除いていけば自ずと求まる
 ================================================================
 */

vector<int> solve(){
    vector<int> res;
    int H,W; cin >> H >> W;
    vector<vector<int>> D(H,vector<int>(W));
    for(auto& vec:D) for(auto& in:vec) cin >> in;
    vector<vector<int>> couho(H,vector<int>(W,0));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W;j++){
            if(D[i][j] == 0) continue;
            if(D[i][j] != 0){
                int cost = D[i][j];
                for(int k = 0; k < 3;k++){
                    for(int l = 0; l < 3;l++){
                        D[i+k][j+l] -= cost;
                    }
                }
                couho[i+1][j+1]++;
            }
        }
    }
    vector<pii> loc;
    for(int i = 0; i < H;i++){
        for(int j = 0; j < W;j++){
            if(couho[i][j]){
                int cnt = 0;
                for(int k = -1; k <= 1; k++){
                    for(int l = -1; l <= 1; l++){
                        if(couho[i+k][j+l]) cnt++;
                    }
                }
                if(cnt <= 2){
                    loc.push_back({i,j});
                }
            }
        }
    }
    sort(loc.rbegin(),loc.rend());
    res = vector<int>{loc.begin()->first,loc.begin()->second,loc.rbegin()->first,loc.rbegin()->second};
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
