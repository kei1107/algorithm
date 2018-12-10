#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

/*
 <url:https://yukicoder.me/problems/no/372>
 問題文============================================================
 =================================================================
 解説=============================================================
 dp
 
 dp[i][j] := i桁目までで部分列をMで割ったあまりがjとなるものの個数
 としてかぞえあげる。
 leading zerosは禁止なので、そこだけ例外処理する。
 ================================================================
 */

const ll MOD = 1e9+7;
ll dp[2][20001];
ll solve(){
    ll res = 0;
    string S; cin >> S;
    ll M; cin >> M;
    
    int cur = 0,next = 1;
    dp[cur][0] = 0;
    for(int i = 0; i < S.length();i++){
        int c = S[i] - '0';
        for(int j = 0; j < M;j++){
            (dp[next][(j*10+c)%M] += dp[cur][j])%=MOD;
            (dp[next][j] += dp[cur][j])%=MOD;
            dp[cur][j] = 0;
        }
        if(c == 0) (res+=1)%=MOD;
        else (dp[next][c%M]+=1)%=MOD;
        
        swap(cur,next);
    }
    (res += dp[cur][0])%=MOD;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
