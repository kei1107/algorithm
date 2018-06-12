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
 <url:https://arc076.contest.atcoder.jp/tasks/arc076_c>
 問題文============================================================
 すぬけ君は、パズルゲームで遊んでいます。
 このパズルゲームでは、R×C の長方形の盤面に、1 から N までの整数が 2 つずつ書かれています。
 整数 i が書かれている座標は、(xi,1,yi,1) と (xi,2,yi,2) です。
 
 すぬけ君の目的は、1 から N までのすべての整数に対し、同じ整数の書かれている座標同士を曲線で結ぶことです。
 このとき、曲線が長方形の外に出たり、互いに交わったりしてはいけません。
 
 このようなことが可能かどうか判定してください。
 =================================================================
 解説=============================================================
 
 この問題は、同じ整数の書かれている座標同士を自由な曲線で結ぶことができることから
 両方の整数が枠上に存在し、長方形を物理的に分割せざるおえない状況にならない限り、
 自由に結ぶことができると手で書いたりして実験するとわかる。
 
 よって、この問題は
 RxCの長方形を分割するような同じ整数の書かれている座標同士をまっすぐ結んだ線分が
 他の同様の条件を満たす線分と交差するか否かという問題に落とし込むことができる。
 
 単純に考えると、各線分同士を比較して交差判定を行う。という解法が思いつくが、
 頂点数の制約から間に合わない。
 そこで、線分を順番に見て行って、過去に確認した線分と交差するか否かを高速に判定できる方法を
 考える。
 その結果、考察を進めると、
 枠上の頂点(0,0)から(0,C)->(R,C)->(R,0)->(0,0)
 という反時計回りの巡回路を考える。
 該当するペアに関して、この巡回路上に順番に現れるものから処理を行う。
 この時、もう片方の頂点は必ず直前に見た頂点ペアの巡回路の距離的に遠い方よりも
 巡回路の短ければ交差しないことがわかる。
 
 このことを利用してstackなどで、注意すべき距離を保存していけばO(N)で判定可能になる。

 ================================================================
 */

ll R,C,N;
ll p2d(ll x,ll y){
    if(x!=0 && x!= R && y!= 0 && y!= C) return -1;
    ll res = -1;
    if(x==0) res = y;
    else if(y==C) res = C+x;
    else if(x==R) res = C+R+(C-y);
    else if(y==0) res = C+R+C+(R-x);
    return res;
}
string solve(){
    cin >> R >> C >> N;
    vector<pll> ps;
    for(int i = 0; i < N;i++){
        ll x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
        ll d1 = p2d(x1,y1); if(d1 < 0) continue;
        ll d2 = p2d(x2,y2); if(d2 < 0) continue;
        if(d1 > d2) swap(d1,d2);
        ps.push_back({d1,d2});
    }
    sort(ps.begin(),ps.end());
    stack<ll> s;
    s.push(LINF);
    for(auto& p:ps){
        ll d1,d2; tie(d1,d2) = p;
        while(d1 >= s.top()) s.pop();
        if(d2 >= s.top()) return "NO";
        s.push(d2);
    }
    return "YES";
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
