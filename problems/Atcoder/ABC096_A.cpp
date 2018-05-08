//#include "bits/stdc++.h"
//using namespace std;
//typedef long long ll;
//typedef pair<int, int> pii;
//typedef pair<ll, ll> pll;
//const int INF = 1e9;
//const ll LINF = 1e18;
//template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
//template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
//template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
//template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }
//
///*
// <url:>
// 問題文============================================================
// =================================================================
// 解説=============================================================
// ================================================================
// */
//
//int dx[4] ={1,0,-1,0};
//int dy[4] ={0,1,0,-1};
//
//void Fill(int x,int y,vector<vector<char>>& masu){
//    masu[x][y] = '.';
//    for(int k = 0; k < 4;k++){
//        int nx = x + dx[k],ny = y + dy[k];
//        if(masu[nx][ny] == '#') Fill(nx,ny,masu);
//    }
//}
//string solve(){
//    ll H,W; cin >> H >> W;
//    vector<vector<char>> masu(H+2,vector<char>(W+2,'@'));
//    for(int i = 1; i <= H;i++){
//        for(int j = 1; j <= W;j++){
//            cin >> masu[i][j];
//        }
//    }
//    for(int i = 1; i<=H;i++){
//        for(int j = 1; j <=W;j++){
//            for(int k = 0; k < 4;k++){
//                int nx = i + dx[k], ny = j + dy[k];
//                if(masu[i][j] == '#' && masu[nx][ny] == '#'){
//                    Fill(i,j,masu);
//                }
//            }
//        }
//    }
//    for(int i = 1; i <= H;i++){
//        for(int j = 1; j <= W;j++){
//            if(masu[i][j] == '#') return "No";
//        }
//    }
//    return "Yes";
//}
//int main(void) {
//    cin.tie(0); ios_base::sync_with_stdio(false);
//    cout << solve() << endl;
//    return 0;
//}
