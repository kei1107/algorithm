#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
 <url:https://cf17-relay-open.contest.atcoder.jp/tasks/relay2_c>
 問題文============================================================
 あなたの家の庭には、東に果てしなく伸びる細長い花壇があります。
 あなたは、何も植えられていないこの花壇に N 種類の花を植えることにしました。
 便宜上、これらの花の種類を花 1, 2, …, N と呼びます。
 また、花壇の西端から p センチメートルの位置を位置 p と呼びます。
 
 花 i (1≤i≤N) は、位置 wi に一つ植え、そこから di センチメートルおきに一つずつ、
 東へと無数に植えていくことにします。
 すなわち、花 i は位置 wi, wi+di, wi+2di, … に植えられることになります。
 複数の花が同じ位置に植えられることもありえます。
 
 西から K 番目に植えられる花の位置を求めてください。
 なお、同じ位置に複数の花が植えられる場合、それらは個別に数えます。
 =================================================================
 解説=============================================================
 
 にぶたん
 
 ================================================================
 */

ll N,K;
vector<ll> w,d;
bool check(ll m){
    ll cnt = 0;
    for(int i = 0; i < N;i++){
        if(m < w[i]) continue;
        cnt += (m - w[i])/d[i] + 1;
        if(cnt > K) return false;
    }
    if(cnt == K) return false;
    return true;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> N >> K;
    w.resize(N); d.resize(N);
    for(int i = 0; i < N;i++) cin >> w[i] >> d[i];
    ll l = 0, r = LLONG_MAX;
    for(int kassa = 0; kassa < 100; kassa++){
        ll mid = l + (r-l)/2LL;
        if(check(mid)){
            l = mid;
        }else{
            r = mid;
        }
    }
    cout << r << endl;
    return 0;
}
