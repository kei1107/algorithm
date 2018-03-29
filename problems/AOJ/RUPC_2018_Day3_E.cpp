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
<url:https://onlinejudge.u-aizu.ac.jp/services/room.html#RitsCamp18Day3/problems/E>
問題文============================================================

 n 頂点からなる根つき木 T が与えられる。
 ここで、 n は奇数であり、 T の根は頂点番号が 1 である。
 さらに、それぞれの頂点 v に対して G もしくは W のラベルが与えられ、
 頂点 v と v の子孫からなる部分木を v の部分木 Tv と呼ぶ。
 
 次の操作が q 回行われる。それぞれの操作終了時に、
 T 中の全ての頂点で、G のラベルを持つ頂点が過半数をこえる場合は
 “broccoli”、そうでない場合は “cauliflower” と出力せよ。
 
 頂点 v が与えられる。部分木 Tv 中の頂点 u がラベル G を持つならば u のラベルを W に、
 W を持つならば u のラベルを G にする。
 
=================================================================

解説=============================================================

 頂点vを根とする部分木はeuler tour にすることで一次元の配列の区間に変換できる
 
 よって、この配列に対する 0 1 反転の処理をすれば良い
 
================================================================
*/


const int MAX_N = 1 << 17;
ll seg[MAX_N * 2];     // 区間内の1の個数
ll lazy[MAX_N * 2];    // 後でノードを反転させるつもりがあるか

// 遅延
void lazy_evaluate(ll k, ll l, ll r) {
    // このノードを反転させるつもりがなかったなら何もしない
    if (lazy[k] == 0) return;
    // 以下、このノードを反転させる場合
    // ノードが表す区間内の1の数が反転
    seg[k] = (r - l) - seg[k];
    // ノードkが子を持つならば、子を後で反転させるつもりにしておく
    if (r - l > 1) {
        lazy[k * 2 + 1] ^= 1;
        lazy[k * 2 + 2] ^= 1;
    }
    // ノードkはもう反転させたので0にしておく
    lazy[k] = 0;
}

// 区間内のビットを反転させる
void inv(ll a,ll b, ll k = 0, ll l = 0, ll r = MAX_N) {
    lazy_evaluate(k, l, r);
    // ノードが範囲外なら何もしない
    if (r <= a || b <= l) { return; }
    // ノードが完全に区間に含まれていれば、反転回数が反転
    if (a <= l && r <= b) {
        lazy[k] ^= 1;
        lazy_evaluate(k, l, r);
    }
    // 子ノードを反転させ（↓）、自身を子ノードの和に更新（↑）
    else {
        inv(a, b, k * 2 + 1, l, (l + r) / 2);
        inv(a, b, k * 2 + 2, (l + r) / 2, r);
        seg[k] = seg[k * 2 + 1] + seg[k * 2 + 2];
    }
}


ll sum(ll a, ll b, ll k = 0, ll l = 0, ll r = MAX_N) {
    lazy_evaluate(k, l, r);
    // ノードが範囲外なら0を返す
    if (r <= a || b <= l) {
        return 0;
    }
    // ノードが完全に区間に含まれていれば、このノードの値を返す
    else if (a <= l && r <= b) {
        return seg[k];
    }
    // 上記以外の場合、左右の子ノードの和を返す
    else {
        ll res = 0;
        res += sum(a, b, k * 2 + 1, l, (l + r) / 2);
        res += sum(a, b, k * 2 + 2, (l + r) / 2, r);
        return res;
    }
}


// ET 
void dfs(int n,vector<vector<int>>& G,vector<vector<int>>& T,int &ETV){
    T[n].push_back(ETV++);
    for(int next:G[n]) dfs(next,G,T,ETV);
    T[n].push_back(ETV);
}

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    
    int n,q; cin >> n >> q;
    vector<vector<int>> G(n);
    for(int i = 1; i < n;i++){
        int p; cin >> p; p--;
        G[p].push_back(i);
    }
    
    // create euler tour
    vector<vector<int>> T(n);
    int ETV = 0;
    dfs(0,G,T,ETV);
    
    for(int i = 0; i < n;i++){
        char c; cin >> c;
        if(c == 'G'){
            inv(T[i][0],T[i][0]+1); // ビットを立てる
        }
    }

    while(q--){
        int v; cin >> v; v--;
        inv(T[v][0],T[v][1]);
        ll ret = sum(0,ETV);
        if(ret >= (n+1)/2){
            cout << "broccoli" << endl;
        }else{
            cout << "cauliflower" << endl;
        }
    }
	return 0;
}
