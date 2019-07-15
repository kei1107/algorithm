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
template<class T> ostream& operator << (ostream& out,const vector<T>& V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> >& Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T>& mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }
template<typename T>vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}
/*
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1127>
 問題文============================================================
 =================================================================
 解説=============================================================
 距離をコストとした最小全域木を作ればいい。
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
struct P{
    double x,y,z,r;
    P(){}
    P(double x,double y,double z,double r):x(x),y(y),z(z),r(r){}
    double operator - (const P& o){
        return max(0.0,sqrt((x-o.x)*(x-o.x)+(y-o.y)*(y-o.y)+(z-o.z)*(z-o.z)) - r - o.r);
    }
};

template<class Type>
Type solve(Type res = Type()){
    int n;
    while(cin >> n,n){
        vector<P> Ps(n);
        for(int i = 0; i < n;i++){
            double x,y,z,r;cin >> x >> y >> z >> r;
            Ps[i] = P(x,y,z,r);
        }
        
        using Item = tuple<double,int,int>;
        priority_queue<Item,vector<Item>,greater<Item>> pq;
        for(int i = 0; i < n;i++){
            for(int j = i+1;j<n;j++){
                pq.push(Item(Ps[i]-Ps[j],i,j));
            }
        }
        UnionFind UF(n);
        double ans = 0;
        while(pq.size()){
            double cost; int u,v;
            tie(cost,u,v) = pq.top(); pq.pop();
            if(UF.same(u, v)) continue;
            ans += cost;
            UF.unite(u, v);
        }
        cout << fixed << setprecision(3) << ans << endl;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve(0);
    //cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
