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
 <url:https://yukicoder.me/problems/no/21>
 問題文============================================================
 N 個の数字が与えられるのでこれらをK(≥3)個のグループに振り分ける。
 ただし各グループには最低一つ数字が含まれているとする。
 
 ex) 例えば 与えれる数字が {10,3,23,91,5}, K=3 なら
 {{3,91},{23,5},{10}} のような振り分けかたはただしく
 {{},{3,5,10},{23,91}} のような振り分けかたは認められません
 
 グループごとに平均を計算し, それらをもとに 最大の平均 - 最小の平均 を計算し、
 最後に小数点以下を切り上げその値を「平均の差」と呼ぶ。
 平均の差を最も大きくするようなグループ分けをしたとき、平均の差はいくつになるか答えよ。
 =================================================================
 解説=============================================================
 
 最大要素 - 最小要素
 が答え
 ================================================================
 */

ll solve(){
    ll res = 0;
    ll N,K; cin >> N >> K;
    vector<ll> n(N); for(auto& in:n) cin >> in;
    return res = *max_element(n.begin(), n.end()) - *min_element(n.begin(), n.end());
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
