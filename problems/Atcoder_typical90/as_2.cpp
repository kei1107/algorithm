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
template<class T> ostream& operator << (ostream& out,const vector<T>& V){ for(size_t i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> >& Mat){ for(size_t i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T>& mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }
template<typename T>vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}
/*
 <url:https://atcoder.jp/contests/typical90/tasks/typical90_as>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int N,K; cin >> N >> K;
    vector<ll> X(N),Y(N);
    for(int i = 0; i < N;i++){
        cin >> X[i] >> Y[i];
    }
    auto calc = [&](int i,int j){
        return (X[i]-X[j])*(X[i]-X[j]) + (Y[i]-Y[j])*(Y[i]-Y[j]);
    };
    vector<ll> d(1<<N);
    for(int i = 0; i < (1<<N); i++){
        vector<int> id;
        for(int j = 0; j < N;j++){
            if((i>>j)&1) id.emplace_back(j);
        }

        for(int j = 0; j < (int)id.size(); j++){
            for(int k = j+1; k < (int)id.size(); k++){
                d[i] = max(d[i],calc(id[j],id[k]));       
            }
        }
    }

    auto dp = make_v<ll>(K+1,1<<N);
    fill_v(dp,LINF);

    dp[0][0] = 0;
    for(int k = 1; k <= K; k++){
        for(int b = 0; b < (1<<N); b++){
            for(int subb = b; subb != 0 ; subb = (subb - 1) & b){
                dp[k][b] = min(dp[k][b],max(dp[k-1][b-subb],d[subb]));
            }
        }
    }
    res = dp[K][(1<<N)-1];

    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    //solve<ll>(0);
    cout << fixed << setprecision(12) << solve<ll>() << endl;
    return 0;
}