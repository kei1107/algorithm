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
 <url:https://yukicoder.me/problems/no/155>
 問題文============================================================
 =================================================================
 解説=============================================================
 戻すDP
 新しい知見だ。。。
 
 まぁ当然自力ACはできなかった
 
 >> http://kmjp.hatenablog.jp/entry/2015/02/18/0900
 ================================================================
 */

typedef long double ld;

ll dp[22005][55];
ll dp2[22005][55];

ld solve(){
    ld res = 0;
    int N,L; cin >> N >> L;
    L *= 60;
    vector<int> S(N);
    for(int i = 0; i < N;i++){
        int m,s; char c; cin >> m >> c >> s;
        S[i] = m*60 + s;
    }
    if(L >= accumulate(S.begin(),S.end(),0)) return N;
    
    vector<ld> fact(N+1);
    fact[0] = 1;
    for(int i = 0; i < N;i++) fact[i+1] = fact[i]*(i+1);

    dp[0][0] = 1;
    for(int i = 0; i < N;i++){
        for(int x = i; x >= 0;x--){
            for(int y = 0; y < 22001;y++){
                dp[min(22000,y+S[i])][x+1] += dp[y][x];
            }
        }
    }
    
    for(int i = 0; i < N;i++){
        for(int x = 0; x <= N;x++){
            for(int y = 0; y <= L+S[i]-1;y++){
                dp2[y][x] = dp[y][x];
                if(y>=S[i] && x>0) dp2[y][x]-=dp2[y-S[i]][x-1];
                if(x<N && y<L) res += dp2[y][x] * (fact[x] * fact[N-(x+1)])/fact[N];
            }
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(12) << solve() << endl;
    return 0;
}
