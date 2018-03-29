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
<url:https://code-thanks-festival-2017-open.contest.atcoder.jp/tasks/code_thanks_festival_2017_h>
問題文============================================================
 最初、{1},{2},…,{N} という N 個の集合が与えられます。
 この後に、集合を併合する操作が M 回行われます。
 時刻 i(1≦i≦M) 回目の操作では 要素 ai を持つ集合と 要素 bi を持つ集合を併合します。
 ただし、要素 ai と要素 bi が既に同じ集合に属している場合には何も起こりません。
 
 次に、Q 個の質問クエリが与えられ、j(1≦j≦Q) 番目の質問クエリの内容は以下の通りです。
 
 ｢要素 xj と 要素 yj が同じ集合に併合されるのは何回目の操作後ですか?｣
 M 回の操作後に 要素 xj と 要素 yj が 同じ集合に属さない場合には、-1 を出力してください。
 そうでない場合、K(1≦K≦M) 回目の操作後に要素 xj と 要素 yj が同じ集合に属するので、最小の K を出力してください。
=================================================================

解説=============================================================

 union find
 
 要素の併合を行う際に、同時にquery番号の併合を行い
 root(i)をキーとしたquery番号の集合を処理していけば良い
 
================================================================
*/

#define MAX_N 100010
set<int> s[MAX_N];
int ans[MAX_N];
int num = 1;

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
        if(rank[x] < rank[y]) swap(x,y);
        
        // 併合するときに、あらかじめ取得しておいたquery番号を用いた、併合を行う
        for(auto it:s[y]){
            if(s[x].count(it)){
                ans[it]=num;
                s[x].erase(it);
            }else{
                s[x].insert(it);
            }
        }
        s[y].clear(); // s[y]をs[x]に併合したので
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

void solve(){
    int N,M;cin>> N >> M;
    vector<int> a(M),b(M);
    for(int i = 0; i < M;i++){ cin >> a[i] >> b[i]; a[i]--; b[i]--; }
    int Q; cin >> Q;
    vector<int> x(Q),y(Q);
    for(int i = 0; i < Q;i++){ cin >> x[i] >> y[i]; x[i]--; y[i]--; }
    
    UnionFind uf(N);
    for(int i = 0; i < Q;i++){ s[x[i]].insert(i); s[y[i]].insert(i); ans[i]=-1; }
    for(int i = 0; i < M;i++){ uf.unite(a[i],b[i]); num++; }
    for(int i = 0; i < Q;i++){ cout << ans[i] << endl; }
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    solve();
	return 0;
}
