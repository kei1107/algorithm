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
<url:https://onlinejudge.u-aizu.ac.jp/services/room.html#RitsCamp18Day2/problems/C>
問題文============================================================
 N 個のボールがあり、各ボールには色と価値が決められている。
 ボールの色は1からCまでC種類存在し、各色ごとに選べるボールの数の上限が決められている。
 ボールを全体で高々M個選ぶとき、得られる価値の合計を最大化せよ。

=================================================================

解説=============================================================

 価値の高いものから貪欲にとっていくのが最適
 
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N,M,C; cin >> N >> M >> C;
    vector<ll> l(C);
    for(auto& in:l) cin >> in;
    vector<pll> cw(N);
    for(auto& in:cw) cin >> in.second >> in.first;
    sort(cw.begin(),cw.end(),greater<pll>());
    
    ll cnt = 0;
    ll ans = 0;
    for(int i = 0; i < N;i++){
        if(l[cw[i].second-1]-- > 0){
            cnt++;
            ans += cw[i].first;
        }
        if(cnt == M) break;
    }
    cout << ans << endl;
	return 0;
}
