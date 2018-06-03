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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1373>
 問題文============================================================
 
 深さ無限の完全二分木が与えられる。
 ここで深さはrootが0である。
 
 番号が振られたコインがn枚存在する。
 次の条件を満たすようにコインを順番に最適においていった時、
 そのコインを置くことができるのであればYes、
 どうやってもおくことができないのであればNoを
 出力せよ
 
 条件
 
 dが書かれたコインは深さdのノードにおく
 あるノードには最大１個までしかコインをおくことができない
 あるコインが置かれたノードから根までの間にコインが置かれたノードがあってはならない
 
 =================================================================
 解説=============================================================

 
 この問題は深さに応じた二進数として考えることができる
 
 例えば深さ2のコインが2個存在すれば、それは深さ１のコインが1個存在することと等しい
 すなわち 100 + 100 = 010
 
 これは他の深さに関しても同様であり、この考えにより深さ0のコイン、上の例でいえば 001 のような
 場合になった時、どのような数字のコインがきてもおくことができない
 
 
 このような考え方をして、あとはsetなりBITなりで実装すれば良い
 
 
 ================================================================
 */

void solve(){
    int n; cin >> n;
    vector<int> x(n); for(auto& in:x) cin >> in;
    set<int> s;
    int lim = 1;
    for(int i = 0; i < n;i++){
        if(s.count(0)){
            cout << "No" << endl;
            continue;
        }
        while(s.count(lim)) lim++;
        if(x[i] < lim - 1){
            cout << "No" << endl;
            continue;
        }
        if(x[i] == lim -1 && s.size() != x[i]){
            cout << "No" << endl;
            continue;
        }
        cout << "Yes" << endl;
        while(s.count(x[i])) s.erase(x[i]--);
        s.insert(x[i]);
    }
    return;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
