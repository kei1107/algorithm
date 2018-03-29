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
<url:https://onlinejudge.u-aizu.ac.jp/services/room.html#RitsCamp18Day2/problems/G>
問題文============================================================

 N個の非負整数のペア(ai,bi)と非負整数A, B が与えられる。
 以下のいずれかの操作をできるだけたくさん行いたい。
 
 (1) |ai−bi|≤A または B≤|ai−bi|≤2Aを満たす要素iを取り出し、削除する
 (2) |(ai+aj)−(bi+bj)|≤A または B≤|(ai+aj)−(bi+bj)|≤2A を満たす要素iと要素j (i≠j)の組を取り出し、削除する
 
 最大の操作回数を求めよ。
 
=================================================================

解説=============================================================

 出来うる限り　操作(1)を行う
 その後、余った要素ペアに関して操作(2)の条件を満たすペアとの二部マッチングを解く
 
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

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    ll N,A,B; cin >> N >> A >> B;
    vector<ll> a(N),b(N);
    for(int i = 0; i < N;i++) cin >> a[i] >>b[i];
    
    vector<int> f(N,0);
    for(int i = 0; i < N;i++){
        ll Abs = abs(a[i]-b[i]);
        if(Abs <= A || (B <= Abs && Abs <= 2*A)){
            f[i] = -1;
        }
    }
    ll cnt = -accumulate(f.begin(),f.end(),0LL);
    V = 0;
    for(int i = 0; i < N;i++){
        if(f[i] == 0){
            f[i] = V;
            V++;
        }
    }
    G.resize(V);
    match.resize(V);
    used.resize(V);
    
    for(int i = 0; i < N;i++){
        for(int j = 0; j < N;j++){
            if(f[i] == -1 || f[j] == -1) continue;
            ll Absdayo = abs(a[i]+a[j]-b[i]-b[j]);
            if(Absdayo <= A || (B <= Absdayo && Absdayo <= 2*A )){
                 add_edge(f[i],f[j]);
            }
        }
    }
//    cout << cnt << " " << bipartite_matching() << endl;
    cout << cnt + bipartite_matching() << endl;
	return 0;
}
