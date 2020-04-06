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
 <url:https://atcoder.jp/contests/abc157/tasks/abc157_d>
 問題文============================================================
 D - Friend Suggestions
 =================================================================
 解説=============================================================

 UnionFindを用いて友達関係で繋がるグラフのグループを作っておく。
 ある人uについてみたとき、
 まず、友達関係のグラフ上での友達候補の人数は (グループの人数) - (uの友達) - 1(自分自身)
 となる。その後、ブロックしている人の個数を引けば答えが得られる。
 これは、前述のUnionFindを用いてブロック関係の人が同じグループに属するか否かを都度判定していけばいい。

 https://atcoder.jp/contests/abc157/submissions/11577477
 ================================================================
 */

/*
 UnionFind
 */
struct UnionFind {
    vector<int> data;
    UnionFind(int size) : data(size, -1) { }
    bool unionSet(int x, int y) {
        x = root(x); y = root(y);
        if (x != y) {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y]; data[y] = x;
        }
        return x != y;
    }
    bool findSet(int x, int y) {
        return root(x) == root(y);
    }
    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    int size(int x) {
        return -data[root(x)];
    }
};

template<class Type>
Type solve(Type res = Type()){
    int N,M,K; cin >> N >> M >> K;

    UnionFind UF(N);
    vector<vector<int>> FG(N);
    for(int i = 0; i < M; i++){
        int A,B; cin >> A >> B;
        A--; B--;
        UF.unionSet(A,B);

        FG[A].emplace_back(B);
        FG[B].emplace_back(A);
    }

    vector<vector<int>> BG(N);
    for(int i = 0; i < K; i++){
        int C,D; cin >> C >> D;
        C--; D--;

        BG[C].emplace_back(D);
        BG[D].emplace_back(C);
    }
    for(int i = 0; i < N;i++) sort(BG[i].begin(),BG[i].end());

    res = vector<ll>(N);
    for(int u = 0; u < N;u++){
        res[u] = UF.size(u) - 1;
        res[u] -= FG[u].size();

        for(auto v:BG[u]){
            res[u] -= UF.findSet(u,v);
        }
    }

    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<vector<ll>>() << endl;
    return 0;
}
