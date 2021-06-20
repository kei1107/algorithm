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
template<class T> ostream& operator << (ostream& out,const vector<T>& V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> >& Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T>& mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }
template<typename T>vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}
/*
 <url:https://atcoder.jp/contests/typical90/tasks/typical90_bp>
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

template<class Type>
Type solve(Type res = Type()){
    int N,Q; cin >> N >> Q;

    vector<ll> T(Q),X(Q),Y(Q),V(Q);
    for(int i = 0; i < Q;i++){
        cin >> T[i] >> X[i] >> Y[i] >> V[i];
        X[i]--; Y[i]--;
    }

    vector<ll> sum(N,0),diff(N,0);
    for(int i = 0; i < Q;i++){
        if(T[i] == 0) sum[X[i]] = V[i];
    }
    for(int i = 1; i < N;i++){
        diff[i] = sum[i-1] - diff[i-1];
    }

    UnionFind UF(N);

    for(int i = 0; i < Q;i++){
        if(T[i] == 0){
            UF.unite(X[i],Y[i]);
        }else{
            if(UF.same(X[i],Y[i])){
                if((X[i]+Y[i])%2==0){
                    cout << V[i] + (diff[Y[i]] - diff[X[i]]) << endl;
                }else{
                    cout << (diff[Y[i]] + diff[X[i]]) - V[i] << endl;
                }
            }else{
                cout << "Ambiguous" << endl;
            }
        }
    }

    return res;
}

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    solve<ll>(0);
    // cout << fixed << setprecision(12) << solve<ll>() << endl;
    return 0;
}