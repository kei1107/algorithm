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
 <url:https://codeforces.com/contest/1287/problem/C>
 問題文============================================================
 C. Garland
 =================================================================
 解説=============================================================

 dp[i][j][k][l] := i番目の数字を見た時、これまで偶数の数字をj個、奇数の数字をk個使用しており、直前のパリティがlの時の最小複雑度

 でdpすればいい
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int n; cin >> n;
    vector<int> p(n);

    int cnt[2] = {};
    for(auto& in:p){
        cin >> in;
        if(in == 0) continue;
        cnt[in%2]++;
    }

    auto dp = make_v<int>(n+1,n+1,n+1,2);
    fill_v(dp,INF);

    dp[0][0][0][0] = dp[0][0][0][1] = 0;
    auto chmin = [&](int& a,const int x){
        a = min(a,x);
    };
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++){
            for(int k = 0; k < n;k++){

                for(int l = 0; l < 2;l++){
                    if(p[i] != 0){
                        chmin(dp[i+1][j][k][p[i]%2],dp[i][j][k][l]+(p[i]%2!=l));
                    }else{
                        chmin(dp[i+1][j+1][k][0],dp[i][j][k][l]+(l!=0));
                        chmin(dp[i+1][j][k+1][1],dp[i][j][k][l]+(l!=1));
                    }
                }
            }
        }
    }
    int need_even = n/2-cnt[0];
    int need_odd = (n+1)/2-cnt[1];

    res = min(dp[n][need_even][need_odd][0],dp[n][need_even][need_odd][1]);
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
