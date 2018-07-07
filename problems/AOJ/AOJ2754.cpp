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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2754>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 dp[i][j] := i番目の壺を見る時、すでに体積jの水を使用している場合の最大高さ
 
 としてdpすれば良い
 ================================================================
 */

double clac(int n,int add,vector<int>& S,vector<int>& H){
    double ret = 0;
    int sz = (int)S.size();
    for(int i = 0; i < sz;i++){
        int V = S[i]*H[i];
        if(add >= V){
            ret += H[i];
            add -= V;
        }else{
            ret += H[i]*add/(double)V;
            break;
        }
    }
    return ret;
}
double solve(){
    double res = 0;
    int N,M; cin >> N >> M;
    vector<int> K(N);
    vector<vector<int>> S(N),H(N);
    for(int i = 0; i < N;i++){
        cin >> K[i];
        S[i].resize(K[i]); H[i].resize(K[i]);
        for(int j = 0; j < K[i];j++){
            cin >> S[i][j] >> H[i][j];
        }
    }
    
    vector<vector<double>> dp(N+1,vector<double>(M+1,0));
    for(int i = 0; i < N;i++){
        for(int j = 0; j <= M;j++){
            for(int k = 0; k <= M; k++){
                if(j + k > M)continue;
                dp[i+1][j+k] = max(dp[i+1][j+k],dp[i][j] + clac(i,k,S[i],H[i]));
            }
        }
    }
    res = dp[N][M];
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(12) <<  solve() << endl;
    return 0;
}
