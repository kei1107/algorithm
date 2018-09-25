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
 <url:https://yukicoder.me/problems/no/168>
 問題文============================================================
 =================================================================
 解説=============================================================
 最小全域木を作る要領で短いへんからつなげていき
 1-Nが連結になった瞬間に繋げた物差しがもっともの長い物差し
 
 
 想定解
 物差しの長さを二分探索して、
 長さ以下のものさしで作るグラフが1-Nが連結になっていればok
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

typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-9, pi = acos(-1.0);
namespace std {
    bool operator<(const Point &lhs, const Point &rhs) {
        if (lhs.real() < rhs.real() - eps) return true;
        if (lhs.real() > rhs.real() + eps) return false;
        return lhs.imag() < rhs.imag();
    }
}
Point input_point() {ld x, y; cin >> x >> y; return Point(x, y);} // 点の入力
bool eq(ld a, ld b) {return (abs(a - b) < eps);} // 誤差つき等号判定
ld dot(Point a, Point b) {return real(conj(a) * b);} // 内積
ld cross(Point a, Point b) {return imag(conj(a) * b);} // 外積


struct edge{
    int u,v;
    ld cost;
    edge(int u,int v,ld c):u(u),v(v),cost(c){}
    bool operator < (const edge& o) const{
        return cost < o.cost;
    }
    bool operator > (const edge& o) const{
        return cost > o.cost;
    }
};
ll solve(){
    ll res = 0;
    int N; cin >> N;
    vector<Point> ps(N);
    for(int i = 0; i < N;i++) ps[i] = input_point();
    priority_queue<edge,vector<edge>,greater<edge>> pq;
    for(int i = 0; i < N;i++){
        for(int j = i+1; j < N;j++){
            pq.push(edge(i,j,abs(ps[i]-ps[j])));
        }
    }
    
    UnionFind UF(N);
    ld maxL = 0;
    while(pq.size()){
        auto e = pq.top(); pq.pop();
        if(UF.same(e.u,e.v)) continue;
        UF.unite(e.u,e.v);
        if(UF.same(0,N-1)){ maxL = e.cost; break;}
    }
    
    res = ceil(maxL/10)*10;
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
