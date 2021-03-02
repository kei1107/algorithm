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
 <url:https://atcoder.jp/contests/agc044/tasks/agc044_a>
 問題文============================================================
 A - Pay to Win
 =================================================================
 解説=============================================================
 ================================================================
 */

map<ll,ll> mp;
ll A,B,C,D; 

ll dfs(ll N){
    if(N==0) return 0;
    if(N==1) return D;
    if(mp.count(N)) return mp[N];

    ll& ret = mp[N];
    ret = LINF;
    if(N < ret/D) ret = N*D;
    
    auto check = [&](ll n,ll T,ll m){
        ret = min(ret,llabs(n-N)*D + T + dfs(n/m));
    };

    check(N/2*2,A,2);
    check((N+1)/2*2,A,2);
    check(N/3*3,B,3);
    check((N+2)/3*3,B,3);
    check(N/5*5,C,5);
    check((N+4)/5*5,C,5);

    return ret;
}

template<class Type>
Type solve(Type res = Type()){
    mp.clear();
    ll N;
    cin >> N >> A >> B >> C >> D;
    res = dfs(N);
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    //solve<ll>(0);

    int T; cin >> T;

    while(T--) cout << fixed << setprecision(12) << solve<ll>() << endl;
    return 0;
}