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
 <url:https://arc077.contest.atcoder.jp/tasks/arc077_c>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 ある値をお気に入りにした時、単純に順送りボタンを押していった場合からどれだけ
 減少させることができるかを考える。
 
 ここで ai <= x <= a_{i+1} にお気に入りボタンが存在すれば x - (ai + 1)回分
 順送りボタンを押す操作を減らすことができる
 
 よって、imos法および累積和を用いることで各xに置ける減少数が計算できる
 ================================================================
 */

ll solve(){
    ll res = 0;
    ll n,m; cin >> n >> m;
    vector<ll> a(n); for(auto &in:a){ cin >> in; in--;}
    vector<ll> imos1(2*m,0);
    vector<ll> imos2(2*m,0);
    ll sum = 0;
    for(int i = 0; i < n-1;i++){
        ll l = a[i], r = a[i+1];
        if(r < l) r += m;
        sum += r - l;
        if(r - l <= 1) continue;
        imos1[l+2] += 1;
        imos1[r+1] -= 1;
        imos2[r+1] -= (r+1) - (l+2);
    }
    
    imos2[0] += imos1[0];
    for(int i = 0; i < 2*m-1;i++){
        imos1[i+1] += imos1[i];
        imos2[i+1] += imos2[i] + imos1[i+1];
    }
    
    vector<ll> dec(m);
    for(int i = 0; i < m;i++) dec[i] = imos2[i] + imos2[i+m];
    res = sum - *max_element(dec.begin(),dec.end());
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
