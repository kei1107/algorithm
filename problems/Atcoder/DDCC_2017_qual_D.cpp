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
 <url:https://ddcc2017-qual.contest.atcoder.jp/tasks/ddcc2017_qual_d>
 問題文============================================================
 南北方向に H 、東西方向に W のグリッド状の庭があり、
 北から i(1≦i≦H) 番目、西から j(1≦j≦W) 番目のマスを (i,j) とします。
 
 ただし、 H と W は偶数とします。
 
 各マスには石が高々 1 つ置かれており、また、 1 つ以上のマスに石が置かれています。
 
 なお、最初の庭の状態は、文字列 mi,j を用いて、
 (i,j) に石があるなら mi,j = S、石がないなら mi,j = . として与えられます。
 
 これらの石を 1 つずつ取り除いていきます。
 
 石を取り除いた直後に、庭の石の配置が南北方向に対称なら A の幸福度、
 東西方向に対称なら B の幸福度が得られます。
 
 ただし、南北方向にも東西方向にも対称のときは A+B の幸福度が得られることとします。
 
 全ての石を自由な順番で取り除くとき、得られる最大の幸福度を求めてください。
 
 なお、南北方向に対称とは、以下のことが成り立つ場合です。
 
 すべての i,j(1≦i≦H,1≦j≦W) において (i,j) に石があるなら (H+1−i,j) にも石があり、
 (i,j) に石がなければ (H+1−i,j) に石がない。
 
 また、東西方向に対称とは、以下のことが成り立つ場合です。
 
 すべての i,j(1≦i≦H,1≦j≦W) において (i,j) に石があるなら (i,W+1−j) にも石があり、
 (i,j) に石がなければ (i,W+1−j) に石がない。
 
 =================================================================
 
 解説=============================================================
 
 石が置かれていない盤面から復元する形で考える
 
 東西南北対称な石があれば
     A + B + max(A,B)
 の幸福度を得て、４つの石をおいたあとも東西南北対称である
 
 その後、東西対称 or 南北対称の石しかなく、なおかつ
 一度東西対称の石をおけば、その後盤面を南北対称にすることができず
 一度南北対称の石をおけば、その後盤面を東西対称にすることができない
 
 よって ２パターンを試すことで、その後の最大幸福度を計算することができる。
 
 最後に、石が置かれていない状態も東西南北対称な盤面であること　かつ、　盤面の初期状態も
 対称かどうかで　幸福度を加算・減算しておけば良い
 
 ================================================================
 */
ll solve(){
    ll ret = 0;
    ll H,W; cin >> H >> W;
    ll A,B; cin >> A >> B;
    vector<vector<char>> m(H+1,vector<char>(W+1));
    for(int i = 1; i <= H;i++) for(int j = 1; j <= W;j++) cin >> m[i][j];
    
    ret += A+B;
    
    bool a = true, b = true;
    [&]{
        for(int i = 1; i <= H/2; i++) for(int j = 1; j <= W; j++){
            if(m[i][j] != m[H+1-i][j]){
                a = false; return;
            }
        }
    }();
    [&]{
        for(int j = 1; j <= W/2;j++) for(int i = 1; i <= H;i++){
            if(m[i][j] != m[i][W+1-j]){
                b = false; return;
            }
        }
    }();
    if(a) ret -= A;
    if(b) ret -= B;
    
    vector<vector<char>> tm(H+1,vector<char>(W+1,'.'));
    for(int i = 1; i <= H/2; i++){
        for(int j = 1; j <= W/2;j++){
            if((m[i][j] == 'S') && (m[H+1-i][j] == 'S') && (m[i][W+1-j] == 'S') && (m[H+1-i][W+1-j] == 'S')){
                ret += A+B + max(A,B);
                tm[i][j] = tm[H+1-i][j] = tm[i][W+1-j] = tm[H+1-i][W+1-j] = 'S';
            }
        }
    }

    ll sA = 0;
    for(int i = 1; i <= H/2; i++){
        for(int j = 1; j <= W; j++){
            if(tm[i][j] == 'S') continue;
            if((m[i][j] == 'S') && (m[H+1-i][j] == 'S')){
                sA += A;
            }
        }
    }
    ll sB = 0;
    for(int i = 1; i <= H;i++){
        for(int j = 1; j <= W/2;j++){
            if(tm[i][j] == 'S') continue;
            if((m[i][j] == 'S') && (m[i][W+1-j] == 'S')){
                sB += B;
            }
        }
    }
    ret += max(sA,sB);
    
    return ret;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
