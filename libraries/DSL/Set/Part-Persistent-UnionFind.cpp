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
 部分永続UnionFind
 Getnow := 最新の更新時間を返却
 Tに確認したい状態の更新時間を与える
 */
class PartParsistentUnionFind{
    typedef pair<int,int> pii;
private:
    vector<int> par;
    vector<int> time;
    vector<vector<pii>> size;
    int now;
public:
    PartParsistentUnionFind(){}
    PartParsistentUnionFind(int N){init(N);}
    void init(int N){
        par.clear(); time.clear(); size.clear();
        par.assign(N,1);
        time.resize(N,INT_MAX);
        size.assign(N,vector<pii>(1,{0,1}));
        now = 0;
    }
    int find(int x,int T = INT_MAX){
        if(T == INT_MAX) T = now;
        if(time[x] > T) return x;
        else return find(par[x],T);
    }
    bool unite(int x,int y){
        now++;
        x = find(x,now); y = find(y,now);
        if(x == y) return false;
        if(par[x] < par[y]) swap(x,y);
        par[x] += par[y];
        par[y] = x;
        time[y] = now;
        size[x].push_back({now,par[x]});
        return true;
    }
    int Getnow(){ return now; }
    pii Getsize(int x,int T = INT_MAX){
        if(T == INT_MAX) T = now;
        x = find(x);
        int idx = (int)(upper_bound(size[x].begin(), size[x].end(), pii(T,INT_MAX)) - size[x].begin()) - 1;
        return size[x][idx];
    }
    bool same(int x,int y,int T = INT_MAX){
        if(T == INT_MAX) T = now;
        return find(x,T) == find(y,T);
    }
};

void solve(){
    int n,q; cin >> n >> q;
    PartParsistentUnionFind PPUF(n);
    vector<pair<int,pii>> query;
    while(q--){
        int com; cin >> com;
        int x,y; cin >> x >> y;
        if(com == 0){
            PPUF.unite(x, y);
            cout << PPUF.Getsize(x) << endl;
        }else{
            query.push_back({PPUF.Getnow(),{x,y}});
        }
    }
    for(auto q:query){
        cout << PPUF.same(q.second.first,q.second.second,q.first) << endl;
    }
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
