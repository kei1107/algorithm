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
 <url:https://atcoder.jp/contests/typical90/tasks/typical90_l>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */
/*
 UnionFind
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
    int H,W; cin >> H >> W;
    UnionFind UF(H*W);
    auto used = make_v<bool>(H,W);
    auto pos2id = [W](int r,int c){
        return r*W + c;
    };

    int DIR[4] = {1,0,-1,0};

    int Q; cin >> Q;
    while(Q--){
        int com; cin >> com;
        if(com == 1){
            int r,c; cin >> r >> c;
            r--; c--;
            used[r][c] = true;

            for(int k = 0; k < 4;k++){
                int nr = r + DIR[k];
                int nc = c + DIR[k^1];
                if(nr < 0 || nr >= H || nc < 0 || nc >= W) continue;
                if(used[nr][nc]){
                    UF.unionSet(pos2id(r,c),pos2id(nr,nc));
                }
            }
        }else{
            int ra,ca,rb,cb; cin >> ra >> ca >> rb >> cb;
            ra--; ca--; rb--;cb--;

            if(used[ra][ca] && used[rb][cb] && UF.findSet(pos2id(ra,ca),pos2id(rb,cb))){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
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