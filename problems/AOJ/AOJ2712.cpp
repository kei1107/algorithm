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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2712>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 二重辺連結成分分解してしまえば、木として扱えることがわかる。
 ここで、あるグループの頂点数が3点以上あつ待ったグループがあれば、
 根に戻ることができるという点に注意してdpを行えば良い
 
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

void rec(ll n,ll prev,
         vector<vector<int>>& G,
         vector<ll>& Cost,
         vector<vector<int>>& each_bcc,
         vector<ll>& dp1,vector<ll>& dp2){
    for(auto& next:G[n]){
        if(next == prev) continue;
        rec(next,n,G,Cost,each_bcc,dp1,dp2);
        dp1[n] += dp1[next];
    }
    ll T = dp1[n];
    if(dp1[n] || each_bcc[n].size() > 1) dp1[n] += Cost[n];
    for(auto& next:G[n]){
        if(next == prev) continue;
        dp2[n] = max(dp2[n],T-dp1[next]+dp2[next]);
    }
    dp2[n] += Cost[n];
}
ll solve(){
    int N,M; cin >> N >> M;
    vector<int> w(N); for(auto& in:w) cin >> in;
    BCC bcc(N);
    for(int i = 0; i < M;i++){
        int u,v; cin >> u >> v; u--; v--;
        bcc.add_edge(u, v);
    }
    bcc.fix();
    auto group = bcc.Get_group();
    auto G = bcc.Get_Graph();
    auto each_bcc = bcc.Get_each_bcc();
    vector<ll> Cost(G.size(),0);
    for(int i = 0; i < N;i++){
        Cost[group[i]] += w[i];
    }
    int root = group[0];
    vector<ll> dp1(G.size(),0),dp2(G.size(),0);
    rec(root,-1,G,Cost,each_bcc,dp1,dp2);
    return dp2[root];
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
