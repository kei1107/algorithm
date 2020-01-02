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
 <url:https://atcoder.jp/contests/abc147/tasks/abc147_e>
 問題文============================================================
 E - Balanced Path
 =================================================================
 解説=============================================================

 H,Wが小さいので
 dp[i][j][k] := マス(i,j)にいる時、「赤の総和-青の総和」がkの場合の有無
 としてdpができる。

 https://atcoder.jp/contests/abc147/submissions/9124467
 ================================================================
 */

bool dp[85][85][80*160*2+1];
const int base = 80*160;
template<class Type>
Type solve(Type res = Type()){
    int H,W; cin >> H >> W;
    auto A = make_v<int>(H,W);
    auto B = make_v<int>(H,W);

    for(auto& vec:A) for(auto& in:vec) cin >> in;
    for(auto& vec:B) for(auto& in:vec) cin >> in;

    dp[0][0][base] = true;
    for(int i = 0; i < H;i++){
        for(int j = 0; j < W;j++){
            for(int k = 0; k <= 80*160*2; k++){
                if(dp[i][j][k]){
                    dp[i+1][j][k+(A[i][j]-B[i][j])] = true;
                    dp[i+1][j][k-(A[i][j]-B[i][j])] = true;

                    dp[i][j+1][k+(A[i][j]-B[i][j])] = true;
                    dp[i][j+1][k-(A[i][j]-B[i][j])] = true;
                }
            }
        }
    }

    res = LINF;
    for(ll k = 0; k <= 80*160*2; k++){
        if(dp[H][W-1][k] | dp[H-1][W][k]){
            res = min(res,abs(k-base));
        }
    }

    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
