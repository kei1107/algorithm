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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1619&lang=jp>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 n,mの値の大きさに合わせて２パターンの解法を考えれば良い
 
 まず n*m <= 500 より
 min(n,m) <= 22 となる
 
 よって
 n <= 20 の時 , 25 <= m <= 500 であり
 nについて全探索を行うことによって解くことができる
 また、
 20 < n <= 500 の時 , m <= 22 であり、
 mのパターンが少ないので、
 dp[i][j] := i番目のレシピを見た時、これまでの食品の状態が j である時の最大レシピ数
 ここで、 j はbit列であり、 1が立っていれば奇数回使用, 0 が立っていれば偶数回使用されている
 としたbitdpで解くことが可能
 ================================================================
 */

ll n,m;
string b[505];

// n <= m
bool ok[501];

// n >= m
int bit[501];
int dp[2][1<<25];

int solve(){
    int res = 0;
    for(int i = 0; i < n;i++) cin >> b[i];
    if(n <= 20){
        for(int i = 0; i < (1<<n);i++){
            if(res >= __builtin_popcount(i)) continue;
            fill(ok,ok+501,false);
            for(int j = 0; j < n;j++){
                if(!((i>>j)&1)) continue;
                for(int k = 0; k < m;k++){
                    if(b[j][k] == '1') ok[k] = !ok[k];
                }
            }
            if(accumulate(ok,ok+m,0)) continue;
            res = max(res,__builtin_popcount(i));
        }
    }else{
        fill(bit,bit+n,0);
        for(int i = 0; i < n;i++){
            for(int j = 0; j < m;j++){
                if(b[i][j] == '1'){
                    bit[i] |= (1<<j);
                }
            }
        }
        for(int i = 0; i < 2;i++) for(int j = 0; j < (1<<m);j++) dp[i][j] = -1;
        dp[0][0] = 0;
        int cur = 0, next = 1;
        for(int i = 0; i < n;i++){
            for(int j = 0; j < (1<<m);j++){
                if(dp[cur][j] == -1) continue;
                dp[next][j] = max(dp[next][j],dp[cur][j]);
                dp[next][j^bit[i]] = max(dp[next][j^bit[i]],dp[cur][j]+1);
                
                dp[cur][j] = -1;
            }
            swap(cur,next);
        }
        res = dp[cur][0];
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    while(cin >> n >> m,n){
        cout << solve() << endl;
    }
    return 0;
}
