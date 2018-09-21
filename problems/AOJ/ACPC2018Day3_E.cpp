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
 <url:https://onlinejudge.u-aizu.ac.jp/services/room.html#ACPC2018Day3/problems/E>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 二重辺連結成分分解を行い、
 二重辺連結成分と橋を列挙する。
 
 ここで、連結成分内の辺を取り除くのが候補となる削除方法
 次に橋を取り除くのが候補となる削除方法となる
 
 前者は、全体の重みの合計から単純に辺の重みを引くだけなのでuku
 
 後者に関しては、
 連結成分を圧縮し（重みも圧縮して頂点に持たせる）てグループ同士を繋いだ木を構築、
 構築した木の各頂点を根とした部分木の重み（辺の重みも含む）をdfsで求めておくことによって
 橋を取り除いたときの左右の木の重みをO(1)で求めることができる.
 
 ================================================================
 */

class BCC{
private:
    typedef pair<int,int> pii;
    vector<vector<int>> G;
    
    vector<vector<int>> newG; // BCCのグループの頂点をひとまとめにして新たに作ったグラフ
    vector<pii> bridges; // 橋の列挙
    vector<int> group; // 各頂点が含まれるBCCの番号
    vector<vector<int>> each_bcc; //各BCCでまとまった配列
    vector<int> order; // 各頂点に訪れた順番
    stack<int> S; // 既に訪れた頂点のうち、まだどの二重辺連結成分にも割り振られていない頂点の集合
    vector<int> inS; // 集合Sに各頂点が含まれているかどうかの情報
    stack<int> roots; // 各二重辺連結成分を、DFS木の部分木として見た時の根の集合
    
    int N;
public:
    BCC(int _N){init(_N);}
    void init(int _N){
        N = _N;
        G.clear(); G.resize(N);
        bridges.clear();
        group.clear();
        each_bcc.clear();
        order.clear();
        inS.clear();
    }
    void add_edge(int u,int v){
        G[u].push_back(v);
        G[v].push_back(u);
    }
    void visit(int cur,int prev,int &k){
        order[cur] = k++;
        S.push(cur); inS[cur] = true; roots.push(cur);
        for(int i = 0; i < G[cur].size();i++){
            int v = G[cur][i];
            if(order[v] == -1) visit(v,cur,k);
            else if(v != prev && inS[v]){
                while(order[roots.top()] > order[v]) roots.pop();
            }
        }
        if(cur == roots.top()){
            if(prev != -1) bridges.push_back({min(prev,cur),max(prev,cur)});
            vector<int> bcc;
            while(true){
                int node = S.top(); S.pop();
                inS[node] = false;
                bcc.push_back(node);
                group[node] = (int)each_bcc.size();
                if(node == cur) break;
            }
            each_bcc.push_back(bcc);
            roots.pop();
        }
    }
    void fix(){
        order.assign(N,-1); inS.assign(N,0); group.assign(N,-1);
        while(S.size()) S.pop(); while(roots.size()) roots.pop();
        int k = 0;
        for(int i = 0; i < N;i++){
            if(order[i] == -1) visit(i,-1,k);
        }
        
        newG.resize(each_bcc.size());
        for(int u = 0; u < N;u++){
            for(int& v:G[u]){
                if(group[u] == group[v]) continue;
                newG[group[u]].push_back(group[v]);
                newG[group[v]].push_back(group[u]);
            }
        }
        for(int u = 0; u < each_bcc.size();u++){
            sort(newG[u].begin(),newG[u].end());
            newG[u].erase(unique(newG[u].begin(),newG[u].end()),newG[u].end());
        }
    }
    
    vector<vector<int>>& Get_each_bcc(){return each_bcc;}
    vector<int>& Get_group(){return group;}
    vector<pii>& Get_bridges(){ return bridges; }
    vector<vector<int>>& Get_Graph(){return newG; }
};


void tree_weight(ll n,int dep,vector<ll>& Ws,vector<int>& node_dep,vector<vector<pll>>& G){
    node_dep[n] = dep;
    for(const pll& p:G[n]){
        if(node_dep[p.first] != -1) continue;
        tree_weight(p.first, dep+1, Ws, node_dep, G);
        Ws[n] += Ws[p.first] + p.second;
    }
}
pll solve(){
    pll res = {LINF,LINF};
    int N,M; cin >> N >> M;
    
    BCC bcc(N);
    using edge = tuple<int,int,ll>;
    vector<edge> edges(M);
    
    ll sumw = 0;
    for(int i = 0; i < M;i++){
        int u,v; ll w; cin >> u >> v >> w;
        u--; v--;
        
        sumw += w;
        edges[i] = edge(u,v,w);
        bcc.add_edge(u, v);
    }
    bcc.fix();
    
    ll mincost = LINF;
    auto each_bcc = bcc.Get_each_bcc();
    auto group = bcc.Get_group();
    
    int g_sz = (int)each_bcc.size();
    
    vector<ll> Ws(each_bcc.size()); // BCCの重みの総和
    vector<vector<pll>> compG(g_sz);
    
    for(const edge& e:edges){
        int u,v; ll w; tie(u,v,w) = e;
        if(group[u] == group[v]){
            Ws[group[u]] += w;
            ll cost = sumw - w;
            if(mincost == cost){
                res = min(res,{min(u,v),max(u,v)});
            }else if(mincost > cost){
                mincost = cost;
                res = {min(u,v),max(u,v)};
            }
        }else{
            compG[group[u]].push_back(make_pair(group[v], w));
            compG[group[v]].push_back(make_pair(group[u], w));
        }
    }
    
    vector<int> node_dep(g_sz,-1);
    tree_weight(0,0, Ws, node_dep,compG);

    for(const edge& e:edges){
        int u,v; ll w; tie(u,v,w) = e;
        if(group[u] != group[v]){
            int gu = group[u], gv = group[v];
            if(node_dep[gu] < node_dep[gv]){
                swap(gu,gv); // gvがguの親となるように
            }
            ll costA = Ws[gu];
            ll costB = sumw - costA - w;
            ll cost = abs(costA-costB);
            if(mincost == cost){
                res = min(res,{min(u,v),max(u,v)});
            }else if(mincost > cost){
                mincost = cost;
                res = {min(u,v),max(u,v)};
            }
        }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    pll ans = solve();
    cout << ans.first +1 << " " << ans.second + 1 << endl;
    return 0;
}
