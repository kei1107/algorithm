#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2313>
 問題文============================================================
 ハコの魔女 H.N.ELLY はとある動画サイトの熱狂的なファンである
 ハコの魔女の強さはその時々のその動画サイトからの転送速度に応じて変化するのではないかと美樹さやかは考えた
 そこで動画サイトからハコの魔女の持つコンピュータまでの過去の転送速度 (=単位時間あたりのデータの転送量) を調べたい．
 初期のインターネットのネットワークの構造とそれ以降のネットワークの構造の変化を表すクエリが与えられるので，
 各変化について変化した直後の動画サイトからハコの魔女の持つコンピュータまでの転送速度を求めよ．
 インターネットは複数の転送装置からなるものと見なし，各々をつなぐ回線は双方向に情報を送ることができ
 その転送速度の最大は 1 であるとする．
 また，ネットワークは常に動画サイトからハコの魔女へ送られるデータの転送速度を最大化するように運ぶものとする．
 =================================================================
 出力=============================================================
 各変化の直後における，動画サイトからハコの魔女の持つコンピュータまでの転送速度を出力せよ．
 ================================================================
 解説=============================================================
 M == 1 (辺u-vを追加するとき)
 単純に辺を追加して、頂点0 -> 頂点V-1 への増加道ができるか確認
 増加道があれば最大流を+1 なければ 何もしない
 
 M == 2 (辺u-vを削除するとき)
 G[u][v] == G[v][u] == 1 (容量が通っていない）のであれば、そのまま辺を削除しても問題ない
 逆に、辺が利用されているのであれば
  辺u-vを利用せずに, 辺u -> v への増加道があるか確認
 　　あれば, そのままその道に容量１を流せば辺u-vを削除しても無影響（最大流はそのまま）
 　　なければ、辺u-vは現在の最大流で必ず使用されなければならない辺のため、最大流は-1される
 　　ここで、頂点u -> 0 及び 頂点 (V-1) -> v へ容量を1だけ押し戻しておく
 
 上記内容を繰り返し、実行するたびにその最大流の大きさを出力する
 ================================================================
 */
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
