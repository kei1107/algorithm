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
 <url:https://yukicoder.me/problems/no/421>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 二部マッチング使って、最大マッチング=幸福度100の個数
 
 あとは、方法2 -> 方法1の優先度で決定していけばいい
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

ll solve(){
    ll res = 0;
    int N,M; cin >> N >> M;
    vector<vector<char>> S(N+2,vector<char>(M+2,'.'));
    
    int cntb = 0,cntw = 0;
    for(int i = 1; i<= N;i++) for(int j = 1; j <= M;j++){
        cin >> S[i][j];
        cntb += S[i][j] == 'b';
        cntw += S[i][j] == 'w';
    }
    
    int d[4] = {1,0,-1,0};

    V = (N+2)*(M+2);
    G.resize(V); used.resize(V); match.resize(V);
    for(int i = 1; i <= N;i++){
        for(int j = 1; j <= M;j++){
            if(S[i][j] == '.') continue;
            for(int k = 0; k < 4;k++){
                int ni = i + d[k];
                int nj = j + d[k^1];
                if(S[ni][nj] == '.') continue;
                if(S[i][j] != S[ni][nj]){
                    add_edge(i*(M+2)+j,ni*(M+2)+nj);
                }
            }
        }
    }
    
    ll bm = bipartite_matching();
    res += bm*100;
    cntw -= bm; cntb -= bm;
    res += 10*min(cntw,cntb);
    res += max(cntw,cntb) - min(cntw,cntb);
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
