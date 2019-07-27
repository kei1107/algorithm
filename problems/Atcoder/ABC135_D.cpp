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
 <url:https://atcoder.jp/contests/abc135/tasks/abc135_d>
 問題文============================================================
 =================================================================
 解説=============================================================
 dp[i桁目][13で割ったあまりがj] := 総数でdp
 ================================================================
 */

const ll MOD = 1e9+7;
template<class Type>
Type solve(Type res = Type()){
    string S; cin >> S;
    reverse(S.begin(),S.end());

    int len = (int)S.length();
    vector<vector<ll>> dp(len+1,vector<ll>(13,0));
    dp[0][0] = 1;

    vector<ll> ten(len);
    ten[0] = 1;
    for(int i = 1; i < len;i++){
        ten[i] = ten[i-1] * 10 %13;
    }
    for(int i = 0; i < len;i++){
        for(int j = 0; j < 13;j++){
            if(dp[i][j] == 0) continue;
            if(S[i] != '?'){
                (dp[i+1][(j+ten[i]*(S[i]-'0'))%13] += dp[i][j])%=MOD;
            }else{
                for(int k = 0; k <= 9;k++){
                    (dp[i+1][(j+ten[i]*k)%13] += dp[i][j])%=MOD;
                }
            }
        }
    }
    res = dp[len][5];
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
