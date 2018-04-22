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
 <url:https://beta.atcoder.jp/contests/maximum-cup-2018/tasks/maximum_cup_2018_c>
 問題文============================================================
 天使の中に悪魔が紛れ込んだ。あなたは上司にこれを報告しなければならないが、
 上司は『最大でどれだけ悪魔が紛れ込んだか調査しろ』と命じてきた。
 
 「一体、誰が悪魔なんですかね」
 
 あなたが言うと、彼らは『あいつが悪魔だ』と指摘し合った。誰も同じ者を指ささずバラバラの者を指摘していた。
 
 どうやら天使は必ず悪魔を、悪魔は必ず天使を指摘しているようだった。
 
 最大で何人の悪魔がいるだろうか。その数を報告してほしい。
 
 ただし、あなたや上司は天使でも悪魔でもなく、入力で与えられる『彼ら』には含まれない。
 また、『彼ら』はそれぞれ天使か悪魔のどちらかである。
 =================================================================
 解説=============================================================
 
 与えられたグラフが二部グラフでなければ矛盾が生じる
 
 二部グラフであれば、その2色の数が大きいほうが答え
 ================================================================
 */

class BipartiteGraph{
public:
    vector<vector<ll>> G; // グラフ
    ll N; // 頂点数
    vector<int> color; // 頂点iの色(1 or -1);
    
    vector<ll> lv,rv;
    BipartiteGraph(int _N):N(_N){ G.resize(N); color.resize(N,0); }
    BipartiteGraph(ll _N):N(_N){ G.resize(N); color.resize(N,0); }

    void init(ll _N){
        N = _N;
        G.clear(); color.clear();
        G.resize(N); color.resize(N,0);
    }

    void add_edge(ll u,ll v){
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    bool dfs(ll v,int c){
        color[v] = c; // 頂点vをcで塗る
        for(int i = 0; i < G[v].size(); i++){
            // 隣接している頂点が同じ色ならfalse
            if(color[G[v][i]] == c) return false;
            // 隣接している頂点がまだ塗られていないなら-cで塗る
            if(color[G[v][i]] == 0 && !dfs(G[v][i],-c)) return false;
        }
        // すべての頂点を濡れたらtrue
        return true;
    }
    
    bool build(){
        for(int i = 0; i < N;i++){
            if(color[i] == 0){
                // まだ頂点iが塗られていなければ1で塗る
                if(!dfs(i,1)) return false;
            }
        }
        return true;
    }
    
    void make(){
        for(int i = 0; i < N;i++){
            if(color[i] == 1) lv.push_back(i);
            if(color[i] == -1) rv.push_back(i);
        }
    }
};
ll solve(){
    ll res = 0;
    ll N; cin >> N;
    vector<ll> A(N);
    BipartiteGraph BG(N);
    for(int i = 0; i < N;i++){
        ll A; cin >> A; A--;
        BG.add_edge(i,A);
    }
    
    if(!BG.build()) return res = -1;
    BG.make();
    res = max(BG.lv.size(),BG.rv.size());
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
