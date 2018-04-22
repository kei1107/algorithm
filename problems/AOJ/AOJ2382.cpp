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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2382>
 問題文============================================================
 周りが壁に囲まれた W x Hのマスの空間がある。
 N匹のスライムがマス(xi,yi)にいる。
 各スライムは上下左右いずれかの方向にスライムにぶつかるか壁にぶつかるまで移動できる。
 
 スライム同士がぶつかると、合体して1匹のスライムになる。
 N匹のスライムが1匹のスライムになるまでの最小の移動回数を述べよ
 =================================================================
 解説=============================================================
 
 まず、各スライムが１回の行動で他のスライムと合体できるような位置関係であれば、
 N-1回で全てのスライムが合体できることから、最低でもN-1回の行動が必要である。
 
 ここで、あるスライムから同一の列または行にいるスライムは1回の行動で合体することができる為、合体させたほうがいい。
 また、連鎖的に同一の行・列にいるスライム達も連鎖的に最適な行動をすれば全て1回で合体できる。
 よって、union-findを用いて、そのような集合を求める。
 
 次に、union-findの集合の数が2個以上存在すれば、それらのスライム達は
 壁を用いなければ他のスライムと合体できない為、全てのスライムが同一の壁際に集まり、
 合体すれば最適となる。
 この時、注意点として、すでに壁際にスライムが存在する場合がある為、その場合の例外処理をしておく
 ================================================================
 */

struct UnionFind {
    vector<int> data;
    UnionFind(ll size) : data(size, -1) { }
    bool unionSet(int x, int y) {
        x = root(x); y = root(y);
        if (x != y) {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y]; data[y] = x;
        }
        return x != y;
    }
    bool findSet(int x, int y) {
        return root(x) == root(y);
    }
    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    int size(int x) {
        return -data[root(x)];
    }
};

ll solve(){
    ll res = LINF;
    ll N,W,H; cin >> N >> W >> H;
    vector<ll> x(N),y(N);
    bool f = false;
    for(int i = 0; i < N;i++){
        cin >> x[i] >> y[i];
        f |= (x[i]==1|x[i]==W|y[i]==1|y[i]==H);
    }
    
    vector<vector<pll>> wG(W+2),hG(H+2);
    for(int i = 0; i < N;i++){
        wG[x[i]].push_back({y[i],i});
        hG[y[i]].push_back({x[i],i});
    }
    
    UnionFind uf(N);
    for(int i = 0; i < W+2;i++){
        if(wG[i].size() < 2) continue;
        for(int j = 0; j < wG[i].size()-1;j++){
            int idx1 = wG[i][j].second, idx2 = wG[i][j+1].second;
            uf.unionSet(idx1, idx2);
        }
    }
    for(int i = 0; i < H+2;i++){
        if(hG[i].size() < 2) continue;
        for(int j = 0; j < hG[i].size()-1;j++){
            int idx1 = hG[i][j].second, idx2 = hG[i][j+1].second;
            uf.unionSet(idx1, idx2);
        }
    }
    set<int> s;
    for(int i = 0; i < N;i++) s.insert(uf.root(i));
    if(s.size() == 1){
        res = N-1;
    }else{
        res = N-1+s.size()-f;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
