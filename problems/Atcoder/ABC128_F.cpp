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
 <url:https://atcoder.jp/contests/abc128/tasks/abc128_f>
 問題文============================================================
 =================================================================
 解説=============================================================
 解説AC : https://img.atcoder.jp/abc128/editorial.pdf
 移動経路の式変形まではできたけど、dpの形に持って行くところまでいけなかった
 
 以下解説の抜粋
 
 制約より 0 < B < A <= N-1となる
 ここで、ゴールにたどりつけると仮定すると、その移動経路は非負整数kを用いて
 ０,A,AーB,２A-B,2A-2B,...,(k+1)A-kB
 となる。C=A-Bとすると
 ０,A,C,A+C,2*C,A+2C,...,A+kC
 さらにA+kC=N-1より、経路からAを消去すると
 0,(N-1)-kC,C,(N-1)-(k-1)Cm,...N-1
 となる。
 これはk,Cが決まれば一意に決まり, (k+1)C < N-1より、O(NlogN)で
 dp[k][C] := k,Cの時の得点
 dp[k+1][C] = dp[k][C] + S_{N-1-kC} + S_{kC}
 として解ける。（同じ座標を二度通らないように注意する）
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    ll N; cin >> N;
    vector<ll> s(N); for(auto& in:s) cin >> in;

    for(int C = 1; C < N;C++){
        map<ll,int> mp;
        ll dp = 0;
        for(int k = 1; k < N; k++){
            if((k+1)*C >= N-1) break;
            ll p1 = N-1-k*C;
            ll p2 = k*C;
            if(mp[p1]) break;
            mp[p1]++;
            if(mp[p2]) break;
            mp[p2]++;
            
            dp += s[N-1-k*C] + s[k*C];
            res = max(res,dp);
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
