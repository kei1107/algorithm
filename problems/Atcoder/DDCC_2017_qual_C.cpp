#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://ddcc2017-qual.contest.atcoder.jp/tasks/ddcc2017_qual_c>
問題文============================================================
 N 本の棒があり、 i(1≦i≦N) 本目の棒の長さは Li です。
 
 これらを長さ C のケースに収納していきます。
 
 ケースには 1 本か 2 本の棒を収納できますが、棒を収納できる条件は
 
 1 本の棒を収納するには、棒の長さが a のとき、 a≦C
 2 本の棒を収納するには、棒の長さが a,b のとき、 a+b+1≦C
 です。
 
 全ての棒を収納するのに、ケースは最小でいくつ必要か答えてください。
 

=================================================================

解説=============================================================
最適な棒の選び方は
 今選べる棒のうち最も長い棒と短い棒が一緒のケースに入れれるのであれば、入れる
 そうでなければ長い方の棒だけをケースに入れる
 である
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    int N,C; cin >> N >> C;
    vector<int> L(N);
    for(auto &in:L) cin >> in;
    sort(L.begin(),L.end());
    int l = 0, r = N - 1;
    int cnt = 0;
    while(l <= r){
        if(L[l] + L[r] + 1 <= C){
            cnt++;
            l++; r--;
            continue;
        }
        r--;
        cnt++;
    }
    cout << cnt << endl;
	return 0;
}
