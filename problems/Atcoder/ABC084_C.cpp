#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://abc084.contest.atcoder.jp/tasks/abc084_c>
問題文============================================================
 Atcoder国に、 1 本の東西方向に走る鉄道が完成しました。
 
 この鉄道には N 個の駅があり、西から順に 1,2,…,N の番号がついています。
 
 明日、鉄道の開通式が開かれます。
 
 この鉄道では、1≦i≦N−1 を満たす全ての整数 i に対して、駅 i から駅 i+1 に、
 Ci 秒で向かう列車が運行されます。ただし、これら以外の列車は運行されません。
 
 駅 i から駅 i+1 に移動する列車のうち最初の列車は、
 開通式開始 Si 秒後に駅 i を発車し、その後は Fi 秒おきに駅 i を発車する列車があります。
 
 また、Si は Fi で割り切れることが保証されます。
 
 つまり、A％B で A を B で割った余りを表すとき、
 Si≦t,t％Fi=0 を満たす全ての t に対してのみ、開通式開始 t 秒後に駅 i を出発し、
 開通式開始 t+Ci 秒後に駅 i+1 に到着する列車があります。
 
 列車の乗り降りにかかる時間を考えないとき、全ての駅 i に対して、
 開通式開始時に駅 i にいる場合、駅 N に到着できるのは最も早くて開通式開始何秒後か、答えてください。
=================================================================

解説=============================================================

 各駅から順番にN駅に到達するまでの時間をシミュレーションすれば良い
 
================================================================
*/
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<int> C(N,0),S(N,0),F(N,0);
    for(int i = 0; i < N-1;i++) cin >> C[i] >> S[i] >> F[i];
    for(int s = 0; s < N;s++){
        int ans = S[s] + C[s];
        for(int i = s+1; i < N-1;i++){
            if(ans <= S[i]){
                ans = S[i] + C[i];
            }else{
                ans = (ans - S[i] + F[i]-1)/F[i] * F[i] + S[i] + C[i];
            }
        }
        cout << ans << endl;
    }
	return 0;
}