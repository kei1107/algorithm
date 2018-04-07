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
 <url:http://codeforces.com/contest/961/problem/C>
 問題文============================================================
 Magnus decided to play a classic chess game. Though what he saw in his locker shocked him!
 His favourite chessboard got broken into 4 pieces, each of size n by n, n is always odd.
 And what's even worse, some squares were of wrong color. j-th square of the i-th row of
 k-th piece of the board has color ak, i, j; 1 being black and 0 being white.
 
 Now Magnus wants to change color of some squares in such a way that he recolors minimum
 number of squares and obtained pieces form a valid chessboard. Every square has its color
 different to each of the neightbouring by side squares in a valid board.
 Its size should be 2n by 2n. You are allowed to move pieces but not allowed to
 rotate or flip them.
 
 Input
 The first line contains odd integer n (1 ≤ n ≤ 100) — the size of all pieces of the board.
 
 Then 4 segments follow, each describes one piece of the board.
 Each consists of n lines of n characters; j-th one of i-th line is equal to 1
 if the square is black initially and 0 otherwise. Segments are separated by an empty line.
 
 Output
 Print one number — minimum number of squares Magnus should recolor to be able to
 obtain a valid chessboard.
 =================================================================
 解説=============================================================
 
 理想的な状態は一松模様であることがわかる。
 
 各チェスボードについて確認すべきパターンは4!しかないので、理想とする一松模様と比較して、
 もっとも差が小さいのが答え
 
 ================================================================
 */

ll solve(){
    ll res = INF;
    ll n; cin >> n;
    vector<vector<int>> masu[4];
    for(int i = 0; i < 4; i++){
        masu[i] = vector<vector<int>>(n,vector<int>(n,0));
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n;k++){
                char c; cin >> c;
                masu[i][j][k] = c - '0';
            }
        }
    }
    
    vector<vector<int>> M[2];
    M[0] = vector<vector<int>>(n,vector<int>(n,0));
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++){
            if((i+j)%2 == 0) M[0][i][j] = 1;
        }
    }
    M[1] = vector<vector<int>>(n,vector<int>(n,0));
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++){
            if((i+j)%2 == 1) M[1][i][j] = 1;
        }
    }
    vector<int> next(4); iota(next.begin(),next.end(),0);
    do{
        ll cost = 0;
        for(int k  = 0; k < 4;k++){
            int mode = k%2;
            for(int i = 0; i < n;i++){
                for(int j = 0; j < n;j++){
                    cost += (M[mode][i][j] != masu[next[k]][i][j]);
                }
            }
        }
        res = min(res,cost);
    }while(next_permutation(next.begin(),next.end()));
    
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
