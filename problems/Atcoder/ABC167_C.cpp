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
 <url:https://atcoder.jp/contests/abc167/tasks/abc167_c>
 問題文============================================================
 C - Skill Up
 =================================================================
 解説=============================================================

 bit全探索で本を購入する全てのパターンについて見てやればいい

 https://atcoder.jp/contests/abc167/submissions/13143460

 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int N,M,X; cin >> N >> M >> X;
    vector<int> C(N);
    auto A = make_v<int>(N,M);

    for(int i = 0; i < N;i++){
        cin >> C[i];
        for(int j = 0; j < M;j++){
            cin >> A[i][j];
        }
    }

    res = LINF;
    for(int b = 0; b < (1<<N); b++){
        vector<int> sum(M);
        ll Csum = 0;
        for(int i = 0; i < N; i++){
            if((b>>i)&1){
                Csum += C[i];
                for(int j = 0; j < M;j++){
                    sum[j] += A[i][j];
                }
            }
        }

        bool ok = true;
        for(int j = 0; j < M;j++){
            if(sum[j] < X) ok = false;
        }
        if(ok) res = min(res,Csum);
    }
    if(res == LINF) res = -1;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
