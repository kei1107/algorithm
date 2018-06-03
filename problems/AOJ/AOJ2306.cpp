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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2306>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 愚直に全部の集合を見ていくと間に合わないが、今回の条件では
 一つでも親密度が０のペアがいれば、そのペアのうちどちらかは集合に入れないほうがいい。
 よって、与えられた辺において完全グラフとなるような部分集合を探せばよく、
 辺の数が最大でも１００なのであまり集合が大きくならないので通る
 ================================================================
 */


void dfs(ll n,vector<ll>& use,vector<vector<ll>>& cost,ll& res){
    size_t size = use.size();
    if(size >= 2){
        ll sum = 0;
        for(int i = 0; i < size;i++){
            ll minc = INF;
            for(int j = 0; j < size;j++){
                if(i == j) continue;
                minc = min(minc,cost[use[i]][use[j]]);
            }
            sum += minc;
        }
        res = max(res,sum);
    }
    
    for(ll next = n + 1; next < cost[0].size(); next++){
        [&]{
            for(int i = 0; i < size;i++){
                if(cost[next][use[i]] == 0) return;
            }
            use.push_back(next);
            dfs(next,use,cost,res);
            use.pop_back();
        }();
    }
}
ll solve(){
    ll res = 0;
    ll n,m; cin >> n >> m;
    vector<ll> u(m),v(m),f(m);
    for(int i = 0; i < m;i++){
        cin >> u[i] >> v[i] >> f[i];
        u[i]--; v[i]--;
    }
    vector<vector<ll>> cost(n,vector<ll>(n,0));
    for(int i = 0;i < m;i++){
        cost[u[i]][v[i]] = cost[v[i]][u[i]] = f[i];
    }
    vector<ll> use;
    for(int i = 0; i < n;i++){
        use.clear();
        use.push_back(i);
        dfs(i,use,cost,res);
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
