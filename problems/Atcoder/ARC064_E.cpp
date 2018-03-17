#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream &operator << (ostream& out,const pair<S,T>& o){
    out << "(" << o.first << "," << o.second << ")"; return out;
}

/*
<url:https://arc064.contest.atcoder.jp/tasks/arc064_c>
問題文============================================================
 xy 平面があります。 すぬけ君は座標 (xs,ys) から座標 (xt,yt) まで移動しようとしています。
 すぬけ君は好きな向きへ速さ 1 で動くことができます。 なお、すぬけ君は大きさのない点と見なすことにします。
 
 平面上には N 個の円形のバリアが張ってあります。
 i 番目のバリアは中心が (xi,yi) で半径が ri です。
 バリアは互いに重なっていたり、互いを含んでいたりすることがあります。
 
 平面上の各座標について、その座標がどのバリアの内部にも含まれない場合、その座標には宇宙線が降り注いでいます。
 
 すぬけ君は移動中にできるだけ宇宙線を浴びたくないので、宇宙線を浴びる時間が最小になるように移動します。
 すぬけ君が移動中に宇宙線を浴びる時間の最小値を求めてください。

=================================================================

解説=============================================================
よくあるパターン　頻出　ICPCにも似たようなやつあった
 
 自由な向きに移動できるので
 あるバリア内の自由な位置から出ることができる為
 バリアi -> バリアj への移動は単純な円同士の距離で出せる。
 始点と終点に関しては 半径0の円とみなせるので
 この問題は 円から円へ最短経路を取って言った時に、 0 -> N+1までの最短距離と言った
 単純なdijkstraに落とし込める
================================================================
*/
struct edge{
    int u,v;
    double c;
    edge(){}
    edge(int u,int v,double c):u(u),v(v),c(c){}
};

#define MAX_N 1000
ll x[MAX_N+2],y[MAX_N+2],r[MAX_N+2];

inline double c_dist(int i,int j){
    double d = hypot(x[i]-x[j],y[i]-y[j]);
    return max(d-(r[i]+r[j]),0.0);
}
double solve(){
    ll xs,ys,xt,yt; cin >> xs >> ys>> xt >> yt;
    int N; cin >> N;
    x[0] = xs; y[0] = ys; r[0] = 0;
    for(int i = 1; i <= N;i++) cin >> x[i] >> y[i] >> r[i];
    x[N+1] = xt; y[N+1] = yt; r[N+1] = 0;
    
    vector<vector<edge>> G(N+2);
    for(int i = 0; i < N+2;i++){
        for(int j = i+1; j < N+2;j++){
            double d = c_dist(i,j);
            G[i].push_back(edge(i,j,d));
            G[j].push_back(edge(j,i,d));
        }
    }
    
    vector<double> dist(N+2,LINF*2);
    typedef pair<double,int> pdi;
    priority_queue<pdi,vector<pdi>,greater<pdi>> pq;
    dist[0] = 0; pq.push(pdi(0.0,0));
    while(pq.size()){
        pdi p = pq.top(); pq.pop();
        double d; int n; tie(d,n) = p;
        if(d > dist[n]) continue;
        for(edge& e:G[n]){
            if(dist[e.v] > dist[e.u] + e.c){
                dist[e.v] = dist[e.u] + e.c;
                pq.push(pdi(dist[e.v],e.v));
            }
        }
    }
    return dist[N+1];
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    cout << fixed << setprecision(12) << solve() << endl;
	return 0;
}
