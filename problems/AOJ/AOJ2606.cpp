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
 <url:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2606>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 サイクルの最大周期が40なので、
 指定区間の全ての数が一致するタイミングをlcmで求めることができる。
 よって、区間のlcmを高速に求めることがまず必要となるがこれはseg木やsparsetable
 で取得できる。
 
 また実際の計算方法だが、サイクル数が少ないので、i番目まで見たときサイクル数がk
 の時の値の総和を累積和でとれば高速に求めることができる
 
 ================================================================
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
    Type query(int a,int b){
        int l = b - a;
        return func(dat[idx[l]][a],dat[idx[l]][b-(1<<idx[l])]);
    }
};

const ll MOD = 1e9+7;
void solve(){
    int N,Q; cin >> N >> Q;
    vector<int>  x(N+1); iota(x.begin(),x.end(),0);
    vector<int> p(N+1); for(int i = 1; i <= N;i++) cin >> p[i];
    vector<vector<ll>> Val(N+1,vector<ll>(1,0));
    vector<int> flag(N+1,true); flag[0] = false;
    
    // init Val
    while(accumulate(flag.begin(),flag.end(),0)){
        for(int j = 1; j <= N;j++){
            if(!flag[j]) continue;
            x[j] = p[x[j]];
            Val[j].push_back(Val[j][Val[j].size()-1]+x[j]);
            if(j == x[j]) flag[j] = false;
        }
    }
    // init cusum
    vector<vector<ll>> cusum(N+1,vector<ll>(41,0));
    for(int i = 1; i <= N;i++){
        for(int j = 1; j <= 40;j++){
            cusum[i][j] += cusum[i-1][j];
        }
        cusum[i][Val[i].size()-1] += Val[i][Val[i].size()-1];
    }

    // init SparseTable
    vector<ll> table(N+1);
    table[0] = 1;
    for(int i = 1; i <= N;i++) table[i] = Val[i].size()-1;
    SparseTable<ll>::Func func = [](ll a,ll b){ return lcm(a,b); };
    SparseTable<ll> ST(N+1,func);
    ST.build(table);
    
    
    while(Q--){
        int l,r; cin >> l >> r;
        ll LCM = ST.query(l,r+1);
        ll ans = 0;
        for(int i = 1; i <= 40; i++){
            if(LCM%i != 0) continue;
            ll L = (LCM/i)%MOD;
            ans += L*(cusum[r][i] - cusum[l-1][i]);
            ans %= MOD;
        }
        cout << ans << endl;
    }
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
