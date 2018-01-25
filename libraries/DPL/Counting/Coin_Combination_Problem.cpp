#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
 http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_4_A&lang=jp
 
 コインの組み合わせ
 ４つの袋Ａ, Ｂ, Ｃ, Ｄにそれぞれ N 枚, 合計 4N 枚のコインが入っています。それぞれの袋に入っているコインの値段はai, bi, ci, di 円です。D 君は, 各袋から１枚, 合計4 枚のコインを得たいと思っていて, 値段の合計はちょうどV 円にしたいと思っています。このようなコインの選び方は何通りあるでしょうか? ただし, それぞれのコインは区別するものとします。
 
 Constraints
 1 ≤ N ≤ 1000
 1 ≤ ai, bi, ci, di ≤ 10^16
 1 ≤ V ≤ 10^16
 入力はすべて整数で与えられる
 Output
 選び方の総数を 1 行に出力しなさい。
 */
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll N,V;cin >> N >> V;
    vector<ll> a(N),b(N),c(N),d(N);
    for(int i = 0; i < N;i++) cin >> a[i];
    for(int i = 0; i < N;i++) cin >> b[i];
    for(int i = 0; i < N;i++) cin >> c[i];
    for(int i = 0; i < N;i++) cin >> d[i];

    /*
     a + b + c + d = V : O(N^4)
     => a + b = V - c - d : O(N^2) + O(N^2)
     */
    map<ll,ll> m;
    for(int i = 0; i < N;i++){
        for(int j = 0; j < N;j++){
            m[a[i]+b[j]]++;
        }
    }
    
    ll ans = 0;
    for(int i = 0; i < N;i++){
        for(int j = 0; j < N;j++){
            ans += m[V - c[i] - d[j]];
        }
    }
    cout << ans << endl;
    return 0;
}
