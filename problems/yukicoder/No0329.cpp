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
 <url:https://yukicoder.me/problems/no/329>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 i -> jまでの道のりの中で それまでの要素の最小値がw[j]よりも大きければ
 全射可能である(注 サンプル3は 4->2->3->1 で4から1へ全射可能)
 
 よって、全射可能なペアに対して w[i]の要素をw[j]の要素に全射させるような組み合わせを求めればいい。
 これは i 個の区別できるボールを j 個の区別できる箱に入れるとき、可能な入れ方の総数
 (http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_C&lang=jp)
 と等しい
 
 
 問題はi->jへどのように全射可能か確かめるかどうかだが、
 これはワーシャルフロイドを用いて G[i][j] := iからjへたどり着く時の最小要素数の最大値とおけば
 G[j][k] = max(G[j][k],min(G[j][i],G[i][k]))
 で求める事が可能
 ================================================================
 */

const ll MAX_N = 1e5 + 10;
const ll MOD = 1e9+7;
ll Inv[MAX_N];
ll fact[MAX_N];
ll factInv[MAX_N];
void Inv_init(){
    Inv[1] = 1;
    for(int i = 2; i < MAX_N; i++) {
        Inv[i] = Inv[MOD%i] * (MOD - MOD/i) % MOD;
    }
}
void fact_init(){
    fact[0] = fact[1] = factInv[0] = factInv[1] = 1;
    for(int i = 2; i < MAX_N; i++){
        fact[i] = (fact[i-1] * i) % MOD;
        factInv[i] = (factInv[i-1] * Inv[i])%MOD;
    }
}

// a^b % MOD;
ll powmod(ll a,ll b) {ll res=1;a%=MOD; for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}


const ll MAXNM = 1010;
//i個の物を、j個の区別できる箱に、最低1個ずつ入れる入れ方
ll I2J[MAXNM][MAXNM]; // Ai -> Ajへの全射の数


void I2J_init(){
    I2J[0][0] = 1;
    for(int i = 1; i < MAXNM; i++){
        for(int j = 1; j < MAXNM; j++){
            I2J[i][j] += I2J[i-1][j] * j %MOD;
            I2J[i][j] += I2J[i-1][j-1] * j %MOD;
            I2J[i][j] %= MOD;
        }
    }
}
void init(){
    Inv_init();
    fact_init();
    I2J_init();
}


ll G[300][300];
ll solve(){
    init();
    ll res = 0;
    ll N,M; cin >> N >> M;
    vector<ll> w(N); for(auto& in:w) cin >> in;
    if(M == 0){
        for(int i = 0; i < N;i++) (res += fact[w[i]])%=MOD;
        return res;
    }
    for(int i = 0; i < N;i++) G[i][i] = w[i];
    for(int i = 0; i < M;i++){
        int I,J; cin >> I >> J; I--; J--;
        G[I][J] = min(w[I],w[J]);
    }
    for(int i = 0; i < N;i++){
        for(int j = 0; j < N;j++){
            for(int k = 0; k < N;k++){
                G[j][k] = max(G[j][k],min(G[j][i],G[i][k]));
            }
        }
    }
    for(int i = 0; i < N;i++){
        for(int j = 0; j < N;j++){
            if(G[i][j] >= w[j]){
                (res += I2J[w[i]][w[j]])%=MOD;
            }
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
