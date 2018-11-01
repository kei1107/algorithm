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
 <url:https://yukicoder.me/problems/no/322>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 二つの難所でどちらが先に来るべきかを考えてみる
 この時、二つの難所の時間と難易度をそれぞれT1,D1,T2,D2とすると
 
 1個目の難所を先に攻略するとかかる時間は
    T = T1/2 * D1 + T1 * D2 + T2/2 * D2 + T1 + T2
 2個目の難所を先に攻略するとかかる時間は
    T' = T2/2 * D2 + T2 * D1 + T1/2 * D1 + T1 + T2
 
 ここで
    T - T' = T1 * D2 - T2 * D1
 となる。
 よって T1 * D2が T2 * D1 よりも大きければ1個目の難所を先に攻略した方がいい事がわかる
        逆の場合は2個目の難所優先
 
 こればN個のうちのどの二つを選んでも同様の事が言えるため
 この条件を比較関数として組み込んでソートしてやればいい
 
 ================================================================
 */

vector<ll> solve(){
    vector<ll> res;
    ll N; cin >> N;
    vector<ll> T(N),D(N);
    for(auto& in:T) cin >> in;
    for(auto& in:D) cin >> in;
    
    vector<pair<pll,ll>> TD(N);
    for(int i = 0; i < N;i++) TD[i] = {{T[i],D[i]},i};
    sort(TD.begin(),TD.end(),[](const pair<pll,ll>& p1,const pair<pll,ll>& p2){
        return p1.first.first*p2.first.second > p1.first.second*p2.first.first;
    });
    res = vector<ll>(N);
    for(int i = 0; i < N;i++) res[i] = TD[i].second+1;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
