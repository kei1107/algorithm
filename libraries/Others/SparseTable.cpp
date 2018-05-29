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
 <url:https://beta.atcoder.jp/contests/arc023/tasks/arc023_4>

 SparseTable verify
 
 reference: https://github.com/beet-aizu/library/blob/master/sparsetable.cpp
 */

/*
 gcd : 最大公約数
 lcm : 最小公倍数
 */
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }

template<typename Type>
struct SparseTable{
    using Func = function<Type(Type,Type)>;
    int N;
    vector<vector<Type>> dat;
    vector<int> idx;
    const Func func;
    SparseTable(){}
    SparseTable(int n,Func func):func(func),N(n){init(n);};
    void init(int N){
        int _n = 1;
        while((1<<_n)<N) _n++;
        dat.assign(_n,vector<Type>(N));
        idx.assign(N+1,0);
        for(int j = 2; j <= N;j++) idx[j] = idx[j>>1]+1;
    }
    void build(vector<Type>& v){
        int N = (int)v.size();
        int _n = 1;
        while((1<<_n)<N) _n++;
        for(int j = 0; j < N;j++) dat[0][j] = v[j];
        for(int i = 1,p = 1; i < _n;i++,p<<=1){
            for(int j = 0; j < N;j++){
                dat[i][j] = func(dat[i-1][j],dat[i-1][min(j+p,N-1)]);
            }
        }
    }
    // [a,b)
    Type query(int a,int b){
        int l = b - a;
        return func(dat[idx[l]][a],dat[idx[l]][b-(1<<idx[l])]);
    }
};

void solve(){
    int n,m; cin >> n >> m;
    vector<ll> a(n),x(m);
    for(auto& in:a) cin >> in;
    for(auto& in:x) cin >> in;
    SparseTable<ll>::Func func = [](ll a,ll b){return gcd(a,b);};
    SparseTable<ll> ST(n,func);
    ST.build(a);
    
    map<ll,ll> ans;
    for(int i = 0; i < n;i++){
        int l = i;
        ll pre = a[i],lst = ST.query(i,n);
        while(lst!=pre){
            int r = n,pl = l;
            while(l+1<r){
                int m = (l+r)/2;
                if(ST.query(i,m)!=pre) r = m;
                else l = m;
            }
            ans[pre] += (l-pl);
            pre = ST.query(i,r);
        }
        ans[lst] += (n-l);
    }
    for(int i = 0; i < m;i++){
        cout << ans[x[i]] << endl;
    }
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
