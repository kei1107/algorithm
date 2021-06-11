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
 <url:https://atcoder.jp/contests/typical90/tasks/typical90_bc>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int N,S; cin >> N >> S;
    vector<int> A(N),B(N);
    for(int i = 0; i < N; i++) cin >> A[i] >> B[i];

    auto dp = make_v<int>(N+1,S+2);
    dp[0][0] = true;

    for(int i = 0; i < N;i++){
        for(int j = 0; j <= S; j++){
            if(!dp[i][j]) continue;
            dp[i+1][min(j+A[i],S+1)] = dp[i+1][min(j+B[i],S+1)] = true;
        }
    }

    if(!dp[N][S]) return "Impossible";

    int now = N, sum = S;
    while(now){
        if(sum-A[now-1] >= 0){
            if(dp[now-1][sum-A[now-1]]){
               sum = sum - A[now-1];
               now--;
               res += "A";
               continue;
            } 
        }
        if(sum-B[now-1] >= 0){
            if(dp[now-1][sum-B[now-1]]){
                sum = sum - B[now-1];
                now--;
                res += "B";
                continue;
            }
        }
        assert(false);
    }
    reverse(res.begin(),res.end());

    {
        int sum = 0;
        for(int i = 0; i < N;i++){
            sum += res[i]=='A'?A[i]:B[i];
        }
        assert(sum == S);
    }
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    //solve<ll>(0);
    cout << fixed << setprecision(12) << solve<string>() << endl;
    return 0;
}