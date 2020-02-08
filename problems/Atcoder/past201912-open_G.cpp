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
 <url:>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    ll N; cin >> N;
    vector<vector<ll>> A(N,vector<ll>(N,-LINF));
    for(int i = 0; i < N;i++){
        for(int j = i+1; j < N;j++){
            cin >> A[i][j];
        }
    }

    auto calc = [&](const vector<int>& g){
        ll T = 0;
        int nz = (int)g.size();
        for(int i = 0; i < nz;i++){
            for(int j = i+1; j < nz;j++){
                T += A[g[i]][g[j]];
            }
        }
        return T;
    };

    res = -LINF;
    function<void(int,vector<int>&,vector<int>&,vector<int>&)> dfs = [&](int n,vector<int>& g1,vector<int>& g2,vector<int>& g3){
        if(n == N){
            ll c1 = calc(g1);
            ll c2 = calc(g2);
            ll c3 = calc(g3);
            res = max(res,c1+c2+c3);
            return;
        }

        g1.push_back(n);
        dfs(n+1,g1,g2,g3);
        g1.pop_back();

        g2.push_back(n);
        dfs(n+1,g1,g2,g3);
        g2.pop_back();

        g3.push_back(n);
        dfs(n+1,g1,g2,g3);
        g3.pop_back();

        return;
    };
    vector<int> g1,g2,g3;
    dfs(0,g1,g2,g3);

    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
