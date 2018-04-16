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
 <url:https://csacademy.com/contest/round-76/task/overlapping-matrices/>
 問題文============================================================
 HxWの行列Aと(H+X)x(W+Y)の行列Bが与得られる。
 行列Bは行列Aと、行列AをX行、Y列分スライドさせて作った行列から成っている、
 その結果としてBは次のような性質をもつ
 
 ・もしセル(i,j)がA由来でなければ Bij = 0
 ・もしセル(i,j)がA及びAをスライドさせて作られた行列の両方の要素であれば Bij = Aij + A(i-x)(j-y)
 ・もしセル(i,j)がA及びAをスライドさせて作られた行列のどちらかの要素であれば Bij = Aij or A(i-x)(j-y)
 
 BとX,Yが与えられるので、元々の行列Aを求めよ
 
 =================================================================
 解説=============================================================
 
 A固有の要素を a, Aスライドさせて作られた行列固有の要素を b 、互いに共通な要素を cとすると
 
 aaaa00     aaaa                    00
 aacc00  =  aaaa   +  bbbb  +
 00bbbb               bbbb      00
 
 と成っている
 よって最初に左上部分と右下部分からAの元々の要素が取得でき、
 その後、 c部分を見ることによって、　 Bij = Aij + A(i-x)(j-y) のどちらかのA要素は
 確定しているため復元が可能
 ================================================================
 */

void show(vector<vector<ll>>& A,int H,int W){
    for(int i = 0; i < H;i++){
        for(int j  = 0; j < W;j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}
void solve(){
    int H,W,X,Y; cin >> H >> W >> X >> Y;
    vector<vector<ll>> B(H+X,vector<ll>(W+Y));
    for(auto& a:B)for(auto& in:a) cin >> in;
    
    vector<vector<ll>> A(H,vector<ll>(W,0));
    
    for(int i = 0; i < X;i++){
        for(int j = 0; j < W;j++){
            A[i][j] = B[i][j];
        }
    }
    
    for(int i = X; i < H;i++){
        for(int j = 0; j < Y;j++){
            A[i][j] = B[i][j];
        }
    }
    
    for(int i = X; i < H;i++){
        for(int j = W; j < W+Y;j++){
            A[i-X][j-Y] = B[i][j];
        }
    }
    
    for(int i = H;i<H+X;i++){
        for(int j = Y; j < W+Y;j++){
            A[i-X][j-Y] = B[i][j];
        }
    }
    
    for(int i = X;i<H;i++){
        for(int j = Y;j<W;j++){
            A[i][j] = B[i][j] - A[i-X][j-Y];
        }
    }
    
    
    for(int i = 0; i < H;i++){
        for(int j  = 0; j < W;j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
