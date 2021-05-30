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
 <url:https://atcoder.jp/contests/typical90/tasks/typical90_ai>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */

struct Monoid {
    using Type = ll;/* Monoidに乗せる型 */
    static Type id() { return  0; /* モノイドの初期値 */};
    static Type Nid() { return LINF; /* 遅延評価時の初期値 */}
    static Type Qid() { return  0; /* 範囲外クエリ処理時の値 */}
    
    // ================================================ //
    //                              マージ処理                               //
    // ================================================ //
    
    // 要素と要素のマージ
    static Type op1(const Type&l, const Type &r) {
        Type ret;
        ret = l + r;
        return ret;
    }
    
    // 要素と作用素のマージ
    static Type op2(const Type&l, const Type &r) {
        Type ret;
        ret = r;
        return ret;
    }
    
    // 作用素と作用素のマージ
    static Type op3(const Type&l, const Type &r) {
        Type ret;
        ret = r;
        return ret;
    }
    
    // 作用素を下に降ろす時に行う演算
    // (第一引数は作用素のもとの値, 第二引数は降ろした後の区間の長さ)
    static Type op4(const Type&l, const int &r) {
        Type ret;
        ret = l * r; // sum : 区間の長さ分だけ乗算
        return ret;
    }
};


/*
 HL-Decomposition
 */
struct HLD{
    typedef int TYPE;
    typedef pair<TYPE,TYPE> PTT;
    TYPE V; // 頂点数
    TYPE root; // 根の頂点番号
    vector<vector<TYPE>> G;
    // parent : 親
    // Hchild : Heavy Childの頂点番号
    // number : 新しく割り当てた頂点番号
    // id :  割り当て直した数字の元のノード番号 (id[number[pos]] = pos)
    // group : 各ノードが属するグループ番号
    // depth : 各頂点の深さ
    vector<TYPE> parent,Hchild,number,id,group,depth;
    vector<PTT> paths; // [u,v]間の経路を分解(最大でもlogN)
    vector<PTT> Ledges; // pathsを結ぶライドエッジ
    
    HLD() {root = V = -1; }
    HLD(TYPE V):
    V(V),root(0),G(V),parent(V,-1),Hchild(V,-1),number(V,-1),id(V,-1),group(V,-1),depth(V,0){}
    void init(TYPE V){
        V = V; root = 0;
        G.clear(); parent.clear(); Hchild.clear(); number.clear();
        id.clear(); group.clear(); depth.clear();
        G.resize(V); parent.assign(V,-1); Hchild.assign(V,-1);
        number.assign(V,-1); id.assign(V,-1); group.assign(V,-1); depth.assign(V,0);
    }
    
    void add_edge(TYPE u,TYPE v){ G[u].push_back(v); G[v].push_back(u);}
    void build(TYPE _root = 0){
        root = _root;
        int num = 0;
        dfs1(); init_number(num); dfs2();
    }
    TYPE dfs1(TYPE pos = -1,TYPE pre = -1){
        if(pos == -1) pos = root;
        TYPE maxw = -1, weight = 1;
        for(TYPE next:G[pos]){
            if(next == pre) continue;
            TYPE child_weight = dfs1(next,pos);
            weight += child_weight;
            if(maxw < child_weight){ Hchild[pos] = next; maxw = child_weight; }
        }
        return weight;
    }
    void dfs2(TYPE pos = -1,TYPE pre = -1,TYPE dep = 0,TYPE g = -1){
        if(pos == -1) pos = g = root;
        parent[pos] = pre; depth[pos] = dep; group[pos] = g;
        for(TYPE next:G[pos]){
            if(next == pre) continue;
            dfs2(next,pos,dep+1,Hchild[pos]==next?g:next);
        }
    }
    void init_number(int& num,TYPE pos = -1,TYPE pre = -1){
        if(pos == -1) pos = root;
        number[pos] = num++;
        id[number[pos]] = pos;
        if(Hchild[pos] >= 0) init_number(num,Hchild[pos],pos);
        for(TYPE next:G[pos]){
            if(next != pre && next != Hchild[pos]) init_number(num,next,pos);
        }
    }
    
    void buildPaths(TYPE u,TYPE v){
        if(depth[group[u]] < depth[group[v]]) swap(u,v);
        TYPE num_u=number[u], num_v=number[v];
        if(same(u,v)){ paths.push_back({min(num_u,num_v),max(num_u,num_v)}); return;}
        TYPE group_u = group[u];
        buildPaths(parent[group_u],v);
        paths.push_back({number[group_u], number[u]});
        Ledges.push_back({number[parent[group_u]], number[group_u]});
    }
    
    TYPE lca(TYPE u,TYPE v){
        if(depth[group[u]] < depth[group[v]]) swap(u,v);
        if(same(u,v)) return depth[u] < depth[v]?u:v;
        return lca(parent[group[u]],v);
    }
    TYPE distance(TYPE u,TYPE v){
        return depth[u] + depth[v] - 2*depth[lca(u,v)];
    }
    
    // u<->vへのパス、u<->vをつなぐライトエッジを返却
    pair<vector<PTT>,vector<PTT>> getPath(TYPE u,TYPE v){
        paths.clear(); Ledges.clear();
        buildPaths(u,v);
        return make_pair(paths,Ledges);
    }
    
    void for_each_edge(int u,int v,const function<void(int,int)>& f){
        paths.clear(); Ledges.clear();
        buildPaths(u, v);
        
        paths[0].first++;
        for(auto path:paths){
            if(path.first > path.second) continue;
            f(path.first,path.second);
        }
    }
    
    bool same(TYPE a,TYPE b){return group[a] == group[b];}
};

template<class Type>
Type solve(Type res = Type()){
    int N; cin >> N;
    vector<vector<int>> T(N);
    vector<int> Tid(N,-1);
    HLD hld(N);
    for(int i = 0; i < N-1;i++){
        int A,B; cin >> A >> B;
        A--; B--;
        hld.add_edge(A,B);
        T[A].emplace_back(B);
        T[B].emplace_back(A);
    }
    hld.build();

    auto dfs = [&](auto self,int n,int pre = -1,int& idx) -> void{
        Tid[n] = idx++;

        for(auto next:T[n]){
            if(next == pre) continue;
            self(self,next,n,idx);
        }
    };
    int idx = 0;
    dfs(dfs,0,-1,idx);
    
    int Q; cin >> Q;
    while(Q--){
        int K; cin >> K;
        vector<pii> V(K); 
        for(int i = 0; i < K;i++){
            int v; cin >> v;
            v--;
            V[i] = {Tid[v],v};
        }
        sort(V.begin(),V.end());
        ll ans = 0;
        for(int i = 0; i < K;i++){
            ans += hld.distance(V[i].second,V[(i+1)%K].second);
        }
        ans /= 2;
        cout << ans << endl;
    }

    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    solve<ll>(0);
    // cout << fixed << setprecision(12) << solve<ll>() << endl;
    return 0;
}