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
 <url:https://atcoder.jp/contests/abc148/tasks/abc148_f>
 問題文============================================================
 F - Playing Tag on Tree
 =================================================================
 解説=============================================================
 この問題における最適な動きを考えた時
 青木くん => 高橋くんに近づいていく
 高橋くん => 青木くんに近づけるだけ近づいたあとひたすら逃げる
 が最適となる。
 
 高橋くんの行動を
 1)青木くんにできるだけ近づく
 2)青木くんからひたすら逃げる
 の2パターンに分けた時
 1) 青木-高橋間のパスを見つけて近づける
 2) 1)の状態の青木君の頂点を始点として最も遠い頂点へ移動する
 とすればいいので書く。
 （この時、最初の青木-高橋間の距離が偶数の場合は最後に青木君が行動してゲームが終了するので答えが+1される, sample 1）
 
 https://atcoder.jp/contests/abc148/submissions/9079147
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int N,u,v; cin >> N >> u >> v;
    u--; v--;
    vector<vector<int>> G(N);
    for(int i = 0; i < N-1;i++){
        int A,B; cin >> A >> B;
        A--; B--;
        G[A].push_back(B);
        G[B].push_back(A);
    }
    vector<int> order;
    function<bool(int,int)> path_check = [&](int n,int pre){
        order.push_back(n);

        if(n == v) return true;
        for(auto next:G[n]){
            if(next == pre) continue;
            if(path_check(next,n)) return true;
        }
        order.pop_back();
        return false;
    };
    path_check(u,-1);

    int l = 0, r = (int)order.size()-1;
    while(r-l>2){
        l++;
        r--;
        res++;
    }
    u = order[l];
    v = order[r];

    int ng_idx = v;
    if(r-l==2){
        res++;
        ng_idx = order[l+1];
    }

    vector<ll> dist(N,LINF);
    dist[u] = 0;
    priority_queue<pll> pq;
    pq.push(pll(0,u));
    while(pq.size()){
        ll c,n; tie(c,n) = pq.top(); pq.pop();
        if(dist[n] < -c) continue;
        for(auto next:G[n]){
            if(next == ng_idx) continue;
            if(dist[next] > dist[n] + 1){
                dist[next] = dist[n] + 1;
                pq.push(pll(-dist[next],next));
            }
        }
    }
    ll maxdist = 0;
    for(int i = 0; i < N;i++){
        if(dist[i] == LINF) continue;
        maxdist = max(maxdist,dist[i]);
    }
    res += maxdist;

    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
