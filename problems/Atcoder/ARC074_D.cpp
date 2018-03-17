#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://arc074.contest.atcoder.jp/tasks/arc074_b>
問題文============================================================
 N を 1 以上の整数とします。
 
 長さ 3N の数列 a=(a1,a2,…,a3N) があります。
 すぬけ君は、a からちょうど N 個の要素を取り除き、残った 2N 個の要素を元の順序で並べ、
 長さ 2N の数列 a' を作ろうとしています。
 このとき、a' のスコアを (a'の前半N要素の総和)−(a'の後半N要素の総和) と定義します。
 
 a' のスコアの最大値を求めてください。
=================================================================

解説=============================================================

 この問題は [1...3N]を [1...x],[x+1...3N] の二つの区間に分けた時
 
 [1...x]の中に含まれる上からN個の大きい値の総和 - [x+1...3N]の中に含まれる上からN個の小さい値の総和
 
 が最も大きくなる時の値を求めよ
 
 と言い換えることができる
 
 よって、[1...x]の上からN個の大きい値総和、および[x+1...3N]の上からN個の小さい値の総和は
 priority_queue を用いることによって効率的に求めることができるので、
 xについてその総和を保存したテーブルを作っておくことによって
 [N...2N]の全てを確認して O(3N)で解ける
 
================================================================
*/
ll solve(){
    ll N; cin >> N;
    vector<ll> a(3*N);
    for(auto &in:a) cin >> in;
    ll ret = -LINF;
    
    vector<ll> Front(3*N,0);
    priority_queue<ll,vector<ll>,greater<ll>> pq1;
    for(int i = 0; i < N;i++){
        if(i == 0){
            Front[i] = a[i]; pq1.push(a[i]);
        }else{
            Front[i] = Front[i-1] + a[i];
            pq1.push(a[i]);
        }
    }
    for(ll i = N; i < 2*N;i++){
        Front[i] = Front[i-1] + a[i];
        pq1.push(a[i]);
        Front[i] -= pq1.top(); pq1.pop();
    }
    
    vector<ll> Back(3*N,0);
    priority_queue<ll> pq2;
    for(ll i = 3*N-1; i >= 2*N;i--){
        if(i == 3*N-1){
            Back[i] = a[i]; pq2.push(a[i]);
        }else{
            Back[i] = Back[i+1] + a[i];
            pq2.push(a[i]);
        }
    }
    for(ll i = 2*N-1; i >= N;i--){
        Back[i] = Back[i+1] + a[i];
        pq2.push(a[i]);
        Back[i] -= pq2.top(); pq2.pop();
    }
    
    for(ll i = N-1; i < 2*N;i++){
        ret = max(ret,Front[i] - Back[i+1]);
    }
    return ret;
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    cout << solve() << endl;
	return 0;
}
