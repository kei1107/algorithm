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
 <url:http://codeforces.com/contest/959/problem/C>
 問題文============================================================
 Mahmoud was trying to solve the vertex cover problem on trees. The problem statement is:
 
 Given an undirected tree consisting of n nodes, find the minimum number of vertices that
 cover all the edges. Formally, we need to find a set of vertices such that for
 each edge (u, v) that belongs to the tree, either u is in the set,
 or v is in the set, or both are in the set. Mahmoud has found the following algorithm:
 
 Root the tree at node 1.
 Count the number of nodes at an even depth. Let it be evenCnt.
 Count the number of nodes at an odd depth. Let it be oddCnt.
 The answer is the minimum between evenCnt and oddCnt.
 
 
 The depth of a node in a tree is the number of edges in the shortest path between
 this node and the root. The depth of the root is 0.
 
 Ehab told Mahmoud that this algorithm is wrong, but he didn't believe because he had
 tested his algorithm against many trees and it worked, so Ehab asked you to find 2 trees
 consisting of n nodes. The algorithm should find an incorrect answer for the first tree
 and a correct answer for the second one.
 =================================================================
 解説=============================================================
 
 n<6までは、Mahmoudさんの考えたアルゴリズムは正しい
 n>=6では
 root に 2,3,4をつなげ、その後2,3,4のいづれかに以降の頂点をつなげれば反例となる。
 
 正しい形については、1->2->3->4->....
 といった風に直線にすれば良い
 
 ================================================================
 */

void solve(){
    ll n; cin >> n;
    // ans 1
    if(n <= 5){
        cout << -1 << endl;
    }else{
        cout << 1 << " " << 2 << endl;
        cout << 1 << " " << 3 << endl;
        cout << 1 << " " << 4 << endl;
        for(int i = 5; i <= n; i++){
            cout << 2 << " " << i << endl;
        }
    }
    
    // ans 2 :  1->2->3->...
    for(int i = 1; i <= n-1;i++){
        cout << i << " " << i+1 << endl;
    }
}

int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
