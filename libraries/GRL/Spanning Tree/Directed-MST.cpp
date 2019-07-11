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

// original
// 最小全域有向木 O(EV)
// 1-index
const int MAXV = 10010;
const int MAXE = 10010;
const int MAXW = 2147483647;
struct Edge {
    int u, v, c;
    Edge(int x = 0, int y = 0, int z = 0) : u(x), v(y), c(z) {}
};
int V, E, root;
Edge edges[MAXE];
inline int newV() { return ++V; }
inline void addEdge(int u, int v, int c)
{
    edges[++E] = Edge(u, v, c);
}
bool con[MAXV];
int mnInW[MAXV], prv[MAXV], cyc[MAXV], vis[MAXV];
inline int DMST() {
    fill(con, con + V + 1, 0);
    int r1 = 0, r2 = 0;
    while (1) {
        fill(mnInW, mnInW + V + 1, MAXW);
        fill(prv, prv + V + 1, -1);
        for (int i = 1; i <= E; i++) {
            int u = edges[i].u, v = edges[i].v, c = edges[i].c;
            if (u != v && v != root && c < mnInW[v]){mnInW[v] = c; prv[v] = u;}
        }
        fill(vis, vis + V + 1, -1);
        fill(cyc, cyc + V + 1, -1);
        r1 = 0;
        bool jf = 0;
        for (int i = 1; i <= V; i++) {
            if (con[i]) continue;
            if (prv[i] == -1 && i != root) {
                return -1;
            }
            if (prv[i] > 0) r1 += mnInW[i];
            int s;
            for (s = i; s != -1 && vis[s] == -1; s = prv[s])
                vis[s] = i;
            if (s > 0 && vis[s] == i) {
                // get a cycle
                jf = 1; int v = s;
                do {
                    cyc[v] = s, con[v] = 1;
                    r2 += mnInW[v]; v = prv[v];
                } while (v != s);
                con[s] = 0;
            }
        }
        if (!jf) break;
        for (int i = 1; i <= E; i++) {
            int &u = edges[i].u;
            int &v = edges[i].v;
            if (cyc[v] > 0) edges[i].c -= mnInW[edges[i].v];
            if (cyc[u] > 0) edges[i].u = cyc[edges[i].u];
            if (cyc[v] > 0) edges[i].v = cyc[edges[i].v];
            if (u == v) edges[i--] = edges[E--];
        }
    }
    return r1 + r2;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int e;
    cin >> V >> e >> root;
    root++;
    for(int i = 0; i < e;i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a++; b++;
        addEdge(a, b, c);
    }
    cout << DMST() << endl;
    
    return 0;
}


// ================================================================ //
/*
 最小全域有向木 O(EV) 0-index
 */
const int MAXV = 10010;
const int MAXE = 10010;
const int MAXW = 2147483647;
struct Edge {
    int u, v, c;
    Edge(int x = 0, int y = 0, int z = 0) : u(x), v(y), c(z) {}
};
int V, E, root;
Edge edges[MAXE];
inline void addEdge(int u, int v, int c){ edges[E++] = Edge(u, v, c);}
bool con[MAXV];
int mnInW[MAXV], prv[MAXV], cyc[MAXV], vis[MAXV];
inline int DMST() {
    fill(con, con + V, 0);
    int r1 = 0, r2 = 0;
    while (true) {
        fill(mnInW, mnInW + V, MAXW);
        fill(prv, prv + V, -1);
        for (int i = 0; i < E; i++) {
            int u = edges[i].u, v = edges[i].v, c = edges[i].c;
            if (u != v && v != root && c < mnInW[v]){mnInW[v] = c; prv[v] = u;}
        }
        fill(vis, vis + V, -1);
        fill(cyc, cyc + V, -1);
        r1 = 0;
        bool jf = false;
        for (int i = 0; i < V; i++) {
            if (con[i]) continue;
            if (prv[i] == -1 && i != root) {
                return -1;
            }
            if (prv[i] >= 0) r1 += mnInW[i];
            int s;
            for (s = i; s != -1 && vis[s] == -1; s = prv[s]) vis[s] = i;
            if (s >= 0 && vis[s] == i) {
                // get a cycle
                jf = true; int v = s;
                do { cyc[v] = s; con[v] = true; r2 += mnInW[v]; v = prv[v];
                } while (v != s);
                con[s] = false;
            }
        }
        if (!jf) break;
        for (int i = 0; i < E; i++) {
            int &u = edges[i].u;
            int &v = edges[i].v;
            if (cyc[v] >= 0) edges[i].c -= mnInW[edges[i].v];
            if (cyc[u] >= 0) edges[i].u = cyc[edges[i].u];
            if (cyc[v] >= 0) edges[i].v = cyc[edges[i].v];
            if (u == v){ edges[i--] = edges[--E]; }
        }
    }
    return r1 + r2;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(false);
    int e;
    cin >> V >> e >> root;
    for(int i = 0; i < e;i++) {
        int a, b, c;
        cin >> a >> b >> c;
        addEdge(a, b, c);
    }
    cout << DMST() << endl;
    
    return 0;
}

