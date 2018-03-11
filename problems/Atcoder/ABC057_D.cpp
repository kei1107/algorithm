#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://abc057.contest.atcoder.jp/tasks/abc057_d>
問題文============================================================
 N 個の品物が与えられます。
 i 番目の品物の価値は vi(1≦i≦N) です。
 これらの品物から、A 個以上、B 個以下を選ばなければなりません。
 この制約下において、選んだ品物の価値の平均の最大値を求めてください。
 また、選んだ品物の平均が最大となるような品物の選び方が何通りあるかを求めてください。
=================================================================

解説=============================================================

 平均が最大になるには、価値の高いものから順に選んでいけばよい
 よって、平均の最大は価値の高いものから順にA個選んだ時の平均値である。
 
 選び方に関しては、重複に気をつけて計算を行う
 
================================================================
*/

ll C(int n,int m){
    m = m<(n-m) ? m : (n-m);
    if(m == 0) return 1;
    ll ans = 1;
    for(int i=1;i<=m;i++){
        ans = ans *(n-i+1)/i;
    }
    return ans;
}

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    int N,A,B; cin >> N >> A >> B;
    vector<ll> v(N);
    for(auto &in:v) cin >> in;
    map<ll,int> mp;
    for(int i = 0; i < N;i++) mp[v[i]]++;
    
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    reverse(v.begin(),v.end());
    
    double S = 0;
    ll ans = 1;
    if(mp[v[0]] >= A){
        S = v[0];
        ans = 0;
        for(int i = A; i <= min(mp[v[0]],B);i++){
            ans += C(mp[v[0]],i);
        }
    }else{
        int tA = A;
        for(int i = 0; i < v.size();i++){
            int cnt = mp[v[i]];
            if(cnt < tA){
                ans *= cnt;
                tA -= cnt;
                S += v[i]*cnt;
            }else{
                ans *= C(cnt,tA);
                S += v[i] * tA;
                break;
            }
        }
        S /= A;
    }
    cout << fixed << setprecision(10) << S << endl;
    cout << ans << endl;
	return 0;
}
