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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1163&lang=jp>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 最も多くのペアを作りたい -> 最大マッチング
 
 よって、取り除けるペアに辺を張って最大マッチングを求めれば良い
 
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
/*
 gcd : 最大公約数
 lcm : 最小公倍数
 */
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }

int m,n;
ll solve(){
    ll res = 0;
    V = m+n;
    G.clear(); match.clear(); used.clear();
    G.resize(V); match.resize(V); used.resize(V);
    vector<int> b(m),r(n);
    for(auto& in:b) cin >> in;
    for(auto& in:r) cin >> in;
    for(int i = 0; i < m;i++){
        for(int j = 0; j < n;j++){
            if(gcd(b[i],r[j]) == 1) continue;
            add_edge(i,m+j);
        }
    }
    res = bipartite_matching();
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    while(cin >> m >> n,m|n){
        cout << solve() << endl;
    }
    return 0;
}
