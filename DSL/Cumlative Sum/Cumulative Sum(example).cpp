#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define INF 1<<30
#define LINF 1LL<<60

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_A&lang=jp
int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    ll N,T; cin >> N >> T;
    vector<ll> CumSum(T+1,0);
    for(int i = 0; i < N;i++){
        ll l,r; cin >> l >> r;
        CumSum[l]++;
        CumSum[r]--;
    }
    ll ans = CumSum[0];
    //cout << CumSum[0] << " ";
    for(int i = 1; i <= T;i++){
        CumSum[i] += CumSum[i-1];
        //cout << CumSum[i] << " ";
        ans = max(ans,CumSum[i]);
    }
    //cout << endl;
    cout << ans << endl;
    return 0;
}