#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://arc072.contest.atcoder.jp/tasks/arc072_a>
問題文============================================================
 長さ N の数列があり、i 番目の数は ai です。
 あなたは 1 回の操作でどれか 1 つの項の値を 1 だけ増やすか減らすことができます。
 
 以下の条件を満たすために必要な操作回数の最小値を求めてください。
 
 すべてのi(1≦i≦n) に対し、第 1 項から第 i 項までの和は 0 でない
 すべてのi(1≦i≦n−1) に対し、i 項までの和と i+1 項までの和の符号が異なる
=================================================================

解説=============================================================
 
 まず、初期条件として、第一項が正か負かの場合で分けて考える。
 第二項以降に関しては、その項を加算した時、正負が逆転するかどうか、
 しなければ+1(or -1)になるように調整して、計算していけば良い
 
================================================================
*/

ll calc(ll n,vector<ll>&a,ll s,ll sum){
    ll ret = s;
    
    ll S = sum;
    for(int i = 1; i < n;i++){
        if(S > 0){
            if(S + a[i] < 0){
                S += a[i];
            }else{
                ret += abs(S+a[i]) + 1;
                S = -1;
            }
        }else{
            if(S + a[i] > 0){
                S += a[i];
            }else{
                ret += abs(S+a[i]) + 1;
                S = 1;
            }
        }
    }
    return ret;
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll n; cin >> n;
    vector<ll> a(n);
    for(auto& in:a) cin >> in;
    cout << min(
                calc(n,a,a[0]>0?0:abs(a[0])+1,a[0]>0?a[0]:1),
                calc(n,a,a[0]<0?0:abs(a[0])+1,a[0]<0?a[0]:-1)
    ) << endl;
	return 0;
}
