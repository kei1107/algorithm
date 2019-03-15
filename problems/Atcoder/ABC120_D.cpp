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
 <url:https://atcoder.jp/contests/abc120/tasks/abc120_d>
 問題文============================================================
 =================================================================
 解説=============================================================
 互いに行き来可能な集合の組のサイズがわかれば、その集合内での”不便でなさ”は一意に決まるので
 橋が0の状態から逆に復元しつつ、最大不便さN*(N-1)/2から引いていく
 ================================================================
 */

struct UnionFind {
    vector<int> data;
    UnionFind(int size) : data(size, -1) { }
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

template<class Type>
Type solve(Type res = Type()){
    ll N,M; cin >> N >> M;
    vector<pii> AB(M);
    for(auto &in:AB){
        cin >> in.first >> in.second;
        in.first--;
        in.second--;
    }
    vector<ll> ans(M);
    UnionFind UF((int)N);
    vector<ll> cost(N);
    reverse(AB.begin(),AB.end());
    ans[0] = N*(N-1)/2;
    for(int i = 0; i < M-1;i++){
        int u,v; tie(u,v) = AB[i];
        if(UF.findSet(u,v)){
            ans[i+1] = ans[i];
        }else{
            ll ru = UF.root(u),rv = UF.root(v);
            ans[i+1] = ans[i] + cost[ru] + cost[rv];
            UF.unionSet(u,v);
            
            ll r = UF.root(u);
            ll sz = UF.size(r);
            cost[r] = sz*(sz-1)/2;
            ans[i+1] -= cost[r];
        }
    }
    reverse(ans.begin(),ans.end());
    for(auto a:ans){
        cout << a << endl;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve(0);
    //cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
