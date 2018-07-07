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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1318>
 問題文============================================================
 
 都市群が存在する。
 都市間の距離とステーションの都市名が与えられる。
 
 ある都市から目的の都市に行きたい。
 あなたが移動する車は最大燃料が存在し、10km進むと1l 減る
 ステーションの街に着けば、燃料を補給することができる。
 
 目的の都市まで到達可能か？
 到達可能であれば、その最小の移動距離を述べよ
 
 =================================================================
 解説=============================================================
 
 拡張ダイクストラでえいする
 ================================================================
 */
ll N,M,cap;
map<string,int> city2idx;
vector<string> citys;
ll solve(){
    ll res = -1;
    city2idx.clear(); citys.clear();
    
    string src,dest; cin >> src >> dest;
    citys.push_back(src); citys.push_back(dest);
    vector<string> c1(N),c2(N); vector<ll> d(N);
    for(int i = 0; i < N;i++){
        cin >> c1[i] >> c2[i] >> d[i];
        citys.push_back(c1[i]); citys.push_back(c2[i]);
    }
    vector<string> s(M);
    for(int i = 0; i < M;i++){
        cin >> s[i];
        citys.push_back(s[i]);
    }
    int idx = 0;
    sort(citys.begin(),citys.end());
    citys.erase(unique(citys.begin(),citys.end()),citys.end());
    for(string& city:citys){
        city2idx[city] = idx++;
    }
    int S = city2idx[src],T = city2idx[dest];
    vector<vector<pll>> G(citys.size());
    for(int i = 0; i < N;i++){
        ll u = city2idx[c1[i]], v = city2idx[c2[i]];
        G[u].push_back(make_pair(v,d[i]));
        G[v].push_back(make_pair(u,d[i]));
    }
    vector<int> stations(citys.size());
    for(int i = 0; i < M;i++){
        ll n = city2idx[s[i]];
        stations[n] = 1;
    }
    vector<vector<ll>> dist(citys.size(),vector<ll>(cap*10 + 1,LINF));
    dist[S] = vector<ll>(cap*10+1,0);
    queue<pll> q; q.push({S,0});
    while(q.size()){
        ll n,C; tie(n,C) = q.front(); q.pop();
        if(stations[n]){ dist[n][0] = min(dist[n][0],dist[n][C]); C = 0;}
        for(auto e:G[n]){
            ll next = e.first, cost = e.second;
           if(C + cost > cap*10) continue;
            if(dist[next][C+cost] > dist[n][C] + cost){
                dist[next][C+cost] = dist[n][C] + cost;
                q.push(make_pair(next,C+cost));
            }
        }
    }
    res = *min_element(dist[T].begin(),dist[T].end());
    if(res == LINF) return -1;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    while(cin >> N >> M >> cap,N){
        cout << solve() << endl;
    }
    return 0;
}
