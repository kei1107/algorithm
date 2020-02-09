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

/*
 使い方:イメージはこれがわかりやすい<https://ei1333.hateblo.jp/entry/2018/05/29/011140>
 HLDの構成はいつもの形
 
 HLD後の頂点番号はnumberに格納されるので、初期化等はこれを用いる
 
 getPathでu<->vへのパス、u<->vをつなぐライトエッジを返却する。
 各頂点に対して操作を行うときは u<->vへのパスをそのまま使う
 
 各辺に対して操作を行うときは u<->vへのパスの最初の辺の開始点が余分になる為+1する
 具体的には
 auto path = hld.getPath(0,u).first;
 path[0].first++;
 
 また、経路構成時の辺はある頂点からその親への移動が基となるように作られているので、
 辺u<->parent[u]に対して何かしらの初期値を与えたい場合はuすなわちnumber[u]に対して値を載せておく
 
 ex.
 ライトエッジは (parent[i],u)で与えられる
 ヘビーエッジは(parent[parent[...parent[u]...]],u)
 ※これは新しく割り当てた頂点番号で与えられるので注意
 
 
 https://ei1333.hateblo.jp/entry/2018/05/29/011140の例だと
 HLD hld(13);
 hld.add_edge(0, 1);
 hld.add_edge(0, 2);
 hld.add_edge(0, 3);
 hld.add_edge(1, 4);
 hld.add_edge(1, 5);
 hld.add_edge(4, 8);
 hld.add_edge(4, 9);
 hld.add_edge(2, 6);
 hld.add_edge(6, 10);
 hld.add_edge(6, 11);
 hld.add_edge(6, 12);
 hld.add_edge(3, 7);
 
 hld.build();
 
 cout << "parent" << endl;
 // -1 0 0 0 1 1 2 3 4 4 6 6 6
 cout << "number" << endl;
 // 0 1 6 11 2 5 7 12 3 4 8 9 10
 cout << "id" << endl;
 // 0 1 4 8 9 5 2 6 10 11 12 3 7
 
 auto ps = hld.getPath(4, 12);
 
 cout << ps.first << endl; // (0,2) (6,7) (10,10)
 
 cout << ps.second << endl; // (0,6) (7,10)
 cout << "===" << endl;
 ps = hld.getPath(12, 10);
 cout << ps.first << endl; // (7,8) (10,10)
 cout << ps.second << endl; // (7,10)
 
  でおおよそ分かる
 */
// ================================= //
// use example


