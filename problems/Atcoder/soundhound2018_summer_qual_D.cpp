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
 <url:https://beta.atcoder.jp/contests/soundhound2018-summer-qual/tasks/soundhound2018_summer_qual_d>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 街sから出発してある街iで両替をして街tへ行きたい時、
 最小費用は (s->iへの円での最小費用) + (i->tへのスヌークでの最小費用)となる
 (s->iへの円での最小費用)は始点をsとしたダイクストラで、
 (i->tへのスヌークでの最小費用)は始点をtとしてダイクストラで求まる。
 
 あとは、街を数字の大きい順に確認して行けば、全ての年についてO(N)で求まる。
 ================================================================
 */
void solve(){
    ll n,m; cin >> n >> m;
    ll s,t; cin >> s >> t; s--; t--;
    vector<vector<pll>> G1(n),G2(n);
    for(int i = 0; i < m;i++){
        ll u,v,a,b; cin >> u >> v >> a >> b;
        u--; v--;
        G1[u].push_back({v,a});
        G2[u].push_back({v,b});
        G1[v].push_back({u,a});
        G2[v].push_back({u,b});
    }
    
    vector<ll> dist1(n,LINF),dist2(n,LINF);
    dist1[s] = 0; dist2[t] = 0;
    queue<ll> q;
    
    q.push(s);
    while(q.size()){
        ll n = q.front(); q.pop();
        for(auto e:G1[n]){
            ll next = e.first,cost = e.second;
            if(dist1[next] > dist1[n] + cost){
                dist1[next] = dist1[n] + cost;
                q.push(next);
            }
        }
    }
    q.push(t);
    while(q.size()){
        ll n = q.front(); q.pop();
        for(auto e:G2[n]){
            ll next = e.first,cost = e.second;
            if(dist2[next] > dist2[n] + cost){
                dist2[next] = dist2[n] + cost;
                q.push(next);
            }
        }
    }
    vector<ll> ans(n,1e15);
    ll minV = LINF;
    for(ll i = n-1;i>=0;i--){
        minV = min(minV,dist1[i]+dist2[i]);
        ans[i] -= minV;
    }
    for(int i = 0; i < n;i++){
        cout << ans[i] << endl;
    }
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
