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
<url:https://arc092.contest.atcoder.jp/tasks/arc092_b>
問題文============================================================
 2 つの長さ N の非負整数列 a1,…,aN,b1,…,bN が与えられます。
 
 1≤i,j≤N となるように整数 i,j を選ぶ方法は N2 通りありますが，
 この N^2 通りの i,j それぞれについて，ai+bj を計算し，紙に書き出します。
 つまり，紙に N^2 個の整数を書きます。
 
 この N^2 個の整数のxorを計算してください。
=================================================================

解説=============================================================

 解説を見た
 
 各桁について順番に1が ai + bj のうち aiを固定した時にいくつあるかを確認すれば良い
 
 k-bit目を見る時,T = 2^k とすれば
 [0,T) => 0
 [T,2T) => 1
 [2T,3T) => 0
 [3T,4T) => 1
 と2T周期になるので
 ai %= 2T , bj %= 2T として
 
 T <= ai + bj < 2T / 3T <= ai + bj < 4T
 となるものの個数が 1となるものの個数である
 これは ai,bj をソートしておけば aiを固定してにぶたんで求めることができる
 
================================================================
*/
ll solve(){
    ll res = 0;
    ll N; cin >> N;
    vector<ll> a(N),b(N),A(N),B(N);
    for(auto &in:a) cin >> in; for(auto &in:b) cin >> in;
    for(int k = 28; k >= 0; k--){
        ll T = (1<<k);
        for(int i = 0; i < N;i++){ A[i] = a[i]%(2*T); B[i] = b[i]%(2*T); }
        sort(A.begin(),A.end()); sort(B.begin(),B.end());
        ll cnt = 0,cnt2 = 0; // cnt : 0 cnt2 : 1
        for(int i = 0; i < N;i++){
            
            // [0,T) : 0
            if(A[i] < T) cnt += (lower_bound(B.begin(), B.end(),T-A[i]) - B.begin());
            
            // [2T,3T) : 0
            cnt += (lower_bound(B.begin(),B.end(),3*T-A[i]) - lower_bound(B.begin(),B.end(),2*T-A[i]));
        }
        cnt2 = N*N - cnt;
        cnt2 %= 2;
        res += (cnt2)*T;
    }
    return res;
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    cout << solve() << endl;
	return 0;
}
