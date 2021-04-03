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
 <url:https://atcoder.jp/contests/keyence2020/tasks/keyence2020_d>
 問題文============================================================
 D - Swap and Flip 
 =================================================================
 解説=============================================================
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int N; cin >> N;
    vector<int> A(N),B(N);
    for(auto& in:A) cin >> in;
    for(auto& in:B) cin >> in;

    auto dp = make_v<int>(1<<N,51);
    fill_v(dp,INF);

    dp[0][0] = 0;
    for(int bit = 0; bit < (1<<N); bit++){
        int cnt = __builtin_popcount(bit);

        for(int i = 0; i <= 50; i++){
            if(dp[bit][i] == INF) continue;
            int id = cnt;
            for(int j = 0; j < N;j++){
                if((bit>>j)&1) continue;
                int t = abs(j-cnt)%2 == 0 ? A[j] : B[j];

                if(t >= i){
                    dp[bit|(1<<j)][t]
                        = min(dp[bit|(1<<j)][t], dp[bit][i] + abs(id-cnt));
                }
                id++;
            }
        }
    }

    res = *min_element(dp.back().begin(),dp.back().end());
    if(res == INF) res = -1;
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    //solve<ll>(0);
    cout << fixed << setprecision(12) << solve<ll>() << endl;
    return 0;
}