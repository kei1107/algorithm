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
<url:https://apc001.contest.atcoder.jp/tasks/apc001_d>
問題文============================================================
 N 頂点 M 辺の森が与えられます。頂点には 0 から N−1 の番号がついています。
 辺は (xi,yi) の形で与えられます。これは頂点 xi と yi が辺でつながっていることを意味します。
 
 各頂点 i には ai という値が定まっています。 あなたは与えられた森に辺を追加して連結にしたいです。
 辺を追加するときには、まず異なる頂点二つを選択し( i , j とする)、 i と j の間に辺を張ります。
 この時コストが ai+aj かかります。そしてこれ以降，頂点 i と j は永遠に選択できなくなります。
 
 森を連結にする最小コストを求めてください。 連結にするのが不可能な場合はImpossibleと出力してください。
=================================================================

解説=============================================================

 まず、 N頂点中でM辺の森がいくつに分割されるかを考える。
 
 実験等として考えると
 N - M 個に分割される

 M == N - 1の時　すなわち 1個に分割は　すでに木になっていることを示すので
 
 M < N - 1 として,
 N - M 個に分割されたものを木にするには N - M 個の頂点として考えれば良いので
 N - M - 1 個の辺があれば良い。
 よって 2*(N-M-1)個の頂点が必要である。
 ここで、選べる全頂点は N 個なので  N < 2*(N-M-1) であれば Impossibleとなる
 
 次に、木への復元を考える
 N-Mの分割された成分から 木にするには　必ず、それぞれから少なくとも１頂点を選ぶ必要がある
 また、2*(N-M-1)の頂点を選択してしまえば都合よく辺を引くことで木にすることができるので、
 
 それぞれの連結成分から 一番小さいコストの頂点を1つ選んでおき、
 残りの足りない分を残った全体から小さい順に選んでいけばよい
 
================================================================
*/

void dfs(ll n,vector<int>& color,vector<vector<ll>>& G,int color_idx){
    color[n] = color_idx;
    for(auto next:G[n]){
        if(color[next]==-1)dfs(next,color,G,color_idx);
    }
}

ll solve(){
    ll res = 0;
    ll N,M; cin >> N >> M;
    vector<ll> a(N); for(auto &in:a) cin >> in;
    vector<ll> x(M),y(M);
    for(int i = 0; i < M;i++) cin >> x[i] >> y[i];
    if(M == N-1)return res;
    if(N < 2*(N-1-M)) return -1;
    vector<vector<ll>> G(N);
    for(int i = 0; i < M;i++){
        G[x[i]].push_back(y[i]);
        G[y[i]].push_back(x[i]);
    }
    vector<int> color(N,-1);
    int color_idx = 0;
    for(int i = 0;i < N;i++){
        if(color[i]==-1) dfs(i,color,G,color_idx++);
    }
    
    vector<vector<ll>> color_cost(color_idx);
    for(int i = 0; i < N;i++){
        color_cost[color[i]].push_back(a[i]);
    }
    for(auto& array:color_cost)sort(array.begin(),array.end());
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    ll cnt = 2*(N-M-1);
    for(auto& array:color_cost){
        res += array[0]; cnt--;
        for(int i = 1; i < array.size();i++){
            pq.push(array[i]);
        }
    }
    while(cnt--){
        res += pq.top();pq.pop();
    }
    return res;
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll ans = solve();
    if(ans == -1) cout << "Impossible" << endl;
    else cout << ans << endl;
	return 0;
}
