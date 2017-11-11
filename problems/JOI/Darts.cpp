#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
 <url:https://www.ioi-jp.org/joi/2007/2008-ho-prob_and_sol/2008-ho.pdf>
 問題文============================================================
 
 得ることの出来る特点の配列が与えられる。
 その配列から最大4回まで点数を得ることができるが、その点数の合計はM(1<=M<=2*10^8)
 以下でなければならない。もしMを超えた場合は得た特点が0となる
 
 得ることの出来る特点の最大値を求める
 
 =================================================================
 解説=============================================================
 
 半分全列挙
     ダーツを先に投げる二本と後に投げる二本に分ける
     前半部でできる特点の和を保持しておき、
     後半部でできた和と前半部の和がMを超えない範囲での値をにぶたん
 
 ================================================================
 */

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll N,M; cin >> N >> M;
    vector<ll> P(N+1,0);
    for(int i = 1; i <= N;i++) cin >> P[i];
    
    vector<ll> V;
    for(int i = 0; i <= N;i++){
        for(int j = 0; j <= N;j++){
            V.push_back(P[i] + P[j]);
        }
    }
    sort(V.begin(),V.end());
    V.erase(unique(V.begin(),V.end()),V.end());
    
    ll res = 0;
    for(int i = 0; i <= N;i++){
        for(int j = 0; j <= N;j++){
            ll sum = P[i] + P[j];
            if(M - sum < 0)continue;
            auto it = upper_bound(V.begin(), V.end(), M - sum);
            res = max(res,sum + V[it - V.begin() - 1]);
        }
    }
    cout << res << endl;
    return 0;
}
