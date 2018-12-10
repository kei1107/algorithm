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
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

/*
 <url:https://yukicoder.me/problems/no/399>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 HL分解じゃなくてもできるっぽいけど、
 まぁ問題見た感じHL分解＋区間addっぽかったのでえいした
 ================================================================
 */

// HL-Decomposition
struct HLD{
    typedef ll TYPE;
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
    
    // u<->vへのパス　、　u<->vをつなぐライトエッジを返却
    pair<vector<PTT>,vector<PTT>> getPath(TYPE u,TYPE v){
        paths.clear(); Ledges.clear();
        buildPaths(u,v);
        return make_pair(paths,Ledges);
    }
    bool same(TYPE a,TYPE b){return group[a] == group[b];}
};

/*
 update : [s,t)にxを加算する
 query : [s,t) の総和を出力する
 */
const ll INIT = 0;
struct SegTree {
    int N;
    ll init_v;
    vector<ll> node, lazy;
    
    SegTree(int _N):init_v(INIT) {
        N = 1;
        while (N < _N) N *= 2;
        node.resize(2 * N - 1, init_v);
        lazy.resize(2 * N - 1, init_v);
    }
    
    ll merge(ll l,ll r){
        return l + r;
    }
    void build(){
        for(int k = N - 2; k >= 0; k--){
            node[k] = merge(node[2*k+1],node[2*k+2]);
        }
    }
    void direct_update(int k,ll v){
        node[k+N-1] = v;
    }
    
    void lazy_evaluate(int k) {
        node[k] += lazy[k]; // add のため加算
        if (k < N - 1) {
            lazy[2 * k + 1] += lazy[k] / 2; // add のため加算
            lazy[2 * k + 2] += lazy[k] / 2;
        }
        lazy[k] = 0;
    }
    
    /* [a,b) 引数の範囲に注意!! s~tまでを更新→update(s,t+1,~) */
    ll update(int a, int b, ll x) { return update(a, b, 0, 0, N, x); }
    ll update(int a, int b, int k, int l, int r, ll x) {
        if (r <= a || b <= l) {
            lazy_evaluate(k); // nodeを参照する前には必ず更新
            return node[k];
        }
        if (a <= l && r <= b) {
            lazy[k] += (r - l) * x; // 参照区間が指定区間を完全に含んでいれば, 参照区間長*加算値分nodeに加算される
            lazy_evaluate(k);
            return node[k];
        }
        else {
            lazy_evaluate(k);
            ll vl = update(a, b, 2 * k + 1, l, (l + r) / 2, x);
            ll vr = update(a, b, 2 * k + 2, (l + r) / 2, r, x);
            return node[k] = merge(vl,vr);
        }
    }
    
    /* [a,b) 引数の範囲に注意!! */
    ll query(int a, int b) { return query(a, b, 0, 0, N); }
    ll query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return init_v;
        if (a <= l && r <= b) {
            lazy_evaluate(k);
            return node[k];
        }
        else {
            lazy_evaluate(k);
            ll vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
            ll vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
            return merge(vl,vr);
        }
    }
};


ll solve(){
    ll res = 0;
    int N; cin >> N;
    HLD hld(N);
    for(int i = 0; i < N-1;i++){
        int u,v; cin >> u >> v;
        u--; v--;
        hld.add_edge(u, v);
    }
    hld.build();
    
    SegTree ST(N);
    
    auto query = [&](int u,int v){
        auto path = hld.getPath(u, v).first;
        ll ret = 0;
        for(auto p:path){
            ret += ST.query(p.first,p.second+1) + (p.second-p.first+1);
            ST.update(p.first, p.second+1, 1);
        }
        return ret;
    };
    int Q; cin >> Q;
    while(Q--){
        int A,B; cin >> A >> B;
        A--; B--;
        res += query(A,B);
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
