#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0360>
問題文============================================================
 ＰＣＫ研究所が運用するスーパーコンピュータ「エル」は、研究所外部の企業や大学などの依頼に応じて様々な計算を行っています。
 エルの使用には予約が必要で、予約の際は開始時刻と終了時刻を指定します。ただし、異なる予約が重複してはいけません。
 
 新しい予約が、すでに存在する予約のどれかと重複するかを報告するプログラムを作成せよ。
 ただし、ある予約の終了時刻と、別の予約の開始時刻が同じ場合は重複しないと考えて良い。
 また、すべての時刻は、エルの運用開始からの経過分数で与えられる。
 
=================================================================

解説=============================================================
imosではい
================================================================
*/
ll imos[1010];
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll a,b; cin >> a >> b;
    ll N; cin >> N;
    for(int i = 0; i < N;i++){
        ll s,f; cin >> s >> f;
        imos[s]++; imos[f]--;
    }
    for(int i = 1; i < 1010;i++) imos[i] += imos[i-1];
    for(int i = a; i < b;i++){
        if(imos[i] == 1){
            cout << 1 << endl;
            return 0;
        }
    }
    cout << 0 << endl;
	return 0;
}
