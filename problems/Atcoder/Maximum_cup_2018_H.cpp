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
 <url:https://beta.atcoder.jp/contests/maximum-cup-2018/tasks/maximum_cup_2018_h>
 問題文============================================================
 N の地点と M 個の通路があります。 N 個の地点は 1 から N まで 1 つずつ番号が振られていて、
 i 個目の通路は地点 vi と地点 ui を長さ wi [m]で結んでいます。
 
 埼大君は、そこである一風変わったスタンプラリーに参加しようとしています。
 内容は、地点 a1 でスタートして最初にスタンプを押した後、地点 a2 から
 地点 aK まで、 K 個の地点を順番にめぐり、スタンプを押していくというものです。
 
 このスタンプラリーには成績が付き、その成績は
 
 si := 地点 ai でスタンプを押してから地点 ai+1 でスタンプを押すまでに移動した道のり[m]
 と定義したときに、max(si|1≤i≤K−1)
 で表され、この値が小さいほど成績がよくなります。
 
 地点同士は高々一本の通路で繋がっていて、通路同士は地点以外では交わりません。
 また、一方通行の通路はありません。
 すべての地点は、どの地点からでも徒歩で通路をたどれば必ずたどり着くことができます。
 
 このスタンプラリーの変わった点は、参加者にはスタート時にQ個の魔法の石が渡されることにあります。
 
 この石にはそれぞれ相異なる数字b1~bQ
 が書かれていて、この石を割ることで、その石が書かれている数字の地点までワープできます。
 割った石は二度と使うことはできません。そして、ワープ中に移動した道のりは 0 メートルとして記録されます。
 また、魔法の石はどの場所にいても使うことができます。
 したがって、対応する魔法の石があれば、ある地点からその次の地点に直接ワープすることもできます。
 魔法の石は必ずしも使い切る必要はありません。
 
 魔法の石を上手く活用することで、どこまで成績をよくできるか求めてください。
 =================================================================
 解説=============================================================
 
 二分探索＋二部マッチング
 
 max(si)となる 値 m について二部探索を行う。
 判定方法については dist[a[i]][a[i+1]] が　m より大きいものに関して
 魔法石を使って m 以下となるマッチングを求めることによってできる。
 
 distは制約よりワーシャルフロイドで前もって求めておける
 ================================================================
 */

ll V;
vector<vector<ll>> G;
vector<ll> match;
vector<int> used;

void add_edge(ll u, ll v) {
    G[u].push_back(v);
    G[v].push_back(u);
}

bool dfs(ll v) {
    used[v] = 1;
    for (int i = 0; i < G[v].size(); i++) {
        ll u = G[v][i], w = match[u];
        if (w < 0 || ((used[w] == 0) && dfs(w))) {
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    return false;
}

ll bipartite_matching() {
    ll res = 0;
    for (int i = 0; i < (int)match.size();i++)match[i] = -1;
    for (int v = 0;v < V;v++) {
        if (match[v] < 0) {
            for (int i = 0; i < (int)used.size();i++)used[i] = 0;
            if (dfs(v))res++;
        }
    }
    return res;
}

ll N,M;
vector<ll> a;
vector<ll> b;
vector<vector<ll>> dist;

bool C(ll m){
    for(auto& array:G) array.clear();
    ll cnt = 0;
    for(int i = 0; i < a.size()-1; i++){
        if(dist[a[i]][a[i+1]] <= m) continue;
        cnt++;
        for(int j = 0; j < b.size(); j++){
            if(dist[b[j]][a[i+1]] <= m) add_edge(i+1,N+j);
        }
    }
    if(bipartite_matching() < cnt) return false;
    else return true;
}

ll solve(){
    ll res = LINF;
    cin >> N >> M; vector<ll> v(M),u(M),w(M);
    for(int i = 0; i < M;i++){ cin >> v[i] >> u[i] >> w[i]; v[i]--; u[i]--; }
    ll K; cin >> K; a.resize(K);
    for(int i = 0; i < K;i++){ cin >> a[i]; a[i]--; }
    ll Q; cin >> Q; b.resize(Q);
    for(int i = 0; i < Q;i++){ cin >> b[i]; b[i]--; }
    
    dist.assign(N,vector<ll>(N,LINF));
    for(int i = 0; i < N;i++) dist[i][i] = 0;
    for(int i = 0; i < M;i++){
        dist[v[i]][u[i]] = dist[u[i]][v[i]] = min(dist[v[i]][u[i]],w[i]);
    }
    
    for(int i = 0; i < N;i++){
        for(int j = 0; j < N;j++){
            for(int k = 0; k < N;k++){
                dist[j][k] = min(dist[j][k],dist[j][i]+dist[i][k]);
            }
        }
    }
    
    V = N+Q;
    G.resize(V); match.resize(V); used.resize(V);
    ll l = -1, r = LINF;
    while(r - l > 1){
        ll m = (l+r)/2;
        if(C(m)){
            r = m;
        }else{
            l = m;
        }
    }
    res = r;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
