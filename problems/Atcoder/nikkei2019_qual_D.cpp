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
template<class T> ostream& operator << (ostream& out,const vector<T>& V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> >& Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T>& mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }
template<typename T>vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}
/*
 <url:https://atcoder.jp/contests/nikkei2019-qual/tasks/nikkei2019_qual_d>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 トポロジる
 ================================================================
 */

// topological sort
// dfs版  O(N + E)
// https://ja.wikipedia.org/wiki/%E3%83%88%E3%83%9D%E3%83%AD%E3%82%B8%E3%82%AB%E3%83%AB%E3%82%BD%E3%83%BC%E3%83%88
void topological_sort_dfs(int n,vector<int>& visit,vector<vector<int>>& G,vector<int>& ret){
    if(visit[n]) return;
    visit[n] = true;
    for(auto& next:G[n]) topological_sort_dfs(next,visit,G,ret);
    
    ret.push_back(n);
}
vector<int> topological_sort(int N,vector<vector<int>>& G){
    vector<int> ret;
    
    vector<int> visit(N);
    for(int n = 0; n < N;n++) topological_sort_dfs(n,visit,G,ret);
    reverse(ret.begin(),ret.end());
    
    if(ret.size() != N){ // 閉路!
        return vector<int>{-1};
    }
    return ret;
}
template<class Type>
Type solve(Type res = Type()){
    int N,M; cin >> N >> M;
    vector<vector<int>> G(N);
    vector<vector<int>> rG(N);
    for(int i = 0; i < N-1+M;i++){
        int A,B; cin >> A >> B;

        A--; B--;
        G[A].push_back(B);
        rG[B].push_back(A);
    }
    
    auto visit = topological_sort(N,G);
    
    vector<int> priority(N);
    for(int i = 0; i < N;i++){
        priority[visit[i]] = i;
    }
    
    vector<int> ans(N);
    for(int i = 0; i < N;i++){
        int min_pri = -1;
        for(auto par_cand:rG[i]){
            if(priority[par_cand] > min_pri){
                min_pri = priority[par_cand];
                ans[i] = par_cand + 1;
            }
        }
    }
    
    for(int i = 0; i < N;i++){
        cout << ans[i] << endl;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve(0);
    // cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
