#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://arc080.contest.atcoder.jp/tasks/arc080_a>
問題文============================================================
 長さ N の数列 a=(a1,a2,…,aN) があります。 各 ai は正の整数です。
 
 すぬけ君の目標は、a の要素を自由に並べ替え、次の条件が成り立つようにすることです。
 
 各 1≤i≤N−1 について、ai と ai+1 の積は 4 の倍数である。
 すぬけ君が目標を達成できるか判定してください。

=================================================================

解説=============================================================

 まず、4の倍数の数値(4の倍数を v 、４の倍数でない値を x とする）が存在する時
 
 x v x v x v x v ... とおいていけば条件を満たす
 つまり、4の倍数である値の個数を V とすると 2*V 分カバーできる
 
 注意：
     x v x v x v ... x v x
 で数列が終了する時 2*V + 1 ＝＝　N をカバーできる
 
 2*c で　数列全てをカバーできない時, ２の倍数をb とすると
 
 x v x v x v x v ... x v b b b b b b .... b
 
 とおいていけば条件を満たす
 
 よって上の注意ケースを除いて,２の倍数の個数とBとすると
 
 2*V + B >= N
 
 となっていれば条件を満たす

================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N; cin >> N;
    vector<ll> a(N);
    for(auto & in:a) cin >> in;
    ll four = 0, two = 0;
    for(int i = 0; i < N;i++){
        if(a[i]%4 == 0) four++;
        if(a[i]%2 == 0) two++;
    }
    two -= four;
    if(four*2 + 1 >= N){
        cout << "Yes" << endl;
        return 0;
    }
    if(four*2 + two >= N){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
	return 0;
}
