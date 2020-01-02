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
 <url:https://atcoder.jp/contests/abc147/tasks/abc147_f>
 問題文============================================================
 F - Sum Difference
 =================================================================
 解説=============================================================

 解説みた。
 きちんと考えれば解けたかもしれないけど、これは難しみ
 ================================================================
 */


template<class Type>
Type solve(Type res = Type()){
    ll N,X,D; cin >> N >> X >> D;

    if(D == 0){
        res = X==0?1:N+1;
    }else{
        if(D < 0){
            X = -X;
            D = -D;
        }
        
        auto MOD = [](ll x,ll m){
            return (x%m + m)%m;
        };
        map<ll,vector<pll>> secs;
        
        for(ll k = 0; k <= N;k++){
            // 取れる区間
            ll L = (k-1)*k/2;
            ll R = N*k - k*(k+1)/2;

            secs[MOD(k*X,D)].emplace_back(k*X/D+L,k*X/D+R);
        }
        
        for(auto& ps:secs){
            auto V = ps.second;
            sort(V.begin(),V.end());
            
            ll left = numeric_limits<ll>::min();
            
            for(auto sec:V){
                left = max(left,sec.first-1);
                res += max(0LL,sec.second-left);
                left = max(left,sec.second);
            }
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
