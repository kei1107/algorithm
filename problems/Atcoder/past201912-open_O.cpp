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
 <url:https://atcoder.jp/contests/past201912-open/tasks/past201912_o>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int N; cin >> N;
    auto A = make_v<ll>(N,6);
    vector<ll> vals;
    for(int i = 0; i < N;i++){
        for(auto& in:A[i]){ cin >> in; vals.emplace_back(in); }
        sort(A[i].begin(),A[i].end());
    }
    sort(vals.begin(),vals.end());
    vals.erase(unique(vals.begin(),vals.end()),vals.end());
    
    
    int n = (int)vals.size();
    vector<vector<int>> Idx(n+1);
    
    for(int i = 0; i < N;i++){
        for(int j = 0; j < 6;j++){
            A[i][j] = lower_bound(vals.begin(),vals.end(),A[i][j]) - vals.begin();
            Idx[A[i][j]].emplace_back(i);
        }
    }
    
    vector<double> tp(N,1);
    double max_tp = 1.0;
    vector<double> dp(n+1);
    for(int i = n; i >= 0; i--){
        dp[i] = max_tp;
        for(auto id:Idx[i]){
            tp[id] += dp[i]/6.0;
            max_tp = max(max_tp,tp[id]);
        }
    }
    
    for(int i = 0; i < N;i++){
        double p = 1;
        for(int j = 0; j < 6;j++){
            p += dp[A[i][j]]/6.0;
        }
        res = max(res,p);
    }
    
    
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<double>() << endl;
    return 0;
}
