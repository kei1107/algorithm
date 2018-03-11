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
<url:https://beta.atcoder.jp/contests/abc090/tasks/abc090_b>
問題文============================================================
A以上B以下の整数のうち回文はいくつか
=================================================================

解説=============================================================
貪欲全チェック
================================================================
*/
bool check(ll X){
    string S = to_string(X);
    ll len = (int)S.length();
    for(int i = 0; i < len/2;i++){
        if(S[i] != S[len-1-i])return false;
    }
    return true;
}
ll solve(){
    ll res = 0;
    ll A,B; cin >> A >> B;
    for(;A <= B;A++){
        if(check(A)) res++;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}

