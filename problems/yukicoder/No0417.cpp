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
 <url:https://yukicoder.me/problems/no/417>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 葉から根に向かってボトムアップ的にdpを進めていけばいい。
 
 ================================================================
 */


int dp[200][2001];
void rec(int n,int pre,vector<vector<pii>>& G,vector<int>& U){
    dp[n][0] = U[n];
    for(auto p:G[n]){
        int next,cost; tie(next,cost) = p;
        if(next == pre) continue;
        rec(next,n,G,U);
        for(int i = 2000; i >= 0; i--){
            if(dp[n][i] == -1) continue;
            for(int j = 2000; j >= 0; j--){
                if(dp[next][j] == -1) continue;
                if(i+j+cost > 2000) continue;
                dp[n][i+j+cost] = max(dp[n][i+j+cost],dp[n][i]+dp[next][j]);
            }
        }
    }
    
}
ll solve(){
    ll res = 0;
    int N,M; cin >> N >> M;
    vector<int> U(N); for(auto& in:U) cin >> in;
    vector<vector<pii>> G(N);
    for(int i = 0; i < N-1;i++){
        int A,B,C; cin >> A >> B >> C;
        G[A].push_back(pii(B,C));
        G[B].push_back(pii(A,C));
    }
    
    fill(*dp,*dp+200*2001,-1);
    rec(0,-1,G,U);
    for(int i = 0; i*2 <= M;i++) res = max(res,(ll)dp[0][i]);
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
