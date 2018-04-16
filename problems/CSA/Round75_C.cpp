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
 <url:https://csacademy.com/contest/round-75/task/race-cars/>
 問題文============================================================
 There are N race cars. Each car is characterised by two integers D and V representing
 the distance until it crosses the finish line and the speed.
 There is a hacker capable of doing one of two things:
 
 increase the speed of your car by X
 reduce the speed of all other cars by Y
 
 Consider that the hacker is driving each car.
 What's the best place the hacker can finish the race opting for the best hack?
 
 All scenarios are independent of each other -
    the choice made for car i does not affect other cars.
 
 If two cars cross the finish lane at the same time,
 the car with the lowest id will be crossing first,
 that is the car that appears first in the input.

 =================================================================
 解説=============================================================
 
 ゴールに到達するまでの時間に着目する
 
 何も操作をしていない状態での、各車の{タイム,番号}と、Yだけ減速した場合の{タイム,番号}の配列をそれぞれ持っておき、
 昇順にソートしておく
 前者を ai, 後車を　biとする
 
 ここで、
 Xだけある車が加速した時の順位は
 aiでの{ 加速した時のタイム、番号} が昇順にはいる最小のindexから求めることができる
 
 次に、
 自分以外の車がYだけ減速した時の順位は
 biでの{ 通常のタイム、番号} が昇順にはいる最小のindexから求めることができる
 
 これらはともに lower_boundでもとまる
 
 ================================================================
 */

inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }

void solve(){
    ll N,X,Y; cin >> N >> X >> Y;
    vector<double> D(N),V(N);
    
    for(int i = 0; i < N; i++){
        cin >> D[i] >>V[i];
    }
    
    vector<pair<double,ll>> a(N),b(N);
    for(int i = 0; i < N;i++){
        a[i] = {V[i]/D[i],-i};
        b[i] = {(V[i]-Y)/D[i],-i};
    }
    
    vector<ll> ans(N,INF);
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    
    for(int i = 0; i < N;i++){
        ans[-a[i].second] = N - i;
    }
    
    for(int i = 0; i < N;i++){
        ll idx = -a[i].second;
        double new_v1 = (V[idx]+X)/D[idx];
        
        auto it1 = lower_bound(a.begin(),a.end(),pair<double,ll>(new_v1,-idx)) - a.begin();
        ans[idx] = min(ans[idx],(ll)(N+1 - it1));
        
        auto it2 = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        ans[idx] = min(ans[idx],(ll)(N+1 - it2));
    }
    
    for(int i = 0; i < N;i++){
        cout << ans[i] << endl;
    }
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
