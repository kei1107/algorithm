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
template<class T> ostream& operator << (ostream& out,const vector<T>& V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> >& Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T>& mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }
template<typename T>vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}
/*
 <url:https://atcoder.jp/contests/abc160/tasks/abc160_f>
 問題文============================================================
 F - Distributing Integers
 =================================================================
 解説=============================================================
 
 最初に頂点1を根とする木を考える
 この時、dp1[i] := 頂点iを根とする木を考えた時の、整数の書き方
 としてdpを行う。
 これは、子の部分木を頂点の数列として組み合わせ順列を考えることで解くことができる。
 >> https://emtubasa.hateblo.jp/entry/2020/03/28/230227 がわかりやすい
 
 dp1が計算できたら、上のブログにある数式を変化させることで全方位木dpの形に持っていくことができるので
 全方位木dpによりO(N)で解ける。
 
 https://atcoder.jp/contests/abc160/submissions/11902324
 
 ================================================================
 */

const ll MAX_N = 3e6 + 10;
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
// 逆元 1/a % MOD
ll inversemod(ll a) { return powmod(a,MOD - 2);}

// 1 以上 N 以下の N 個の整数の中から，相異なる K 個の整数を選ぶパターンの数
ll nCr(int n,int r) {
    if(n < r) return 0;
    return (fact[n] * (factInv[r] * factInv[n-r] % MOD)) % MOD;
}
// 1 以上 N 以下の N 個の整数の中から，相異なる K 個の整数を選び，順番に並べるパターンの数
ll nPr(int n,int r){
    if(n < r) return 0;
    return (fact[n]*factInv[n-r])%MOD;
}
// 1 以上 N 以下の N 個の整数の中から，重複を許して K 個の整数を選ぶパターンの数
ll nHr(int n,int r){
    if(n == 0 && r == 0) return 1;
    return nCr(n+r-1,r);
}

void init(){
    Inv_init();
    fact_init();
}
template<class Type>
Type solve(Type res = Type()){
    init();
    ll N; cin >> N;
    vector<vector<ll>> G(N);
    for(int i = 0; i < N-1;i++){
        ll a,b; cin >> a >> b;
        a--; b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    
    auto dp1 = make_v<ll>(N);
    auto trsz = make_v<ll>(N);
    function<void(ll,ll)> dfs1 = [&](ll n,ll pre){
        
        ll cntsum = 0;
        
        ll X = 1, Y = 1;
        for(auto next:G[n]){
            if(next == pre) continue;
            dfs1(next,n);
            
            (X *= dp1[next])%=MOD;
            (Y *= factInv[trsz[next]])%=MOD;
            
            cntsum += trsz[next];
        }
        dp1[n] = fact[cntsum] * X % MOD * Y % MOD;
        trsz[n] = cntsum + 1;
    };
    dfs1(0,-1);
    
    auto dp = make_v<ll>(N);
    dp[0] = dp1[0];
    
    function<void(ll,ll,ll,ll)> dfs2 = [&](ll n,ll par,ll val,ll sz){
        
        if(n != 0){
            ll X = val, Y = factInv[sz];
            for(auto next:G[n]){
                if(next == par) continue;
                (X *= dp1[next])%=MOD;
                (Y *= factInv[trsz[next]])%=MOD;
            }
            dp[n] = fact[N-1] * X %MOD * Y % MOD;
        }
        for(auto next:G[n]){
            if(next == par) continue;
            /*
             *  now_val = (sz-1)!/Πtrsz[next]! * Πdp1[next]
             *  next_val = (sz-next_trsz-1)!//Πtrsz[next以外]! * Πdp1[next以外]
             */
            
            ll now_val = dp[n];
            ll next_trval = dp1[next];
            ll next_trsz = trsz[next];
            
            ll next_val = now_val;
            (next_val *= fact[trsz[next]])%=MOD;
            (next_val *= inversemod(next_trval))%=MOD;
            (next_val *= factInv[N-1])%=MOD;
            (next_val *= fact[N-next_trsz-1])%=MOD;
            
            dfs2(next,n,next_val,N-trsz[next]);
        }
    };
    dfs2(0,-1,-1,-1);
    for(int i = 0; i < N;i++){
        cout << dp[i] << endl;
    }
    
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve(0);
    // cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
