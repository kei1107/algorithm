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
 <url:https://yukicoder.me/problems/no/91>
 問題文============================================================
 赤、緑、青の3種類の石を1つずつ使って1つのアクセサリーができる。
 石は同じ色の石2個を別の色の石1個に交換することができる。
 最初に持っている赤、緑、青の石から最大何個のアクセサリーを作ることができるか？
 =================================================================
 解説=============================================================
 
 C(m) := 欲しいアクセサリーの個数がm個に作ることができるかどうか
 
 で二分探索
 ================================================================
 */

bool C(ll m,ll R,ll G,ll B){
    ll enough_stone = 0;
    ll hope_stone = 0;
    
    
    enough_stone += max(R - m,0LL)/2;
    enough_stone += max(G - m,0LL)/2;
    enough_stone += max(B - m,0LL)/2;
    
    hope_stone += max(m - R,0LL);
    hope_stone += max(m - G,0LL);
    hope_stone += max(m - B,0LL);
    
    return enough_stone>=hope_stone;
}
ll solve(){
    ll res = 0;
    ll R,G,B; cin >> R >> G >> B;
    ll& l = res;
    ll r = INF;
    while(r-l>1){
        ll m = (l+r)/2;
        if(C(m,R,G,B)){
            l = m;
        }else{
            r = m;
        }
    }
    C(l,R,G,B);
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
