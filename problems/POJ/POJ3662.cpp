#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <set>
#include <sstream>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <climits>
#include <list>
#include <fstream>
#include <functional>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef vector<string> VS;

#define ALL(a)  a.begin(),a.end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/*
 <url:http://poj.org/problem?id=3662>
 問題文============================================================
 N頂点，辺P本のグラフが与えられる．K本の辺は無料で使うことができ，
 それ以上使うとK本からはみ出た辺の中での最大の長さだけの料金が発生する．
 頂点1から頂点Nまでの経路をできるだけ安い料金で実現したい．
 =================================================================
 解説=============================================================
 ある値X以下のコストは全部無視、それよりおおきいものをつかって到達できるかを判定。
 できなければXをさげていく。
 これで二分探索し、Xが答え

 ちょっとライブラリ借りた
 ================================================================
 */

#define DijkV 1005

/*------- setting -------*/
bool  dist[DijkV];
typedef pair<int, int> typedijk;
vector<vector<typedijk> >G;

LL Dijkstra(vector<vector<typedijk> >& G, int s, int t,LL costline) {
    FOR(i, 0, DijkV)dist[i] = 0;
    priority_queue<typedijk, vector<typedijk>, greater<typedijk> > que; //優先度付きqueue 降順(距離、頂点)
    que.push(typedijk(0LL, s)); // push(距離,頂点)
    
    while (!que.empty()) {
        typedijk p = que.top(); que.pop(); //queueのデータ構造
        int v; /* 頂点*/ long long d; /* 頂点vまでの距離 */
        d = p.first, v = p.second;
        
        if (v == t)return d;
        if (dist[v]) continue;
        dist[v] = 1;
        FOR(i, 0, (int)G[v].size()) { //頂点vからはi本の辺が存在
            int nv = G[v][i].first; // v->nv
            int nc = G[v][i].second;
            if (nc <= costline) {
                que.push(typedijk(d, nv)); //push(距離,頂点)
            }
            else {
                que.push(typedijk(d + 1, nv)); //push(距離,頂点)
            }
        }
    }
    return -1;
}



LL N, P, K;

LL ans = 0LL;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    //cin >> N >> P >> K;
    scanf("%lld%lld%lld", &N, &P, &K);
    vector<vector<PII> >G(N);
    FOR(i, 0, P) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a--, b--;
        G[a].push_back(PII(b, c));
        G[b].push_back(PII(a, c));
    }
    
    LL L, R, mid;
    L = 0;
    R = INF;
    for(int i = 0; i < 32;i++) {
        mid = (L + R) >> 1;
        LL val = Dijkstra(G, 0, N - 1, mid);
        if (0 <= val&&val <= K) {
            R = mid;
        }
        else L = mid;
    }
    ans = R;
    if (R == INF)ans = -1;
    printf("%lld\n", ans);// cout << ans << "\n";
    
    return 0;
}
