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
 <url:https://atcoder.jp/contests/abc149/tasks/abc149_f>
 問題文============================================================
 F - Surrounded Nodes
 =================================================================
 解説=============================================================
 期待値の線形性 (E[X+Y] = E[X] + E[Y])を用いることで
 この問題は、各頂点nが部分木Sに含まれ、かつ、白く塗られる期待値の総和とできる。
 各頂点が白く塗られる期待値は自明に1/2
 
 ある頂点nが部分木Sに含まれる期待値を求める事を考える。
 ある頂点nが部分木Sに含まれるには、木Tから頂点nを取り除いた時にできる部分木のうち
 少なくとも2つの部分木が黒く塗られた頂点を含むことが必要十分条件となる。
 
 ここで、木Tから頂点nを取り除いた時にできる各部分木の頂点数をv1,v2,...,vmとすると
 部分木iに黒く塗られた頂点が含まれる確率(:=少なくとも1つが黒く塗られている確率）は
 1-(1/2)^viとできる。
 
 この確率を用いて 少なくとも2つの部分木が黒く塗られた頂点を含む確率 は余事象を考える事で容易に求まる。
 
 あとは、v1,v2,...,vmをどうやって求めるかに関しては、全方位木dpを行う事でO(N)で求まる。
 具体的には、ある頂点を根とした木を考え、dp[i] := iと子孫の頂点数をdfsで求める。
 次に、親iから子jに移動する時に、jを根とした木について、親方向の頂点数計算したdpテーブルを用いて計算してやればいい。
 
 https://atcoder.jp/contests/abc149/submissions/9324466
 ================================================================
 */

const ll MOD = 1e9+7;
// a^b % MOD;
ll powmod(ll a,ll b) {ll res=1;a%=MOD; for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
// 逆元 1/a % MOD
ll inversemod(ll a) { return powmod(a,MOD - 2);}

template<class Type>
Type solve(Type res = Type()){
    ll N; cin >> N;
    vector<vector<ll>> G(N);
    for(int i = 0; i < N-1;i++){
        ll A,B; cin >> A >> B;
        A--; B--;
        G[A].emplace_back(B);
        G[B].emplace_back(A);
    }
    vector<ll> pow2(N+1),powinv2(N+1);
    pow2[0] = 1; pow2[1] = 2;
    powinv2[0] = 1; powinv2[1] = inversemod(2);
    for(int i = 2; i <= N;i++){
        powinv2[i] = powinv2[i-1]*powinv2[1]%MOD;
        pow2[i] = pow2[i-1]*2%MOD;
    }
    
    vector<ll> dp(N);
    function<ll(ll,ll)> dfs1 = [&](ll n,ll pre){
        ll child_sum = 0;
        for(auto next:G[n]){
            if(next == pre) continue;
            child_sum += dfs1(next,n);
        }
        return dp[n] = child_sum + 1;
    };
    dfs1(0,-1);
    //cout << dp << endl;
    
    function<void(ll,ll,ll)> dfs2 = [&](ll n,ll par_val,ll pre){
        vector<ll> v;    // 各部分木の個数
        if(par_val != -1) v.emplace_back(par_val);
        for(auto next:G[n]){
            if(next == pre) continue;
            v.emplace_back(dp[next]);
        }
        
        vector<ll> pv(v.size());    // 各部分木中に少なくとも1つが黒く塗られる確率
        for(int i = 0; i < (int)v.size();i++){
            pv[i] = (1-powinv2[v[i]]+MOD)%MOD;
        }
        
        // 全部分木中の少なくとも2つが黒く塗られる確率
        // (余事象）全部分木が白 or 1つのみ黒
        ll p1 = 1;  // 全部分木が白くなる確率
        {
            for(int i = 0; i < (int)v.size(); i++){
                ll p = (1-pv[i]+MOD)%MOD;
                p1 *= p;
                p1 %= MOD;
            }
        }
        ll p2 = 0;  // 1つのみが黒く確率
        {
            for(int i = 0; i < (int)v.size(); i++){
                ll p = (1-pv[i]+MOD)%MOD;
                p2 += p1*inversemod(p)%MOD*pv[i]%MOD;
                p2 %= MOD;
            }
        }
        ll addp = (1-p1-p2+2*MOD)%MOD*powinv2[1]%MOD;
        
        /*
        cout << string(10,'=') << endl;
        cout << v << endl;
        cout << pv << endl;
        cout << n << " : " << p1 << " " << p2 << endl;
        cout << addp << endl;
        //*/
        
        res += addp;
        res %= MOD;
        
        
        ll sumv = accumulate(v.begin(),v.end(),0LL);
        
        for(auto next:G[n]){
            if(next == pre) continue;
            dfs2(next,sumv-dp[next]+1,n);
        }
    };
    dfs2(0,-1,-1);
    
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
