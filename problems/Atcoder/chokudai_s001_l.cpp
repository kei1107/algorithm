#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:https://chokudai_s001.contest.atcoder.jp/tasks/chokudai_S001_l>
問題文============================================================
数列 a の任意の 2 つの要素を N 回スワップした時、
昇順に並び替えられるなら YES、そうでないならNOと出力しなさい。
=================================================================

解説=============================================================
i番目の位置にiがあるか順に確認していき、なければ、i番目の位置にiとなるようにswap
 
最終的にソートされる
 
 ソート後 N - (swap回数) が偶数になっていれば ok
================================================================
*/

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N; cin >> N;
    vector<ll> Id1(N+1),Id2(N+1);
    for(int i = 1;i<=N;i++){
        int a; cin >> a;
        Id1[a] = i;
        Id2[i] = a;
    }
    int cnt = 0;
    for(int i = 1; i <= N;i++){
        if(Id1[i] == i) continue;
        cnt++;
        ll A = Id2[i], B = Id2[Id1[i]];
        ll Apos = i, Bpos = Id1[i];
        
        Id1[A] = Bpos; Id2[Apos] = B;
        Id1[B] = Apos; Id2[Bpos] = A;
    }

    if((N - cnt) % 2 == 0){
        cout << "YES"<<endl;
    }else{
        cout << "NO" << endl;
    }
	return 0;
}
