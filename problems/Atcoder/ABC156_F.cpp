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
 <url:https://atcoder.jp/contests/abc156/tasks/abc156_f>
 問題文============================================================
 F - Modularness
 =================================================================
 解説=============================================================
 
 解説AC : https://img.atcoder.jp/abc156/editorial.pdf
 
 各クエリに対して
 事前にdをmod mとした値にしておく。
 (ai mod m) >= (ai+1 mod m) となる場合を考える
 
 1) (ai mod m) = (ai+1 mod m) となるとき
 　di mod k = 0となっているはずなので、O(k)でその総数を数える事が可能
 2) (ai mod m) > (ai+1 mod m)　となるとき
 　二つの要素を順に見ていくのではなく、最初と最後の要素だけ見ればいい
  ある二要素において  (ai mod m) > (ai+1 mod m) となるということは
  aiをmで割った商が1大きくなることを意味する。
  よって、 an-1をmで割った商をa0をmで割った商で引く事でもとまる。
  これもO(k)で計算可能
 
 よって、各クエリに対してO(k)で計算可能となるため、この問題はO(kq)で解ける
 
 https://atcoder.jp/contests/abc156/submissions/11470408
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int k,q; cin >> k >> q;
    vector<int> d(k); for(auto& in:d) cin >> in;
    
    for(int unchi = 0; unchi < q; unchi++){
        int n,x,m; cin >> n >> x >> m;
        
        vector<int> dm(k);
        for(int i = 0; i < k; i++) dm[i] = d[i]%m;

        ll zero = 0;
        
        for(int i = 0; i < min(k,n-1);i++){
            if(dm[i] == 0){
                zero += ((n-1)-(i+1))/k + 1;
            }
        }
        
        ll a0_div_m = x/m;
        ll an_1 = x;
        for(int i = 0; i < min(k,n-1);i++){
            ll cnt = ((n-1)-(i+1))/k+1;
            an_1 += dm[i]*cnt;
        }
        ll an_1_div_m = an_1/m;
        
        ll X = zero + (an_1_div_m - a0_div_m);
        
        cout << (n-1) - X << endl;
    }

    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve(0);
    // cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
