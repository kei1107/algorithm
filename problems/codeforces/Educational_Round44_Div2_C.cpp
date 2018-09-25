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
 <url:http://codeforces.com/contest/985/problem/C>
 問題文============================================================
 
 m(= n*k) 個の板がある。ここでこの板のうちk個の板を使って一つのタルを作ることができるとし、
 n個のたるを作りたい。
 
 たるの容量というものを用いたk個の板のうちもっとも長さが小さいものとした時、
 
  |vx - vy| ≤ l （vはたるの容量）
 となるようにした時のたるの容量の総和の最大値を述べよ
 
 =================================================================
 解説=============================================================
 
 全ての板を使うので、最も容量の小さいたるは最も長さの小さい板に起因する。
 
 よって条件のみたす板が絞られるので、あとは大きい順に順番に板を使っていけば良い
 ================================================================
 */

ll solve(){
    ll res = 0;
    ll n,k,l; cin >> n >> k >> l;
    vector<ll> a(n*k); for(auto& in:a) cin >> in;
    sort(a.begin(),a.end());
    ll r = 0;
    for(; r < n*k; r++){
        if((a[r] - a[0]) <= l) continue;
        break;
    }
    if(r < n) return res;
    vector<int> used(n*k,false);
    ll R = n*k-1;
    for(ll i = r-1; i>=0; i--){
        if(used[i])continue;
        ll add = a[i];
        used[i] = true;
        ll t = k-1;
        while(t){
            if(used[R]){
                R--;
                continue;
            }
            t--;
            add = min(add,a[R]);
            used[R] = true;
            R--;
        }
        res += add;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
