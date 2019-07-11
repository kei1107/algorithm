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
 木の同型判定
 */
// 森の部分木と与えられた根なし木の同型判定

typedef vector<vector<int>> Graph;
// 森から連結成分を取り出す
vector<Graph> ConnectedComponent(Graph& f){
    int n = (int)f.size(), pos = 0;
    vector<int> used(n,false);
    vector<Graph> res;
    queue<int> q;
    while(pos < n){
        vector<int> used_v;
        int size = 0;
        q.push(pos);
        used[pos] = true;
        while(q.size()){
            size++;
            int v = q.front(); q.pop();
            used_v.push_back(v);
            for(int i = 0; i < f[v].size();i++){
                if(used[f[v][i]] == true)continue;
                q.push(f[v][i]); used[f[v][i]] = true;
            }
        }
        sort(used_v.begin(),used_v.end());
        Graph g(used_v.size());
        for(int i = 0; i < used_v.size();i++){
            for(int j = 0; j < f[used_v[i]].size();j++){
                g[i].push_back((int)(lower_bound(used_v.begin(), used_v.end(), f[used_v[i]][j])-used_v.begin()));
            }
        }
        res.push_back(g);
        while(pos < n && used[pos]) pos++;
    }
    return res;
}

vector<int> bfs(const Graph& g,vector<int>& dist, int v){
    int n = (int)g.size();
    queue<pii> q;
    vector<int> par(n);
    for(int i = 0; i < n;i++) par[i] = i;
    q.push(make_pair(v,0));
    dist[v] = 0;
    while(q.size()){
        int v,d; tie(v,d) = q.front(); q.pop();
        for(int i = 0; i < g[v].size();i++){
            if(dist[g[v][i]] >= 0) continue;
            dist[g[v][i]] = d + 1;
            par[g[v][i]] = v;
            q.push(pii(g[v][i],d+1));
        }
    }
    return par;
}

// 木の中心
inline vector<int> CenterTree(const Graph&g,int v = 0){
    int n = (int)g.size();
    vector<int> dist(n,-1);
    bfs(g,dist,v);
    int u = -1,maxi = -1;
    for(int i = 0; i < n;i++){
        if(dist[i] > maxi){
            u = i; maxi = dist[i];
        }
    }
    fill(dist.begin(),dist.end(),-1);
    vector<int> par = bfs(g,dist,u);
    int diam = 0;
    for(int i = 0; i < n;i++){
        if(dist[i] > diam){ diam = dist[i]; v = i;}
    }
    for(int i = 0; i < diam/2;i++) v = par[v];
    
    vector<int> res;
    res.push_back(v);
    if(diam%2 != 0) res.push_back(par[v]);
    return res;
}


// =================================================== //
// 木のHash生成
map<vector<int>,int> tree_hash;
int AHUHash(const Graph& t,int v,int par = -1){
    if(t[v].size() == 1 && par != -1) return 0;
    vector<int >res;
    for(int i = 0; i < t[v].size();i++){
        if(t[v][i] == par) continue;
        res.emplace_back(AHUHash(t, t[v][i],v));
    }
    sort(res.begin(),res.end());
    if(tree_hash.count(res) == 0){
        tree_hash[res] = (int)tree_hash.size();
    }
    return tree_hash[res];
}
// ================================================== //

void AOJ2821(){
    
    // 森の入力
    int N1,M1; cin >> N1 >> M1;
    Graph Forest(N1);
    for(int i = 0; i < M1;i++){
        int u,v; cin >> u >> v;
        u--; v--;
        Forest[u].push_back(v);
        Forest[v].push_back(u);
    }
    
    // 木の入力
    int N2; cin >> N2;
    Graph Tree(N2);
    for(int i = 0; i < N2-1;i++){
        int u,v; cin >> u >> v;
        u--; v--;
        Tree[u].push_back(v);
        Tree[v].push_back(u);
    }
    
    int ans = 0;
    
    vector<int> CT = CenterTree(Tree); // 木の中心を得る
    vector<ll> TH(CT.size()); // 木のHash
    for(int i = 0; i < CT.size(); i++){
        TH[i] = AHUHash(Tree, CT[i]); // CT[i]を根として木のHashを得る
    }
    
    
    vector<Graph> Tree_set = ConnectedComponent(Forest); // 森から連結成分の部分木を取り出す
    for(auto T:Tree_set){
        if(T.size() != N2) continue; // 頂点数がN2と一致しなければ明らかに同型ではない
        vector<int> CT2 = CenterTree(T); // 木の中心を得る
        vector<ll> TH2(CT2.size()); // 木のHash
        for(int i = 0; i < CT2.size();i++){
            TH2[i] = AHUHash(T, CT2[i]); // CT2[i]を根として木のHashを得る
        }
        
        if(CT.size() != CT2.size()) continue; // 木の中心の数が異なれば明らかに同型ではない
        
        // 今見ている木TがTreeと同型か判定する
        bool ok = [&]{
            for(int i = 0; i < TH.size(); i++){
                for(int j = 0; j < TH2.size();j++){
                    if(TH[i] == TH2[j]) return true;
                }
            }
            return false;
        }();
        if(ok) ans++; // 同型である
    }
    cout << ans << endl;
}


int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    AOJ2821();
    return 0;
}
