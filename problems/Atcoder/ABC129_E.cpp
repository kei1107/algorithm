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
 <url:https://atcoder.jp/contests/abc129/tasks/abc129_e>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 dp[i桁目][L以下であるか] ：＝条件を満たす(A,B)の組み合わせの総数
 
 として桁dpする。
 この時、 a^b == a+bを満たすには、
 aとbのbitwiseandが0となってればいい
 ================================================================
 */

const ll MOD = 1e9+7;

template<class Type>
Type solve(Type res = Type()){
    // a + b <= L
    // a ^ b == a + b
    string L; cin >> L;
    for(auto& v:L) v -= '0';
    
    // a ^ b = a + b + 2 * (a&b)
    // a ^ b <= L
    // a & b = 0であれば成り立つ
    ll len = L.length();
    // dp[i桁目][L以下か否か]
    auto add = [&](ll& t,ll v){
        (t += v)%=MOD;
    };
    
    auto dp = make_v<ll>(len+1,2);
    dp[0][0] = 1;
    for(int i = 0; i < len;i++){
        for(int j = 0; j < 2;j++){
            if(!dp[i][j]) continue;
            
            for(int s1 = 0; s1 <= 1; s1++){
                for(int s2 = 0; s2 <= 1; s2++){
                    if(s1&s2) continue;
                    if(j){
                        add(dp[i+1][j],dp[i][j]);
                    }else{
                        if(s1+s2 < L[i]){
                            add(dp[i+1][1],dp[i][j]);
                        }else if(s1+s2 == L[i]){
                            add(dp[i+1][0],dp[i][j]);
                        }
                    }
                }
            }
        }
    }
    res = dp[len][0] + dp[len][1];
    res %= MOD;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // test();
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
