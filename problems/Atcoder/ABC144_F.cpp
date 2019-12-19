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
 <url:https://atcoder.jp/contests/abc144/tasks/abc144_f>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 dp[i] := 部屋iから部屋Nまでの移動回数の期待値を考える。
 
 このdpは後ろから更新していくことが容易に計算可能。
 
 通路を塞ぐ部屋iを決め打ちした時、塞ぐべき通路は
 部屋iから移動できる部屋jのうちdp[j]が最も高い通路である。
 
 よって
 1) 塞ぐ部屋を決め打ちする
 2) dpを計算する
 3) 最初の部屋の期待値を確認する
 を繰り返せばよく O(NM)で解ける
 
 提出：https://atcoder.jp/contests/abc144/submissions/9020807
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int N,M; cin >> N >> M;
    vector<vector<int>> G(N);
    for(int i = 0; i < M;i++){
        int s,t; cin >> s >> t;
        s--; t--;
        G[s].emplace_back(t);
    }
    
    res = LINF;
    for(int i = 0; i < N-1;i++){
        vector<double> dp(N,LINF);
        dp[N-1] = 0;
        for(int j = N-2; j>= 0; j--){
            double sump = 0;
            double maxp = 0;
            for(auto v:G[j]){
                sump += dp[v];
                maxp = max(maxp,dp[v]);
            }
            
            if(j == i && G[j].size() > 1){
                dp[j] = (sump-maxp)/(G[j].size()-1) + 1;
            }else{
                dp[j] = sump/G[j].size() + 1;
            }
        }
        res = min(res,dp[0]);
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<double>() << endl;
    return 0;
}
