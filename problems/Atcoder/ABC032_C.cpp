#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e16;

/*
 <url:https://beta.atcoder.jp/contests/abc032/tasks/abc032_c>
 問題文============================================================
 
 （略)
 
 =================================================================
 
 解説=============================================================
 
 Aと同じように区間(l,r)を持ってスライドさせながら見ていけば良い
 コーナーケースとして、区間sの中に0が含まれる場合はその積が常に0となるので、
 その部分だけ例外処理をしていく
 
 ＊しゃくとり法
 
 ================================================================
 */
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll N,K; cin >> N >> K;
    vector<ll> s(N);
    for(auto &in: s) cin >> in;
    
    for(auto v:s){
        if(v == 0){
            cout << N << endl;
            return 0;
        }
    }
    if(K == 0){
        cout << 0 << endl;
        return 0;
    }
    ll ans = 0;
    ll l = 0, r= 0;
    ll sum = 1;
    while(true){
        while(sum <= K){
            ans = max(ans,r - l);
            if(r == N) break;
            if(s[r] != 0){
                sum *= s[r];
                r++;
            }else{
                r++;
                l = r;
                sum = 1;
            }
        }
        if(sum < K) break;
        if(r == N) break;
        sum /= s[l];
        l++;
    }
    cout << ans << endl;
    return 0;
}
