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
 <url:https://atcoder.jp/contests/typical90/tasks/typical90_ak>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int W,N; cin >> W >> N;
    vector<int> L(N),R(N),V(N);
    for(int i = 0; i < N;i++){
        cin >> L[i] >> R[i] >> V[i];
    }

    auto dp = make_v<ll>(N+1,W+2);
    auto ok = make_v<int>(N+1,W+2);
    ok[0][0] = true;
    for(int i = 0; i < N;i++){
        vector<vector<ll>> emplace_val(W+2),erase_val(W+2);
        for(int j = W; j >= 0; j--){
            if(!ok[i][j]) continue;;
            int l = j + L[i], r = j + R[i];
            if(l > W) continue;
            r = min(r,W);

            emplace_val[l].emplace_back(dp[i][j]+V[i]);
            erase_val[r+1].emplace_back(dp[i][j]+V[i]);
        }

        multiset<ll> mst;
        for(int j = 0; j <= W;j++){
            for(auto v:emplace_val[j]){
                mst.emplace(v);
            }
            for(auto v:erase_val[j]){
                mst.erase(mst.lower_bound(v));
            }
            if(ok[i][j]){ // nanimo sinai
                dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
                ok[i+1][j] = true;
            }
            if(!mst.empty()){ // tukuru
                dp[i+1][j] = max({dp[i+1][j],dp[i][j],*mst.rbegin()});
                ok[i+1][j] = true;
            }
        }
    }

    // for(int j = 0; j <= W+1; j++){
    //     cout << setw(4) << j << " ";
    // }cout << endl;
    // for(int i = 0; i <= N; i++){
    //     for(int j = 0; j <= W+1; j++){
    //         cout << setw(4) << dp[i][j] << " ";
    //     }cout << endl;
    // }

    res = ok[N][W]?dp[N][W]:-1;
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    //solve<ll>(0);
    cout << fixed << setprecision(12) << solve<ll>() << endl;
    return 0;
}