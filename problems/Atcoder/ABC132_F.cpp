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
 <url:https://atcoder.jp/contests/abc132/tasks/abc132_f>
 問題文============================================================
 =================================================================
 解説=============================================================
 dpを行う
 
 dp[k個目][直近の値がx] := 総数
 
 普通にやるとTLEするが
 N/x == N/y となるxとyは同じ状態として考えることができる。
 N/x が同じ値となるようなものの個数は
 xが1〜√Nまでは1個
 xが√Nより大きいとき複数個出てくる
 
 後者に関しては、数学的に考えると同じ状態をひとまとめにした時の個数はおおよそ√N個の状態に
 分けられるので、
 
 dpで前半の状態と後半の状態で分けて考えることで高速化ができる。
 ちなみに全状態数をMとすると、それぞれの関係から j個目の状態を見た時、隣に置くことができる状態はM-j個目までである。
 ================================================================
 */

ll dp[105][100005];
ll cnt[100005];
const ll MOD =1e9+7;
template<class Type>
Type solve(Type res = Type()){
    ll N,K; cin >> N >> K;
    
    ll M = 0;
    for(ll i = 1; i <= N;){
        ll j = N/i;
        if(i <= j){
            cnt[M++] = 1;
            i++;
        }else{
            cnt[M++] = N/j - i + 1;
            i = N/j + 1;
        }
    }
    
    auto add = [&](ll& l,const ll v){
        (l += v)%=MOD;
    };
    
    vector<ll> cusum(M+5);
    
    dp[0][0] = 1;
    for(int k = 0; k < K;k++){
        fill(cusum.begin(),cusum.end(),0);
        
        for(int j = 0; j < M;j++){
            cusum[j+1] = cusum[j] + dp[k][j];
        }
        for(int j = 0; j < M;j++){
            add(dp[k+1][j],cusum[M-j]*cnt[j]%MOD);
        }
    }
    
    for(auto v:dp[K]){
        add(res,v);
    }
    
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
