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
 <url:https://beta.atcoder.jp/contests/abc107/tasks/arc101_b>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 二分探索+BIT
 
 まず、目的となる中央値を二分探索で求める。
 今見ている値をxとすると
 xは最終的に整数列bの中では
 bの中にx以上の要素が半分以上含まれることと、左の条件を満たす整数の中で最大であることが条件となる
 
 ここでmのうちx以上の要素は
 aの連続部分列(1<=l<=r<=N)のうち  [l,r]のうちx未満の個数 <= [l,r]のうちx以上の個数　を満たすものの総数
 としてわかる。
 コレは累積和で見ればBITでもとまる
 ================================================================
 */

struct BIT {
    ll N;
    vector<ll> bit;
    BIT(ll N):N(N) {
        /* BITは[1..N]で扱う */
        bit.resize(N + 1, 0);
    }
    
    void add(int x, ll val){
        while (x <= N) {
            bit[x] += val;
            x += x & -x;
        }
    }
    
    ll sum(int x){
        ll ret = 0;
        while (x) {
            ret += bit[x];
            x &= (x - 1);
        }
        return (ret);
    }
};
ll solve(){
    ll res = 0;
    ll N; cin >> N;
    vector<ll> a(N); for(auto& in:a) cin >> in;
    
    vector<ll> ta = a;
    sort(ta.begin(),ta.end());
    ll l = 0,r = N;
    
    ll M = N*(N+1)/2;
    ll HM = (M+1)/2;
    while(r-l>1){
        ll m = (r+l)/2;
        ll ma = ta[m];
        vector<ll> cusum(N+1);
        for(int i = 0; i < N;i++){
            cusum[i+1] = cusum[i];
            if(a[i]>=ma) cusum[i+1]++;
            else cusum[i+1]--;
        }

        ll sum = 0;
        BIT bit(2*N);
        
        for(int i = 0; i <= N;i++){
            sum += bit.sum(cusum[i]+N);
            bit.add(cusum[i]+N,1);
        }
        if(sum >= HM){
            l = m;
        }else{
            r = m;
        }
    }
    res = ta[l];
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
