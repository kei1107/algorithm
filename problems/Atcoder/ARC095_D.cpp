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
 <url:https://beta.atcoder.jp/contests/arc095/tasks/arc095_b>
 問題文============================================================
 n 個のものから順番を無視して r 個を選ぶ場合の数を comb(n,r) と書くことにします。
 n 個の非負の整数 a1,a2,…,an から 2 つの数 ai>aj を comb(ai,aj) が最大になるように選んで下さい。
 最大になる組が複数ある場合、どれを選んでも構いません。
 =================================================================
 解説=============================================================
 組み合わせ数 nCrを見たとき、rはn/2に近くなればなるほどnCrは大きくなる。
 
 またnは大きければ大きいほど値が大きくなると考えられるので、
 それっぽいのを探す。
 
 （あとで見たが、nが最大値で良いと証明できるっぽい)
 ================================================================
 */

void solve(){
    ll n; cin >> n;
    vector<ll> a(n); for(auto& in:a) cin >> in;
    sort(a.begin(),a.end());
    ll dif = -1;
    ll l = -1,r = -1;
    for(int i = 1; i < n;i++){
        auto it = lower_bound(a.begin(), a.end(), a[i]/2) - a.begin();
        for(int j = -1; j <= 1; j++){
            if(it+j<0) continue;
            if(it+j>=i) continue;
            ll x = a[it+j];
            if(a[i]-x>x) x = a[i]-x;
            if(a[i]-x >= dif){
                dif = a[i]-x;
                l = a[i]; r = a[it+j];
            }
        }
    }
    cout << l << " " << r << endl;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
