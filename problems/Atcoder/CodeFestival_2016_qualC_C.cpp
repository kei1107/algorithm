#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://code-festival-2016-qualc.contest.atcoder.jp/tasks/codefestival_2016_qualC_c>
問題文============================================================
 アルピニストである高橋君と青木君は最近ある有名な山脈を踏破しました。
 この山脈はN 個の山からなっており、西から東に向けて山1,山2,…,山Nと一直線に並んでいます。
 高橋君は西から、青木君は東からこの山脈を踏破しました。
 
 山i の高さはhi ですが、二人とも各hi の値は忘れてしまいました。
 その代わり、各i(1≦i≦N) に対して、山i の山頂にたどり着いた時の、
 それまでに登った山(山i も含む)の高さの最大値を記録しています。
 高橋君の記録した値はTi で、青木君の記録した値はAi です。
 
 各山の高さhi が正の整数であることはわかっています。
 山の高さの列としてありうるものが何通りあるかを10^9+7 で割ったあまりを求めてください。
 
 ただし記録が間違っていてありうる山の高さの列が存在しないこともあります。
 この場合は0を出力してください。
 
 
=================================================================

解説=============================================================

 高橋くんと青木くんの情報からそれぞれで、
 その山 i がなりうる最大の値と最小の値を調べる（これは単純に、値が一つ手前の山よりも大きくなれば、その山は必ずその値であり、それ以外では最小 = 1, 最大 = 値　でできる）
 
 次に、それぞれの情報から
     その山 i がなりうる真の最大の値と最小の値を調べる。
 
 真の最小  = max(高橋くんが確認した最小、青木くんが確認した最小)
 真の最大　= min(               最大,               最大)
 
 これでその山 i がなりうる値がわかったので、あとは全ての山に関していくつの場合があるかを確認して行けば良い
 
 また、この時、真の最小が真の最大を上回ったりするようなことがあれば、互いの情報が矛盾しているということにもなる
 
================================================================
*/
const ll MOD = 1e9 + 7 ;
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N; cin >> N;
    vector<ll> T(N),A(N);
    for(auto &in:T) cin >> in;
    for(auto &in:A) cin >> in;
    
    vector<pll> l(N),r(N);
    ll maxh = -1;
    for(int i = 0; i < N;i++){
        if(maxh < T[i]){
            l[i] = {T[i],T[i]};
            maxh = T[i];
        }else{
            l[i] = {1,maxh};
        }
    }
    maxh = -1;
    for(ll i = N - 1; i >= 0; i--){
        if(maxh < A[i]){
            r[i] = {A[i],A[i]};
            maxh = A[i];
        }else{
            r[i] = {1,maxh};
        }
    }
    
    ll res = 1;
    for(int i = 0; i < N;i++){
    //    cout << l[i].first << " " << l[i].second << " " << r[i].first << " " << r[i].second << endl;
        res *= min(r[i].second,l[i].second) - max(r[i].first,l[i].first) + 1;
        if(res <= 0) {
            res = 0; break;
        }
        res %= MOD;
    }
    cout << res << endl;
	return 0;
}
