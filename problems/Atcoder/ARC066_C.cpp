#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://arc066.contest.atcoder.jp/tasks/arc066_a?lang=en>
問題文============================================================
 1~N までの番号がついた、N 人の人がいます。
 彼らは昨日、ある順番で左右一列に並んでいましたが、今日になってその並び方が分からなくなってしまいました。
 しかし、彼らは全員、「自分の左に並んでいた人数と自分の右に並んでいた人数の差の絶対値」を覚えています。
 彼らの報告によると、人 i の、「自分の左に並んでいた人数と自分の右に並んでいた人数の差の絶対値」は Ai です。
 
 彼らの報告を元に、元の並び方が何通りあり得るかを求めてください。
 ただし、答えは非常に大きくなることがあるので、10^9+7 で割った余りを出力してください。
 また、彼らの報告が間違っており、ありうる並び方がないこともありえます。 その際は 0 を出力してください。
=================================================================

解説=============================================================

 考察を進めると
 a[i] := 数列中に存在する個数
 if N is even then
     a[i] == 2 (i is odd) / a[i] == 0 (i is even)
 else then
     a[0] == 1 / a[i] == 2 (i is even) / a[i] == 0 (i is odd)
 
 と確定できる。
 よって、数列が矛盾していないか確かめながら、計算をすれば良い
 
================================================================
*/
const ll MOD = 1e9+7;
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N; cin >> N;
    vector<ll> A(N);
    vector<int> cnt(N,0);
    for(auto& in:A){
        cin >> in;
        cnt[in]++;
    }
    ll ans = 1;
    if(N%2 == 0){
        if(cnt[0]){
            cout << 0 << endl;
            return 0;
        }else{
            for(int i = 1; i < N;i++){
                if(i%2 == 0){
                    if(cnt[i]){
                        cout << 0 << endl;
                        return 0;
                    }
                }else{
                    if(cnt[i] == 2){
                        (ans *= 2)%=MOD;
                    }else{
                        cout << 0 << endl;
                        return 0;
                    }
                }
            }
        }
    }else{
        if(cnt[0] != 1){
            cout << 0 << endl;
            return 0;
        }
        for(int i = 1; i < N;i++){
            if(i%2 == 0){
                if(cnt[i] == 2){
                    (ans *= 2)%=MOD;
                }else{
                    cout << 0 << endl;
                    return 0;
                }
            }else{
                if(cnt[i]){
                    cout << 0 << endl;
                    return 0;
                }
            }
        }
    }
    cout << ans << endl;
	return 0;
}
