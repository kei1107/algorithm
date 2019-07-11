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
 Range Inverse Query
 */
//typedef pair<int, int> P;
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
