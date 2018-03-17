#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream &operator << (ostream& out,const pair<S,T>& o){
    out << "(" << o.first << "," << o.second << ")"; return out;
}

/*
<url:https://arc075.contest.atcoder.jp/tasks/arc075_c>
問題文============================================================
 長さ N の整数列 a= {a1,a2,…,aN} と、整数 K が与えられます。
 
 a の空でない連続する部分列 {al,al+1,…,ar} (1≤l≤r≤N) は N(N+1)⁄2 個存在します。
 これらのうち、算術平均が K 以上であるものは何個あるでしょうか？
 
 入力値はすべて整数である。
 1≤N≤2×10^5
 1≤K≤10^9
 1≤ai≤10^9
=================================================================

解説=============================================================

 そのままやると O(N^2) で、まぁ間に合わない。
 ここで、a の累積和を cusum とすると,
 目的は (cusum[r] - cusum[l])/(r-l) >= K となるものを探すことである
 この条件について,あらかじめ全てのaをKで減じておくと K => 0 となるため
 
 (cusum[r] - (cusum[l])/(r-l) >= 0
 
 cusum[r] - cusum[l] >= 0
 
 となり、目的は cusum[r] が cusum[l] (1 <= l < r) 以上であるという条件に置き換えることができる
 これは indexとともにソートされたcusumをBITなどで管理すれば O(NlogN)で解くことができる
================================================================
*/


struct BIT {
    int N;
    vector<ll> bit;
    BIT(int N):N(N) {
        /* BITは[1..N]で扱う */
        bit.resize(N + 1, 0);
    }
    
    void add(int x, int val)
    {
        while (x <= N) {
            bit[x] += val;
            x += x & -x;
        }
    }
    
    int sum(int x)
    {
        int ret = 0;
        while (x) {
            ret += bit[x];
            x &= (x - 1);
        }
        
        return (ret);
    }
};

ll solve(){
    ll res = 0;
    ll N,K; cin >> N >> K;
    vector<ll> a(N); for(auto &in:a){ cin >> in; in -= K; }
    vector<pll> cusum(N);
    for(int i = 0; i < N;i++){
        if(i == 0){
            cusum[i] = {a[i],i+1};
        }else{
            cusum[i] = {cusum[i-1].first + a[i],i+1};
        }
    }
    sort(cusum.begin(),cusum.end());
    reverse(cusum.begin(),cusum.end());
    BIT bit(N);
    for(int i = 0; i < N;i++){
        if(cusum[i].first >= 0){
            res += bit.sum(cusum[i].second);
            bit.add(cusum[i].second,1);
        }else{
            bit.add(cusum[i].second,1);
            res += bit.sum(cusum[i].second);
        }
    }
    return N*(N+1)/2 - res;
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    cout << solve() << endl;
	return 0;
}
