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
 <url:http://codeforces.com/contest/959/problem/E>
 問題文============================================================
 Ehab is interested in the bitwise-xor operation and the special graphs.
 Mahmoud gave him a problem that combines both. He has a complete graph
 consisting of n vertices numbered from 0 to n - 1. For all 0 ≤ u < v < n,
 vertex u and vertex v are connected with an undirected edge that has weight u^v
 (where ^ is the bitwise-xor operation).
 Can you find the weight of the minimum spanning tree of that graph?
 
 You can read about complete graphs in https://en.wikipedia.org/wiki/Complete_graph
 
 You can read about the minimum spanning tree in
 https://en.wikipedia.org/wiki/Minimum_spanning_tree
 
 The weight of the minimum spanning tree is the sum of the weights on the edges included in it.
 
 Input
 The only line contains an integer n (2 ≤ n ≤ 1012), the number of vertices in the graph.
 
 Output
 The only line contains an integer x, the weight of the graph's minimum spanning tree.
 =================================================================
 解説=============================================================
 
 OEISさん。
 
 test関数のような物を書いて、結果を見ると、
 数列
 <https://oeis.org/A006520> (1)
 が得られる。
 また、この数列(1)は
 <https://oeis.org/A006519> (2)
 の累積和であることもわかる。
 
 数列(2)は、各値について周期的に現れることがわかるので、その周期に合わせて総和を出すことができる。
 
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

void test(){
    for(int i = 2; i < 100; i++){
        UnionFind UF(i);
        priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<pair<int,pii>>> pq;
        for(int j = 0; j < i;j++){
            for(int k = j + 1; k < i; k++){
                pq.push({j^k,{j,k}});
            }
        }
        ll res = 0;
        while(pq.size()){
            auto p = pq.top(); pq.pop();
            if(UF.same(p.second.first,p.second.second)) continue;
            res += p.first;
            UF.unite(p.second.first, p.second.second);
        }
        cout << res << endl;
    }
}

ll solve(ll n){
    n--;
    ll res = 0;
    ll t = 1LL<<0;
    while(t <= n){
        ll next_t = t<<1;
        res += t*(((n-t)/next_t)+1);
        t = next_t;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    ll n; cin >> n;
    cout << solve(n) << endl;
    return 0;
}
