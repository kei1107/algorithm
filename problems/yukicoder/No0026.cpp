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
 <url:https://yukicoder.me/problems/no/26>
 問題文============================================================
 太郎君と二郎君はゲームをしています。
 
 テーブルの上にカップが3つあり、その中の1つだけに○印、
 それ以外の2つには×印が外から見えないように記されています。
 
 太郎君から見て左にあるカップから1番、2番、3番として、
 最初に○印がどのカップについてるかが公開された後、
 二郎君は、何度かカップの位置をそれぞれ入れ替えるので、
 太郎君はどのカップに○印が付いているかを当てなければなりません。
 
 入れ替え中も入れ替えた後も、常に、左にあるカップから1番、2番、3番とし、
 最初以外は、カップについている印は見ることは出来ません。
 
 入力に、最初に○印が付いているカップの位置番号と、
 二郎君が入れ替えたカップの位置番号が与えられるので、
 最終的に○印が付いているカップの位置番号を出力してください。
 =================================================================
 解説=============================================================
 実際に印をつけてシミュレーションするだけ
 ================================================================
 */

ll solve(){
    ll N,M; cin >> N >> M;
    vector<ll> P(M),Q(M);
    for(int i = 0; i < M;i++) cin >> P[i] >> Q[i];
    
    bool cups[4] = {false};
    cups[N] = true;
    for(int i = 0; i < M;i++){
        swap(cups[P[i]],cups[Q[i]]);
    }
    for(int i = 1; i <= 3;i++){
        if(cups[i])return i;
    }
    return 0;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
