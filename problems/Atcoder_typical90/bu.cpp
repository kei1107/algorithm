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
template<class T> ostream& operator << (ostream& out,const vector<T>& V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> >& Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T>& mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }
template<typename T>vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}
/*
 <url:https://atcoder.jp/contests/typical90/tasks/typical90_bu>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */


const ll MOD = 1e9+7;

template<class Type>
Type solve(Type res = Type()){
    int N; cin >> N;
    vector<char> c(N); for(auto& in:c) cin >> in;
    vector<vector<int>> G(N);
    for(int i = 0; i < N-1;i++){
        int A,B; cin >> A >> B;
        A--; B--;
        G[A].emplace_back(B);
        G[B].emplace_back(A);
    }

    auto dp = make_v<ll>(N,3);


    auto rec = [&](auto self,int n,int pre) -> void{
        for(auto next:G[n]){
            if(next == pre) continue;
            self(self,next,n);
        }
        int t = c[n] != 'a';
        ll T1 = 1, T2 = 1;
        for(auto next:G[n]){
            if(next == pre) continue;
            (T1 *= (dp[next][t] + dp[next][2])%MOD)%=MOD;
            (T2 *= (dp[next][0] + dp[next][1] + 2 * dp[next][2])%MOD)%=MOD;
        }

        dp[n][t] = T1;
        dp[n][2] = (T2 - T1 + MOD)%MOD;


    };
    rec(rec,0,-1);
    return res = dp[0][2];
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    //solve<ll>(0);
    cout << fixed << setprecision(12) << solve<ll>() << endl;
    return 0;
}