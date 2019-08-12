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
 <url:https://codeforces.com/contest/1200/problem/D>
 問題文============================================================
 =================================================================
 解説=============================================================
 ある列or行みたときどこに消しゴムを使えばその列or行が白線になるかを二次元いもす使って数え上げ
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int n,k; cin >> n >> k;
    vector<vector<char>> masu(n,vector<char>(n));
    for(auto& vec:masu)for(auto& in:vec) cin >> in;

    vector<vector<ll>> cusum(n+1,vector<ll>(n+1));


    ll all_add = 0;
    // row
    for(int i = 0; i < n;i++){
        int l = INF,r = -INF;
        for(int j = 0; j < n;j++){
            if(masu[i][j] == 'B'){
                l = min(l,j);
                r = max(r,j);
            }
        }

        if(l == INF){
            all_add++;
            continue;
        }
        if(r-l >=k) continue;
        int uy = max(r-k+1,0);
        int ux = max(i-k+1,0);
        int ly = l;
        int lx = i;

        cusum[ux][uy]++;
        cusum[ux][ly+1]--;
        cusum[lx+1][uy]--;
        cusum[lx+1][ly+1]++;
    }

    // col
    for(int j = 0; j < n;j++){
        int l = INF,r = -INF;
        for(int i = 0; i < n;i++){
            if(masu[i][j] == 'B'){
                l = min(l,i);
                r = max(r,i);
            }
        }
        if(l == INF){
            all_add++;
            continue;
        }
        if(r-l >= k) continue;

        int uy = max(j-k+1,0);
        int ux = max(r-k+1,0);

        int ly = j;
        int lx = l;

        cusum[ux][uy]++;
        cusum[ux][ly+1]--;
        cusum[lx+1][uy]--;
        cusum[lx+1][ly+1]++;
    }

    for(int i = 0; i <= n;i++){
        for(int j = 1; j <= n;j++){
            cusum[i][j] += cusum[i][j-1];
        }
    }
    for(int j = 0; j <=n;j++){
        for(int i = 1; i <= n;i++){
            cusum[i][j] += cusum[i-1][j];
        }
    }




    for(int i = 0; i <= n;i++){
        for(int j = 0; j <= n;j++){
            res = max(res,cusum[i][j]+all_add);
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
