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
 <url:https://atcoder.jp/contests/abc149/tasks/abc149_e>
 問題文============================================================
 E - Handshake
 =================================================================
 解説=============================================================
 まず、二分探索(NlogN)を用いてM回以上握手可能な1回の握手における最小の取得幸福度を求める。
 この幸福度をBとした時、B+1以上の幸福度が得られる握手には無条件で応じてよい。
 また、残りの握手は全て幸福度BとしてもよいのでB*(M-[B+1以上の幸福度が得られる握手の回数])の幸福度が得られる。
 B+1以上の幸福度が得られる握手の回数と得られる総幸福度は片手握手する人を
 決め打ちした際にAについての累積和を用いることでO(NlogN)で求まる。

 https://atcoder.jp/contests/abc149/submissions/9317330
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    ll N,M; cin >> N >> M;
    vector<ll> A(N); for(auto& in:A) cin >> in;
    
    sort(A.begin(),A.end());
    ll l = 0, r = INF;
    while(r-l>1){
        ll m = (l+r)/2;

        ll x = 0;
        for(int i = 0; i < N;i++){
            ll it = lower_bound(A.begin(),A.end(),m-A[i]) - A.begin();
            x += N-it;
        }
        if(x >= M){
            l = m;
        }else{
            r = m;
        }
    }

    vector<ll> cusum(N+1);
    reverse(A.begin(),A.end());
    for(int i = 0; i < N;i++) cusum[i+1] = cusum[i] + A[i];
    reverse(A.begin(),A.end());

    ll left = M;
    for(int i = 0; i < N;i++){
        ll it = lower_bound(A.begin(),A.end(),r-A[i]) - A.begin();
        res += cusum[N-it] + A[i]*(N-it);
        left -= N-it;
    }
    res += l*left;

    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
