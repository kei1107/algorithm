#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

/*
 <url:https://atcoder.jp/contests/code-festival-2014-relay/tasks/code_festival_relay_i>
 問題文============================================================
 =================================================================
 解説=============================================================
 早く交差点に着くのに越したことはないので、単純にdijkstraで最短路を見つければいい
 この時、更新コストに注意して計算する
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    ll n,m,s,d; cin >> n >> m >> s >> d;
    vector<ll> a(n),b(n),c(n); for(int i = 0; i < n;i++) cin >> a[i] >> b[i] >> c[i];
    vector<vector<pll>> G(n);
    for(int i = 0; i < m;i++){
        ll x,y,t; cin >> x >> y >> t;
        x--; y--;
        G[x].push_back({y,t});
        G[y].push_back({x,t});
    }
    
    s--; d--;
    vector<ll> dist(n,LINF);
    dist[s] = 0;
    queue<ll> q; q.push(s);
    while(q.size()){
        ll now = q.front(); q.pop();
        for(auto p : G[now]){
            ll nextt = dist[now];
            nextt = max(nextt,c[now]);
            ll diff = nextt - c[now];
            ll cycle = diff%(a[now] + b[now]);
            
            if(cycle >= a[now]){
                nextt += (a[now]+b[now] - cycle);
            }
            
            nextt += p.second;
            
            if(dist[p.first] > nextt){
                dist[p.first] = nextt;
                q.push(p.first);
            }
        }
    }
    
    res = dist[d];
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    //solve<ll>();
    cout << fixed << setprecision(12) << solve<ll>() << endl;
    return 0;
}
