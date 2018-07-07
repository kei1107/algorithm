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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2776>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 最小費用流問題に帰着できる。
 
 AからBへ　互いに良ければ 0 、　片方だけ良ければ 1 , 両方ダメであれば 2 のコストで辺をはる
 
 その後完成したグラフに関して、1ずつ流量を流していけば、必要な総費用と流量の関係から
 答えがわかる
 ================================================================
 */
typedef ll PD_Type;
const PD_Type PD_INF = INF;
struct Primal_Dual
{
    typedef pair< PD_Type, int > pii;
    
    struct edge
    {
        int to, rev;
        PD_Type    cap, cost;
        edge() {}
        edge(int to, PD_Type cap, PD_Type cost, int rev) :to(to), cap(cap), cost(cost), rev(rev) {}
        
    };
    vector< vector< edge > > graph;
    vector< int > prevv, preve;
    vector< PD_Type > potential, min_cost;
    Primal_Dual(int V) : graph(V) {}
    
    void add_edge(int from, int to, PD_Type cap, PD_Type cost)
    {
        graph[from].push_back(edge(to, cap, cost, (int)graph[to].size()));
        graph[to].push_back(edge(from, 0, -cost, (int)graph[from].size() - 1));
    }
    
    PD_Type min_cost_flow(int s, int t, int f)
    {
        int V = (int)graph.size();
        PD_Type ret = 0;
        priority_queue< pii, vector< pii >, greater< pii > > que;
        potential.assign(V, 0);
        preve.assign(V, -1);
        prevv.assign(V, -1);
        
        while (f > 0) {
            min_cost.assign(V, PD_INF);
            que.push(pii(0, s));
            min_cost[s] = 0;
            
            while (!que.empty()) {
                pii p = que.top();
                que.pop();
                if (min_cost[p.second] < p.first) continue;
                for (int i = 0; i < (int)graph[p.second].size(); i++) {
                    edge &e = graph[p.second][i];
                    PD_Type nextCost = min_cost[p.second] + e.cost + potential[p.second] - potential[e.to];
                    if (e.cap > 0 && min_cost[e.to] > nextCost) {
                        min_cost[e.to] = nextCost;
                        prevv[e.to] = p.second; preve[e.to] = i;
                        que.push(pii(min_cost[e.to], e.to));
                    }
                }
            }
            if (min_cost[t] == PD_INF) return -1;
            for (int v = 0; v < V; v++) potential[v] += min_cost[v];
            PD_Type addflow = f;
            for (int v = t; v != s; v = prevv[v]) {
                addflow = min(addflow, graph[prevv[v]][preve[v]].cap);
            }
            f -= addflow;
            ret += addflow * potential[t];
            for (int v = t; v != s; v = prevv[v]) {
                edge &e = graph[prevv[v]][preve[v]];
                e.cap -= addflow;
                graph[v][e.rev].cap += addflow;
            }
        }
        return ret;
    }
};

void solve() {
    int A, B, K; cin >> A >> B >> K;
    vector<string> a(A), b(B);
    for (auto& in : a) cin >> in;
    for (auto& in : b) cin >> in;
    
    int S = A + B, T = A + B + 1;
    Primal_Dual clojure(A + B + 2);
    for (int i = 0; i < A; i++) clojure.add_edge(S, i, 1, 0);
    for (int i = 0; i < B; i++) clojure.add_edge(A+i, T, 1, 0);
    
    for (int i = 0; i < A; i++) {
        for (int j = 0; j < B; j++) {
            ll cost = 0;
            if (a[i][j] == '1') cost++;
            if (b[j][i] == '1') cost++;
            clojure.add_edge(i, A + j, 1, cost);
        }
    }
    
    ll ans = 0;
    while (true) {
        ll ret = clojure.min_cost_flow(S, T, 1);
        if (ret == -1) break;
        if (ret > K) break;
        K -= ret;
        ans++;
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
