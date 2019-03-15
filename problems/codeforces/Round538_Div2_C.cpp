#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

/*
 <url:https://codeforces.com/contest/1087/problem/C>
 問題文============================================================
 グリッドマス上に3頂点が与えられる
 
 ３頂点が連結となるようにグリッドを塗りつぶすとき、
 その塗りつぶすグリッドの最小個数と塗りつぶした頂点群を出力せよ
 =================================================================
 解説=============================================================
 x軸(y軸)について中間となる頂点からまっすぐ棒を伸ばして、残りの２頂点がその棒に向かって真っ直ぐ繋がる感じ
 で実装
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    vector<pii> ps(3);
    for(auto& in:ps) cin >> in.first >> in.second;
    sort(ps.begin(),ps.end(),[](const pii& p1,const pii& p2){return p1.first < p2.first;});

    vector<pii> ans1;
    for(int x = min(ps[0].first,ps[1].first); x <= max(ps[0].first,ps[1].first); x++){
        ans1.push_back({x,ps[0].second});
    }
    for(int x = min(ps[2].first,ps[1].first); x <= max(ps[2].first,ps[1].first); x++){
        ans1.push_back({x,ps[2].second});
    }
    for(int y = min({ps[0].second,ps[1].second,ps[2].second}); y <= max({ps[0].second,ps[1].second,ps[2].second}); y++){
        ans1.push_back({ps[1].first,y});
    }
    sort(ans1.begin(),ans1.end());
    ans1.erase(unique(ans1.begin(),ans1.end()),ans1.end());

    cout << ans1.size() << endl;
    for(int i = 0; i < ans1.size();i++){
        cout << ans1[i].first << " " << ans1[i].second << endl;
    }

    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    solve<ll>(0);
    //cout << fixed << setprecision(12) << solve<ll>() << endl;
    return 0;
}