// LCA : http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C&lang=jp
void GRL_5_C(){
    ll n; cin >> n;
    HLD hld(n);
    for(int i = 0; i < n;i++){
        ll k; cin >> k;
        for(int j = 0; j < k;j++){
            ll c; cin >> c;
            hld.add_edge(i, c);
        }
    }
    hld.build();
    ll q; cin >> q;
    while(q--){
        ll u,v; cin >> u >> v;
        cout << hld.lca(u,v) << endl;
    }
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D&lang=jp
void GRL_5_D(){
    ll n; cin >> n;
    HLD hld(n);
    for(int i = 0; i < n;i++){
        ll k; cin >> k;
        for(int j = 0; j < k;j++){
            ll c; cin >> c;
            hld.add_edge(i, c);
        }
    }
    hld.build();
    SegTree ST(n); // RAQ_RSQ
    
    // add(v,w): 節点 v の親と、節点 v の間にある辺の重みを w 増加させる
    auto query0=[&](ll u,ll w){
        auto path = hld.getPath(hld.parent[u], u).first; // 割り当てられた辺の番号が返却
        path[0].first++; // 今回の実装ではroot->rootへの自己辺（番号 0）が存在するため、seg木でその番号を見ないようにする
        for(auto p:path){
            ll l = p.first, r = p.second;
            ST.update(l,r+1,w); // 該当する辺に対して重みを増加
        }
    };
    
    // getSum(u) : 根から節点 u までの間にある辺の重みの総和を報告する。
    auto query1 = [&](ll u){
        auto path = hld.getPath(0,u).first;
        path[0].first++;
        ll ret = 0;
        for(auto p:path){
            ll l = p.first, r = p.second;
            ret += ST.query(l,r+1);
        }
        return ret;
    };
    
    ll q; cin >> q;
    while(q--){
        ll com; cin >> com;
        if(com == 0){
            ll v,w; cin >> v >> w;
            query0(v,w);
        }else{
            ll u; cin >> u;
            cout << query1(u) << endl;
        }
    }
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_E&lang=jp
void GRL_5_E(){
    ll n; cin >> n;
    HLD hld(n);
    for(int i = 0; i < n;i++){
        ll k; cin >> k;
        for(int j = 0; j < k;j++){
            ll c; cin >> c;
            hld.add_edge(i, c);
        }
    }
    hld.build();
    SegTree ST(n); // RAQ_RSQ
    
    // add(v,w): 節点 v の親と、節点 v の間にある辺の重みを w 増加させる
    auto query0=[&](ll u,ll w){
        auto path = hld.getPath(0, u).first;
        path[0].first++;
        for(auto p:path){
            ll l = p.first, r = p.second;
            ST.update(l,r+1,w);
        }
    };
    
    // getSum(u) : 根から節点 u までの間にある辺の重みの総和を報告する。
    auto query1 = [&](ll u){
        auto path = hld.getPath(0,u).first;
        path[0].first++;
        ll ret = 0;
        for(auto p:path){
            ll l = p.first, r = p.second;
            ret += ST.query(l,r+1);
        }
        return ret;
    };
    
    ll q; cin >> q;
    while(q--){
        ll com; cin >> com;
        if(com == 0){
            ll v,w; cin >> v >> w;
            query0(v,w);
            
            // or
            
            hld.for_each_edge(0, v, [&](int l,int r){
                ST.update(l,r+1,w);
            });
            
        }else{
            ll u; cin >> u;
            cout << query1(u) << endl;
            
            // or
            
            ll ans = 0;
            hld.for_each_edge(0, u, [&](int l,int r){
                ans += ST.query(l,r+1);
            });
            cout << ans << endl;
        }
    }
}

// https://codeforces.com/contest/1296/problem/F
void codeforces_Round617_F(){
    int n; cin >> n;
    map<pii,int> mp;
    for(int i = 0; i < n-1;i++){
        int a,b; cin >> a >> b;
        a--; b--;
        if(a > b) swap(a,b);
        mp[pii(a,b)] = i;
    }
    
    int m; cin >> m;
    using Item = tuple<int,int,int>;
    vector<Item> query(m);
    for(int i = 0; i < m;i++){
        int a,b,g; cin >> a >> b >> g;
        a--; b--;
        if(a > b) swap(a,b);
        query[i] = Item(g,a,b);
    }
    sort(query.begin(),query.end());
    
    HLD hld(n);
    for(auto p:mp){
        hld.add_edge(p.first.first, p.first.second);
    }
    hld.build();
    
    SegTree ST(n); // RUQ_RM(in)Q
    for(auto q:query){
        int g,a,b; tie(g,a,b) = q;
        
        auto f = [&](int u,int v){
            ST.update(u,v+1,g);
        };
        hld.for_each_edge(a, b, f);
    }
    
    bool ng = false;
    for(auto q:query){
        int g,a,b; tie(g,a,b) = q;
        
        ll MIN = LINF;
        auto f = [&](int u,int v){
            MIN = min(MIN,ST.query(u,v+1));
        };
        hld.for_each_edge(a, b, f);
        
        if(g < MIN){
            ng = true;
            break;
        }
    }
    
    if(ng){
        return vector<ll>{-1};
    }
    vector<ll> ans(n-1);
    for(auto p:mp){
        int id = p.second;
        int u,v; tie(u,v) = p.first;
        
        auto f = [&](int u,int v){
             ans[id] = ST.query(u,v+1);
        };
        hld.for_each_edge(u, v, f);
        
        if(ans[id] == INIT) ans[id] = 1;
    }
    cout << ans << endl;
    
}

void test(){
    ll n; cin >> n;
    HLD hld(n);
    for(int i = 0; i < n;i++){
        ll k; cin >> k;
        for(int j = 0; j < k;j++){
            ll c; cin >> c;
            hld.add_edge(i, c);
        }
    }
    hld.build();

    auto query=[&](ll u){
        auto paths = hld.getPath(0, u);
        auto path = paths.first;
        
        cout << "path l r ==============" << endl;
        for(auto p:path){
            ll l = p.first, r = p.second;
            cout << l << " " << r << endl;
        }
        auto ledge = paths.second;
        cout << "ledge l r ==============" << endl;
        for(auto e:path){
            ll l = e.first, r = e.second;
            cout << l << " " << r << endl;
        }
    };
    
    ll q; cin >> q;
    while(q--){
        ll u; cin >> u;
        query(u);
    }
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    //GRL_5_C();
    //GRL_5_D();
    //GRL_5_E();
    // codeforces_Round617_F()
    test();
    return 0;
}
