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
 <url:http://codeforces.com/contest/985/problem/A>
 問題文============================================================
 
 BWBWBWBWBW...
 と印がつけられた1xnの板がある。（nが偶数）
 
 ここでn/2個のピースの位置が与えられるので、ピースを全てBか全てWの上になるように
 移動する際の最小移動回数を述べよ
 =================================================================
 解説=============================================================
 
 ピースの個数とその色の印の個数は等しいので、
 色を固定して、最終的にどのピースをどのマスに移動させると決定したときの移動数は変わらない
 よってBとWにおいて、あいているマスと現在条件を満たしていないピースを順番に見て移動させればよい

 ================================================================
 */

ll solve(){
    ll res = INF;
    ll n; cin >> n;
    vector<ll> p(n/2); for(auto& in:p) cin >> in;
    vector<int> f(n+1,false);
    for(int i = 0; i < n/2;i++) f[p[i]] = true;
    sort(p.begin(),p.end());
    //   reverse(p.begin(),p.end());
    ll tmp = 0;
    for(int i = 0; i < n/2; i++){
        if(p[i]%2 == 0) continue;
        for(ll j = 1; j <= n;j++){
            if(f[j] == false && j%2 == 0){
                f[j] = true;
                tmp += abs(j - p[i]);
                break;
            }
        }
    }
    res = min(res,tmp);

    tmp = 0;
    fill(f.begin(),f.end(),false);
    for(int i = 0; i < n/2;i++) f[p[i]] = true;
    for(int i = 0; i < n/2; i++){
        if(p[i]%2 == 1) continue;
        for(int j = 1; j <= n;j++){
            if(f[j] == false && j%2 == 1){
                f[j] = true;
                tmp += abs(j - p[i]);
                break;
            }
        }
    }
    res = min(res,tmp);
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
