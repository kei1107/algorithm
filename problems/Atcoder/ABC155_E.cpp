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
 <url:https://atcoder.jp/contests/abc155/tasks/abc155_e>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 dp[i][j] := i桁目をみたとき、繰り上がりが発生しているか否か(j=0 or 1)で桁dp
 
 https://atcoder.jp/contests/abc155/submissions/11468394
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    string N; cin >> N;
    int len = (int)N.length();
    auto dp = make_v<ll>(len+1,2);
    fill_v(dp,LINF);
    
    dp[0][0] = 0; dp[0][1] = 1;
    
    for(int i = 0; i < len; i++){
        int n = N[i] - '0';
        dp[i+1][0] = min(dp[i][0]+n,dp[i][1]+(10-n));
        dp[i+1][1] = min(dp[i][0]+(n+1),dp[i][1]+10-(n+1));
    }
    res = dp[len][0];
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
