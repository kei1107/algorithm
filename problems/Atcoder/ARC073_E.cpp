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
 <url:https://arc073.contest.atcoder.jp/tasks/arc073_c>
 問題文============================================================
 2 個の白いボールが入った袋が N 個あります。
 i 個目の袋にはそれぞれ整数 xi と yi が書かれたボールが 1 個ずつ入っています。
 
 あなたはこの袋それぞれについて、片方のボールを赤く塗り、もう片方を青く塗ります。
 
 そのあと 2N 個のボールを、塗られた色で分類します。
 
 そして
 
 赤く塗られたボールに書かれた整数の最大値を Rmax
 赤く塗られたボールに書かれた整数の最小値を Rmin
 青く塗られたボールに書かれた整数の最大値を Bmax
 青く塗られたボールに書かれた整数の最小値を Bmin
 
 としたときに、(Rmax−Rmin)×(Bmax−Bmin) の最小値を求めてください。
 
 =================================================================
 解説=============================================================
 
 必要な要素は4要素のみであり、
 全ての値の最大値と最小値をとれば、その4要素のうち2要素は定まる。
 
 よって、問題が簡単になるので、
 残りパターンについて確認すれば良い
 ================================================================
 */

ll solve(){
    ll res = LLONG_MAX;
    ll N; cin >> N;
    vector<ll> x(N),y(N);
    vector<pll> ps(N);
    ll Ri = LLONG_MAX,Ra = -1;
    for(int i = 0; i < N;i++){
        cin >> x[i] >> y[i];
        if(x[i] > y[i]) swap(x[i],y[i]);
        Ri = min(Ri,x[i]);
        Ra = max(Ra,y[i]);
        ps[i] = {x[i],y[i]};
    }
    
    sort(ps.begin(),ps.end());
    ll La = ps[N-1].first, Rb = Ra;
    for(auto& p:ps) Rb = min(Rb,p.second);
    res = min(res,(La-Ri)*(Ra-Rb));
    
    set<pll> s;
    s.insert({ps[0].second,LINF});
    for(int i = 1; i < N;i++) s.insert({ps[i].second,i});
    
    while(true){
        ll dif = s.rbegin()->first-s.begin()->first;
        res = min(res,(Ra-Ri)*dif);
        
        auto t = *s.rbegin();
        s.erase(*s.rbegin());
        if(t.second >= LINF) break;
        s.insert({ps[t.second].first,LINF});
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
