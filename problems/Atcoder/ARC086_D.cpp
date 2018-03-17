#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream &operator << (ostream& out,const pair<S,T>& o){
    out << "(" << o.first << "," << o.second << ")"; return out;
}

/*
<url:https://arc086.contest.atcoder.jp/tasks/arc086_b>
問題文============================================================
 すぬけ君は長さ N の数列 a を持っています。a の (1-indexedでの) i 番目の数は ai です。
 
 すぬけ君は以下の操作を何度でも行うことができます。
 
 操作：1 以上 N 以下の整数 x,y を選び、ay に ax を加算する。
 すぬけ君はこの操作を 0 回以上 2N 回以下行って a が下記の条件を満たすようにしたいです。
 そのような操作手順の一例を示してください。
 なお、この問題の制約下で、条件を満たすような操作の手順が必ず存在することが証明できます。
 
 条件：a1≤a2≤…≤aN
=================================================================

解説=============================================================
累積和を想定する。
 
 全ての要素の符号が一致していれば累積和の要領で条件を満たすことができる
 
 符号を全て一致させるには、一番絶対値の大きい要素を全ての要素に足し合わせれば良い
 
 よって、足し合わせる作業、　累積和を作る作業で 2*N-1 回の操作となり条件を満たす
================================================================
*/

void solve(){
    ll N; cin >> N;
    vector<ll> a(N); for(auto &in:a) cin >> in;
    cout << 2*N-1 << endl;
    ll absmax = -1; bool Sign = false; ll loc = -1;
    for(int i = 0; i < N;i++){
        if(abs(a[i]) > absmax){
            absmax = abs(a[i]);
            Sign = (a[i] >= 0)?true:false;
            loc = i+1;
        }
    }
    for(int i = 1; i <= N; i++){
        cout << loc << " " << i << endl;
    }
    if(Sign){
        for(int i = 1; i < N;i++){
            cout << i << " " << i + 1 << endl;
        }
    }else{
        for(int i = N; i > 1; i--){
            cout << i << " " << i - 1 << endl;
        }
    }
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    solve();
	return 0;
}
