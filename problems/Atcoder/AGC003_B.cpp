#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://agc003.contest.atcoder.jp/tasks/agc003_b>
問題文============================================================
 高橋君は 1 から N までの整数のうちのどれかが書かれたカードをたくさん持っています。
 高橋君は整数 i が書かれたカードを Ai 枚持っています。
 
 2 枚のカードについて、それらに書かれた整数の差の絶対値が 1 以下のとき、これらをペアにすることができます。
 
 高橋君は、同じカードが複数のペアに使われないように、できるだけ多くのペアを作りたいです。
 高橋君が作れるペアの個数の最大値を求めてください。
 
=================================================================

解説=============================================================
 
 まず、ある整数i自身でペアを作ることができるのであれば作った方がいい。
 そして、残るようであれば i-1 または i+1で作ればいいが、
 これは、左(右）から順に流していくと
 
 左からなら i-1までのペアは作りきっているので、 i+1だけを見ればよく
 右からなら i+1までのペアは作りきっているので、 i-1だけを見ればいい
 
 よって、これをシミュレーションすればok
 (おそらく片方からのみで十分だが、念のため左右から行っている)
 
 
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N; cin >> N;
    vector<ll> A(N);
    for(auto&in:A) cin >> in;
    vector<ll> tA(A);
    
    ll cntl = 0;
    for(int i = 0; i < N - 1;i++){
        cntl += A[i]/2;
        A[i] -= A[i]/2 * 2;
        ll minv = min(A[i],A[i+1]);
        cntl += minv;
        A[i] -= minv; A[i+1] -= minv;
    }
    cntl += A[N-1]/2;
    
    A = tA;
    
    ll cntr = 0;
    for(int i = N - 1; i > 0; i--){
        cntr += A[i]/2;
        A[i] -= A[i]/2 * 2;
        ll minv = min(A[i],A[i-1]);
        cntr += minv;
        A[i] -= minv; A[i-1] -= minv;
    }
    cntr += A[0]/2;
    cout << max(cntl,cntr) << endl;
	return 0;
}
