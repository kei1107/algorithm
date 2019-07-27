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
 <url:https://atcoder.jp/contests/abc134/tasks/abc134_d>
 問題文============================================================
 =================================================================
 解説=============================================================
 全パターン存在する。
 箱をNから1まで順に見ていくことで箱にボールを入れるかどうか一意に決定できる。
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    ll N; cin >> N;
    vector<ll> a(N); for(auto& in:a) cin >> in;

    vector<ll> b(N,-1);

    for(ll n = N; n >= 1; n--){
        ll cnt = 0;
        for(ll m = 2*n; m <= N; m+=n){
            cnt += b[m-1];
        }
        cnt%=2;

        if(a[n-1] != cnt%2){
            b[n-1] = 1;
        }else{
            b[n-1] = 0;
        }
    }

    vector<ll> ans;

    for(int i = 0; i < N;i++){
        if(b[i]){
            ans.push_back(i+1);
        }
    }
    cout << ans.size() << endl;
    if(ans.empty()) return res;
    cout << ans << endl;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve(0);
    // cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
