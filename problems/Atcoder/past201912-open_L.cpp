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
 <url:https://atcoder.jp/contests/past201912-open/tasks/past201912_l>
 問題文============================================================
 =================================================================
 解説=============================================================
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

typedef complex<double> Point;
template<class Type>
Type solve(Type res = Type()){
    res = LINF;
    int N,M; cin >> N >> M;
    vector<Point> ltp(N),stp(M);
    vector<int> ltc(N),stc(M);
    
    for(int i = 0; i < N;i++){
        double x,y; int c;
        cin >> x >> y >> c;
        ltp[i] = Point(x,y);
        ltc[i] = c;
    }
    for(int i = 0; i < M;i++){
        double x,y; int c;
        cin >> x >> y >> c;
        stp[i] = Point(x,y);
        stc[i] = c;
    }
    
    for(int b = 0; b < (1<<M);b++){
        using Item = tuple<double,int,int>;
        priority_queue<Item,vector<Item>,greater<Item>> pq;
        
        vector<int> stidx;
        for(int i = 0; i < M;i++){
            if((b>>i)&1) stidx.push_back(i);
        }
        
        for(int i = 0; i < N;i++){
            for(int j = i+1; j < N;j++){
                double cost = abs(ltp[i]-ltp[j]);
                if(ltc[i]!=ltc[j]) cost *= 10;
                pq.push(Item(cost,i,j));
            }
            for(int j = 0; j < (int)stidx.size(); j++){
                int jj = stidx[j];
                double cost = abs(ltp[i]-stp[jj]);
                if(ltc[i]!=stc[jj]) cost *= 10;
                pq.push(Item(cost,i,N+j));
            }
        }
        for(int i = 0; i < (int)stidx.size(); i++){
            for(int j = i+1; j < (int)stidx.size(); j++){
                int ii = stidx[i];
                int jj = stidx[j];
                double cost = abs(stp[ii]-stp[jj]);
                if(stc[ii]!=stc[jj]) cost *= 10;
                pq.push(Item(cost,N+i,N+j));
            }
        }
        
        double T = 0;
        UnionFind UF(N+(int)stidx.size());
        while(pq.size()){
            double cost; int u,v;
            tie(cost,u,v) = pq.top(); pq.pop();
            
            if(UF.same(u,v)) continue;
            T += cost;
            UF.unite(u,v);
        }
        res = min(res,T);
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<double>() << endl;
    return 0;
}
