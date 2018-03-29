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
 <url:https://yukicoder.me/problems/no/1>
 問題文============================================================
 N 個の町があります。それぞれ1…Nと番号がふられています。
 それぞれの街は直接、道でつながっているものもあれば、つながってないものがあります。
 それぞれの道は　町Siから町Tiに行くのに Yiのコスト（お金：円）がかかり、Mi 単位時間 かかります。
 
 あなたは 1 の町にいます。
 N の都市に行きたいと思っています。
 何個道や町を経由してもいいですが、あなたは今C円しか持っていません。
 
 （つまり、通った道のコスト Yi の合計がC以下にしないといけない。）
 
 その中で一番早く付く道を選べた時、合計の単位時間を答えてください。
 この制約の中で辿りつけない場合 −1を返してください。
 
 =================================================================
 解説=============================================================
 拡張ダイクストラ
 
 dist[頂点番号][残余金額] でdijkstra やるだけ
 ================================================================
 */

struct edge{
    ll u,v,cost,time;
    edge(){};
    edge(ll u,ll v,ll c,ll t):u(u),v(v),cost(c),time(t){}
};
ll solve(){
    ll res = LINF;
    ll N,C,V; cin >> N >> C >> V;
    vector<ll> S(V),T(V),Y(V),M(V);
    for(auto& in:S) cin >> in;
    for(auto& in:T) cin >> in;
    for(auto& in:Y) cin >> in;
    for(auto& in:M) cin >> in;
    
    vector<vector<edge>> G(N);
    for(int i = 0; i < V;i++){
        S[i]--; T[i]--;
        G[S[i]].push_back(edge(S[i],T[i],Y[i],M[i]));
        //G[T[i]].push_back(edge(T[i],S[i],Y[i],M[i]));
    }

    vector<vector<ll>> dist(N,vector<ll>(C+1,LINF));
    dist[0][C] = 0;
    queue<pll> q; q.push({0,C});
    while(q.size()){
        ll n, can_use; tie(n,can_use) = q.front(); q.pop();
        for(edge& e:G[n]){
            if(e.cost > can_use) continue;
            if(dist[e.v][can_use-e.cost] > dist[e.u][can_use] + e.time){
                dist[e.v][can_use-e.cost] = dist[e.u][can_use] + e.time;
                q.push({e.v,can_use-e.cost});
            }
        }
    }
    res = *min_element(dist[N-1].begin(),dist[N-1].end());
    return res==LINF?-1:res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
