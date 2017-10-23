#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
 http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_4_B&lang=jp
 
 コインの組み合わせ II
 N 枚のコインがあります。それぞれのコインの値段はai 円です。E 君は, ちょうどK 個のコインを得たいと思っていて, 値段の合計はL 円以上 R 円以下にしたいと思っています。このようなコインの選び方は何通りあるでしょうか? ただし, それぞれのコインは区別するものとします。
 
 Constraints
 1 ≤ K ≤ N ≤ 40
 1 ≤ ai ≤ 1016
 1 ≤ L ≤ R ≤ 1016
 入力はすべて整数で与えられる
 
 Output
 選び方の総数を 1 行に出力しなさい。
 */
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll N,K,L,R; cin >> N >> K >> L >> R;
    vector<ll> a(N);
    for(int i = 0; i < N;i++) cin >> a[i];
    
    
    /*
     bitを用いて最大N/2個用いた場合の全通りを保持
     その後残りのN - N/2個に対して L - X <= (Y) <= R - X　となるか試す
     O(N^20) + O(N^20*logM)
     */
    vector<vector<ll>> half_Sum(N/2 + 1);
    ll n1 = N/2;
    for(int i = 0; i < (1<<n1);i++){
        ll Sum = 0;
        ll cnt = 0;
        for(int j = 0; j < n1;j++){
            if((i >> j)&1){
                cnt++;
                Sum += a[j];
            }
        }
        half_Sum[cnt].emplace_back(Sum);
    }
    for(int i = 0; i < n1;i++) sort(half_Sum[i].begin(),half_Sum[i].end());
    ll ans = 0;
    ll n2 = N - n1;
    for(int i = 0; i < (1<<n2);i++){
        ll Sum = 0;
        ll cnt = 0;
        for(int j = 0; j < n2;j++){
            if((i>>j)&1){
                cnt++;
                Sum += a[n1 + j];
            }
        }
        
        if(!(K - cnt >= 0)|| n1 + cnt < K)continue;
        
        ll it1 = upper_bound(half_Sum[K - cnt].begin(), half_Sum[K-cnt].end(), R-Sum) - half_Sum[K-cnt].begin();
        ll it2 = lower_bound(half_Sum[K-cnt].begin(), half_Sum[K-cnt].end(), L-Sum) - half_Sum [K-cnt].begin();
        
        if(it1 - it2 <= 0) continue;
        ans += it1 - it2;
    }
    cout << ans << endl;
    return 0;
}

