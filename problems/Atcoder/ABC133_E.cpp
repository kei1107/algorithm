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
 <url:https://atcoder.jp/contests/abc133/tasks/abc133_e>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 ある頂点を見た時、その頂点で塗れる色の数は
 K - (その親と親からつながる頂点で色が塗られている頂点の個数)
 である。
 この時、ある親からつながる頂点で色が塗られている頂点の個数はdfsをしながら
 値を数えておくことができるので計算自体はO（1)で可能。
 
 よって、dfsで全頂点を巡りつつ計算を行えばいい
 ================================================================
 */

const ll MOD = 1e9+7;
template<class Type>
Type solve(Type res = Type()){
    ll N,K; cin >> N >> K;
    vector<vector<int>> G(N);
    for(int i = 0; i < N-1;i++){
        int u,v; cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    vector<ll> check_cnt(N);
    function<void(ll,ll)> rec = [&](ll n,ll pre){
        ll cnt = 0;
        if(pre != -1){
            cnt = check_cnt[pre] + 1;
        }
        (res *= max(K-cnt,0LL))%=MOD;
        for(auto next:G[n]){
            if(next == pre) continue;
            check_cnt[next]++;
            rec(next,n);
            check_cnt[n]++;
        }
    };
    
    res = 1;
    rec(0,-1);
    
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
