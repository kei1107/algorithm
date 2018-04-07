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
 <url:https://beta.atcoder.jp/contests/arc094/tasks/arc094_b>
 問題文============================================================
 高橋君を含めた 10^10^10 人の参加者が 2 回のプログラミングコンテストに参加しました。
 各コンテストでは全員に 1 位から 10^10^10 位までの相異なる順位がつきました。
 
 参加者のスコアとは、2 回のコンテストでの順位を掛け合わせた値です。
 
 次のクエリ Q 個に答えてください。
 
 i 個目のクエリでは、2 つの正の整数 Ai,Bi が与えられる。
 高橋君が 1 回目のコンテストで Ai 位、2 回目のコンテストで Bi 位を取ったと仮定して、
 高橋君よりスコアの小さい参加者の人数の最大値を求めよ。
 
 =================================================================
 解説=============================================================
 
 各クエリについてにぶたんして独立に考える
 以下 Ai := x , Bi := yとする
 
 最初、問題を簡単にするために x > y であれば　swapしておく
 
 ここで、何ペア作りたいかについてだが、選択できる範囲としては
 x について [1,x) (x,x*y)
 y について [1,y) (y,x*y)
 の範囲から選択できる
 
 この時 [1,x)  [1,y)  からそれぞれ順位を選んだならば必ず条件は達成できるが、
 最大人数という意味では最適ではなく
 
 よって
(x,x*y) [1,y)
 [1,x) (y,x*y)
 からできる限りペアを作りたい
 
 ここで それぞれについて 1から何位まで最大でペアを作ることができるのかについてにぶたんを行う
  (x,x*y) [1,y)
 について　単純に[1,m]位から mペアを作るとかていした時、作られるペアを最適に選んだ場合の順位の最大値は　(x+1)*m
 となる
 
  [1,x) (y,x*y)については
 mが　x <= m であれば前半と同様と考え方ができるが、
     x > m となった場合
        最大値は、 (x+1)とmの平均近辺となる。
            より厳密に言えば和が偶数であれば (x+1+m)/2 *  (x+1+m)/2
                         和が奇数であれば　(x+1+m)/2 *  (x+1+m)/2 + 1
 となる。
 
 よって、それぞれの組について最大ペア数がわかる
 
 最後に一番最初に確認した　[1,x)  [1,y) のペアについてまだ選択できる余地があれば選択すれば良い
 
 
 ================================================================
 */

void solve(){
    ll Q; cin >> Q;
    while(Q--){
        ll x,y; cin >> x >> y;
        if(x > y) swap(x,y);
        ll S = x*y;
        
        ll l = 0, r = x;
        while(r-l>1){
            ll m = (l+r)/2;
            ll _x = m;
            
            ll _y = y + 1;
            if(_x*_y >= S){
                r = m;
            }else{
                l = m;
            }
        }
        ll xcnt = l;
        
        l = 0; r = y;
        while(r-l>1){
            ll m = (l+r)/2;
            ll _x = x + 1;
            ll _y = m;
            if(_y > x){
                ll ave = (_x + _y)/2;
                if((_x+_y)%2 == 0) _x = _y = ave;
                else {_x = ave; _y = ave+1;}
            }

            if(_x*_y >= S){
                r = m;
            }else{
                l = m;
            }
        }
        ll ycnt = l;
        ll cnt_add = min(x-1-xcnt,y-1-ycnt);

        cout << xcnt + ycnt + cnt_add << endl;
    }
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
