#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

/*
 <url:https://yukicoder.me/problems/no/235>
 問題文============================================================
 =================================================================
 解説=============================================================
 典型的なHL分解+Seg木問題
 
 ライブラリで殴る
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


const ll MAX_N = 10;
const ll MOD = 1e9+7;
ll Inv[MAX_N];
void Inv_init(){
    Inv[1] = 1;
    for(int i = 2; i < MAX_N; i++) {
        Inv[i] = Inv[MOD%i] * (MOD - MOD/i) % MOD;
    }
}

/*
 update : [s,t)にxを加算する
 query : [s,t) の総和を出力する
 */
const pll INIT = make_pair(0, 0);
struct SegTree {
    int N;
    pll init_v;
    vector<pll> node;
    vector<ll> lazy;
    
    SegTree(int _N):init_v(INIT) {
        N = 1;
        while (N < _N) N *= 2;
        node.resize(2 * N - 1, init_v);
        lazy.resize(2 * N - 1, 0);
    }
    
    void build(){
        for(int k = N - 2; k >= 0; k--){
            node[k] = merge(node[2*k+1],node[2*k+2]);
        }
    }
    
    pll merge(pll l,pll r){
        pll ret = INIT;
        ret.first = (l.first + r.first)%MOD;
        ret.second += (l.second + r.second)%MOD;
        return ret;
    }
    
    void lazy_evaluate(ll k) {
        lazy[k]%=MOD;
        (node[k].first += lazy[k]*node[k].second%MOD)%=MOD;
        if (k < N - 1) {
            (lazy[2 * k + 1] += lazy[k])%=MOD;
            (lazy[2 * k + 2] += lazy[k])%=MOD;
        }
        lazy[k] = 0;
    }
    
    /* [a,b) 引数の範囲に注意!! s~tまでを更新→update(s,t+1,~) */
    pll update(ll a, ll b, ll x) { return update(a, b, 0, 0, N, x); }
    pll update(ll a, ll b, int k, int l, int r, ll x) {
        if (r <= a || b <= l) {
            lazy_evaluate(k); // nodeを参照する前には必ず更新
            return node[k];
        }
        if (a <= l && r <= b) {
            (lazy[k] += x)%=MOD;
            lazy_evaluate(k);
            return node[k];
        }
        else {
            lazy_evaluate(k);
            pll vl = update(a, b, 2 * k + 1, l, (l + r) / 2, x);
            pll vr = update(a, b, 2 * k + 2, (l + r) / 2, r, x);
            return node[k] = merge(vl,vr);
        }
    }
    
    /* [a,b) 引数の範囲に注意!! */
    pll query(ll a, ll b) { return query(a, b, 0, 0, N); }
    pll query(ll a, ll b, ll k, ll l, ll r) {
        if (r <= a || b <= l) return init_v;
        if (a <= l && r <= b) {
            lazy_evaluate(k);
            return node[k];
        }
        else {
            lazy_evaluate(k);
            pll vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
            pll vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
            return merge(vl,vr);
        }
    }
};

void solve(){
    Inv_init();
    int N; cin >> N;
    vector<pll> SC(N);
    for(auto& in:SC) cin >> in.first;
    for(auto& in:SC) cin >> in.second;
    
    HLD hld(N);
    for(int i = 0; i < N-1;i++){
        ll A,B; cin >> A >> B; A--; B--;
        hld.add_edge(A, B);
    }
    hld.build();
    
    SegTree ST(N);
    for(int i = 0; i < N;i++){
        ST.node[hld.number[i] + ST.N - 1] = SC[i];
    }
    ST.build();
    ll Q; cin >> Q;
    auto query0 = [&](ll x,ll y,ll z){
        auto path = hld.getPath(x, y).first;
        for(auto p:path){
            ll l = p.first,r = p.second;
            ST.update(l,r+1,z);
        }
    };
    auto query1 = [&](ll x,ll y){
        auto path = hld.getPath(x, y).first;
        ll ret = 0;
        for(auto p:path){
            ll l = p.first, r = p.second;
            (ret += ST.query(l,r+1).first)%=MOD;
        }
        return ret;
    };
    
    while(Q--){
        int com; cin >> com;
        if(com == 0){
            ll X,Y,Z; cin >> X >> Y >> Z;
            X--; Y--;
            query0(X,Y,Z);
        }else{
            ll X,Y; cin >> X >> Y;
            X--; Y--;
            cout << query1(X,Y) << endl;
        }
    }
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
