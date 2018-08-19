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
 <url:https://yukicoder.me/problems/no/114>
 問題文============================================================
 =================================================================
 解説=============================================================
 T < 13であれば、ライブラリを張る。
 T >= 14であれば、
    部分集合v以外で使用する可能性のあるN-T個の点を全探索する
 ================================================================
 */


/*
 最小シュタイナー木 : http://www.prefield.com/algorithm/dp/steiner_tree.html
 
 無向グラフgに対して、指定した部分集合Tを全て連結にした木（シュタイナー木）を作る際に選択した
 辺の最小コストを返す
 
 Tのサイズは高々13,頂点数は40程度が限界？
 
 T : 部分集合配列（重複可能)
 g : グラフの隣接行列
 */
const ll MAX_V = 14;
const ll MAX_N = 40;
ll OPT[1<<MAX_V][MAX_N];
ll minimum_steiner_tree(const vector<int>& T,const vector<vector<ll>>& g){
    const int n = (int)g.size();
    const int numT = (int)T.size();
    if(numT <= 1) return 0;
    
    vector<vector<ll>> d(g);
    for(int i = 0; i < n;i++){
        for(int j = 0;j < n;j++){
            for(int k = 0; k < n;k++){
                d[j][k] = min(d[j][k],d[j][i]+d[i][k]);
            }
        }
    }
    
    for(int S = 0; S < (1<<numT);S++){
        for(int x = 0; x < n;x++){
            OPT[S][x] = INF; // or LINF
        }
    }
    
    for(int p = 0; p < numT;p++){
        for(int q = 0; q < n; q++){
            OPT[1<<p][q] = d[T[p]][q];
        }
    }
    
    for(int S = 1; S < (1<<numT);S++){
        if(!(S&(S-1))) continue;
        for(int p = 0; p < n;p++){
            for(int E = 0; E < S;E++){
                if((E|S)==S) OPT[S][p] = min(OPT[S][p],OPT[E][p]+OPT[S-E][p]);
            }
        }
        for(int p = 0; p < n;p++){
            for(int q = 0; q < n;q++){
                OPT[S][p] = min(OPT[S][p],OPT[S][q]+d[p][q]);
            }
        }
    }
    ll ret = INF;
    for(int S = 0; S < (1<<numT);S++){
        for(int q = 0; q < n;q++){
            ret = min(ret,OPT[S][q]+OPT[((1<<numT)-1)-S][q]);
        }
    }
    return ret;
}

struct edge{
    int u,v; ll cost;
    edge(int u = 0,int v = 0,ll cost = 0):u(u),v(v),cost(cost){}
};

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

ll solve(){
    ll res = LINF;
    int N,M,T; cin >> N >> M >> T;
    vector<vector<ll>> G(N,vector<ll>(N,INF));
    vector<edge> edges(M);
    
    for(int i = 0; i < N;i++) G[i][i] = 0;
    for(int i = 0; i < M;i++){
        int a,b; ll c; cin >> a >> b >> c;
        a--; b--;
        G[a][b] = G[b][a] = min(G[a][b],c);
        edges[i] = edge(a,b,c);
    }
    vector<int> t(T);
    for(int i = 0; i < T;i++){
        cin >> t[i]; t[i]--;
    }
    if(T < 14){
        res = minimum_steiner_tree(t, G);
    }else{
        sort(edges.begin(),edges.end(),[](const edge& e1,const edge& e2){return e1.cost < e2.cost;});
        
        ll cand_num = N-T;
        vector<ll> cands;
        vector<int> can_use(N);
        for(auto& v:t) can_use[v] = true;
        for(int v = 0; v < N;v++) if(!can_use[v]) cands.push_back(v);
        for(int i = 0; i < (1<<cand_num);i++){
            for(int j = 0; j < cand_num;j++) if((i>>j)&1) can_use[cands[j]] = true;
            
            // kruskal begin
            ll C = 0;
            UnionFind UF(N);
            for(int j = 0; j < M;j++){
                int u = edges[j].u,v = edges[j].v; ll cost = edges[j].cost;
                if(can_use[u] == false || can_use[v] == false) continue;
                if(UF.findSet(u, v)) continue;
                C += cost;
                if(res < C) break;
                UF.unionSet(u, v);
            }
            for(int i = 0; i < T;i++){
                if(!UF.findSet(t[0],t[i])){ C = INF; break;}
            }
            res = min(res,C);
            // kruskal end
            
            for(int j = 0; j < cand_num;j++) if((i>>j)&1) can_use[cands[j]] = false;
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
