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
 <url:https://yukicoder.me/problems/no/307>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 頑張って実装しましょう。。。
 
 全面が同一色に塗られれば最後のクエリ以外は無視してよくなる
 ================================================================
 */

void solve(){
    int H,W; cin >> H >> W;
    vector<vector<int>> A(H,vector<int>(W));
    for(auto& vec:A)for(auto& in:vec) cin >> in;
    int Q; cin >> Q;
    vector<int> R(Q),C(Q),X(Q);
    for(int i = 0; i < Q;i++){
        cin >> R[i] >> C[i] >> X[i];
        R[i]--; C[i]--;
    }
    
    bool allfilled = false;
    int d[4] = {1,0,-1,0};
    for(int i = 0; i < Q;i++){
        if(allfilled && i != Q-1) continue;
        if(A[R[i]][C[i]]==X[i]) continue;
        
        queue<pii> q; q.push({R[i],C[i]});
        while(q.size()){
            int x,y; tie(x,y) = q.front(); q.pop();
            if(A[x][y]==X[i]) continue;
            A[x][y] = X[i];
            for(int k = 0; k < 4;k++){
                int nx = x + d[k];
                int ny = y + d[k^1];
                if(nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
                if(A[nx][ny]!=X[i]){
                    q.push({nx,ny});
                }
            }
        }
        
        allfilled = true;
        [&](){
            for(int i = 0; i < H;i++)for(int j = 0; j < W;j++) if(A[0][0]!=A[i][j]){allfilled = false; return;}
        }();
    }
    cout << A << endl;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
