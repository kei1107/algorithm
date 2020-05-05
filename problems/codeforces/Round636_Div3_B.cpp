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
 <url:https://codeforces.com/contest/1343/problem/B>
 問題文============================================================
 B. Balanced Array
 =================================================================
 解説=============================================================

 2,4,6,...,1,3,5,...

 と配列をつくって、総和が等しくなるように最後の要素で調節すればいい
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;

        vector<ll> a(n,0);

        ll even_sum = 0;
        ll odd_sum = 0;
        for(int i = 0; i < n/2; i++){
            a[i] = 2*(i+1);
            a[i+n/2] = 2*i + 1;

            even_sum += a[i];
            odd_sum  += a[i+n/2];
        }

        a[n-1] += even_sum - odd_sum;

        if(a[n-1]%2 == 0){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
            cout << a << endl;
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve(0);
    // cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
