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
 <url:https://atcoder.jp/contests/abc169/tasks/abc169_e>
 問題文============================================================
 E - Count Median
 =================================================================
 解説=============================================================
 
 指定区間の間で値を自由に決めていいので、中央値もある区間の間で自由に決めることができる。
 中央値の該当の区間は[Xiを全てAiにしたときの中央値、Xiを全てBiにしたときの中央値]となるので、
 Nが偶数の時は0.5刻み、奇数のときは1刻みで個数を数え上げればよい。
 
 https://atcoder.jp/contests/abc169/submissions/13818309
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    ll N; cin >> N;
    vector<pll> AB(N);
    for(auto& in:AB) cin >> in.first >> in.second;

    vector<ll> A(N),B(N);
    for(int i = 0; i < N;i++){
        A[i] = AB[i].first;
        B[i] = AB[i].second;
    }

    sort(A.begin(),A.end());
    sort(B.begin(),B.end());

    if(N%2 == 1){
        ll L = A[N/2];
        ll R = B[N/2];
        res = R-L+1;
    }else{
        ll L = A[N/2-1] + A[N/2];
        ll R = B[N/2-1] + B[N/2];

        res = R-L+1;
    }

    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
