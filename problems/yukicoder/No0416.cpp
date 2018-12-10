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
 <url:https://yukicoder.me/problems/no/416>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 UF使って頑張る
 
 ================================================================
 */

struct UnionFind{
    vector<int> parent, rank;
    UnionFind(int n) : parent(n, -1), rank(n, 0) { }
    int find(int x){
        if(parent[x] == -1) return x;
        else return (parent[x] = find(parent[x]));
    }
    bool unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return false;
        if(rank[x] < rank[y])
            parent[x] = y;
        else
            parent[y] = x;
        if(rank[x] == rank[y]) rank[x]++;
        return true;
    }
    bool same(int x, int y){
        return find(x) == find(y);
    }
};


map<pii,int> mp;
set<int> children[100005];
UnionFind UF(100005);
void solve(){
    int N,M,Q; cin >> N >> M >> Q;
    for(int i = 0; i < M;i++){
        int A,B; cin >> A >> B; A--; B--;
        if(A > B) swap(A,B);
        mp[pii(A,B)]++;
    }
    
    vector<pii> edges(Q);
    for(int i = 0; i < Q;i++){
        int C,D; cin >> C >> D;
        C--; D--;
        if(C > D) swap(C,D);
        mp[pii(C,D)]--;
        edges[i] = pii(C,D);
    }
    
    for(auto p:mp){
        if(p.second){
            UF.unite(p.first.first,p.first.second);
        }
    }
    vector<int> ans(N);
    for(int i = 1; i <= N;i++){
        if(UF.same(0,i)) ans[i] = -1;
    }
    

    for(int i = 0; i < N;i++) children[UF.find(i)].insert(i);
    for(int i = Q-1; i >= 0; i--){
        int rootx = UF.find(edges[i].first);
        int rooty = UF.find(edges[i].second);
        if(rootx == rooty) continue;
        int rootzero = UF.find(0);
        if(rootx == rootzero){
            for(auto v:children[rooty]){
                ans[v] = i+1;
            }
            UF.unite(rootx, rooty);
        }else if(rooty == rootzero){
            for(auto v:children[rootx]){
                ans[v] = i+1;
            }
            UF.unite(rootx, rooty);
        }else{
            UF.unite(rootx, rooty);
            int next_root = UF.find(rootx);
            if(next_root == rootx){
                for(auto v:children[rooty]) children[rootx].insert(v);
            }else{
                for(auto v:children[rootx]) children[rooty].insert(v);
            }
        }
    }
    for(int i = 1; i < N;i++){
        cout << ans[i] << endl;
    }
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
