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
 <url:https://atcoder.jp/contests/arc016/tasks/arc016_3>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int N,M; cin >> N >> M;

    vector<vector<pii>> C(M);
    vector<ll> cost(M);
    for(int i = 0; i < M;i++){
        int Cnum;
        cin >> Cnum >> cost[i];
        for(int j = 0; j < Cnum;j++){
            int idol,p; cin >> idol >> p;
            idol--;
            C[i].emplace_back(idol,p);
        }
    }
    
    vector<double> dp(1<<N,DBL_MAX);
    dp.back() = 0;
    for(int i = (1<<N)-2; i >= 0; i--){
        for(int j = 0; j < M;j++){
            int have_p = 0;
            for(auto info:C[j]){
                int idol,p; tie(idol,p) = info;
                if((i>>idol)&1) have_p += p;
            }
            if(have_p == 100) continue;
            
            double not_have_p = (100-have_p)/100.0;
            double t_cost = cost[j]/not_have_p;
            
            for(auto info:C[j]){
                int idol,p; tie(idol,p) = info;
                if((i>>idol)&1) continue;
                
                t_cost += 1.0*p/(100-have_p) * dp[i|(1<<idol)];
            }
            dp[i] = min(dp[i],t_cost);
        }
    }
    res = dp.front();
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<double>() << endl;
    return 0;
}
