#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2313

int V,E;
int G[501][501]; // グラフの隣接リスト表現
vector<int> used; // DFSですでに調べたらフラグ

// fromからtoへ向かう容量capの辺をグラフに追加する
void add_edge(int from, int to, int cap) {
    G[from][to] = G[to][from] = cap;
}

// 増加パスをDFSで探す
int dfs(int v, int t, int f) {
    if (v == t) return f;
    used[v] = true;
    for (int i = 0; i < V; i++) {
        auto &cap = G[v][i];
        if (!used[i] && cap > 0) {
            int d = dfs(i, t, min(f, cap));
            if (d > 0) {
                cap -= d;
                G[i][v] += d;
                return d;
            }
        }
    }
    return 0;
}

// sからtへの最大流を求める
int max_flow(int s, int t) {
	int flow = 0;
    for (;;) {
        fill(used.begin(), used.end(), 0);
        int f = dfs(s, t, INF);
        if (f == 0) return flow;
        flow += f;
    }
}

/* one_path check*/
bool check(int v, int t) {
	if (v == t)return true;
	used[v] = true;
	for (int i = 0; i < V;i++) {
		auto& cap = G[v][i];
		if (!used[i] && cap > 0) {
			if (check(i, t)) {
				// 容量1だけ押し戻す
				cap--;
				G[i][v]++;
				return true;
			}
		}
	}
	return false;
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> V >> E;
    int Q; cin >> Q;
    for(int i = 0; i < 501;i++){
        for(int j = 0;j < 501;j++){
            G[i][j] = 0;
        }
    }
    used.resize(V);
    for (int i = 0; i < E;i++) {
        int s, t; cin >> s >> t;
        s--;t--;
        add_edge(s, t, 1);
    }
    
    int f = max_flow(0, V - 1);
    for(int i = 0; i < Q;i++){
        int M,A,B; cin >> M >> A >> B;
        A--;B--;
        if(M == 1){
            G[A][B] = G[B][A] = 1; // 辺の追加 := 容量の追加
            fill(used.begin(),used.end(),0);
            f += dfs(0,V-1,INF); // 増加パスがあれば+1される
        }else{
            if(G[A][B] == 0 || G[B][A] == 0){
                int u,v;
                if(G[A][B] == 0){ u = A; v = B;}
                else{u = B; v = A;}
            	
            	/* u->vまでの増加パスを確認, あれば, check時にそちらの道へパスが流れるので十分*/
            	fill(used.begin(), used.end(), 0);
            	if(!check(u,v)){
            		/* なければ, 最大流が-1される。ここで u->0 及び (V-1)->v に
            		余分な流れ(容量1分)が存在するので押し戻す*/
            		fill(used.begin(),used.end(),0);
            		check(u, 0);
            		fill(used.begin(),used.end(),0);
            		check(V - 1, v);
            		f--;
                }
            }
            G[A][B] = G[B][A] = 0;
        }
		cout << f << endl;
	}
    return 0;
}
