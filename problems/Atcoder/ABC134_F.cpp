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
 <url:https://atcoder.jp/contests/abc134/tasks/abc134_f>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 解説AC
 <https://img.atcoder.jp/abc134/editorial.pdf>
 <http://phyllo-algo.hatenablog.com/entry/2019/07/22/224331>

 
 二つの順列
 1,2,3,4,5,6,...,n
 1,2,3,4,5,6,...,n
 があるとする。
 この問題はiペア目をみたとき、そのペアのそれぞれをそれ以前のどれかと繋げるor繋げない
 の操作を行った時に繋いだペアの番号の差分を奇妙さとしていく問題に置き換えることができる。
 
 ここで、
 
 dp[i][j][k]:=iペア目までで、片側でまだ繋いでいない点がj個で確定した奇妙さがkである順列の個数
 
 とする。
 
 この時、
 iペア目をみた時
 
 1. 両方とも点をつながない場合
    dp[i+1][j][k+2*j] += dp[i][j][k]
 2. iペア目同士を繋げる場合
    dp[i+1][j][k+2*j] += dp[i][j][k]
 3. iペア目の片方を以前の繋いでいないどれかの点と繋げる場合
    dp[i+1][j][k+2*j] += dp[i][j][k] * 2* j
 4. iペア目の両方を以前の繋いでいないどれかと点を繋げる場合
    dp[i+1][j-1][k+2*(j-1)] += dp[i][j][k] * j * j
 
 の４パターンの遷移を考えればいい
 
 ================================================================
 */

const ll MOD = 1e9+7;
template<class Type>
Type solve(Type res = Type()){
    ll n,k; cin >> n >> k;
    auto dp = make_v<ll>(n+1,n+1,n*n+1);
    
    auto add = [&](ll& l,const ll& v){
        (l += v)%=MOD;
    };
    dp[0][0][0] = 1;
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++){
            for(int k = 0; k <= n*n;k++){
                if(dp[i][j][k] == 0) continue;
                
                // 点をつながない
                add(dp[i+1][j+1][k+2*(j+1)],dp[i][j][k]);
                
                // i+1ペア同士をつなぐ
                add(dp[i+1][j][k+2*j],dp[i][j][k]);
                
                // i+1ペアとiペア以前の点をつなぐ
                add(dp[i+1][j][k+2*j],dp[i][j][k]*2*j);
                
                if(j){//i+1ペアの両方をiペア以前のどれかにつなぐ
                    add(dp[i+1][j-1][k+2*(j-1)],dp[i][j][k]*j*j);
                }
            }
        }
    }
    res = dp[n][0][k];
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
