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
 <url:https://atcoder.jp/contests/abc133/tasks/abc133_f>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 HL分解
 
 クエリを色ごとに処理することを考える
 ある色xに対してクエリが与えられるとき、
 HL分解後の配列に対して {辺のコスト, 色xであるかどうか}のクエリを持つSeg木を考える。
 
 Seg木の初期状態は{辺のコスト, 0 }としておき、
 色xに対するクエリを見た時に該当の辺の状態を{0, 1}に更新してRSQを取れば、
 色xを対象とした全てのクエリに答えることができる
 
 ================================================================
 */

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

template <typename Monoid>
struct SegmentTree {
public:
    using Type = typename Monoid::Type;
    int sz; // Array size
    vector<Type>node;
    SegmentTree(int n){
        sz = 1;
        while(sz < n) sz <<= 1;
        node.assign(2*sz,Monoid::id());
    }
    void set(int k,const Type& val){
        node[k+sz] = val;
    }
    void build(){
        for(int k = sz - 1; k > 0; k--){
            node[k] = Monoid::op(node[2*k],node[2*k+1]);
        }
    }
    inline void update(int k, const Type& val) {
        k += sz;
        node[k] = val;
        while (k >>= 1) {
            node[k] = Monoid::op(node[2*k], node[2*k+1]);
        }
    }
    inline Type query(int l, int r) {
        if (l >= r)return Monoid::id();
        Type vl = Monoid::id(), vr = Monoid::id();
        for (l += sz, r += sz; l != r; l >>= 1, r >>= 1) {
            if (l & 1)  vl = Monoid::op(vl, node[l++]);
            if (r & 1)  vr = Monoid::op(node[--r], vr);
        }
        return Monoid::op(vl, vr);
    }
    Type operator[](int i) { return node[i + sz]; }
};

struct Monoid {
    using Type = pll;/* Monoidに乗せる型 */
    static Type id() { return Type(); /* モノイドの初期値 */};
    
    // ================================================ //
    //                              マージ処理                               //
    // ================================================ //
    static Type op(const Type&l, const Type &r) {
        Type ret;
        
        ret.first = l.first + r.first;
        ret.second = l.second + r.second;
        
        return ret;
    }
};

using Item3 = tuple<int,int,int>;
vector<Item3> Color[100010];

using Item4 = tuple<int,int,int,int>;
vector<Item4> Qs[100010];


template<class Type>
Type solve(Type res = Type()){
    int N; cin >> N;
    int Q; cin >> Q;
    
    HLD hld(N);
    vector<int> as(N-1),bs(N-1),ds(N-1);
    for(int i = 0; i < N-1;i++){
        int a,b,c,d; cin >> a >> b >> c >> d;
        a--; b--; c--;
        
        as[i] = a; bs[i] = b; ds[i] = d;
        hld.add_edge(a, b);
        Color[c].push_back(Item3(a,b,d));
    }
    for(int i = 0; i < Q;i++){
        int x,y,u,v; cin >> x >> y >> u >> v;
        x--; u--; v--;
        Qs[x].push_back(Item4(y,u,v,i));
    }
    
    hld.build();
    SegmentTree<Monoid> ST(N);
    vector<ll> ans(Q);
    
    for(int i = 0; i < N-1;i++){
        hld.for_each_edge(as[i], bs[i], [&](int l,int r){
            ST.update(l,pll(ds[i],0));
        });
    }
    for(int c = 0; c < N; c++){
        for(auto e:Color[c]){
            int u,v; tie(u,v,ignore) = e;
            hld.for_each_edge(u, v, [&](int l,int r){
                ST.update(l,pll(0,1));
            });
        }
        
        for(auto query:Qs[c]){
            int y,u,v,i; tie(y,u,v,i) = query;
            pll ret_q = {0,0};
            hld.for_each_edge(u, v, [&](int l,int r){
                pll ret = ST.query(l, r+1);
                ret_q.first += ret.first;
                ret_q.second += ret.second;
            });
            ans[i] = ret_q.first + ret_q.second * y;
        }
        
        for(auto e:Color[c]){
            int u,v,d; tie(u,v,d) = e;
            hld.for_each_edge(u, v, [&](int l,int r){
                ST.update(l,pll(d,0));
            });
        }
    }
    for(auto a:ans){
        cout << a << endl;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve(0);
    // cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
