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
 <url:https://atcoder.jp/contests/abc152/tasks/abc152_f>
 問題文============================================================
 F - Tree and Constraints
 =================================================================
 解説=============================================================
 余事象を考える。
 これは、「全ての制約について、パスが全て白く塗られている確率」
 を求めることになるが、制約が複数個あるのでそれぞれの対応関係を考えなければならない。
 ここで、Mが20以下なので包除原理で求めることができる。
 
 満たす制約を決めた時、決めた全ての制約上で通るパスの個数（パス重複する可能性があるので注意）xを求める。この時の確率は2^{N-1-x}となる。
 
 xの求め方は各制約についてO(N)でパスを事前に求めておけばいい
 
 https://atcoder.jp/contests/abc152/submissions/9627616
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    vector<ll> pow2(55);
    pow2[0] = 1;
    for(int i = 1; i < 55;i++){
        pow2[i] = pow2[i-1]*2;
    }
    
    int N; cin >> N;
    map<pii,ll> ids;
    int id = 0;
    vector<vector<int>> G(N+1);
    for(int i = 0; i < N-1;i++){
        int a,b; cin >> a >> b;
        
        if(a > b) swap(a,b);
        G[a].push_back(b);
        G[b].push_back(a);
        
        ids[pii(a,b)] = (1LL<<id);
        id++;
    }
    
    int M; cin >> M;
    vector<pii> rules(M);
    // vector<vector<pii>> Path(M);
    vector<ll> Mask(M);
    function<ll(ll,ll,ll,ll)> rec = [&](ll n,ll pre,ll target,ll mask){
        if(n == target) return mask;
        for(auto next:G[n]){
            if(next == pre) continue;
            ll v1 = n, v2 = next;
            if(v1 > v2) swap(v1,v2);
            
            auto ret = rec(next,n,target,mask + ids[pii(v1,v2)]);
            if(ret == -1) continue;
            return ret;
        }
        return -1LL;
    };
    for(int i = 0; i < M;i++){
        ll u,v; cin >> u >> v;
        rules[i] = pii(u,v);
        Mask[i] = rec(u,-1,v,0);
    }
    //cout << Path << endl;
    for(int b = 1; b < (1<<M); b++){
        // set<pii> st;
        int cnt = 0;
        ll V = 0;
        for(int i = 0; i < M;i++){
            if((b>>i)&1){
                cnt++;
                V |= Mask[i];
                // for(auto p:Path[i]) st.insert(p);
            }
        }
        
        ll num = __builtin_popcountl(V);
        
        if(cnt %2 == 1){
            res += pow2[N-1-num];
        }else{
            res -= pow2[N-1-num];
        }
    }
    res = pow2[N-1] - res;
    
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
