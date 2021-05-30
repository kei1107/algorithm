#include "bits/stdc++.h"
#include "atcoder/all"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T>& V){ for(size_t i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> >& Mat){ for(size_t i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T>& mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }
template<typename T>vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}
/*
 <url:https://atcoder.jp/contests/typical90/tasks/typical90_q>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */

/*
 BIT 1-index
 add : x に valを加算
 sum : [1,x] の総和を出力
 */
struct BIT {
    ll N;
    vector<ll> bit;
    BIT(ll N):N(N) {
        /* BITは[1..N]で扱う */
        bit.resize(N + 1, 0);
    }
    
    void add(int x, ll val){
        while (x <= N) {
            bit[x] += val;
            x += x & -x;
        }
    }
    
    ll sum(int x){
        ll ret = 0;
        if(x == 0) return ret;
        while (x) {
            ret += bit[x];
            x &= (x - 1);
        }
        return (ret);
    }
    // [l,r]
    ll sum(int l,int r){
        return sum(r) - sum(l-1);
    }
};

template<class Type>
Type solve(Type res = Type()){

    ll N,M; cin >> N >> M;
    vector<int> L(M),R(M);
    vector<pii> RL(M);
    for(int i = 0; i < M;i++){
        cin >> L[i] >> R[i];
        RL[i] = make_pair(R[i],L[i]);
    }
    ll T1 = 0,T2 = 0, T3 = 0;
    {
        map<ll,ll> mp;
        for(int i = 0; i < M;i++){
            mp[L[i]]++;
            mp[R[i]]++;
        }   
        for(auto p:mp) T1 += p.second*(p.second-1)/2;
    }

    {
        vector<ll> cusum(N+1);
        for(int i = 0; i < M;i++){
            cusum[R[i]]++;
        }
        for(int i = 1; i <= N; i++) cusum[i] += cusum[i-1];

        for(int i = 0; i < M;i++){
            T2 += cusum[L[i]-1];
        }
    }

    {
        sort(RL.begin(),RL.end());
        BIT bit(N+1);
        for(int i = 0; i < M;i++){
            auto [r,l] = RL[i];

            T3 += bit.sum(r-1) - bit.sum(l);
            bit.add(l,1);
        }
    }

    res = M*(M-1)/2 - T1 - T2 - T3;
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    //solve<ll>(0);
    cout << fixed << setprecision(12) << solve<ll>() << endl;
    return 0;
}