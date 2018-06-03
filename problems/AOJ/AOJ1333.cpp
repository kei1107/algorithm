#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

/*
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1333>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 解説を見た　＜http://suikaba.hatenablog.com/entry/2018/04/11/212545＞
 
 二分探索と尺取り法を用いて計算する
 ================================================================
 */

int W,N;
bool C(int m,vector<int>& sum){
    vector<int> dp(N+1);
    int lim = N,r = N;
    int cnt = 0;
    for(int i = N-1; i>= 0;i--){
        while(W - (sum[lim] - sum[i]) - (lim - i - 1) < 0){
            cnt -= dp[lim--];
        }
        while((r > lim || r - i - 1> 0) && (W - (sum[r] - sum[i]) + r - i - 2)/(r - i - 1) <= m){
            cnt += dp[r--];
        }
        dp[i] = lim == N || cnt > 0;
    }
    return dp[0] == 1;
}
int solve(){
    int res = INF;
    vector<int> x(N),sum(N+1);
    for(int i = 0; i < N;i++) cin >> x[i];
    for(int i = 0; i < N;i++) sum[i+1] = sum[i] + x[i];
    int l = 0, r = W;
    while(r - l > 1){
        int m = (l+r)/2;
        if(C(m,sum)){
            r = m;
        }else{
            l = m;
        }
    }
    res = r;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    while(cin >> W >> N, W|N){
        cout << solve() << endl;
    }
    return 0;
}
