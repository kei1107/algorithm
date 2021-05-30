#include "bits/stdc++.h"
#include "atcoder/all"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T>& V){ for(size_t i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> >& Mat){ for(size_t i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T>& mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }
template<typename T>vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}
/*
 <url:https://atcoder.jp/contests/typical90/tasks/typical90_aw>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */

struct UnionFind {
	vector<int> par;
	int n, cnt;
	UnionFind(const int& x = 0) { init(x); }
	void init(const int& x) { par.assign(cnt = n = x, -1); }
	inline int find(const int& x) { return par[x] < 0 ? x : par[x] = find(par[x]); }
	inline bool same(const int& x, const int& y) { return find(x) == find(y); }
	inline bool unite(int x, int y) {
		if ((x = find(x)) == (y = find(y))) return false;
		--cnt;
		if (par[x] > par[y]) swap(x, y);
		par[x] += par[y];
		par[y] = x;
		return true;
	}
	inline int count() const { return cnt; }
	inline int count(int x) { return -par[find(x)]; }
};

struct edge {
	ll u;
	ll v;
	ll cost;
	edge() {}
	edge(ll u, ll v, ll c) :u(u), v(v), cost(c) {}
	bool operator < (const edge& o) const {
		return cost < o.cost;
	}
	bool operator > (const edge& o)const {
		return cost > o.cost;
	}
};


template<class Type>
Type solve(Type res = Type()){

    int N,M; cin >> N >> M;
    vector<ll> C(M);
    vector<int> L(M),R(M);

    UnionFind UF(N+1);
	priority_queue<edge,vector<edge>,greater<edge>> G;

    for(int i = 0; i < M;i++){
        cin >> C[i] >> L[i] >> R[i];
        G.emplace(L[i]-1,R[i],C[i]);
    }
    while(G.size()){
        auto e = G.top(); G.pop();
        if(UF.same(e.u,e.v)) continue;
        UF.unite(e.u,e.v);
        res += e.cost;
    }

    return UF.count()==1?res:-1;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    //solve<ll>(0);
    cout << fixed << setprecision(12) << solve<ll>() << endl;
    return 0;
}