#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:https://www.ioi-jp.org/joi/2008/2009-yo-prob_and_sol/2009-yo-t3/2009-yo-t3.html>
問題文============================================================
次のようなゲームがある．

あるキャラクターが縦 1 列に N 個並んでいる． 
これらのキャラクターの色は赤，青，黄のいずれかであり， 
初期状態で同じ色のキャラクターが4つ以上連続して並んでいることはない．
プレーヤーは，ある位置のキャラクターを選び他の色に変更することができる． 
この操作により同じ色のキャラクターが4つ以上連続して並ぶとそれらのキャラクターは消滅する．
キャラクターが消滅することにより新たに同じ色のキャラクターが4つ以上連続して並ぶと
それらのキャラクターも消滅し，同じ色のキャラクターが4つ以上連続して並んでいる箇所が
なくなるまでこの連鎖は続く．
このゲームの目的は， 消滅しないで残っているキャラクター数をなるべく少なくすることである．
=================================================================
解説=============================================================
i番目のキャラクターの色がXとすると、i番目のキャラクターをX以外の色に変化させたとき、
どこまで消滅させることができるのかを実際にシュミレーションすればよい
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	ll N;
    while(cin >> N,N){
	vector<ll> C(N);
	for (int i = 0; i < N;i++) cin >> C[i];
	ll res = INF;
	for (int i = 0; i < N;i++) {
		ll l = i - 1, r = i + 1;
		for (int j = 1; j <= 3;j++) {
			if (j == C[i])continue;
			ll cnt = 1;
			ll nC = j;
			ll pre_l = i, pre_r = i;
			while (true) {
				if (r < N) {
					if (C[r] == nC) {
						cnt++; r++;
						continue;
					}
				}
				if (l >= 0) {
					if (C[l] == nC) {
						cnt++; l--;
						continue;
					}
				}
				if (cnt < 4)break;
				pre_l = l; pre_r = r;
				if (l < 0 || r >= N)break;
				if (C[l] != C[r])break;
				cnt = 2;
				nC = C[l];
				l--; r++;
			}
			ll temp = max(pre_l + 1, 0LL) + max(0LL, N - pre_r);
			if (pre_l == pre_r) temp--;
			res = min(res, temp);
		}
	}
	cout << res << endl;
    }
	return 0;
}
