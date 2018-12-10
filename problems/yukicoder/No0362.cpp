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
 <url:https://yukicoder.me/problems/no/362>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 桁dp+二分探索問題
 
 f(x) := x以下の門松ナンバーの個数として二分探索する。
 
 この時f(x)の計算には
 dp[i桁目][直近２桁の数字][x以下か否か]:=門松ナンバー数
 として桁dpすればいい
 ================================================================
 */


bool kadomatsu(int a,int b,int c){
    if(a == b || b == c || c == a) return false;
    if(a > b && c > b) return true;
    if(a < b && c < b) return true;
    return false;
}

ll dp[20][100][2];
ll calc(ll X){
    fill(**dp,**dp+20*100*2,0);
    ll ret = 0;

    string SX = to_string(X);
    for(auto& c:SX) c -= '0';
    for(int i = 2; i < SX.length(); i++){
        
        int lim1 = i!=2?99:SX[i-2]*10 + SX[i-1];
        for(int j = 10; j <= lim1; j++){
            if(j%10 == j/10) continue;
            dp[i][j][(i!=2)||(j!=lim1)]+=1;
        }
        
        for(int j = 0; j < 100; j++){
            for(int k = 0; k < 2;k++){
                if(!dp[i][j][k]) continue;
                int lim = k?9:SX[i];
                for(int l = 0; l <= lim;l++){
                    if(kadomatsu(j/10, j%10, l)){
                        dp[i+1][j%10*10+l][k||(l<lim)] += dp[i][j][k];
                    }
                }
            }
        }
    }
    for(int j = 0; j < 100;j++){
        for(int k = 0; k < 2;k++){
            ret += dp[SX.length()][j][k];
        }
    }
    return ret;
}
ll solve(){
    ll res = 0;
    ll K; cin >> K;
    ll l = 100, r = LINF;
    while(r-l>1){
        ll m = (l+r)/2;
        if(calc(m) >= K) r = m;
        else l = m;
    }
    res = r;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    int T; cin >> T;
    while(T--){
        cout << solve() << endl;
    }
    return 0;
}
