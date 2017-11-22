#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
 <url:https://arc074.contest.atcoder.jp/tasks/arc074_b?lang=en>
 問題文============================================================
 N を 1 以上の整数とします。
 長さ 3N の数列 a=(a1,a2,…,a3N) があります。
 すぬけ君は、a からちょうど N 個の要素を取り除き、残った 2N 個の要素を元の順序で並べ、
 長さ 2N の数列 a' を作ろうとしています。
 このとき、a' のスコアを (a'の前半N要素の総和)−(a'の後半N要素の総和) と定義します。
 
 a' のスコアの最大値を求めてください。
 =================================================================
 解説=============================================================
 
 k (N <= k <= 2N)において、前半側は各地点での総和の最大値、後半側は各地点での総和を最小値を
 求める。
 
 求めたあと、各kの場所に置いて、前半側 - 後半側　の値を確認して、その最大値が答え。
 
 priority_queueを用いると早い
 ================================================================
 */

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<ll> a(3*N+1);
    for(int i = 1; i <= 3*N;i++) cin >> a[i];
    priority_queue<ll,vector<ll>,greater<ll>> lpq;
    priority_queue<ll> rpq;
    
    vector<ll> suml(3*N+2,0),sumr(3*N+2,0);
    for(int i = 1; i <= N;i++){
        lpq.push(a[i]); suml[i] += suml[i-1] + a[i];
    }
    for(int i = 3*N; i > 2*N;i--){
        rpq.push(a[i]); sumr[i] += sumr[i+1] + a[i];
    }
    
    for(int i  = N+1; i<= 2*N;i++){
        ll lv = lpq.top();
        if(lv < a[i]){
            suml[i] = suml[i-1] + a[i] - lv;
            lpq.pop(); lpq.push(a[i]);
        }else{
            suml[i] = suml[i-1];
        }
    }
    for(int i = 2*N; i > N;i--){
        ll rv = rpq.top();
        if(rv > a[i]){
            sumr[i] = sumr[i+1] + a[i] - rv;
            rpq.pop(); rpq.push(a[i]);
        }else{
            sumr[i] = sumr[i+1];
        }
    }
    ll res = -(LINF);
    for(int i = N; i <= 2*N;i++){
        res = max(res,suml[i] - sumr[i+1]);
    }
    cout << res << endl;
    return 0;
}
