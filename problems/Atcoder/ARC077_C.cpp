#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://arc077.contest.atcoder.jp/tasks/arc077_a>
問題文============================================================
 長さ n の数列 a1,…,an が与えられます。 空の数列 b に対して、以下の操作を n 回行うことを考えます。
 
 i 回目には
 
 数列の i 番目の要素 ai を b の末尾に追加する。
 b を逆向きに並び替える。
 この操作をしてできる数列 b を求めて下さい。
=================================================================

解説=============================================================
dequeを用いたシミュレーションでO(n)
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll n; cin >> n;
    deque<ll> deq;
    for(int i = 0; i < n;i++){
        ll a; cin >> a;
        if(i%2 == 0){
            deq.push_back(a);
        }else{
            deq.push_front(a);
        }
    }
    if(n%2 == 0){
        for(auto it = deq.begin(); it!=deq.end();it++){
            cout << *it << " ";
        }
        cout << endl;
    }else{
        for(auto it = deq.rbegin(); it!=deq.rend();it++){
            cout << *it << " ";
        }
        cout << endl;
    }
	return 0;
}
