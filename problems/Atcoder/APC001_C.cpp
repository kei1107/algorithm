#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://apc001.contest.atcoder.jp/tasks/apc001_c>
問題文============================================================
 N を 3 以上の奇数とします。
 
 N 個の席が円状に並んでいます。 席には 0 から N−1 まで番号が振られています。
 各 i (0≤i≤N−2) について、席 i と席 i+1 は隣り合っています。 また、席 N−1 と席 0 は隣り合っています。
 
 各席の状態は「空席」「男性が座っている」「女性が座っている」のどれかです。
 ただし、同性どうしが隣り合う席に座っていることはありません。
 N が 3 以上の奇数の場合、空席が少なくとも 1 つは存在することが示せます。
 
 あなたには N のみが与えられ、各席の状態は与えられません。
 あなたの目標は、どれか 1 つの空席の番号を当てることです。
 そのために、あなたは次のクエリを繰り返し送ることができます。
 
 整数 i (0≤i≤N−1) を選ぶ。 席 i が空席ならば、正答となる。
 そうでなければ、席 i に座っている人の性別が知らされる。
 クエリを高々 20 回まで送ることで、どれか 1 つの空席の番号を当ててください。
 
 N は奇数である。
 3≤N≤99,999
=================================================================

解説=============================================================

 r - l is even then l,r が異性 => Vを含む
 r - l is odd then l,r が同性 => Vを含む
 
 の条件でにぶたん
================================================================
*/

bool c(ll m){
    cout << m << endl;
    string s; cin >> s;
    if(s == "Vacant") exit(0);
    else if(s == "Female") return 0;
    else return 1;
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N; cin >> N;
    ll l = 0, r = N - 1;
    bool ff = c(l);
    while(r - l > 1){
        ll m = (r + l)/2;
        bool f = c(m);
        if(((m&1)^ff)!=f) r = m-1;
        else l = m+1;
    }
    
    c(l); c(l+1); c(r);
	return 0;
}
