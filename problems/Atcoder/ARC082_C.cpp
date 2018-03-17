#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://arc082.contest.atcoder.jp/tasks/arc082_a>
問題文============================================================
 長さ N の整数列 a1,a2,…,aN が与えられます。
 
 各 1≤i≤N に対し、ai に 1 足すか、1 引くか、なにもしないかの三つの操作からどれか一つを選んで行います。
 
 この操作の後、ある整数 X を選んで、ai=X となる i の個数を数えます。
 
 うまく操作を行い、X を選ぶことで、この個数を最大化してください。
=================================================================

解説=============================================================

 ある値 a を見た時、可能性としてなりうる値は a-1 , a , a+1
 aの全範囲を網羅する配列に対して、この a-1,a,a+1が生じた分だけ加算していき
 
 最終的のその配列の要素の最大値が答え
 
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N; cin >> N;
    vector<ll> a(N);
    for(auto &in:a) cin >> in;
    const int MAX_V = 10e5;
    vector<ll> X(MAX_V+10,0);
    for(int i = 0; i < N;i++){
        if(a[i] != 0) X[a[i]-1]++;
        X[a[i]]++;
        X[a[i]+1]++;
    }
    cout << *max_element(X.begin(),X.end()) << endl;
	return 0;
}
