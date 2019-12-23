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
 <url:https://atcoder.jp/contests/abc146/tasks/abc146_e>
 問題文============================================================
 E - Rem of Sum is Num
 =================================================================
 解説=============================================================

 この手の問題は、まず任意の区間の総和を求めたいので
 Aの累積和XによってAの区間(l,r]の総和をX[r]-X[l]の形で取得できるようにする。

 ここで、問題の条件を満たす区間(l,r]は
 (X[r] - X[l])%K = r - l
 となる場合である。
 ここで、r - lはK未満になるべきなので
 r - l < Kという条件を加えた時、

 (X[r] - X[l])%K = (r - l)%K
 (X[r] - r)%K    = (X[l] - l)%K
 より、

 ある値rに対して、r - l < Kを満たす範囲で
 (X[r] - r)%K    = (X[l] - l)%K
 となるようなlを探せば良い

 これは、累積和の値を左から順番に見つつ、map等で値を管理することで実装可能
 よってO(NlogK)で解ける

 https://atcoder.jp/contests/abc146/submissions/9105724
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    ll N,K; cin >> N >> K;
    vector<ll> A(N);
    for(auto& in:A){ cin >> in; in%=K; }
    vector<ll> X(N+1);
    for(int i = 0; i < N;i++){
        X[i+1] = (X[i] + A[i])%K;
    }

    /*
     0 <= l < r <= N
     (X_r - X_l)%K = r - l

     if r-l < K
        (X_r - X_l)%K   = (r - l)%K
        (X_r - r)%K     = (X_l - l)%K
    */

    map<ll,ll> mp;
    for(int i = 0; i <= N;i++){
        X[i] = (X[i] - i%K + K)%K;
    }
    for(int i = 0; i <= N;i++){
        if(i-K>=0){
            mp[X[i-K]]--;
        }
        res += mp[X[i]];
        mp[X[i]]++;
    }

    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
