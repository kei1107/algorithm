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
 <url:https://atcoder.jp/contests/abc137/tasks/abc137_e>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 T分経過してゴールした時T*P枚のコインを支払うのではなく、一回の移動毎にP枚のコインを
 支払うと考える。
 そうするとこの問題は各辺に対してC-Pコスト支払う最長経路問題となる。
 よって、コストを負値として最短経路問題に落とし込んでベルマンフォードを行うことで求まる。
 注意事項としてNに到達できない点で生じる閉路を検出してしまう場合があるので検出しないように場合分けを行う。
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int N,M; cin >> N >> M;
    
    vector<vector<pll>> G(N);
    vector<vector<ll>> rG(N);
    
    ll P; cin >> P;
    for(int i = 0; i < M;i++){
        int A,B; cin >> A >> B;
        ll C; cin >> C;
        
        A--;B--;
        G[A].emplace_back(B,-(C-P));
        rG[B].emplace_back(A);
    }
    
    vector<bool> can_visit_to_N(N);
    function<void(int)> rec = [&](int n){
        if(can_visit_to_N[n]) return;
        can_visit_to_N[n] = true;
        for(auto next:rG[n]) rec((int)next);
    };
    rec(N-1);
    
    // bellman ford
    vector<ll> dist(N,LINF);
    dist[0] = 0;
    auto ok = [&](){
        for(int i = 0; i < N;i++){
            bool update = true;
            for(int v = 0; v < N;v++){
                if(dist[v] == LINF) continue;
                for(int j = 0; j < (int)G[v].size();j++){
                    ll next,cost; tie(next,cost) = G[v][j];
                    if(can_visit_to_N[next] && dist[next] > dist[v] + cost){
                        dist[next] = dist[v] + cost;
                        update = false;
                        if(i == N-1) return true;
                    }
                }
            }
            if(update) return false;
        }
        return false;
    }();
    
    if(ok) res = -1;
    else res = max(0LL,-dist[N-1]);
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
