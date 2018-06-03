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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1236>
 問題文============================================================
 
 無向グラフが存在する
 自分は最初そのグラフのノード番号０のノードにいる
 入力が正のとき、それは今いるノードの次数を表す
 入力が負のとき、それは（今いるノードの深さ）ー（１つ前にいたノードの深さ）を表す
 ここで深さとは、ノード０からの距離を意味する
 これらの入力からその無向グラフを復元せよ
 
 =================================================================
 解説=============================================================
 
 dfsにより、復元を行っていく。
 入力の正の数だけ部屋が存在するので、あらかじめその部屋を用意しておき、
 各部屋の残りのつなぐことができる辺の数
 各部屋の繋がれる可能性のある深さの部屋が何かをmapなどを使って保存しておけば良い
 
 ================================================================
 */

vector<vector<int>> G;
vector<int> memo;
vector<pii> roomdoor;
map<int,pii> mp;
void dfs(int dep,int& i){
    if(i >= memo.size()) return;
    int idx = i;
    int n = roomdoor[i].second;
    mp[dep] = {i,n};

    i++;
    while(i < memo.size()){
        if(roomdoor[idx].first == 0) break;
        if(memo[i] > 0){
            int next = roomdoor[i].second;
            G[n].push_back(next);
            G[next].push_back(n);
            roomdoor[idx].first--; roomdoor[i].first--;
            dfs(dep+1,i);
        }else{
            pii p = mp[dep+memo[i]];
            int nextidx = p.first;
            int next = p.second;
            G[n].push_back(next);
            G[next].push_back(n);
            roomdoor[idx].first--; roomdoor[nextidx].first--;
            i++;
        }
    }
}
void solve(){
    mp.clear();
    memo.clear();
    roomdoor.clear();
    G.clear();
    int x; while(cin >> x,x) memo.push_back(x);
    roomdoor.assign(memo.size(),{0,0});
    int V = 0;
    for(int i = 0; i < memo.size();i++){
        if(memo[i] < 0) continue;
        roomdoor[i] = {memo[i],V++};
    }
    
    G.resize(V);
    int i = 0;
    dfs(0,i);
    for(int i = 0; i < V;i++){
        cout << i + 1 << " ";
        sort(G[i].begin(),G[i].end());
        for(int j = 0; j < G[i].size(); j++){
            cout << G[i][j]+1 << " \n"[j==G[i].size()-1];
        }
    }
    
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    int n; cin >> n;
    while(n--){
        solve();
    }
    return 0;
}
