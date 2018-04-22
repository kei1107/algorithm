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
 <url:https://arc058.contest.atcoder.jp/tasks/arc058_c>
 問題文============================================================
 日本の誇る美しいリズムとして、五七五というものがあります。
 いろはちゃんは、数列から五七五を探すことにしました。でもこれは簡単だったので、XYZを探すことにしました。
 
 長さ N の、それぞれの値が 1~10 の数列 a0,a1,…,aN−1 を考えます。
 このような数列は全部で 10^N 通りありますが、そのうちXYZを含むものは何通りでしょう？
 
 ただし、XYZを含むとは以下のように定義されます。
 
 ax+ax+1+…+ay−1=X
 ay+ay+1+…+az−1=Y
 az+az+1+…+aw−1=Z
 
 を満たす 0≦x<y<z<w≦N が存在する。
 
 なお、答えは非常に大きくなることがあるので、答えは 10^9+7 で割ったあまりを出力してください。
 =================================================================
 解説=============================================================
 
 考察が詰めきれなくて解説を読んだ
 
 mayokoさんのサイトもわかりやすかった。<http://mayokoex.hatenablog.com/entry/2016/07/24/131007>
 
 ================================================================
 */

const ll MOD = 1e9+7;
ll powmod(ll a,ll b) {ll res=1;a%=MOD;for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}

#define MAX_N 45
#define MAX_S 18
ll dp[MAX_N][1<<MAX_S];
ll solve(){
    ll res = 0;
    ll N,X,Y,Z; cin >> N >> X >> Y >> Z;
    dp[0][0] = 1;
    ll base = (1<<(X+Y+Z-1))|(1<<(Y+Z-1))|(1<<(Z-1));
    for(int i = 0; i < N;i++){
        for(int j = 0; j < (1<<MAX_S);j++){
            for(int k = 1; k <=10; k++){
                ll next = (j<<k)|(1<<(k-1)); next = next&((1<<MAX_S)-1);
                if((next&base)!=base){
                    (dp[i+1][next] += dp[i][j])%=MOD;
                }
            }
        }
    }
    ll Sum = 0;
    for(int i = 0; i < (1<<MAX_S);i++) (Sum += dp[N][i])%=MOD;
    res = (powmod(10, N) - Sum + MOD*2)%MOD;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
