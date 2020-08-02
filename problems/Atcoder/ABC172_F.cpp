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
 <url:https://atcoder.jp/contests/abc172/tasks/abc172_f>
 問題文============================================================
 F - Unfair Nim
 =================================================================
 解説=============================================================
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    ll N; cin >> N;
    vector<ll> A(N); for(auto& in:A) cin >> in;
    
    ll XOR = 0;
    for(int i = 2; i < N;i++){
        XOR ^= A[i];
    }
    ll X = XOR;
    ll a = 0,b = 0;
    
    auto check = [&](int dep){
        bool ok = true;
        
        ok &= ((a+b) <= (A[0] + A[1])) && (a <= A[0]);
        ok &= (A[0]+A[1]) <= (a+b+2*((1LL<<dep)-1));
        
        return ok;
    };
    function<ll(int)> dfs = [&](int dep){
        ll ret = LINF;
        if(dep == -1){
            if(A[0]>= a){
                if(A[0]-a == b-A[1]){
                    if(a!=0){
                        ret = A[0]-a;
                    }
                }
            }
        }else{
            if((X>>dep)&1){
                a |=  (1LL<<dep);
                if(check(dep)){
                    ret = min(ret,dfs(dep-1));
                }
                a &= ~(1LL<<dep);
                
                b |=  (1LL<<dep);
                if(check(dep)){
                    ret = min(ret,dfs(dep-1));
                }
                b &= ~(1LL<<dep);
            }else{
                if(check(dep)){
                    ret = min(ret,dfs(dep-1));
                }
                
                a |=  (1LL<<dep);
                b |=  (1LL<<dep);
                if(check(dep)){
                    ret = min(ret,dfs(dep-1));
                }
                a &= ~(1LL<<dep);
                b &= ~(1LL<<dep);

            }
        }
        return ret;
    };
    res = dfs(40);
    
    if(res == LINF) res = -1;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
