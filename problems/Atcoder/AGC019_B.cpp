#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://agc019.contest.atcoder.jp/tasks/agc019_b>
問題文============================================================
 英小文字からなる文字列 A=A1A2…An があります。
 
 あなたは 1≤i≤j≤n であるような任意の二つの添字 i,j を選び、
 A のうち部分文字列 AiAi+1…Aj を反転することができます。
 
 この操作は一回まで行うことができます。
 
 これによって得られる文字列は何通りあるでしょうか？
=================================================================

解説=============================================================
 abcda と abcba という文字列があるとする

 [1,5]を反転させると adcba , abcba
 [2,4]を反転させると adcba , abcba
 
 となる。　このことから ある文字(l)を基準とした時,それよりも右側の同一文字(r)を示して反転させることは
 [l-1,r-1] を反転させることに等しい
 よって、ある文字を見た時、それよりも右側にある別の文字と交換して行くことによって重複の文字を防ぐことができる。
 また、両端が別の文字で反転を行っているので回文となる心配がない
 
 よって、右側にいくつ、どのような文字が存在するのかというテーブルを作っておき、順に見ていけば良い
 O(N)
================================================================
*/
ll solve(){
    ll ret = 1;
    string S; cin >> S;
    int alpha[26] = {};
    for(int i = (int)S.length()-1; i >= 0;i--){
        for(int j = 0; j < 26;j++){
            if(j == S[i]-'a')continue;
            ret += alpha[j];
        }
        alpha[S[i]-'a']++;
    }
    return ret;
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    cout << solve() << endl;
	return 0;
}
