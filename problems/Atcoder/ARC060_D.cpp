#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://arc060.contest.atcoder.jp/tasks/arc060_b>
問題文============================================================
 2 以上の整数 b および 1 以上の整数 n に対し、関数 f(b,n) を次のように定義します。
 
 n<b のとき f(b,n)=n
 n≥b のとき f(b,n)=f(b, floor(n⁄b))+(n mod b)
 ここで、floor(n⁄b) は n⁄b を超えない最大の整数を、 n mod b は n を b で割った余りを表します。
 
 直感的に言えば、f(b,n) は、n を b 進表記したときの各桁の和となります。 例えば、
 
 f(10, 87654)=8+7+6+5+4=30
 f(100, 87654)=8+76+54=138
 などとなります。
 
 整数 n と s が与えられます。 f(b,n)=s を満たすような 2 以上の整数 b が存在するか判定してください。
 さらに、そのような b が存在するならば、その最小値を求めてください。
 

 1≤n≤10^11
 1≤s≤10^11
 n, s はいずれも整数である
=================================================================

解説=============================================================

 制約、式から色々と考えていると
 b > √n の時
     n = p*b + q
 と表すことができる
 ここで、
     s = p + q
 であるので
     b = (n-s)/p + 1
 と表すことができる。
 
 ここで、 b > √n より
     n = p*b + q >= p*b > p^2 => p < √n
 
 よって p を全探索すれば b は一意に定まるので O(√n)で全探索できる
 
 また b <= √n の時
 これは単純に全探索すれば良い
 
 最後に コーナーケースとして n = s の時だけ n + 1 を答える
 
================================================================
*/

ll f(ll b,ll n){
    if(n < b) return n;
    else return f(b,n/b) + n%b;
}
ll solve(){
    ll n,s; cin >> n >> s;
    if(n == s) return n + 1;
    ll res = LINF;
    for(ll b = 2; b*b <= n; b++){
        if(f(b,n) == s){
            return b;
        }
    }
    for(ll p = 1; p*p < n;p++){
        ll b = (n-s)/p + 1;
        if(b >= 2){
            if(s == f(b,n)) res = min(res,b);
        }
    }
    return res == LINF? -1 : res;
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    cout << solve() << endl;
	return 0;
}
